// RUN: %clang %s -emit-llvm %O0opt -c -g -o %t.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --asm-external-calls=true --external-calls=all --exit-on-error --output-dir=%t.klee-out %t.bc > %t.output.log 2>&1

#include <assert.h>

int main() {

    int x;
    klee_make_symbolic(&x, sizeof(x), "x");
    if (x == 239) {
        __asm__ ("neg %0" : "+r"(x));
        assert(x == -239);
    }

    int y = x;
    __asm__ ("add $5, %0" : "+r"(x));
    __asm__ ("add $0, %0" : "+r"(y));
    assert(x == y + 5);

    return 0;
}
