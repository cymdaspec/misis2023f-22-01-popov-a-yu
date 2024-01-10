cmake_minimum_required (VERSION 3.20)

project(prj.cw LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_subdirectory(src)
add_subdirectory(example)
target_link_libraries(automations_constructor PUBLIC choreograph)

set_target_properties(choreograph PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(automations_constructor PROPERTIES LINKER_LANGUAGE CXX)
