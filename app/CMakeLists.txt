set(EXE_SOURCES "main.cpp" "cycle.cpp")
add_executable(main ${EXE_SOURCES})

target_link_libraries(main PUBLIC
    lib
    fmt::fmt
    spdlog::spdlog_header_only
    nlohmann_json
    cxxopts::cxxopts
    impl
    imgui
    implot
)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET lib ENABLE ON AS_ERROR OFF)
endif()
