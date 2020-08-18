#include <iostream>
#include <cstdint>
#include "array.hpp"

template <typename T>
void flatten_impl(const T& item, std::ostream& out) {
    out << item << "  ";
}

template <typename T>
void flatten_impl(const Array<T>& array, std::ostream& out) {
    for (size_t i = 0; i < array.size(); ++i) 
        flatten_impl(array[i], out); 
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) {
    flatten_impl(array, out);
    out << std::endl;
}

int main() {
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    Array<Array<int>> arrays(2, ints);
    flatten(arrays, std::cout);

    Array<double> doubles(10, 1.5);
    flatten(doubles, std::cout);

    return 0;
}
