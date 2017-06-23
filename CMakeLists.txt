
cmake_minimum_required(VERSION 3.0)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/HunterGate.cmake)
HunterGate(
    URL  "https://github.com/yadisk-ops/hunter/archive/v0.18.47.3.tar.gz"
    SHA1 "ccc53422f9a992ca12042179a1d2471bd3959b48"
)

project(tree)

set(TREE_MAJOR 0)
set(TREE_VERSION_MINOR 1)
set(TREE_VERSION_PATCH 1)
set(TREE_VERSION ${TREE_VERSION_MAJOR}.${TREE_VERSION_MINOR}.${TREE_VERSION_PATCH})
set(TREE_VERSION_STRING "v${TREE_VERSION}")
SET(PROJECT_NAME "tree") 

option(BUILD_TESTS "Build tests" ON)


hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

hunter_add_package(nlohmann-json)
find_package(nlohmann-json REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# SET(SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/sources/replica.cpp)
# ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sources)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/*)

add_library(${PROJECT_NAME} ${SOURCES}) 
target_link_libraries(${PROJECT_NAME}
	Boost::filesystem Boost::system
	OpenSSL::SSL OpenSSL::Crypto
	CURL::libcurl
 	nlohmann-json::nlohmann-json
)
hunter_add_package(yadisk-client)
find_package(yadisk-client)
target_link_libraries(yadisk-tree yadisk-client::yadisk-client)

install(TARGETS yadisk-tree
		EXPORT yadisk-tree-config
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)

install(EXPORT yadisk-tree-config
		NAMESPACE yadisk-ops::
		DESTINATION cmake
)

include(CPackConfig.cmake)
