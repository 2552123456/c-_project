#include "video_processor.h"
#include <iostream>

VideoProcessor::VideoProcessor(const std::string& filePath) : inputFile(filePath) {
    cap.open(inputFile);
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file: " << inputFile << std::endl;
    }
}

void VideoProcessor::trim(double startSec, double endSec) {
    cap.set(cv::CAP_PROP_POS_MSEC, startSec * 1000);
    while (cap.read(frame) && cap.get(cv::CAP_PROP_POS_MSEC) <= endSec * 1000) {
        cv::imshow("Trimmed Video", frame);
        if (cv::waitKey(30) >= 0) break; // מפסיק אם לוחצים על מקש
    }
}

void VideoProcessor::resize(int width, int height) {
    while (cap.read(frame)) {
        cv::Mat resizedFrame;
        cv::resize(frame, resizedFrame, cv::Size(width, height));
        cv::imshow("Resized Video", resizedFrame);
        if (cv::waitKey(30) >= 0) break; // מפסיק אם לוחצים על מקש
    }
}

void VideoProcessor::rotate(int angle) {
    while (cap.read(frame)) {
        cv::Mat rotatedFrame;
        cv::rotate(frame, rotatedFrame, angle == 90 ? cv::ROTATE_90_CLOCKWISE : cv::ROTATE_90_COUNTERCLOCKWISE);
        cv::imshow("Rotated Video", rotatedFrame);
        if (cv::waitKey(30) >= 0) break; // מפסיק אם לוחצים על מקש
    }
}

void VideoProcessor::addText(const std::string& text, const cv::Point& position) {
    while (cap.read(frame)) {
        cv::putText(frame, text, position, cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);
        cv::imshow("Video with Text", frame);
        if (cv::waitKey(30) >= 0) break; // מפסיק אם לוחצים על מקש
    }
}

void VideoProcessor::applyGrayScale() {
    while (cap.read(frame)) {
        cv::Mat grayFrame;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
        cv::imshow("Grayscale Video", grayFrame);
        if (cv::waitKey(30) >= 0) break; // מפסיק אם לוחצים על מקש
    }
}
