#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <algorithm> // std::swap

struct String {
    String(const char* str = "") 
        : size(strlen(str))
        , str(new char [size + 1]) {
        strcpy(this->str, str);
    }

    String(size_t n, char c) 
        : size(n)
        , str(new char [size + 1]) {
        memset(str, c, size);
    }

    ~String() {
        delete [] str;
        str = nullptr;
    }

    void swap(String& other) {
        std::swap(this->str, other.str);
        std::swap(this->size, other.size);
    }

    void append(String& other) {
        String new_string(size + other.size, '\0');

        strcpy(new_string.str, str);
        strcpy(new_string.str + size, other.str);
        
        swap(new_string);
    }

    size_t size;
    char* str;
};

int main() {
    return 0;
}
