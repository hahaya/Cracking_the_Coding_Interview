#include <iostream>
#include <string>
#include <cstring>

void removeDuplicate1(char *str);
std::string removeDuplicate2(std::string &str);

void removeDuplicate3(char *str);
std::string removeDuplicate4(std::string &str);

void removeDuplicate5(char *str);
std::string removeDuplicate6(std::string &str);

void removeDuplicate7(char *str);
std::string removeDuplicate8(std::string &str);

int main(int argc, char *argv[])
{
    char str1[] = "hahaya";
    removeDuplicate1(str1);
    std::cout << str1 << std::endl;

    std::string str2 = "hahaya";
    std::cout << removeDuplicate2(str2) << std::endl;

    char str3[] = "hahaya";
    removeDuplicate3(str3);
    std::cout << str3 << std::endl;

    std::string str4 = "hahaya";
    std::cout << removeDuplicate4(str4) << std::endl;

    char str5[] = "hahaya";
    removeDuplicate5(str5);
    std::cout << str5 << std::endl;

    std::string str6 = "hahaya";
    std::cout << removeDuplicate6(str6) << std::endl;


    char str7[] = "hahaya";
    removeDuplicate7(str7);
    std::cout << str7 << std::endl;

    std::string str8 = "hahaya";
    std::cout << removeDuplicate8(str8) << std::endl;


    char str10[] = "";
    removeDuplicate1(str10);
    std::cout << str10 << std::endl;

    char str11[] = "aaa";
    removeDuplicate3(str11);
    std::cout << str11 << std::endl;

    std::string str12 = "aabb";
    std::cout << removeDuplicate2(str12) << std::endl;

    std::string str13 = "ababab";
    std::cout << removeDuplicate4(str13) << std::endl;

    return 0;
}

void removeDuplicate1(char *str)
{
    int len = strlen(str);

    if ( len < 2 )
        return;

    int index = 0;  //�ڵ�ǰ�ַ����Ͻ����Ƴ����� ��¼�Ƴ����ַ�������
    for ( int i = 0; i < len; ++i ) //�ӵ�ǰi����һλ��ʼƥ��
    {
        if ( str[i] != '\0' )   //ÿ�Ƚ�һ���ַ����ܻ�ı��ַ��� ���Դ�ʱ��'\0'���ܲ����ǽ�β
        {
            str[index++] = str[i];
            for ( int j = i + 1; j < len; j++ )
            {
                if ( str[i] == str[j] )
                    str[j] = '\0';  //���ַ����е�ǰ�ַ�������ֵ��ظ��ַ���Ϊ'\0'
            }
        }
    }
    str[index] = '\0';  //C����ַ�����β
}

std::string removeDuplicate2(std::string &str)
{
    int len = str.length();
    if ( len < 2 )
        return str;

    std::string temp = "";
    for ( int i = 0; i < len; ++i )
    {
        if ( str[i] != '\0' )
        {
            temp += str[i];
            for ( int j = i + 1; j < len; ++j )
            {
                if ( str[i] == str[j] )
                    str[j] = '\0';
            }
        }
    }

    return temp;
}

void removeDuplicate3(char *str)
{
    int len = strlen(str);
    if ( len < 2 )
        return;

    bool checker[256];
    memset(checker, 0, sizeof(checker));    //��ʼ������Ϊfalse

    int index = 0;
    for ( int i = 0; i < len; ++i )
    {
        if ( !checker[str[i]] ) //ɨ�������ַ��� ����ƴ���ַ��� ֻ��û���ظ����ַ������ַ�����
        {
            str[index++] = str[i];
            checker[str[i]] = true;
        }
    }
    str[index] = '\0'; //C����ַ�����β
}

std::string removeDuplicate4(std::string &str)
{
    int len = str.length();
    if ( len < 2 )
        return str;

    bool checker[256];
    memset(checker, 0, sizeof(checker));  //��ʼ������Ϊfalse

    std::string temp = "";

    for ( int i = 0; i < len; ++i )
    {
        if ( !checker[str[i]] )
        {
            temp += str[i];
            checker[str[i]] = true;
        }
    }
    return temp;
}

void removeDuplicate5(char *str)
{
    int len = strlen(str);
    if ( len < 2 )
        return;

    int checker[8];
    memset(checker, 0, sizeof(checker)); //��ʼ������Ϊfalse

    int index = 0;
    for ( int i = 0; i < len; ++i )
    {
        int value = (int)(str[i]);
        int row = value/32;
        int column = value%32;
        if ( !(checker[row] & (1<<column)) )    //ɨ�������ַ��� ����ƴ���ַ��� ֻ��û���ظ����ַ������ַ�����
        {
            str[index++] = str[i];
            checker[row] |= (1<<column);
        }
    }
    str[index] = '\0';  //C����ַ�����β
}

std::string removeDuplicate6(std::string &str)
{
    int len = str.length();
    if ( len < 2 )
        return str;

    int checker[8];
    memset(checker, 0, sizeof(checker));

    std::string temp = "";
    for ( int i = 0; i < len; ++i )
    {
        int value = (int)(str[i]);
        int row = value/32;
        int column = value%32;
        if ( !(checker[row] & (1<<column)) )
        {
            temp += str[i];
            checker[row] |= (1<<column);
        }
    }
    return temp;
}

void removeDuplicate7(char *str)
{
    int len = strlen(str);
    if ( len < 2 )
        return;

    int checker = 0;
    int index = 0;
    for( int i = 0; i < len; ++i )
    {
        int value = (int)(str[i] - 'a');
        if ( !(checker & (1<<value)) )  //ɨ�������ַ��� ����ƴ���ַ��� ֻ��û���ظ����ַ������ַ�����
        {
            str[index++] = str[i];
            checker |= (1<<value);
        }
    }
    str[index] = '\0';  //C����ַ�����β
}

std::string removeDuplicate8(std::string &str)
{
    int len = str.length();
    if ( len < 2 )
        return str;

    int checker = 0;
    std::string temp = "";
    for ( int i = 0; i < len; ++i )
    {
        int value = (int)(str[i] - 'a');
        if ( !(checker & (1<<value)) )
        {
            temp += str[i];
            checker |= (1<<value);
        }
    }
    return temp;
}
