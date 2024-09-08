cmake_minimum_required(VERSION 3.28)
project(JDP)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file (GLOB_RECURSE SOURCES "src/*.cpp")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_executable(${PROJECT_NAME} ${SOURCES})
    else()
        add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
    endif()

    target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib-5.0_win64_msvc16/include)
    target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib-5.0_win64_msvc16/lib)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib winmm)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_executable(${PROJECT_NAME} ${SOURCES})

    target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib-5.0_linux_amd64/include)
    target_link_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib-5.0_linux_amd64/lib)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
else()
    message(FATAL_ERROR "Operating system is unsupported.")
endif()