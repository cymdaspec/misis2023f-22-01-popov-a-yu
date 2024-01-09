cmake_minimum_required (VERSION 3.20)

project(popov-a-yu-22-01 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/installed)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_GENERATOR "Ninja")


find_package(Doxygen REQUIRED)

add_subdirectory(prj.codeforces)
add_subdirectory(prj.cw)

if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    add_custom_target(
            documentation
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating documentation with Doxygen"
            VERBATIM
    )
endif()