cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/HunterGate.cmake)
HunterGate(
    URL  "https://github.com/yadisk-ops/hunter/archive/v0.18.47.2.tar.gz"
    SHA1 "fe0f3a4d337ae08dbea640fd1ebc1e448919fcd3"
    LOCAL
)

project(yadisk-tree)

set(TREE_VERSION_MAJOR 0)
set(TREE_VERSION_MINOR 1)
set(TREE_VERSION_PATCH 0)
set(TREE_VERSION ${TREE_VERSION_MAJOR}.${TREE_VERSION_MINOR}.${TREE_VERSION_PATCH})
set(TREE_VERSION_STRING "v${TREE_VERSION}")

option(BUILD_TESTS "Build tests" OFF)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

hunter_add_package(nlohmann-json)
find_package(nlohmann-json REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
	Boost::filesystem Boost::system
	OpenSSL::SSL OpenSSL::Crypto
	CURL::libcurl
	nlohmann-json::nlohmann-json
)



if(BUILD_TESTS)
enable_testing()
hunter_add_package(Catch)
find_package(Catch CONFIG REQUIRED)
file(GLOB TESTS_${PROJECT_NAME}_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/ops/tree/tests.cpp)
add_executable(check ${TESTS_${PROJECT_NAME}_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(check ${PROJECT_NAME} Catch::Catch)
add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
endif()



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
