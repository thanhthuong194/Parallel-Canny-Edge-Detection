#include <iostream>
#include <chrono>
#include <vector>
#include "canny.h"

int main() {
    std::string readLocation = "/home/thanhthuong/projects/canny-edge-detector/images/eso_resized.jpg";
    std::string writeLocation = "/home/thanhthuong/projects/canny-edge-detector/images/eso_resized_Canny.jpg";
    double lowerThreshold = 0.03;
    double higherThreshold = 0.1;

    auto start = std::chrono::high_resolution_clock::now();
    cannyEdgeDetection(readLocation, writeLocation, lowerThreshold, higherThreshold);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Thoi gian chay: " << duration.count() << " ms" << std::endl;
    return 0;
}
