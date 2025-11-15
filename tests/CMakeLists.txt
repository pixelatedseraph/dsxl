add_executable(dsxl_test test.c)
target_link_libraries(dsxl_test PRIVATE dsxl)

add_test(NAME DSXLTest COMMAND dsxl_test)
