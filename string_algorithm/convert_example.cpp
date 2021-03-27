#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <boost/algorithm/string/case_conv.hpp>

int main()
{
    std::cout << "* Case Conversion Example *" << std::endl << std::endl;

    std::string str1("AbCdEfG");
    std::vector<char> vec1(str1.begin(), str1.end());

    std::cout << "lower-cased copy of vec1: ";
    boost::to_lower_copy(std::ostream_iterator<char>(std::cout), vec1);
    std::cout << std::endl;

    std::cout << "upper-cased copy of str1:" << boost::to_upper_copy(str1) << std::endl;

    boost::to_lower(str1);
    std::cout << "lower-cased str1: " << str1 << std::endl;

    boost::to_upper(str1);
    std::cout << "then to upper case: " << str1 << std::endl;

    std::cout << std::endl;

    return 0;
}