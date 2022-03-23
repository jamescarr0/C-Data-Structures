cmake_minimum_required(VERSION 3.21)
project(C-Data-Structures C)

set(CMAKE_C_STANDARD 99)

add_executable(Linked_List LinkedList/linkedList.c DriverCode.c Stack/stack.c Stack/stack.h Queue/queue.c Queue/queue.h)
