cmake_minimum_required(VERSION 3.10)
project(solver VERSION 1.0.0)

# Добавляем библиотеку solver
add_subdirectory(solver_lib)

# Создаем исполняемый файл
add_executable(solver solver_lib/solver.cpp)
target_link_libraries(solver solver_lib)

# Установка компонентов
install(TARGETS solver DESTINATION bin)
install(TARGETS solver_lib ARCHIVE DESTINATION lib)
install(FILES solver_lib/solver.h DESTINATION include)

# Настройка CPack
set(CPACK_PACKAGE_NAME "solver")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "Koswos")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Equation solver")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_RPM_FILE_NAME RPM-DEFAULT)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

include(CPack)
