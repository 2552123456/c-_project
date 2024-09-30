cmake_minimum_required(VERSION 3.10)
project(VideoProcessingApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# הגדרת מיקום OpenCV
set(OpenCV_DIR "C:/opencv/build/x64/vc16")

# חיפוש חבילת OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include)  # הוספת תיקיית include

# הוספת קבצים 
add_executable(VideoProcessingApp 
    src/main.cpp 
    src/video_processor.cpp 
)

# קישור לספריות
target_link_libraries(VideoProcessingApp ${OpenCV_LIBS})
