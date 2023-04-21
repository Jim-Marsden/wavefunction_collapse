cmake_minimum_required(VERSION 3.21)
project(wavefunction_collapse LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG master)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master)
FetchContent_MakeAvailable(fmt)


add_executable(wavefunction_collapse src/main.cpp)
target_link_libraries(wavefunction_collapse PRIVATE sfml-graphics fmt)
target_compile_features(wavefunction_collapse PRIVATE cxx_std_23)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET wavefunction_collapse POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:wavefunction_collapse> $<TARGET_FILE_DIR:wavefunction_collapse> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS wavefunction_collapse)