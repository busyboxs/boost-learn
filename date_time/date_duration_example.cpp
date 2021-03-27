#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

int main()
{
    date_duration two_days(2);
    std::cout << two_days << std::endl;

    days dd1(neg_infin);
    days dd2(pos_infin);
    days dd3(not_a_date_time);
    days dd4(max_date_time);
    days dd5(min_date_time);
    days dd6(1);

    std::cout << "The days of two_days is: " << two_days.days() << std::endl;
    std::cout << std::boolalpha;
    std::cout << "two_days is negative? " << two_days.is_negative() << std::endl;
    std::cout << "two_days is special? " << two_days.is_special() << std::endl;
}

