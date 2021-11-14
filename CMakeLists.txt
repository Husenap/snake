cmake_minimum_required(VERSION 3.21)

project("snake" LANGUAGES CXX)

include("cmake/prevent_in_source_builds.cmake")
include("cmake/standard_project_setup.cmake")

include("cmake/compiler_features.cmake")
include("cmake/compiler_warnings.cmake")

include("cmake/auto_group_sources.cmake")

set(${PROJECT_NAME}_FOLDER
    ${PROJECT_NAME}
    CACHE STRING "The folder that ${PROJECT_NAME} projects will be placed in.")

include("thirdparty/wraith.cmake")
add_subdirectory("snake")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "snake")