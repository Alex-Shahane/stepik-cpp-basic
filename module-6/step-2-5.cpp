#include <cstddef>
#include <iostream>

template <typename T, typename U>
void copy_n(T* target, U* source, size_t copy_size) {
    for(size_t i = 0; i != copy_size; ++i)
        target[i] = (T)source[i];
}

int main() {
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4);
    return 0;
}
