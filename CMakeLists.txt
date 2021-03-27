cmake_minimum_required (VERSION 3.8)

project ("BoostUsage")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

#add_subdirectory(string_algorithm)
add_subdirectory(date_time)