#set_directory_properties(PROPERTIES EXCLUDE_FROM_ALL YES)

include(FetchContent) 

FetchContent_Declare(sfml
	GIT_REPOSITORY https://github.com/sfml/sfml.git
	GIT_TAG 69ea0cd863aed1d4092b970b676924a716ff718b
)

FetchContent_MakeAvailable(sfml)

add_executable(main "main.cpp")

target_link_libraries(main PRIVATE choreograph)
target_link_libraries(main PRIVATE automations_constructor)
target_link_libraries(main PRIVATE sfml-graphics) 
target_compile_features(main PRIVATE cxx_std_17)

set(SFML_BUILD_NETWORK:BOOL=FALSE)
set(SFML_BUILD_AUDIO:BOOL=FALSE)
set(SFML_BUILD_EXAMPLES:BOOL=FALSE)
set(SFML_BUILD_DOC:BOOL=FALSE)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()

install(DIRECTORY main
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)