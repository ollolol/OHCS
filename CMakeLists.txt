cmake_minimum_required (VERSION 2.6)
project (OHCS)
# The version number.
set (OHCS_VERSION_MAJOR 0)
set (OHCS_VERSION_MINOR 1)
add_executable(
	ohcs
	main/*.cpp
	bigint/*.cc
)
