//===- SecDev.cpp - Skeleton code for LLVM Tutorial -----------------------===//
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

#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/Scalar/SecDev.h"

using namespace llvm;

#define DEBUG_TYPE "secdev"

//
// Method: runOnModule()
//
// Description:
//  This method is called by the PassManager when this pass needs to transform
//  a module.  This pass will insert calls to a library function for every
//  load and store instruction and every branch.
//
// Inputs:
//  M - A reference to the Module to transform.
//
// Outputs:
//  M - The transformed Module.
//
// Return value:
//  true  - The module has been modified.
//  false - The module has not been modified.
//
bool
SecDev::runOnModule (Module & M) {
   // Assume that we have modified the module
  return true;
}

// Pass identifier variable (used by PassManager)
char SecDev::ID = 0;

// Utility method to create a SecDev pass object
namespace llvm {
ModulePass *createSecDevPass() {
  return new SecDev();
}
}

static RegisterPass<SecDev> X ("secdev", "SecDev Tutorial Pass", false, false);
