cmake_minimum_required(VERSION 3.10)

# שם הפרויקט
project(VideoProcessingApp)

# הוספת C++ סטנדרט
set(CMAKE_CXX_STANDARD 11)

# מציאת OpenCV
find_package(OpenCV REQUIRED)

# אם אתה עובד על מערכת לינוקס או אחרת תשתמש ב-PkgConfig, אם לא (כמו Windows), פשוט תשתמש בקבצי הספרייה הרגילים
if (WIN32)
    # הגדרת נתיב לספריות של GStreamer
    set(GSTREAMER_INCLUDE_DIRS "C:/gstreamer/1.0/msvc_x86_64/include/gstreamer-1.0")
    set(GSTREAMER_LIBRARIES "C:/gstreamer/1.0/msvc_x86_64/lib")
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GST REQUIRED gstreamer-1.0)
endif()

# הוספת קבצי המקור
add_executable(VideoProcessingApp src/main.cpp)

# קישור נגד OpenCV ו-GStreamer
target_include_directories(VideoProcessingApp PRIVATE ${GSTREAMER_INCLUDE_DIRS})
target_link_libraries(VideoProcessingApp ${OpenCV_LIBS} ${GSTREAMER_LIBRARIES})
