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

char* getline() {
    char s;
    int i = 0;
    unsigned size = 5;
    char* input_str = new char [size];
    
    while (std::cin.get(s) && s != '\n') {
        if (i == size) {
            unsigned new_size = size + 10; 
            input_str = resize(input_str, size, new_size);
            size = new_size;
        }
        input_str[i++] = s;
    }
       
    input_str[i] = '\0';
    
    return input_str;
}

int main() {
    char* str = getline();
    std::cout << str << std::endl;
    delete [] str;
    return 0;
 }