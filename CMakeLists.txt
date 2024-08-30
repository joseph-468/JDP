cmake_minimum_required(VERSION 3.28)
project(JDP)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)
file (GLOB_RECURSE SOURCES "src/*.cpp")

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/vendor/raylib-5.0_win64_mingw-w64/include)
    link_directories(${CMAKE_SOURCE_DIR}/vendor/raylib-5.0_win64_mingw-w64/lib)

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_executable(JDP ${SOURCES})
    else()
        add_executable(JDP WIN32 ${SOURCES})
    endif()

    target_link_libraries(JDP raylib winmm)
else()
    message(FATAL_ERROR "Operating System Unsupported")
endif()