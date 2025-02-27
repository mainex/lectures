#include <iostream>

int remaining = 2;

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }
    Foo(const Foo &other) {
        std::cout << "Foo(const Foo&) " << this << "\n";
        if (!--remaining) {
            throw 0;
        }
    }
    Foo &operator=(const Foo&) = delete;
    ~Foo() {
        std::cout << "~Foo " << this << "\n";
    }
};

void func(Foo a, Foo b, Foo c) {
    std::cout << "func\n";
}

int main() {
    Foo a, b, c;
    try {
        std::cout << "before foo\n";
        func(a, b, c);
        std::cout << "after foo\n";
    } catch (...) {
        std::cout << "exception\n";
    }
}
