cmake_minimum_required(VERSION 3.20)
project(solver VERSION 1.2.0)

# Настройка компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека
add_library(solver_lib STATIC solver_lib/solver.cpp)
target_include_directories(solver_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/solver_lib)

# Исполняемый файл
add_executable(solver solver_app/main.cpp)
target_link_libraries(solver solver_lib)

# Установка компонентов (УПРОЩЕННАЯ ВЕРСИЯ)
install(TARGETS solver DESTINATION bin)
install(TARGETS solver_lib DESTINATION lib)
install(FILES solver_lib/solver.h DESTINATION include)

# Настройка CPack
set(CPACK_PACKAGE_NAME "solver")
set(CPACK_PACKAGE_VENDOR "Koswos")
set(CPACK_PACKAGE_CONTACT "support@gmail.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

# Настройки WiX (Windows)
if(WIN32)
    set(CPACK_GENERATOR "WIX")
    
    # Сгенерируйте новые GUID!
    set(CPACK_WIX_UPGRADE_GUID "D6E4D0F0-7A3B-4A5C-9D1E-0F2A3B4C5D6E") # Замените!
    set(CPACK_WIX_PRODUCT_GUID "A1B2C3D4-E5F6-7A8B-9C0D-1E2F3A4B5C6D") # Замените!
    
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
    set(CPACK_WIX_ARCHITECTURE "x64")
    set(CPACK_WIX_UI_REF "WixUI_InstallDir")
    
    # Критически важные настройки
    set(CPACK_WIX_SKIP_PROGRAM_FOLDER YES)
    set(CPACK_WIX_USE_BEST_EFFORT_SHORTCUTS YES)
    set(CPACK_WIX_CULTURES "en-us")
    
    # Явно указываем пути установки
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "Solver")
endif()

include(CPack)
