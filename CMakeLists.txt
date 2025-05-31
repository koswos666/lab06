cmake_minimum_required(VERSION 3.20)
project(solver VERSION 1.1.0)

# Настройка компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека
add_library(solver_lib STATIC solver_lib/solver.cpp)
target_include_directories(solver_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/solver_lib
)

# Исполняемый файл
add_executable(solver solver_app/main.cpp)
target_link_libraries(solver solver_lib)

# Установка компонентов
install(TARGETS solver DESTINATION bin)
install(TARGETS solver_lib ARCHIVE DESTINATION lib)
install(FILES solver_lib/solver.h DESTINATION include)

# Настройка CPack
set(CPACK_PACKAGE_NAME "solver")
set(CPACK_PACKAGE_VENDOR "Koswos")
set(CPACK_PACKAGE_CONTACT "support@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

# Настройки WiX (Windows)
if(WIN32)
    set(CPACK_GENERATOR "WIX")
    set(CPACK_WIX_UPGRADE_GUID "YOUR-UPGRADE-GUID-HERE") # Заменить!
    set(CPACK_WIX_PRODUCT_GUID "YOUR-PRODUCT-GUID-HERE") # Заменить!
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
    set(CPACK_WIX_ARCHITECTURE "x64")
    set(CPACK_WIX_UI_REF "WixUI_InstallDir")
    set(CPACK_WIX_CULTURES "en-us")
    set(CPACK_WIX_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/wix_template.xml")
endif()

include(CPack)
