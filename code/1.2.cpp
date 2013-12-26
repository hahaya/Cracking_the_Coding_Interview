#include <iostream>
#include <cstring>

void reverse(char *str);

int main(int argc, char *argv[])
{
    char p[] = "hahaya"; //char *p = "hahaya"字符串常量 不可修改
    reverse(p);
    std::cout << p << std::endl;

    return 0;
}

void reverse(char *str)
{
    char temp;
    int len = strlen(str);
    for ( int i = 0; i < len/2; ++i )
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
