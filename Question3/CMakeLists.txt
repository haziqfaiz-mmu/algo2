cmake_minimum_required(VERSION 3.9.1)
project(question2)
add_executable(question2 Main.cpp Planet.cpp Graph.cpp)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(gvc REQUIRED libgvc libcgraph libcdt)
LINK_DIRECTORIES(${gvc_LIBRARY_DIRS})
INCLUDE_DIRECTORIES(${gvc_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${gvc_LIBRARIES})