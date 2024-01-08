cmake_minimum_required(VERSION 3.20)

project(prj.cw LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(example)
 #add_executable (example example.cpp)
 #include_directories(src)
 #include_directories(example)
#set_property(TARGET choreograph PROPERTY
#             IMPORTED_LOCATION ${SOURCE_LIB})

#target_link_libraries(automations_constructor PUBLIC choreograph)

set_target_properties(choreograph PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(automations_constructor PROPERTIES LINKER_LANGUAGE CXX)

#sfml
#include(FetchContent) #uncoment for example working
#FetchContent_Declare(sfml
#	GIT_REPOSITORY https://github.com/sfml/sfml.git
#	GIT_TAG 69ea0cd863aed1d4092b970b676924a716ff718b
#)
#FetchContent_MakeAvailable(sfml)
#end