cmake_minimum_required(VERSION 3.20)

# The project name, version and languages
project(Hello 
    VERSION 1.0 
    LANGUAGES CXX
    )


### The library files
set(Lib lib)
add_library(${Lib} ${PROJECT_SOURCE_DIR}/lib/functions.cpp)

target_include_directories(${Lib} PUBLIC include)

target_compile_features(${Lib} PUBLIC cxx_std_20)

target_compile_options(${Lib} 
PUBLIC
    -O3
    -fdata-sections
    -ffunction-sections
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wdouble-promotion
    -Wconversion
    -fno-common
    )


### The executable target
set(TargetName hello)
add_executable(${TargetName} src/hello.cpp)
target_link_libraries(${TargetName} PUBLIC ${Lib})
target_link_options(${TargetName} PUBLIC -Wl,--gc-sections)

add_subdirectory(src)

