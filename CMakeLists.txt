cmake_minimum_required (VERSION 3.1)
project (OHCS)
# The version number.
set (OHCS_VERSION_MAJOR 0)
set (OHCS_VERSION_MINOR 1)
add_executable(
	ohcs
	main/OCSS.cpp
	main/argv.cpp
	main/main.cpp
	bigint/BigIntegerAlgorithms.cc
	bigint/BigUnsigned.cc
	bigint/BigUnsignedInABase.cc
	bigint/BigInteger.cc
	bigint/BigIntegerUtils.cc
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
