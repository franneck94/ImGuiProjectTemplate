set(EXE_SOURCES
    "${EXECUTABLE_NAME}.cpp"
    "cycle.cpp")
set(EXE_HEADERS
    "cycle.hpp")
add_executable(${EXECUTABLE_NAME}
    ${EXE_SOURCES}
    ${EXE_HEADERS})

target_link_libraries(${EXECUTABLE_NAME} PRIVATE
    impl
    ${LIBRARY_NAME}
    fmt::fmt
    cxxopts::cxxopts
    nlohmann_json::nlohmann_json)

target_set_warnings(TARGET ${EXECUTABLE_NAME} ENABLE ${ENABLE_WARNINGS} AS_ERROR ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
    target_enable_lto(${EXECUTABLE_NAME} optimized)
endif()
