#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <video_file>" << std::endl;
        return -1;
    }

    std::string videoFile = argv[1];
    cv::VideoCapture cap(videoFile);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video file " << videoFile << std::endl;
        return -1;
    }

    cv::Mat frame;
    int frameCount = 0;
    
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // הוספת טקסט על גבי הווידאו
        cv::putText(frame, "Frame: " + std::to_string(frameCount++), cv::Point(50, 50),
                    cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);

        // המרת הווידאו לגווני אפור
        cv::Mat grayFrame;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // הצגת הווידאו
        cv::imshow("Processed Video", grayFrame);

        // עצירה אחרי כל פריים כדי לראות את הווידאו
        if (cv::waitKey(30) >= 0) break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}

/* סיכום של הקוד הנוחכי הקוד מבצע פעולות פשוטות בזמן ההרצה אם שימוש ב OpenCV
 הקוד פותח את הקובץ 
 קורא אותו שלב אחרי שלב 
 מוסיף טקסט על כל פריים  ומוסיף את מספר הפריים
 משנה את הכל לגוון של אפור 
 ממתין אחרי כל פריים 30 מילישניות ועוצר אם לוחצים על מקש כל שהוא*/
