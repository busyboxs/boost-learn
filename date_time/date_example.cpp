#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <vector>

using namespace boost::gregorian;

int main()
{
    // construction
    date d(2021, Mar, 14);
    std::cout << d << std::endl;  // 2021-Mar-14

    date d1(d);
    std::cout << d1 << std::endl;  // 2021-Mar-14

    date d_neg_inf(neg_infin);
    std::cout << d_neg_inf << std::endl;  // -infinity
    date d_pos_inf(pos_infin);
    std::cout << d_pos_inf << std::endl;  // +infinity
    date d_not_a_date(not_a_date_time);
    std::cout << d_not_a_date << std::endl;  // not-a-date-time
    date d_max(max_date_time);
    std::cout << d_max << std::endl;  // 9999-Dec-31
    date d_min(min_date_time);
    std::cout << d_min << std::endl;  // 1400-Jan-01

    date d_default;
    std::cout << d_default << std::endl;  // not-a-date-time

    // Construct from string
    std::string ds("2021/3/14");
    date dfs(from_string(ds));
    std::cout << dfs << std::endl;  // 2021-Mar-14

    std::string ds2("2021-3-14");
    date dfs2(from_string(ds2));
    std::cout << dfs2 << std::endl;  // 2021-Mar-14

    std::string ds_undel("20210314");
    date d_undel(from_undelimited_string(ds_undel));
    std::cout << d_undel << std::endl;  // 2021-Mar-14

    // construct from clock
    date d_local_clock(day_clock::local_day());
    std::cout << d_local_clock << std::endl;  // 2021-Mar-14

    date d_utc_clock(day_clock::universal_day());
    std::cout << d_utc_clock << std::endl;  // 2021-Mar-14

    date dddd(from_string(std::string("2021-3-14")));
    std::cout << dddd << std::endl;

    // Accessors
    date today(day_clock::local_day());
    greg_year year = today.year();
    greg_month month = today.month();
    greg_day day = today.day();
    std::cout << "year: "<< year << ", month: " << month << ", day: " << day << std::endl;  // year: 2021, month: Mar, day: 14

    date::ymd_type ymd = today.year_month_day();
    std::cout << "year: "<< ymd.year << ", month: " << ymd.month << ", day: " << ymd.day << std::endl;  // year: 2021, month: Mar, day: 14

    date::day_of_week_type dow = today.day_of_week();
    std::cout << "day of week for today: " << dow << std::endl;  // day of week for today: Sun

    date::day_of_year_type doy = today.day_of_year();
    std::cout << "day of year for today: " << doy << std::endl;  // day of year for today: 73

    date eom = today.end_of_month();
    std::cout << "end of month for today: " << eom << std::endl;  // end of month for today: 2021-Mar-31

    std::cout << std::boolalpha;
    std::cout << "Is infinity for today: " << today.is_infinity() << std::endl;  // Is infinity for today: false
    std::cout << "Is neg infinity for today: " << today.is_neg_infinity() << std::endl;  // Is neg infinity for today: false
    std::cout << "Is pos infinity for today: " << today.is_pos_infinity() << std::endl;  // Is pos infinity for today: false
    std::cout << "Is not a date for today: " << today.is_not_a_date() << std::endl;  // Is not a date for today: false
    std::cout << "Is special for today: " << today.is_special() << std::endl;  // Is special for today: false

    std::vector<std::string> special_string = {"not_a_date_time",
                                               "neg_infin", "pos_infin",
                                               "min_date_time",  "max_date_time",
                                               "not_special", "NumSpecialValues"};
    std::cout << "As special for today: " << special_string[static_cast<int>(today.as_special())] << std::endl;  // As special for today: not_special

    std::cout << "modified julian day for today: " << today.modjulian_day() << std::endl;  // modified julian day for today: 59287
    std::cout << "julian day for today: " << today.julian_day() << std::endl;  // julian day for today: 2459288
    std::cout << "week number of today: " << today.week_number() << std::endl;  // week number of today: 10
    std::cout << "day number of today: " << today.day_number() << std::endl;  // day number of today: 2459288

    // convert to string
    std::string str_today = to_simple_string(today);
    std::cout << "to_simple_string: " << str_today << std::endl;  // to_simple_string: 2021-Mar-14
    std::string str_iso_today = to_iso_string(today);
    std::cout << "to_iso_string: " << str_iso_today << std::endl;  // to_iso_string: 20210314
    std::string str_iso_extend = to_iso_extended_string(today);
    std::cout << "to_iso_extended_string: " << str_iso_extend << std::endl;  // to_iso_extended_string: 2021-03-14
    std::wstring wstr_today = to_simple_wstring(today);
    std::wcout << "to_simple_wstring: "<< wstr_today << std::endl;  // to_simple_wstring: 2021-Mar-14

    // operator
    std::stringstream ss("2021-Mar-14");
    date date_from_str;
    ss >> date_from_str;
    std::cout << date_from_str << std::endl;  // 2021-Mar-14

    date yesterday;
    date tomorrow;
    date_duration one_day(1);
    yesterday = today - one_day;
    tomorrow = today + one_day;
    std::cout << "yesterday: " << yesterday << std::endl;  // yesterday: 2021-Mar-13
    std::cout << "today: " << today << std::endl;  // today: 2021-Mar-14
    std::cout << "tomorrow:" << tomorrow << std::endl;  // tomorrow:2021-Mar-15

    std::cout << "yesterday == today? :" << (yesterday == today) << std::endl;  // yesterday == today? :false
    std::cout << "yesterday != today? :" << (yesterday != today) << std::endl;  // yesterday != today? :true
    std::cout << "yesterday > today? :" << (yesterday > today) << std::endl;  // yesterday > today? :false
    std::cout << "yesterday < today? :" << (yesterday < today) << std::endl;  // yesterday < today? :true
    std::cout << "yesterday >= today? :" << (yesterday >= today) << std::endl;  // yesterday >= today? :false
    std::cout << "yesterday <= today? :" << (yesterday <= today) << std::endl;  // yesterday <= today? :true

    // Struct tm Functions
    tm d_tm = to_tm(today);
    std::cout << "tm_year: " << d_tm.tm_year << std::endl;  // tm_year: 121
    std::cout << "tm_mon: " << d_tm.tm_mon << std::endl;  // tm_mon: 2
    std::cout << "tm_mday: " << d_tm.tm_mday << std::endl;  // tm_mday: 14
    std::cout << "tm_wday: " << d_tm.tm_wday << std::endl;  // tm_wday: 0
    std::cout << "tm_yday: " << d_tm.tm_yday << std::endl;  // tm_yday: 72
    std::cout << "tm_hour: " << d_tm.tm_hour << std::endl;  // tm_hour: 0
    std::cout << "tm_min: " << d_tm.tm_min << std::endl;  // tm_min: 0
    std::cout << "tm_sec: " << d_tm.tm_sec << std::endl;  // tm_sec: 0
    std::cout << "tm_isdst: " << d_tm.tm_isdst << std::endl;  // tm_isdst: -1

    d_tm.tm_hour = 12;
    d_tm.tm_min = 15;
    d_tm.tm_sec = 49;
    date d_from_tm = date_from_tm(d_tm);
    std::cout << d_from_tm << std::endl;  // 2021-Mar-14
}

