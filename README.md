# Parallel Canny Edge Detection

This project is the major assignment for the Parallel Programming course at Hanoi University of Science and Technology (HUST). The goal is to optimize the performance of the Canny Edge Detection algorithm by applying parallel computing techniques (OpenMP, SIMD, etc.) so it can efficiently process very large images.

This implementation is based on the original sequential project by declancm: https://github.com/declancm/canny-edge-detector

## Team Members

| No. | Full Name | Student ID |
|:---:|:---|:---:|
| 1 | Le Thanh Thuong | 20241889E |
| 2 | Le Phuc Hai | 20241727E |
| 3 | Le Van Tung | 20250162E |
| 4 | Vu Ngoc Quan | 20250164E |

## Overview

- Language: C++ (C++17), CMake.
- Objective: Speed up Canny Edge Detection on very large images (e.g., 8K–13K).
- Main techniques: OpenMP for shared-memory parallelism, memory/cache optimizations, and selective SIMD where appropriate.

## Prerequisites

- OS: Linux (Ubuntu/WSL) or Windows.
- C++ compiler with C++17 support (g++ or clang).
- CMake 3.18 or newer.
- OpenCV (core and highgui modules) for image I/O.
- OpenMP (commonly available with g++/clang).

## Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/thanhthuong194/Parallel-Canny-Edge-Detection.git
cd Parallel-Canny-Edge-Detection
```

2. Create a build directory and compile:
```bash
mkdir -p build
cd build
cmake ..
make 
```

If CMake fails to find OpenCV, install it (for example on Ubuntu: `sudo apt install libopencv-dev`) or provide OpenCV_DIR to CMake:
```bash
cmake -DOpenCV_DIR=/path/to/opencv ..
```

## Usage

### 1) Preparing input images (resize_tool)
The project targets very large images. Prepare input by resizing your original large image:

- If resize_tool uses hardcoded paths (common in student projects), open `resize_tool.cpp`, set `inputPath` and `outputPath`, rebuild, and run:
```bash
./resize_tool
```

- If resize_tool accepts command-line arguments (check the source), use:
```bash
./resize_tool /path/to/original.jpg /path/to/resized.jpg WIDTH HEIGHT
```

### 2) Running the Canny benchmark
Configure `main.cpp` if necessary (update `readLocation` and `writeLocation` paths), then run:
```bash
./canny
```

Output:
- The program prints total execution time (milliseconds) to the console for benchmarking.
- The resulting edge image (white edges on black) is saved to the configured output path.

For repeatable benchmarks, run several iterations and compute averages. You can wrap runs in a shell script to automate.

## Optimization Strategy

- Baseline: measure sequential performance on large images to identify hotspots.
- Shared-memory parallelism: use OpenMP to parallelize independent loops (for example):
  - Gaussian blur
  - Grayscale conversion
  - Gradient (Sobel) computation
  - Parts of non-maximum suppression and thresholding when safe
- Memory/cache optimizations:
  - Improve access patterns to be cache-friendly.
  - Minimize unnecessary data copies.
- Optional: explore SIMD (vectorization) for heavy numeric kernels.

## Testing and Benchmarking

- Use very large input images to see meaningful speedups.
- Record times for the overall run and for individual stages if the code prints per-stage timings.
- Compare sequential vs parallel runs and vary thread counts (OMP_NUM_THREADS) to evaluate scaling.

## Project Structure (example)
- src/: C++ source files
- CMakeLists.txt: build configuration
- build/: build output (do not commit)
- data/: test images (optional)

## Attribution

This project is developed from: declancm/canny-edge-detector — https://github.com/declancm/canny-edge-detector

## Contact

For questions or help:
- Le Thanh Thuong — GitHub: https://github.com/thanhthuong194
