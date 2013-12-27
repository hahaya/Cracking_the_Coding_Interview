#include <iostream>
#include <cstring>

void reverse1(char *str);
void reverse2(char *str);

int main(int argc, char *argv[])
{
    char str1[] = "hahaya"; //char *p = "hahaya"�ַ������� �����޸�
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

    while(*p)   //��pָ���ƶ����ַ�����'\0'�ַ���
        ++p;
    --p;        //��pָ���ƶ����ַ�'\0'��ǰһ���ַ���

    char temp;
    while( str < p )  //�ƶ���p�ĵ�ַ�϶�����q �Դ����ж�����
    {
        temp = *str;
        *str = *p;
        *p = temp;

        str++;       //�����ƶ�ָ��
        p--;
    }
}
