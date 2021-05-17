add_executable(unit_tests main.cpp)

target_include_directories(unit_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/external/catch2)

target_link_libraries(unit_tests PRIVATE project_warnings)

add_test(run_unit_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/unit_tests)
