cmake_minimum_required(VERSION "3.22.1")

project("avicena-backend")

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/solver/dummySolver.cpp
    src/rest-api/avicenaService.cpp
    src/rest-api/avicenaServiceSettingFactory.cpp
    src/rest-api/computeResourceFactory.cpp
    src/rest-api/downloadResourceFactory.cpp)

target_link_libraries(avicena-backend restbed)
target_include_directories(avicena-backend PUBLIC ${CMAKE_SOURCE_DIR}/rest-api ${CMAKE_SOURCE_DIR}/solver)
set_property(TARGET avicena-backend PROPERTY CXX_STANDARD 17)