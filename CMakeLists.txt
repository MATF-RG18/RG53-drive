cmake_minimum_required(VERSION 3.12)
project(RG53-drive CXX)

set(CMAKE_CXX_STANDARD 17)

link_libraries(GL)
link_libraries(GLU)
link_libraries(glut)

add_executable(RG53-drive main.cpp figures.cpp figures.h)