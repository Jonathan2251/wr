//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TOOLS_ELF2HEX_ELF2HEX_H
#define LLVM_TOOLS_ELF2HEX_ELF2HEX_H

#include "llvm/DebugInfo/DIContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Object/Archive.h"

#include <stdio.h>
#include "llvm/Support/raw_ostream.h"

#define BOOT_SIZE 16

#define DLINK
//#define ELF2HEX_DEBUG

namespace llvm {
class StringRef;
class MCInst;

namespace object {
  class COFFObjectFile;
  class MachOObjectFile;
  class ObjectFile;
  class Archive;
  class RelocationRef;
}

extern cl::opt<std::string> TripleName;
extern cl::opt<std::string> ArchName;
extern cl::list<std::string> MAttrs;
extern cl::list<std::string> FilterSections;
extern cl::opt<bool> NoShowRawInsn;

// Various helper functions.
void error(std::error_code EC);
bool RelocAddressLess(object::RelocationRef a, object::RelocationRef b);
LLVM_ATTRIBUTE_NORETURN void error(Twine Message);
LLVM_ATTRIBUTE_NORETURN void report_error(StringRef File, std::error_code EC);
LLVM_ATTRIBUTE_NORETURN void report_error(StringRef File, llvm::Error E);
LLVM_ATTRIBUTE_NORETURN void report_error(StringRef FileName,
                                          StringRef ArchiveName,
                                          llvm::Error E,
                                          StringRef ArchitectureName
                                                    = StringRef());
LLVM_ATTRIBUTE_NORETURN void report_error(StringRef ArchiveName,
                                          const object::Archive::Child &C,
                                          llvm::Error E,
                                          StringRef ArchitectureName
                                                    = StringRef());

namespace elf2hex {

using namespace object;

class HexOut {
public:
  virtual void ProcessDisAsmInstruction(MCInst inst, uint64_t Size, 
                                ArrayRef<uint8_t> Bytes, const ObjectFile *Obj) = 0;
  virtual void ProcessDataSection(SectionRef Section) {};
  virtual ~HexOut() {};
};

// Split HexOut from Reader::DisassembleObject() for separating hex output 
// functions.
class VerilogHex : public HexOut {
public:
  VerilogHex(std::unique_ptr<MCInstPrinter>& instructionPointer, 
             std::unique_ptr<const MCSubtargetInfo>& subTargetInfo,
             const ObjectFile *Obj);
  void ProcessDisAsmInstruction(MCInst inst, uint64_t Size, 
                                ArrayRef<uint8_t> Bytes, const ObjectFile *Obj);
  void ProcessDataSection(SectionRef Section);

private:
  void PrintBootSection(uint64_t textOffset, uint64_t isrAddr, bool isLittleEndian);
  void Fill0s(uint64_t startAddr, uint64_t endAddr);
  void PrintDataSection(SectionRef Section);
  std::unique_ptr<MCInstPrinter>& IP;
  std::unique_ptr<const MCSubtargetInfo>& STI;
  uint64_t lastDumpAddr;
  unsigned si;
  StringRef sectionName;
};

class Reader {
public:
  void DisassembleObject(const ObjectFile *Obj, 
                         std::unique_ptr<MCDisassembler>& DisAsm, 
                         std::unique_ptr<MCInstPrinter>& IP, 
                         std::unique_ptr<const MCSubtargetInfo>& STI);
  StringRef CurrentSymbol();
  SectionRef CurrentSection();
  unsigned CurrentSi();
  uint64_t CurrentIndex();

private:
  SectionRef _section;
  std::vector<std::pair<uint64_t, StringRef> > Symbols;
  unsigned si;
  uint64_t Index;
};

} // end namespace elf2hex
} // end namespace llvm

//using namespace llvm;

#endif
