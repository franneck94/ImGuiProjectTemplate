set(EXE_SOURCES
    "main.cpp"
    "cycle.cpp")
set(EXE_HEADERS
    "cycle.hpp")
add_executable(main
    ${EXE_SOURCES}
    ${EXE_HEADERS})

target_link_libraries(main PRIVATE
    impl
    lib
    nlohmann_json
    fmt::fmt
    range-v3
    spdlog::spdlog_header_only
    cxxopts::cxxopts
)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET main ENABLE ON AS_ERROR OFF)
endif()

if(${ENABLE_LTO})
    target_enable_lto(main optimized)
endif()
