if(ENABLE_CLANG_TIDY)
    if(CMake_SOURCE_DIR STREQUAL CMake_BINARY_DIR)
        message(FATAL_ERROR "CMake_RUN_CLANG_TIDY requires an out-of-source build!")
    endif()
    find_program(CLANG_TIDY_COMMAND NAMES clang-tidy)
    if(NOT CLANG_TIDY_COMMAND)
        message(WARNING "CMake_RUN_CLANG_TIDY is ON but clang-tidy is not found!")
        set(CMAKE_CXX_CLANG_TIDY "" CACHE STRING "" FORCE)
    else()
        set(CLANGTIDY_EXTRA_ARGS
            "-extra-arg=-Wno-unknown-warning-option")
        set(CLANGTIDY_EXTRA_ARGS_BEFORE
            "--extra-arg-before=-std=${CMAKE_CXX_STANDARD}")
        set(CMAKE_CXX_CLANG_TIDY
            "${CLANG_TIDY_COMMAND}"
            ${CLANGTIDY_EXTRA_ARGS_BEFORE}
            ${CLANGTIDY_EXTRA_ARGS})
    endif()
endif()
