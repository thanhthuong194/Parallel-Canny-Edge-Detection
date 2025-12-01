#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // 1. Tên file ảnh gốc
    std::string inputPath = "/home/thanhthuong/projects/canny-edge-detector/images/eso1723a.tif";
    // 2. Tên file output
    std::string outputPath = "/home/thanhthuong/projects/canny-edge-detector/images/eso_resized.jpg";

    cv::Mat img = cv::imread(inputPath);
    if(img.empty()){
        std::cout << "Không tìm thấy file!" << std::endl;
        return -1;
    }
    std::cout << "Resize....." << std::endl;
    cv::Mat resized_img;
    cv::resize(img, resized_img, cv::Size(13000, 13000));

    std::cout <<"Saving..." << std::endl;
    cv::imwrite(outputPath, resized_img);
    return 0;
}