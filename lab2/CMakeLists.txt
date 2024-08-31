cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp dynamic-array.h Tests/test-dynamic-array.cpp Tests/test-dynamic-array.h linked-list.h Tests/test-linked-list.cpp Tests/test-linked-list.h mutable-array-sequence.h immutable-array-sequence.h mutable-sequence.h immutable-sequence.h Tests/test-mutable-array-sequence.cpp Tests/test-mutable-array-sequence.h Tests/test-immutable-array-sequence.cpp Tests/test-immutable-array-sequence.h mutable-list-sequence.h Tests/test-mutable-list-sequence.cpp Tests/test-mutable-list-sequence.h immutable-list-sequence.h Tests/test-immutable-list-sequence.cpp Tests/test-immutable-list-sequence.h ui.cpp ui.h)