cmake_minimum_required(VERSION 3.25)
project(robolator)

set(CMAKE_CXX_STANDARD 23)

include_directories(external/OddityEngine/include)

add_subdirectory(external/OddityEngine)

add_executable(robolator source/main.cpp source/Robot.cpp source/Robot.h source/Robotmodel.cpp source/Robotmodel.h)

target_link_libraries(${PROJECT_NAME}
        OddityEngine
        )