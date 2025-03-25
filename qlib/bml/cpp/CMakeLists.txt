cmake_minimum_required(VERSION 3.29)
project(bml)
set(CMAKE_CXX_STANDARD 26)

# set(Boost_DEBUG ON)
set(BOOST_ROOT "C:\\boost")
add_library(bml SHARED "bml.cpp" "random.cpp" "distributions.cpp")
target_include_directories(bml PRIVATE "${PROJECT_SOURCE_DIR}/bml/math")
target_include_directories(bml PRIVATE "${PROJECT_SOURCE_DIR}/bml/random")
target_include_directories(bml PRIVATE "${PROJECT_SOURCE_DIR}/kdb")
find_package(Boost REQUIRED)

include(FetchContent)
FetchContent_Declare(chk
        GIT_REPOSITORY https://github.com/KxSystems/kdb.git
)

FetchContent_MakeAvailable(chk)

set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)


# I recommend using SYSTEM when dealing with 3rd party code.
# Avoids the hassle of warnings from a library you don't own.
# target_include_directories(bml SYSTEM PRIVATE
#         "${CMAKE_BINARY_DIR}/_deps/chk-src/c/c"
# )
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

include_directories("${Boost_INCLUDE_DIRS}")
# target_include_directories(bml SYSTEM PUBLIC ${Boost_INCLUDE_DIR})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_source_files_properties(bml PROPERTIES COMPILE_OPTIONS "/bigobj")
    target_link_options(bml PRIVATE 
        /DEF:${CMAKE_CURRENT_SOURCE_DIR}/bml.def
    )

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        target_link_libraries(bml PRIVATE "${CMAKE_BINARY_DIR}/_deps/chk-src/w64/q.lib")
        install(TARGETS bml DESTINATION "${PROJECT_SOURCE_DIR}/bin/w64/${CMAKE_BUILD_TYPE}")
    else()
        target_link_libraries(bml PRIVATE "${CMAKE_BINARY_DIR}/_deps/chk-src/w32/q.lib")
        install(TARGETS bml DESTINATION "${PROJECT_SOURCE_DIR}/bin/w32/${CMAKE_BUILD_TYPE}")
    endif()
endif()


# target_link_libraries(bml PUBLIC Boost::headers Boost::system Boost::filesystem)
