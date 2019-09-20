#include <stdio.h>

int foo = 0;

int get_foo() {
    return foo;
}

void set_foo(int new_foo) {
    foo = new_foo;
}

int main() {
    printf("foo is %d\n", get_foo());
    printf("Setting foo\n");
    set_foo(42);
    printf("foo is %d\n", get_foo());

    return 0;
}
