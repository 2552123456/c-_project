#ifndef VIDEO_PROCESSOR_H
#define VIDEO_PROCESSOR_H

#include <opencv2/opencv.hpp>
#include <string>

class VideoProcessor {
public:
    VideoProcessor(const std::string& filePath);
    void trim(double startSec, double endSec);
    void resize(int width, int height);
    void rotate(int angle);
    void addText(const std::string& text, const cv::Point& position);
    void applyGrayScale();

private:
    cv::VideoCapture cap;
    std::string inputFile;
    cv::Mat frame;
};

#endif // VIDEO_PROCESSOR_H
