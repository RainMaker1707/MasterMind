cmake_minimum_required(VERSION 3.5)
project(MasterMind)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game/MenuFrame.cpp Game/MenuFrame.h Game/GameFrame.cpp Game/GameFrame.h Game/GameTool.cpp Game/GameTool.h)
set(CMAKE_PREFIX_PATH /Users/rain/Qt/5.15.1/clang_64/lib/cmake)
find_package(Qt5Widgets REQUIRED)
add_executable(MasterMind ${SOURCE_FILES})

target_link_libraries(MasterMind Qt5::Widgets)