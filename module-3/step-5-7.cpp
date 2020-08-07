#include <iostream>

struct Cls {
    Cls(char _c, double _d, int _i)
        : c(_c)
        , d(_d)
        , i(_i) {
    }

    char get_c() {
        return c;
    }

private:
    char c;
    double d;
    int i;
};

char& get_c(Cls& cls) {
    Cls* cls_ptr = &cls;
    char* buf = (char*)cls_ptr;
    return (char&)*(buf + 0);
}

double& get_d(Cls& cls) {
    char* buf = (char*)&cls;
    return (double&)*(buf + 8);
}

int& get_i(Cls& cls) {
    char* buf = (char*)&cls;
    return (int&)*(buf + 16);
}

int main() {
    Cls cls('a', 1.1, 3);

    get_c(cls) = 'c';

    std::cout << cls.get_c() << std::endl;
    std::cout << "=================" << std::endl;

    std::cout << get_c(cls) << std::endl;
    std::cout << get_d(cls) << std::endl;
    std::cout << get_i(cls) << std::endl;
}
