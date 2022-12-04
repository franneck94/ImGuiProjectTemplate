set(LIBRARY_SOURCES "render.cpp")
set(LIBRARY_HEADERS "render.hpp")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(
    ${LIBRARY_NAME}
    PRIVATE impl
            fmt::fmt
            cxxopts::cxxopts
            nlohmann_json::nlohmann_json)

target_set_warnings(
    TARGET
    ${LIBRARY_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_NAME} optimized)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_msvc_to_target(${LIBRARY_NAME})
endif()
