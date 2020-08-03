#include <iostream>

unsigned strlen(const char* str) {
    int length = 0;
    while (*str++) 
        ++length;
    return length;
}

bool strcmp(const char* text, const char* pattern) {
    if (strlen(pattern) > strlen(text))
        return false;

    while (*text && *pattern) {
        if (*text++ != *pattern++) 
            return false;
    }
    return true;
}

const char* strstr_impl(const char* text, const char* pattern) {
    if (!*pattern)
        return text;

    while (*text) {
        if (strcmp(text, pattern))
            return text;

        ++text;
    }
    return nullptr;
}

int strstr(const char* text, const char* pattern) {
    const char* pointer = strstr_impl(text, pattern);
    if (!pointer)
        return -1;  
        
    return pointer - text;
}

int main() {
    char text[] = "a";
    char pattern[] = "a";
    std::cout << strstr(text, pattern) << std::endl;
    return 0;
}
