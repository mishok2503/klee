//===-- KCallable.cpp -------------------------------------------*- C++ -*-===//
//
//                     The KLEE Symbolic Virtual Machine
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "klee/Module/KCallable.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/LLVMContext.h"

using namespace llvm;
using namespace klee;

KCallable::KCallable(Function *func) : func(func), isFunc(true) {}
KCallable::KCallable(InlineAsm *asmValue) : asmValue(asmValue), isFunc(false) {}

StringRef KCallable::getName() const {
    return isFunc ? func->getName() : "InlineAssembly";
}

Function* KCallable::getFunction() {
    return isFunc ? func : nullptr;
}

InlineAsm* KCallable::getInlineAsm() {
    return isFunc ? nullptr : asmValue;
}

LLVMContext &KCallable::getContext() const {
    return isFunc ? func->getContext() : asmValue->getContext();
}

PointerType* KCallable::getType() const {
    return isFunc ? func->getType() : asmValue->getType();
}

bool KCallable::isFunction() const {
    return isFunc;
}