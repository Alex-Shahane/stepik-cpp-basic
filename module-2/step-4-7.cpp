#include <iostream>

unsigned strlen(const char* str) {
    int length = 0;
    while (*str++) 
        ++length;
    return length;
}

void strcat(char* to, const char* from) {
    to += strlen(to);
    while ((*to++ = *from++));
}

int main() {
    char str1[13] = "first";
    const char str2[] = "second";
    strcat(str1, str2);
    std::cout << str1 << std::endl;
    return 0;
}
