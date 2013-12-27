#include <iostream>
#include <cstring>

void reverse1(char *str);
void reverse2(char *str);

int main(int argc, char *argv[])
{
    char str1[] = "hahaya"; //char *p = "hahaya"字符串常量 不可修改
    reverse1(str1);
    std::cout << str1 << std::endl;

    char str2[] = "hahaya";
    reverse2(str2);
    std::cout << str2 << std::endl;

    return 0;
}

void reverse1(char *str)
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

void reverse2(char *str)
{
    if ( 0 == strlen(str) )
        return;

    char *p = str;

    while(*p)   //将p指针移动到字符串的'\0'字符上
        ++p;
    --p;        //将p指针移动到字符'\0'的前一个字符上

    char temp;
    while( str < p )  //移动后p的地址肯定大于q 以此做判断条件
    {
        temp = *str;
        *str = *p;
        *p = temp;

        str++;       //重新移动指针
        p--;
    }
}
