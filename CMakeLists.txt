cmake_minimum_required(VERSION 3.15)

include (CMakeDependentOption)
include (CMakePrintHelpers)

set(DUMMY "dummy")

project(${DUMMY})
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
set(CMAKE_CXX_FLAGS	"${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -fstack-clash-protection -fstack-protector -mstackrealign -g -g3")
set(CMAKE_C_FLAGS	"${CMAKE_C_FLAGS} -O0 -Wall -Werror -fstack-clash-protection -fstack-protector -mstackrealign -g -g3")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs -Wl,-z,now")
endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
set(CMAKE_CXX_FLAGS	"${CMAKE_CXX_FLAGS} /Ox /EHa /EHc")
set(CMAKE_C_FLAGS	"${CMAKE_C_FLAGS} /Ox /EHa /EHc")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEBUG")
endif ()

# LIBRARY
set(DUMMY_LIB "dummyl")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

endif ()

include_directories(libs/include)

# HEADERS
file(GLOB HEADERS "libs/include/*.h*")

# SOURCES
file(GLOB SOURCES "libs/src/*.cpp*")

  # Linux-specific stuff
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
# All the RPATH settings nust come above add_library() call
# Use Build RPATH, don't skip it (usally Cmake would skip this by default)
set(CMAKE_SKIP_BUILD_RPATH FALSE)
#We are building, and let's not use the RPATH we wish to set
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
# RPATH is highest on the dynamic loader/linker search paths
set(CMAKE_INSTALL_RPATH $ORIGIN)
# Add automatic portions to RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif ()

add_library(${DUMMY_LIB} SHARED ${SOURCES})

# Must come after add_library() call
set_target_properties(${DUMMY_LIB} PROPERTIES PUBLIC_HEADER "${HEADERS}")

include(GNUInstallDirs)
install(TARGETS ${DUMMY_LIB}
  RUNTIME	DESTINATION	"${CMAKE_INSTALL_BINDIR}"
            COMPONENT	${DUMMY_LIB}_Runtime
  LIBRARY	DESTINATION	"${CMAKE_INSTALL_LIBDIR}"
            COMPONENT	${DUMMY_LIB}_Runtime
            NAMELINK_COMPONENT	Development
  ARCHIVE	DESTINATION	"${CMAKE_INSTALL_LIBDIR}"
            COMPONENT	${DUMMY_LIB}_Development
  PUBLIC_HEADER	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${DUMMY_LIB}"
)
target_compile_features(${DUMMY_LIB} PUBLIC cxx_std_17)

# CPP_APP
set(DUMMY_APP "dummy-app-cpp")

file(GLOB APP_SRCS "cpp_app/*.cpp")
add_executable("${DUMMY_APP}" ${APP_SRCS})

target_link_libraries(${DUMMY_APP}
  PRIVATE ${DUMMY_LIB}
)


# C_APP
set(DUMMY_APP_C "c-dummy-app")

file(GLOB C_APP_SRCS "c_app/*.c")
add_executable("${DUMMY_APP_C}" ${C_APP_SRCS})

target_link_libraries(${DUMMY_APP_C}
  PRIVATE ${DUMMY_LIB}
)
