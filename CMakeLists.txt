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
  
    set(CPACK_WIX_ARCHITECTURE "x64")
    
   
    set(CPACK_WIX_UPGRADE_GUID "D6E4D0F0-7A3B-4A5C-9D1E-0F2A3B4C5D6E") 
    set(CPACK_WIX_PRODUCT_GUID "A1B2C3D4-E5F6-7A8B-9C0D-1E2F3A4B5C6D") 
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
    
   
    set(CPACK_COMPONENTS_ALL applications libraries headers)
    
 
    set(CPACK_WIX_UI_REF "WixUI_InstallDir")
    
   
    set(CPACK_WIX_PRODUCT_ICON "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.ico")
    set(CPACK_WIX_UPGRADE_GUID "${CPACK_WIX_UPGRADE_GUID}")
    set(CPACK_WIX_CULTURES "en-US")
    set(CPACK_WIX_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/wix_template.xml")
    
    
    set(CPACK_WIX_SKIP_WIX_UI_EXTENSION TRUE)
endif()



set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_CONTACT})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

set(CPACK_RPM_PACKAGE_VENDOR ${CPACK_PACKAGE_VENDOR})

include(CPack)
