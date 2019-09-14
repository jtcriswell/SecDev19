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

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/Scalar/SecDev.h"

using namespace llvm;

#define DEBUG_TYPE "secdev"

//
// Create statistics that the opt and clang tools can report
//
STATISTIC(NumLoads,  "Number of load instructions instrumented");
STATISTIC(NumStores, "Number of store instructions instrumented");
STATISTIC(NumCalls,  "Number of call instructions instrumented");

//
// Method: visitLoadInst()
//
// Description:
//  Add a call to a library function before every load instruction.  This
//  method is called by the InstVisitor class whenever it encounters a load
//  instruction.
//
// Inputs:
//  LI - A reference to the load instruction to transform.
//
// Outputs:
//  None.
//
// Return value:
//  None
//
void
SecDev::visitLoadInst (LoadInst & LI) {
  //
  // Increment the count of load instructions that have been instrumented.
  //
  ++NumLoads;
  return;
}

//
// Method: visitStoreInst()
//
// Description:
//  Add a call to a library function before every store instruction.  This
//  method is called by the InstVisitor class whenever it encounters a store
//  instruction.
//
// Inputs:
//  SI - A reference to the store instruction to transform.
//
// Outputs:
//  None.
//
// Return value:
//  None
//
void
SecDev::visitStoreInst (StoreInst & SI) {
  //
  // Increment the count of store instructions that have been instrumented.
  //
  ++NumStores;
  return;
}

//
// Method: visitCallInst()
//
// Description:
//  Add a call to a library function before every indirect call instruction.
//  This method is called by the InstVisitor class whenever it encounters a
//  call instruction.
//
// Inputs:
//  CI - A reference to the call instruction to transform.
//
// Outputs:
//  None.
//
// Return value:
//  None
//

void
SecDev::visitCallInst (CallInst & CI) {
  //
  // Increment the count of call instructions that have been instrumented.
  //
  ++NumCalls;
  return;
}

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
  //
  // Scan all of the instructions within the module to determine if we need to
  // transform them.  If so, call the appropriate visit method to transform
  // the instruction.
  //
  visit(M);

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
