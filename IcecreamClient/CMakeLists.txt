project(IcecreamClient)

find_package(Qt5Core REQUIRED)
find_package(OpenAL REQUIRED)

# Qt Bluetooth?
# Qt D-Bus?

include_directories(
 ${OPENAL_INCLUDE_DIRS}
 ${CMAKE_SOURCE_DIR}/JGFC
)

set(SRCS
 ClientNetworkManager.h
 ClientNetworkManager.cpp
 ResourceCacheManager.h
 ResourceCacheManager.cpp
 Window.h
 Window.cpp
)

set(RSRCS
 resources.qrc
)
qt5_add_resources(RESOURCES_OUT ${RSRCS})

add_library(IcecreamClientLib STATIC ${SRCS} ${RESOURCES_OUT})
target_link_libraries(IcecreamClientLib JansGameFrameworkClient)
qt5_use_modules(IcecreamClientLib Core Gui Quick Qml Network)

add_executable(IcecreamClient main.cpp)
target_link_libraries(IcecreamClient IcecreamClientLib)
qt5_use_modules(IcecreamClient Core Gui Quick Qml Network)

# this is needed for showing stuff in creators project pane
file(GLOB QML_FILES qml/*.qml qml/*/*.qml)
add_executable(DummyFilesForQtCreatorProjectPane EXCLUDE_FROM_ALL ${QML_FILES})
