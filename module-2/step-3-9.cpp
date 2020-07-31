#include <iostream>

void swap_value(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_items(int* start, int* end) {   
    while ((end - start)/2)
        swap_value(start++, --end);
}

void rotate(int a[], unsigned size, int shift) {
    if (!size)
        return;

    shift %= size;
    if (!shift)
        return;

    int* start = &a[0];
    int* border = start + shift;
    int* end = start + size;

    swap_items(start, border);
    swap_items(border, end);
    swap_items(start, end);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    rotate(a, sizeof(a)/sizeof(int), 4);
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
      std::cout << a[i] << " ";
    return 0;
}

