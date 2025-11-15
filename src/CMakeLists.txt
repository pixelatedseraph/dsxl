# Collect all .c files in this folder
file(GLOB DSXL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

# Build static library
add_library(dsxl STATIC ${DSXL_SOURCES})

# Public headers (users need this)
target_include_directories(dsxl
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
