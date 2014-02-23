project(IcecreamServer)

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Sql REQUIRED)

set(SRCS
 AIManager.h
 AIManager.cpp
 CacheManager.h
 CacheManager.cpp
 EntityManager.h
 EntityManager.cpp
 NetworkManager.h
 NetworkManager.cpp
 PermissionManager.h
 PermissionManager.cpp
 PhysicsManager.h
 PhysicsManager.cpp
 PluginManager.h
 PluginManager.cpp
 SaveManager.h
 SaveManager.cpp
)

include_directories(
 ${Qt5Core_INCLUDE_DIRS}
 ${Qt5Qml_INCLUDE_DIRS}
 ${Qt5Network_INCLUDE_DIRS}
 ${Qt5Sql_INCLUDE_DIRS}
 ${CMAKE_SOURCE_DIR}/JGF
)

set(ICECREAM_SERVER_VERSION 1.0)

configure_file(config.h.in config.h @ONLY)

add_library(IcecreamServerLib STATIC ${SRCS})
target_link_libraries(IcecreamServerLib JansGameFramework)
qt5_use_modules(IcecreamServerLib Core Qml Network Sql)

### libnoise ###
# TODO make platform independent
target_link_libraries(IcecreamServerLib noise)
include_directories(/usr/include/libnoise)

add_executable(IcecreamServer main.cpp)
target_link_libraries(IcecreamServer IcecreamServerLib)
qt5_use_modules(IcecreamServer Core)
