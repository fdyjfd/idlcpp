cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

if (CMAKE_CONFIGURATION_TYPES STREQUAL "Debug")
  set(PROJECT_NAME "idlcppd")
else()
  set(PROJECT_NAME "idlcpp")
endif()

project(${PROJECT_NAME} C CXX)


include(PrintVariables.cmake)
print_variables()

file(GLOB SOURCE_FILES
    "src/*.cpp"
    "src/*.c"
    "src/*.h"
)
# exclude some source files
#list(REMOVE_ITEM SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/libmain.c")
#list(REMOVE_ITEM SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/libyywrap.c")

# Add executable to build.


add_executable(${PROJECT_NAME} 
   ${SOURCE_FILES}
)

install(
    TARGETS ${PROJECT_NAME}  
    RUNTIME DESTINATION "."
    CONFIGURATIONS ${CMAKE_CONFIGURATION_TYPES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE "_CONSOLE")

target_include_directories(${PROJECT_NAME} PRIVATE "src")

target_link_libraries(${PROJECT_NAME} kernel32.lib user32.lib Ws2_32.lib)

set(FAKE_TARGET fakeTarget)     
set(FLEX_FILE ${CMAKE_SOURCE_DIR}/src/idlcpp.l)
set(BISON_FILE ${CMAKE_SOURCE_DIR}/src/idlcpp.y)
add_custom_target(fakeTarget 
  COMMAND ${CMAKE_SOURCE_DIR}/winflexbison/bin/Release/flex.exe -o${FLEX_FILE}.c ${FLEX_FILE}
  COMMAND ${CMAKE_SOURCE_DIR}/winflexbison/bin/Release/bison.exe -o${BISON_FILE}.c -d ${BISON_FILE}
)
add_dependencies(${PROJECT_NAME} ${FAKE_TARGET})
