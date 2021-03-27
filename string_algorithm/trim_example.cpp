#include <string>
#include <iostream>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/classification.hpp>

int main()
{
    std::cout << "* Trim Example *" << std::endl << std::endl;

    std::string str1("     1x x x x1     ");
    std::string str2("<>trim<>");
    std::string str3("123abs123");

    std::cout << "trim_left copy of str1: [" << boost::trim_left_copy(str1) << "]" << std::endl;
    std::cout << "trim_left copy of str2 (space = '<>'): [" << boost::trim_left_copy_if(str2, boost::is_any_of("<>")) << "]" << std::endl;

    std::cout << "trim_right copy of str1: [" << boost::trim_right_copy(str1) << "]" << std::endl;
    std::cout << "trim_right copy of str2 (space = '<>'): [" << boost::trim_right_copy_if(str2, boost::is_any_of("<>")) << "]" << std::endl;

    std::cout << "trimmed copy of str1: [" << boost::trim_copy(str1) << "]" << std::endl;
    std::cout << "trimmed copy of str4 (space = '<>'): [" << boost::trim_copy_if(str2, boost::is_any_of("<>")) << "]" << std::endl;
    std::cout << "trimmed copy of str5 (space = digit): [" << boost::trim_copy_if(str3, boost::is_digit()) << "]" << std::endl;

    str1 = "     1x x x x1     ";
    boost::trim_left(str1);
    std::cout << "trim_left on str1: [" << str1 << "]" << std::endl;

    str2 = "<>trim<>";
    boost::trim_left_if(str2, boost::is_any_of("<>"));
    std::cout << "trim_left of str2 (space = '<>'): [" << str2 << "]" << std::endl;
    
    str1 = "     1x x x x1     ";
    boost::trim_right(str1);
    std::cout << "trim_right on str1: [" << str1 << "]" << std::endl;

    str2 = "<>trim<>";
    boost::trim_right_if(str2, boost::is_any_of("<>"));
    std::cout << "trim_right of str2 (space = '<>'): [" << str2 << "]" << std::endl;

    str1 = "     1x x x x1     ";
    boost::trim(str1);
    std::cout << "trim on str1: [" << str1 << "]" << std::endl;

    str2 = "<>trim<>";
    boost::trim_if(str2, boost::is_any_of("<>"));
    std::cout << "trim of str2 (space = '<>'): [" << str2 << "]" << std::endl;
    
    return 0;
}