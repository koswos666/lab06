cmake_minimum_required(VERSION 3.10)
project(solver VERSION 1.0.0)

# Библиотека solver
add_library(solver_lib STATIC solver_lib/solver.cpp)
target_include_directories(solver_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/solver_lib
)

# Исполняемый файл
add_executable(solver solver_app/main.cpp)
target_include_directories(solver PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/solver_lib
)
target_link_libraries(solver solver_lib)


install(TARGETS solver DESTINATION bin)
install(TARGETS solver_lib ARCHIVE DESTINATION lib)
install(FILES solver_lib/solver.h DESTINATION include)


set(CPACK_PACKAGE_NAME "solver")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "Koswos")
set(CPACK_PACKAGE_CONTACT "koswos@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Equation solver library and application")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

if(WIN32)
    # Явно указываем архитектуру
    set(CPACK_WIX_ARCHITECTURE "x64")
    
    # Указываем явные GUID
    set(CPACK_WIX_UPGRADE_GUID "YOUR_UPGRADE_GUID")
    set(CPACK_WIX_PRODUCT_GUID "YOUR_PRODUCT_GUID")
    
    # Указываем путь к лицензии
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
    
    
    # Явно определяем компоненты установки
    set(CPACK_COMPONENTS_ALL applications libraries headers)
endif()


set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_CONTACT})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

set(CPACK_RPM_PACKAGE_VENDOR ${CPACK_PACKAGE_VENDOR})

include(CPack)
