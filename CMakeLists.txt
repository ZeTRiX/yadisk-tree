cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/HunterGate.cmake)
HunterGate(
    URL  "https://github.com/yadisk-ops/hunter/archive/v0.18.47.2.tar.gz"
    SHA1 "fe0f3a4d337ae08dbea640fd1ebc1e448919fcd3"
    LOCAL
)

project(yadisk-tree) # this command set PROJECT_NAME to "yadisk-subtract"

set(SUBTRACT_VERSION_MAJOR 0)
set(SUBTRACT_VERSION_MINOR 1)
set(SUBTRACT_VERSION_PATCH 0)
set(SUBTRACT_VERSION ${SUBTRACT_VERSION_MAJOR}.${SUBTRACT_VERSION_MINOR}.${SUBTRACT_VERSION_PATCH})
set(SUBTRACT_VERSION_STRING "v${SUBTRACT_VERSION}")
#SET(PROJECT_NAME "yadisk-subtract")



target_include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include)



