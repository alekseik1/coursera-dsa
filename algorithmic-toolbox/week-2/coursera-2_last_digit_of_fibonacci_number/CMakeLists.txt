SET(BASE_NAME toolbox-w2-hw2-fib-last-digit)
SET(EXE_MAIN_NAME ${BASE_NAME}-main)
SET(EXE_TEST_NAME ${BASE_NAME}-test)

add_compile_definitions(MY_COMPILATION)

add_executable(${EXE_MAIN_NAME} main.cpp)

add_executable(${EXE_TEST_NAME} tests.cpp main.cpp)
target_compile_definitions(${EXE_TEST_NAME} PRIVATE IS_TEST=1)
target_link_libraries(${EXE_TEST_NAME} PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(${EXE_TEST_NAME})

add_custom_target(${BASE_NAME}-submission
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        DEPENDS main.h main.cpp
        COMMAND echo '' > submission.cpp
        COMMAND cat main.h >> submission.cpp
        COMMAND cat main.cpp >> submission.cpp
        )