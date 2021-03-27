#include <string>
#include <iostream>
#include <functional>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/classification.hpp>

int main()
{
    std::cout << "* Predicate Example *" << std::endl << std::endl;

    std::string str1("123xxx321");
    std::string str2("abc");

    std::cout << std::boolalpha;
    std::cout << R"(str1 starts with "123": )" << boost::starts_with(str1, std::string("123")) << std::endl;

    std::cout << R"(str1 ends with "123": )" << boost::ends_with(str1, std::string("123")) << std::endl;

    std::cout << R"(str1 contains "xxx": )" << boost::contains(str1, std::string("xxx")) << std::endl;

    std::cout << R"(str2 equals "abc")" << boost::equal(str2, std::string("abc")) << std::endl;

    std::cout << R"("abc" is lexicographically less than "abd": )" << boost::lexicographical_compare(std::string("abc"), std::string("abd")) << std::endl;

    if (boost::all(";.,", boost::is_punct()))
    {
        std::cout << R"(";.," are all punctuation characters)" << std::endl;
    }

    if (boost::all("abcxxx", boost::is_any_of("xabc") && !boost::is_space()))
    {
        std::cout << true << std::endl;
    }

    return 0;
}