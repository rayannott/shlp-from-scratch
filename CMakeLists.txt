cmake_minimum_required(VERSION 3.14)

project(shlp_from_scratch VERSION 2.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shlp_from_scratch src/main.cpp)

add_subdirectory(array-lib)
add_subdirectory(nn-lib)

# Link the executable and the library together
target_link_libraries(shlp_from_scratch array-lib nn-lib)

target_compile_features(shlp_from_scratch PUBLIC cxx_std_17)