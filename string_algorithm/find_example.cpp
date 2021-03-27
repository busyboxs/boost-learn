#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <boost/algorithm/string.hpp>

bool func(char c)
{
    return c == 'o' || c == 'e' || c == 'l';
}

void findTokenExample()
{
    char s1[] = "Hello and Welcome to Boost ";
    char s2[] = "It is very interesting 7873";
    char s3[] = "srtwyuzx  0043A";

    boost::iterator_range<char*> it1 = boost::find_token(s1, func, boost::token_compress_on);
    boost::iterator_range<char*> it2 = boost::find_token(s1, func);
    boost::iterator_range<char*> it3 = boost::find_token(s2, boost::is_digit(), boost::token_compress_on);
    boost::iterator_range<char*> it4 = boost::find_token(s2, boost::is_alpha(), boost::token_compress_on);
    boost::iterator_range<char*> it5 = boost::find_token(s3, boost::is_xdigit(), boost::token_compress_on);

    std::cout << "------------------------------------------------\n";
    std::cout << "With token_compress_on in s1 :   [" << it1 << "]" << std::endl;
    std::cout << "Without token-compress_on in s1 :  [" << it2 << "]" << std::endl << std::endl;
    std::cout << "Identifying the first only digits token in s2 :  [" << it3 << "]" << std::endl;
    std::cout << "Identifying the first only alphabets token in s2 :  [" << it4 << "]" << std::endl << std::endl;
    std::cout << "Identifying the first hexadecimal token in s3:  [" << it5 << "]" << std::endl;
}

int main()
{
    std::cout << "* Find Example *" << std::endl << std::endl;

    std::string str1("abc___cde__dfg");
    std::string str2("abc");

    boost::iterator_range<std::string::iterator> range = boost::find_first(str1, std::string("cde"));
    boost::to_upper(range);
    std::cout << "str1 with upper-cased part matching cde: " << str1 << std::endl;

    char text[] = "hello dolly!";
    boost::iterator_range<char*> crange = boost::find_last(text, "ll");
    std::transform(crange.begin(), crange.end(), crange.begin(), std::bind2nd(std::plus<char>(), 1));
    boost::to_upper(crange);
    std::cout << text << std::endl;

    std::string str3("this is an example of boost. It is useful. It is important.");
    boost::iterator_range<std::string::iterator> second = boost::find_nth(str3, "is", 2);
    boost::to_upper(second);
    std::cout << str3 << std::endl;

    boost::iterator_range<std::string::iterator> head = boost::find_head(str1, 3);
    std::cout << "head(3) of the str1: " << std::string(head.begin(), head.end()) << std::endl;

    head = boost::find_tail(str2, 5);
    std::cout << "tail(5) of the str2: " << std::string(head.begin(), head.end()) << std::endl;

    findTokenExample();

    return 0;
}