set(target_name "snake")

set(src_precompiled
    "src/snake/precompiled.hpp")

set(src_snake
    "src/snake/game.cpp"
    "src/snake/game.hpp"
    "src/snake/main.cpp"
    "src/snake/snake.cpp"
    "src/snake/snake.hpp")

set(src_files
    ${src_precompiled}
    ${src_snake})

# Project
add_executable(${target_name} ${src_files})
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${target_name}
    compiler_features
    compiler_warnings
    Wraith::Engine)

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_precompile_headers(${target_name} PUBLIC ${src_precompiled})

auto_group_sources(src_files ${CMAKE_CURRENT_SOURCE_DIR})
source_group("src/precompiled" REGULAR_EXPRESSION "cmake_pch\.[ch]xx")

set_target_properties(${target_name} PROPERTIES
    FOLDER ${${PROJECT_NAME}_FOLDER}
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)