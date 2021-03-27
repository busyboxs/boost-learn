cmake_minimum_required(VERSION 3.8)

set(BOOST_ROOT "D:/github/boost_1_75_0")
find_package(Boost REQUIRED COMPONENTS date_time)
if(Boost_FOUND)
    message("include path: ${Boost_INCLUDE_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Date "date_example.cpp")
    target_link_libraries(Date ${Boost_LIBRARIES})

    add_executable(Date_Duration date_duration_example.cpp)
    target_link_libraries(Date_Duration ${Boost_LIBRARIES})
endif()