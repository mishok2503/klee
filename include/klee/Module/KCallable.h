//===-- KCallable.h ---------------------------------------------*- C++ -*-===//
//
//                     The KLEE Symbolic Virtual Machine
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef KLEE_KCALLABLE_H
#define KLEE_KCALLABLE_H

namespace llvm {
  class Function;
  class InlineAsm;
  class LLVMContext;
  class StringRef;
  class PointerType;
}

namespace klee {
  class KCallable {
  private:
    union {
      llvm::Function* func;
      llvm::InlineAsm* asmValue;
    };
    bool isFunc;
  public:
    KCallable(llvm::Function*);
    KCallable(llvm::InlineAsm*);
  
    llvm::Function* getFunction();
    llvm::InlineAsm* getInlineAsm();

    llvm::PointerType* getType() const ;

    llvm::StringRef getName() const;
    llvm::LLVMContext &getContext() const;

    bool isFunction() const;

  };
}

#endif /* KLEE_KCALLABLE_H */