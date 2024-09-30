#include <opencv2/opencv.hpp>
#include "../include/video_processor.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_video>" << std::endl;
        return -1;
    }

    std::string inputFile = argv[1];
    VideoProcessor processor(inputFile);

    // חיתוך
    processor.trim(10, 20); // חותך בין 10 ל-20 שניות

    // שינוי גודל
    processor.resize(640, 480);

    // סיבוב
    processor.rotate(90);

    // הוספת טקסט
    processor.addText("שלום עולם!", cv::Point(50, 50));

    // הוספת פילטר גווני אפור
    processor.applyGrayScale();

    return 0;
}
