#include <cstddef>

template<typename T, typename V>
struct SameType {
    static const bool value = false;
};

template<typename T>
struct SameType<T, T> {
    static const bool value = true;
};



template<typename T, size_t S>
size_t array_size(T (&array)[S]) {
    return S;
}