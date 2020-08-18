#include "array.hpp"

int main() {
    Array<int> arr(5, 0);
    Array<int> arr2(5, 1);
    arr.swap(arr2);
    return 0;
}
