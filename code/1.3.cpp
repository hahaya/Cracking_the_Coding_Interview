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

    int index = 0;  //在当前字符串上进行移除操作 记录移除后字符串长度
    for ( int i = 0; i < len; ++i ) //从当前i的下一位开始匹配
    {
        if ( str[i] != '\0' )   //每比较一次字符可能会改变字符串 所以此时的'\0'可能并不是结尾
        {
            str[index++] = str[i];
            for ( int j = i + 1; j < len; j++ )
            {
                if ( str[i] == str[j] )
                    str[j] = '\0';  //将字符串中当前字符后面出现的重复字符置为'\0'
            }
        }
    }
    str[index] = '\0';  //C风格字符串结尾
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
    memset(checker, 0, sizeof(checker));    //初始化数组为false

    int index = 0;
    for ( int i = 0; i < len; ++i )
    {
        if ( !checker[str[i]] ) //扫描整个字符串 重新拼接字符串 只将没有重复的字符放入字符串中
        {
            str[index++] = str[i];
            checker[str[i]] = true;
        }
    }
    str[index] = '\0'; //C风格字符串结尾
}

std::string removeDuplicate4(std::string &str)
{
    int len = str.length();
    if ( len < 2 )
        return str;

    bool checker[256];
    memset(checker, 0, sizeof(checker));  //初始化数组为false

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
    memset(checker, 0, sizeof(checker)); //初始化数组为false

    int index = 0;
    for ( int i = 0; i < len; ++i )
    {
        int value = (int)(str[i]);
        int row = value/32;
        int column = value%32;
        if ( !(checker[row] & (1<<column)) )    //扫描整个字符串 重新拼接字符串 只将没有重复的字符放入字符串中
        {
            str[index++] = str[i];
            checker[row] |= (1<<column);
        }
    }
    str[index] = '\0';  //C风格字符串结尾
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
        if ( !(checker & (1<<value)) )  //扫描整个字符串 重新拼接字符串 只将没有重复的字符放入字符串中
        {
            str[index++] = str[i];
            checker |= (1<<value);
        }
    }
    str[index] = '\0';  //C风格字符串结尾
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
