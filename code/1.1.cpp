#include <iostream>
#include <string>

bool isUniqueChar1(const std::string &str);
bool isUniqueChar2(const std::string &str);
bool isUniqueChar3(const std::string &str);

int main(int argc, char *argv[])
{
    std::string str1 = "just one.";
    if ( isUniqueChar1(str1) )
    {
        std::cout << str1 << " has all unique characters." << std::endl;
    }
    else
    {
        std::cout << str1 << " hasn't all unique characters." << std::endl;
    }

    std::string str2 = "I am hahaya.";
    if ( isUniqueChar2(str2) )
    {
        std::cout << str2 << " has all unique characters." << std::endl;
    }
    else
    {
        std::cout << str2 << " hasn't all unique characters." << std::endl;
    }

    std::string str3 = "abcdefg";
    if ( isUniqueChar3(str3) )
    {
        std::cout << str3 << " has all unique characters." << std::endl;
    }
    else
    {
        std::cout << str3 << " hasn't all unique characters." << std::endl;
    }

    return 0;
}

//当string中的所有字符全为ASCII时(解法一)
bool isUniqueChar1(const std::string &str)
{
    bool char_set[256];
    memset( char_set, 0, sizeof(char_set) ); //必须将所有位设置成false

    for ( unsigned int i = 0; i < str.length(); ++i )
    {
        int value = (int)str.at(i);
        if ( char_set[value] )
        {
            return false;
        }
        char_set[value] = true;
    }
    return true;
}

//当string中的所有字符全为ASCII时(解法二)
bool isUniqueChar2(const std::string &str)
{
    int checker[8];
    memset(checker, 0, sizeof(checker)); //必须将所有位设置成0

    for ( unsigned int i = 0; i < str.length(); ++i )
    {
        int value = (int)str.at(i);
        int row = value/32;
        int colunm = value%32;
        if ( checker[row] & (1<<colunm) )
        {
            return false;
        }
        checker[row] |= (1<<colunm);
    }
    return true;
}

//当string中的所有字符全为字母时(只考虑'a' - 'z')
bool isUniqueChar3(const std::string &str)
{
    int checker = 0;    //必须将所有位设置成0

    for ( unsigned int i = 0; i < str.length(); ++i )
    {
        int value = (int)(str.at(i) - 'a' );
        if ( checker & (1<<value) )
        {
            return false;
        }
        checker |= (1<<value);
    }
    return true;
}
