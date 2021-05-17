add_executable(${PROJECT_NAME} main.cpp editor/editor.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        project_warnings
        ${OPENGL_LIBRARIES}
        ${SFML_LIBRARIES}
        imgui_sfml)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${SFML_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/external/imgui)
