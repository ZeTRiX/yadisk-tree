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

option(BUILD_TESTS "Build tests" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

hunter_add_package(nlohmann-json)
find_package(nlohmann-json REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
	Boost::filesystem Boost::system
	OpenSSL::SSL OpenSSL::Crypto
	CURL::libcurl
 	nlohmann-json::nlohmann-json
)

hunter_add_package(yadisk-client)
find_package(yadisk-client)



if(BUILD_TESTS)
enable_testing()
hunter_add_package(Catch)
find_package(Catch CONFIG REQUIRED)
file(GLOB TESTS_${PROJECT_NAME}_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/ops/tree/tests.cpp)
add_executable(check ${TESTS_${PROJECT_NAME}_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(check ${PROJECT_NAME} Catch::Catch)
add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
endif()

if(BUILD_EXAMPLES)
file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
	get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
	add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
	target_link_libraries(${EXAMPLE_NAME} yadisk-tree)
	install(TARGETS ${EXAMPLE_NAME}
			RUNTIME DESTINATION bin
			)
endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
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
