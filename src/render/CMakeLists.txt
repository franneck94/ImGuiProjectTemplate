set(LIBRARY_SOURCES "render.cpp")
set(LIBRARY_HEADERS "render.hpp")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(lib STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})
target_include_directories(lib PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(lib PRIVATE
    impl
    simple_ini
    fmt::fmt
    range-v3
    spdlog::spdlog_header_only)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET lib ENABLE ON AS_ERROR OFF)
endif()

if(${ENABLE_LTO})
    target_enable_lto(lib optimized)
endif()
