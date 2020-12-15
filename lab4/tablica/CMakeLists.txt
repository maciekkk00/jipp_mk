cmake_minimum_required( VERSION 3.0 )
project( tablica )

# include
include_directories( ./include  )

# target
add_executable( tablica ./tests/tablica.cpp )
