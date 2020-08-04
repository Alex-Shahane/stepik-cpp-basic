#include <iostream>

unsigned min(unsigned a, unsigned b) {
    return (b < a) ? b : a;
}

char* resize(const char* str, unsigned size, unsigned new_size) {
	char* new_str = new char [new_size];
    size = min(size, new_size);

    while (size--)
	    new_str[size] = str[size];

	delete [] str;
	return new_str;
}

void print(const char* str, unsigned size) {
    for (int i = 0; i < size; ++i)
        std::cout << (str[i] ? str[i] : '0');

    std::cout << std::endl;
}

int main() {
    const unsigned size = 5;
    const char* str = new char [size]{'a', 'b', 'c', 'd', 'e'};
    print(str, size);
    
    unsigned new_size = 3;
    char* new_str = resize(str, size, new_size);
    print(new_str, new_size);

    delete [] new_str;
    return 0;
}