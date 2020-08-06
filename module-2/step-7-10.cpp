#include <cassert>
#include <iomanip>
#include <iostream>

void free_matrix(int** m, unsigned rows) {
    for (unsigned i = 0; i != rows; ++i)
        delete[] m[i];
    delete[] m;
}

int** create_matrix(unsigned rows, unsigned cols) {
    int** m = new int* [rows];
    for (unsigned i = 0; i != rows; ++i)
        m[i] = new int[cols];
    return m;
}

void print_matrix(int** m, unsigned rows, unsigned cols) {
    for (unsigned i = 0; i != rows; ++i) {
        for (unsigned j = 0; j != cols; ++j)
            std::cout << std::setfill('0') << std::setw(2) << m[i][j] << '\t';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void init_matrix(int** m, unsigned rows, unsigned cols) {
    for (unsigned i = 0; i != rows; ++i) {
        for (unsigned j = 0; j != cols; ++j)
            m[i][j] = 10 * i + j;
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min_in_array(int* array, unsigned size) {
    assert(size > 0);
    int min_value = array[0];
    for (unsigned i = 0; i != size; ++i)
        min_value = min(array[i], min_value);
    return min_value;
}

void swap_rows(int** a, int** b) {
    int* t = *a;
    *a = *b;
    *b = t;
}

unsigned min_in_matrix(int* m[], unsigned rows, unsigned cols) {
    assert(rows > 0);
    assert(cols > 0);
    
    unsigned row_number = 0;
    int min_value = min_in_array(m[0], cols);
    for (unsigned i = 0; i != rows; ++i) {
        int new_min = min_in_array(m[i], cols);
        if (min_value > new_min) {
            row_number = i;
            min_value = new_min;
        }
    }
    return row_number;
}

void swap_min(int* m[], unsigned rows, unsigned cols) {
    unsigned row_number = min_in_matrix(m, rows, cols);
    swap_rows(&m[0], &m[row_number]);
}

int main() {
    unsigned rows = 3;
    unsigned cols = 4;
    int** m = create_matrix(rows, cols);

    init_matrix(m, rows, cols);

    m[1][3] = (-1);

    print_matrix(m, rows, cols);

    std::cout << min_in_array(m[1], cols) << std::endl;
    std::cout << min_in_matrix(m, rows, cols) << std::endl;

    swap_min(m, rows, cols);

    print_matrix(m, rows, cols);

    free_matrix(m, rows);

    return 0;
}


