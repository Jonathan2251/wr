//===- CPU0.cpp -----------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "InputFiles.h"
#include "OutputSections.h"
#include "Symbols.h"
#include "SyntheticSections.h"
#include "Target.h"
#include "Thunks.h"
#include "lld/Common/ErrorHandler.h"
#include "llvm/Object/ELF.h"
#include "llvm/Support/Endian.h"

using namespace llvm;
using namespace llvm::object;
using namespace llvm::support::endian;
using namespace llvm::ELF;
using namespace lld;
using namespace lld::elf;

namespace {
template <class ELFT> class CPU0 final : public TargetInfo {
public:
  CPU0();
  RelExpr getRelExpr(RelType type, const Symbol &s,
                     const uint8_t *loc) const override;
  void writeGotPlt(uint8_t *buf, const Symbol &s) const override;
//  void writePltHeader(uint8_t *buf) const override;
//  void writePlt(uint8_t *buf, uint64_t gotPltEntryAddr, uint64_t pltEntryAddr,
//                int32_t index, unsigned relOff) const override;
//  bool needsThunk(RelExpr expr, RelType type, const InputFile *file,
//                  uint64_t branchAddr, const Symbol &s) const override;
  void relocateOne(uint8_t *loc, RelType type, uint64_t val) const override;
//  bool usesOnlyLowPageBits(RelType type) const override;
};
} // namespace

template <class ELFT> CPU0<ELFT>::CPU0() {
  gotPltHeaderEntriesNum = 2;
  defaultMaxPageSize = 65536;
  gotBaseSymInGotPlt = false;
  pltEntrySize = 16;
  pltHeaderSize = 32;

  // Set `sigrie 1` as a trap instruction.
  write32(trapInstr.data(), 0x04170001);
}

template <class ELFT>
RelExpr CPU0<ELFT>::getRelExpr(RelType type, const Symbol &s,
                               const uint8_t *loc) const {
  switch (type) {
  default:
    return R_ABS;
  case R_CPU0_32:
  case R_CPU0_HI16:
  case R_CPU0_LO16:
    return R_ABS;
  case R_CPU0_PC24:
    return R_PC;
  }
}

template <class ELFT>
void CPU0<ELFT>::writeGotPlt(uint8_t *Buf, const Symbol &) const {
  uint64_t va = in.plt->getVA();
  write32<ELFT::TargetEndianness>(Buf, va);
}

template <endianness E, uint8_t BSIZE, uint8_t SHIFT>
static void applyCpu0PcReloc(uint8_t *Loc, uint64_t V) {
  uint32_t Mask = 0xffffffff >> (32 - BSIZE);
  uint32_t Instr = read32<E>(Loc);
  write32<E>(Loc, (Instr & ~Mask) | ((V >> SHIFT) & Mask));
}

template <endianness E>
static void writeCpu0Hi16(uint8_t *Loc, uint64_t V) {
  uint32_t Instr = read32<E>(Loc);
  write32<E>(Loc, (Instr & 0xffff0000) | ((V + 0x8000) >> 16));
}

template <endianness E>
static void writeCpu0Lo16(uint8_t *Loc, uint64_t V) {
  uint32_t Instr = read32<E>(Loc);
  write32<E>(Loc, (Instr & 0xffff0000) | (V & 0xffff));
}

template <class ELFT>
void CPU0<ELFT>::relocateOne(uint8_t *Loc, RelType Type, uint64_t Val) const {
  const endianness E = ELFT::TargetEndianness;
  switch (Type) {
  case R_CPU0_32:
    write32<E>(Loc, Val);
    break;
  case R_CPU0_LO16:
    writeCpu0Lo16<E>(Loc, Val);
    break;
  case R_CPU0_HI16:
    writeCpu0Hi16<E>(Loc, Val);
    break;
  case R_CPU0_PC24:
    applyCpu0PcReloc<E, 24, 0>(Loc, Val-4);
    break;
  default:
    llvm_unreachable("unknown relocation");
  }
}

template <class ELFT> TargetInfo *elf::getCpu0TargetInfo() {
  static CPU0<ELFT> target;
  return &target;
}

template TargetInfo *elf::getCpu0TargetInfo<ELF32LE>();
template TargetInfo *elf::getCpu0TargetInfo<ELF32BE>();

