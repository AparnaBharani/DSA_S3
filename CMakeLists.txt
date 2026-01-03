cmake_minimum_required(VERSION 3.10)

project(DsaCodeRepo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.c++
    )
set(HEADERS
    Queue.hpp
    Stack.hpp
    FixedSizeStack.hpp
    QueueApp.hpp
    StackApp.hpp
    FixedSizeStackApp.hpp
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
