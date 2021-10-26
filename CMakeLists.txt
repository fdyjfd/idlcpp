cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(CMAKE_DEBUG_POSTFIX d)
set(PROJECT_NAME "idlcpp")
project(${PROJECT_NAME} C CXX)

file(GLOB SOURCE_FILES
    "src/*.cpp"
    "src/*.c"
    "src/*.h"
)

# Add executable to build.
add_executable(${PROJECT_NAME} 
   ${SOURCE_FILES}
)

install(
    TARGETS ${PROJECT_NAME}  
    RUNTIME DESTINATION "." 
    CONFIGURATIONS ${CMAKE_CONFIGURATION_TYPES}
)

install(TARGETS ${PROJECT_NAME}  DESTINATION "D:/kernel/external/Engine/bin")

target_include_directories(${PROJECT_NAME} PRIVATE "src")
target_compile_definitions(${PROJECT_NAME} PRIVATE "_CONSOLE")

set(FAKE_TARGET fakeTarget)     
set(FLEX_FILE ${CMAKE_SOURCE_DIR}/src/idlcpp.l)
set(BISON_FILE ${CMAKE_SOURCE_DIR}/src/idlcpp.y)

if(UNIX)
 set(FLEX_EXE flex)
 set(BISON_EXE bison)
else()
 set(FLEX_EXE ${CMAKE_SOURCE_DIR}/winflexbison/bin/Release/flex.exe)
 set(BISON_EXE ${CMAKE_SOURCE_DIR}/winflexbison/bin/Release/bison.exe)
 target_link_libraries(${PROJECT_NAME} kernel32.lib user32.lib Ws2_32.lib)
endif()

add_custom_target(fakeTarget 
  COMMAND ${FLEX_EXE} -o${FLEX_FILE}.c ${FLEX_FILE}
  COMMAND ${BISON_EXE} -o${BISON_FILE}.c -d ${BISON_FILE}
)
add_dependencies(${PROJECT_NAME} ${FAKE_TARGET})
