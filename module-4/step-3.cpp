#include <iostream>

class A {
public:
    A() {
        std::cout << "ctor A" << std::endl;
    }

    virtual ~A() {
        std::cout << "dtor A" << std::endl;
    }
};

class B : public A {
public:
    B() {
        std::cout << "ctor B" << std::endl;
    }

    ~B() {
        std::cout << "dtor B" << std::endl;
    }
};

class C : public B {
public:
    C() {
        std::cout << "ctor C" << std::endl;
    }

    ~C() {
        std::cout << "dtor C" << std::endl;
    }
};

class X : public C {
public:
    X() {
        std::cout << "ctor XX" << std::endl;
    }

    ~X() {
        std::cout << "dtor XX" << std::endl;
    }
};

class D {
public:
    D() {
        std::cout << "ctor D" << std::endl;
    }

    ~D() {
        std::cout << "dtor D" << std::endl;
    }
};

class E {
public:
    E() {
        std::cout << "ctor E" << std::endl;
    }

    ~E() {
        std::cout << "dtor E" << std::endl;
    }
};

class F : public X {
public:
    F() 
        : e()
        , d() {
        std::cout << "ctor F" << std::endl;
    }

    ~F() {
        std::cout << "dtor F" << std::endl;
    }

private:
    D d;
    E e;
};



int main() {
    std::cout << "----------------" << std::endl;

    {
        std::cout << "start of block" << std::endl;
        F f;
        std::cout << "end of block" << std::endl;
    }

    {
        std::cout << "start of block" << std::endl;
        A* a = new F;
        delete a;
        std::cout << "end of block" << std::endl;
    }

    std::cout << "----------------" << std::endl;
}
