#include <iostream>

void strcat(char* to, const char* from)
{
    while (*to) {
        to++;
    }
    while (*from) {
        *to++ = *from++;
    }
}

int main()
{
    char str1[] = "first";
    const char str2[] = "second";
    strcat(&str1[0], &str2[0]);
    std::cout << str1 << std::endl;
    return 0;
}