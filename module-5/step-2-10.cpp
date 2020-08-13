#include <iostream>
#include <cstring> // strlen, strcpy

struct String {
    struct SubString {
        SubString(size_t sub_offset, const char* str)
            : sub_offset(sub_offset)
            , sub_str(str) {
        }
       
        String operator[](size_t j) {
            String new_string(j - sub_offset, '\0');
            strncpy(new_string.str, sub_str + sub_offset, new_string.size);
            return new_string;
        }

        size_t sub_offset;
        const char* sub_str;
    };

    String(const char* str = "") 
        : size(strlen(str))
        , str(new char [size + 1]) {
        strcpy(this->str, str);
    }

    String(size_t n, char c) 
        : size(n)
        , str(new char [size + 1]) {
        memset(str, c, size);
        *(str + size) = '\0';
    }

    ~String() {
        delete [] str;
        str = nullptr;
    }

    SubString operator[](size_t i) const {
        return SubString(i, str);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    size_t size;
    char* str;
};

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.str;
    return os;
}

int main() {
    const String hello("hello");
    
    const String hell = hello[0][4]; 
    std::cout << hell << std::endl;

    const String ell = hello[1][4]; 
    std::cout << ell << std::endl;

    return 0;
}
