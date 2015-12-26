cmake_minimum_required (VERSION 2.8) 
project (camdisplay)
set(CMAKE_MODULE_PATH "/usr/local/lib/cmake/${CMAKE_MODULE_PATH}")
find_package(raspicam REQUIRED)

find_path (BCM2835_INCLUDE_DIR bcm2835.h )
find_library (BCM2835_LIBRARY NAMES bcm2835)
include_directories (/opt/vc/include/interface)
include_directories (/opt/vc/include/interface/vcos)
include_directories (/opt/vc/include/interface/vcos/pthreads)
include_directories (/opt/vc/include)
link_directories (/opt/vc/lib)

add_executable (camdisplay camdisplay.cpp RAIO8870.cpp tft.cpp raspicam_still.cpp)
target_link_libraries (camdisplay ${BCM2835_LIBRARY})
target_link_libraries (camdisplay ${raspicam_LIBS})

target_link_libraries (camdisplay mmal mmal_core mmal_util)
