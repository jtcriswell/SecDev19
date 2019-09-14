//===- SecDev.h - Skeleton code for LLVM Tutorial ---------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides skeleton code for a transformation that adds calls to
// every memory access operation and every branch.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TRANSFORMS_SCALAR_SECDEV_H
#define LLVM_TRANSFORMS_SCALAR_SECDEV_H

#include "llvm/IR/InstVisitor.h"
#include "llvm/IR/PassManager.h"

namespace llvm {

  struct SecDev : public ModulePass, InstVisitor<SecDev> {
    // Pass identifier variable
    static char ID;
    SecDev() : ModulePass(ID) {}

    // Module public methods
    bool runOnModule (Module & M);

    // Methods for transforming different instructions
    void visitLoadInst (LoadInst & LI);
    void visitStoreInst (StoreInst & SI);
    void visitCallInst (CallInst & CI);
  };

  ModulePass * createSecDevPass();
} // end namespace llvm

#endif // LLVM_TRANSFORMS_SCALAR_ADCE_H
