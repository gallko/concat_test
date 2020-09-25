file(GLOB SOURCES
        ./*.cpp
        ./src/*.cpp)

set(SOURCES ${SOURCES})

include_directories(include)

add_library(${BINARY_NAME} STATIC ${SOURCES})

target_compile_options(${BINARY_NAME} PRIVATE -Wall)
