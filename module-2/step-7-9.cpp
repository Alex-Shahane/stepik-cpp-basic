#include <iomanip>
#include <iostream>

void free_matrix(int** m, unsigned rows) {
    for (unsigned i = 0; i != rows; ++i)
        delete [] m[i]; 
    delete [] m;
}

int** create_matrix(unsigned rows, unsigned cols) {
    int** m = new int* [rows];
    for (unsigned i = 0; i != rows; ++i)
        m[i] = new int [cols];
    return m;
} 

void print_matrix(int** m, unsigned rows, unsigned cols) {
    for (unsigned i = 0; i != rows; ++i){
        for (unsigned j = 0; j != cols; ++j)
            std::cout << std::setfill('0') << std::setw(2) << m[i][j] << '\t';
        std::cout << std::endl;
    }
} 

void init_matrix(int** m, unsigned rows, unsigned cols) {
    for (unsigned i = 0; i != rows; ++i){
        for (unsigned j = 0; j != cols; ++j)
            m[i][j] = 10*i + j;
    }
} 

int** transpose(const int* const* m, unsigned rows, unsigned cols) {
    int** mm = create_matrix(cols, rows);
    for (unsigned i = 0; i != rows; ++i) {
        for (unsigned j = 0; j != cols; ++j)
            mm[j][i] = m[i][j];
    }
    return mm;
}

int main() {
    unsigned rows = 2;
    unsigned cols = 4;
    int** m = create_matrix(rows, cols);
    
    init_matrix(m, rows, cols);
    print_matrix(m, rows, cols);

    std::cout << std::endl;

    int** mm = transpose(m, rows, cols);
    print_matrix(mm, cols, rows);

    free_matrix(m, rows);
    free_matrix(mm, cols);
    return 0;
}
