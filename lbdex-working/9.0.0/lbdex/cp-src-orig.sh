#!/usr/bin/env bash
SRC_DIR=src
GEN_DIR=src_files_modify/orig/src
mkdir src_files_modify
rm -rf src_files_modify/orig
mkdir src_files_modify/orig
mkdir ${GEN_DIR}
mkdir ${GEN_DIR}/cmake
mkdir ${GEN_DIR}/include
mkdir ${GEN_DIR}/include/llvm
mkdir ${GEN_DIR}/include/llvm/ADT
mkdir ${GEN_DIR}/include/llvm/IR
mkdir ${GEN_DIR}/include/llvm/MC
mkdir ${GEN_DIR}/include/llvm/Object
mkdir ${GEN_DIR}/include/llvm/BinaryFormat
mkdir ${GEN_DIR}/include/llvm/BinaryFormat/ELFRelocs
mkdir ${GEN_DIR}/lib
mkdir ${GEN_DIR}/lib/MC
mkdir ${GEN_DIR}/lib/Object
mkdir ${GEN_DIR}/lib/Support
mkdir ${GEN_DIR}/lib/Target

cp ${SRC_DIR}/CMakeLists.txt ${GEN_DIR}/CMakeLists.txt
cp ${SRC_DIR}/cmake/config-ix.cmake ${GEN_DIR}/cmake/config-ix.cmake
cp ${SRC_DIR}/include/llvm/ADT/Triple.h ${GEN_DIR}/include/llvm/ADT/Triple.h
cp ${SRC_DIR}/include/llvm/IR/Intrinsics.td ${GEN_DIR}/include/llvm/IR/Intrinsics.td
#cp ${SRC_DIR}/include/llvm/MC/MCExpr.h ${GEN_DIR}/include/llvm/MC/MCExpr.h
cp ${SRC_DIR}/include/llvm/Object/ELFObjectFile.h ${GEN_DIR}/include/llvm/Object/ELFObjectFile.h
cp ${SRC_DIR}/include/llvm/BinaryFormat/ELF.h ${GEN_DIR}/include/llvm/BinaryFormat/ELF.h

cp ${SRC_DIR}/lib/MC/MCDwarf.cpp ${GEN_DIR}/lib/MC/MCDwarf.cpp
#cp ${SRC_DIR}/lib/MC/MCELFStreamer.cpp ${GEN_DIR}/lib/MC/MCELFStreamer.cpp
#cp ${SRC_DIR}/lib/MC/MCExpr.cpp ${GEN_DIR}/lib/MC/MCExpr.cpp
cp ${SRC_DIR}/lib/MC/MCSubtargetInfo.cpp ${GEN_DIR}/lib/MC/MCSubtargetInfo.cpp
cp ${SRC_DIR}/lib/MC/SubtargetFeature.cpp ${GEN_DIR}/lib/MC/SubtargetFeature.cpp
cp ${SRC_DIR}/lib/Object/ELF.cpp ${GEN_DIR}/lib/Object/ELF.cpp
cp ${SRC_DIR}/lib/Object/ ${GEN_DIR}/lib/Object/ModuleSymbolTable.cpp

cp ${SRC_DIR}/lib/Support/Triple.cpp ${GEN_DIR}/lib/Support/Triple.cpp
cp ${SRC_DIR}/lib/Target/LLVMBuild.txt ${GEN_DIR}/lib/Target/LLVMBuild.txt

cd ..

