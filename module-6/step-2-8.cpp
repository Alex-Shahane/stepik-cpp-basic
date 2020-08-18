#include <cstddef>
#include <iostream>
#include "array.hpp"

bool less(int a, int b) {
    return a < b;
}

struct Greater {
    bool operator()(int a, int b) const {
        return b < a;
    }
};

template<class T, class Comp>
T minimum(const Array<T>& array, Comp comp) {
    T min = array[0];
    for (size_t i = 1; i != array.size(); ++i)
        min = comp(array[i], min) ? array[i] : min;
        
    return min;
}

template<class T>
void print_array(const Array<T>& array) {
    for (int i = 0; i < array.size(); ++i)
        std::cout << array[i] << "\t";
    std::cout << std::endl;
}

int main() {
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;

    print_array(ints);

    int min = minimum(ints, less); 
    
    print_array(ints);

    int max = minimum(ints, Greater());

    min = minimum(ints, [](int a, int b) -> bool {
        return a < b;
    });

    return 0;
}
