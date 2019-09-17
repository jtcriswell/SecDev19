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
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
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
// Function: getVoidPtrType()
//
// Description:
//  Return a pointer to the void pointer type that belongs to the specified
//  LLVM Context.  In LLVM IR, a void pointer type is a pointer to an 8-bit
//  value (i.e., a "char *" in C).
//
// Inputs:
//  C - A reference to the LLVM Context in which to create or retrieve the
//      void pointer type.
//
// Outputs:
//  None.
//
// Return value:
//  A pointer to the void pointer type is returned.
//
static PointerType *
getVoidPtrType (LLVMContext & C) {
  //
  // Create an integer type that is 8-bits in size and then create a pointer
  // type that pointers to this integer type.
  //
  return (PointerType::getUnqual(IntegerType::get(C, 8)));
}

//
// Function: createRuntimeCheckFunc()
//
// Description:
//  This function creates the declaration of the checkMemory function that
//  checks the pointer dereferenced in a load or store instruction at run-time.
//  If the checkMemory function is already declared or defined within the
//  specified Module, a pointer to it is returned.
//
// Inputs:
//  M - A reference to the Module to which the checkMemory function declaration
//      should be added.
//
// Outputs:
//  M - The Module modified (if necessary) to contain a checkMemory function
//      declaration.
//
// Return value:
//  A pointer to the checkMemory function is returned.
//
static Function *
createRuntimeCheckFunc (Module & M) {
  //
  // Create the types needed for the declaration.
  //
  Type * VoidType = Type::getVoidTy(M.getContext());
  Type * VoidPtrType = getVoidPtrType(M.getContext());
  FunctionType * FuncType = FunctionType::get(VoidType,
                                              ArrayRef<Type *>(VoidPtrType),
                                              false);

  //
  // Create the run-time check function.
  //
  return cast<Function>(M.getOrInsertFunction ("checkMemory", FuncType));
}

//
// Method: visitLoadInst()
//
// Description:
//  Add a call to a library function before every load instruction.  This
//  method is called by the InstVisitor class whenever it encounters a load
//  instruction.
//
// Inputs:
//  LI - A pointer to the load instruction to transform.
//
// Outputs:
//  None.
//
// Return value:
//  None
//
void
SecDev::visitLoadInst (LoadInst * LI) {
  //
  // Retrieve the pointer operand from the load instruction.
  //
  Value * Pointer = LI->getPointerOperand();

  //
  // Cast the pointer argument of the load instruction to our void pointer
  // type.
  //
  LLVMContext & C = LI->getContext();
  Pointer = new BitCastInst(Pointer, getVoidPtrType(C), Pointer->getName(), LI);

  //
  // Insert a call instruction to the check memory function before the load
  // instruction.
  //
  CallInst::Create(checkMemory, ArrayRef<Value*>(Pointer), "", LI);

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
//  SI - A pointer to the store instruction to transform.
//
// Outputs:
//  None.
//
// Return value:
//  None
//
void
SecDev::visitStoreInst (StoreInst * SI) {
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
//  CI - A pointer to the call instruction to transform.
//
// Outputs:
//  None.
//
// Return value:
//  None
//
void
SecDev::visitCallInst (CallInst * CI) {
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
  // Add a declaration of the run-time check functions.
  //
  checkMemory = createRuntimeCheckFunc(M);

  //
  // Scan all of the instructions within the module to determine if we need to
  // transform them.  If so, call the appropriate visit method to transform
  // the instruction.
  //
  for (Module::iterator fi = M.begin(); fi != M.end(); ++fi) {
    for (Function::iterator bi = fi->begin(); bi != fi->end(); ++bi) {
      for (BasicBlock::iterator it = bi->begin(); it != bi->end(); ++it) {
        Instruction * I = &*it;

        //
        // If this is a load instruction, instrument it with a call to the
        // function that checks the pointer used in the load.
        //
        if (LoadInst * LI = dyn_cast<LoadInst>(I)) {
          visitLoadInst(LI);
        }

        //
        // If this is a store instruction, instrument it with a call to the
        // function that checks the pointer used in the store.
        //
        // TODO: Write this code.
        //
      }
    }
  }

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
