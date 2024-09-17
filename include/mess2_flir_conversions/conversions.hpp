#ifndef MESS2_FLIR_CONVERSIONS_HPP
#define MESS2_FLIR_CONVERSIONS_HPP

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

#include </usr/include/opencv4/opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.hpp>

#include "rclcpp/rclcpp.hpp"

namespace mess2_flir_conversions
{
    /**
     * 
     */
    cv::Mat get_frame(const std::string& path_file);

    /**
     * 
     */
    double convert_pixel_to_temperature(const double& pixel, const double& c1, const double& c2);

    /**
     * 
     */
    void convert_frame_to_thermal_map(const cv::Mat& image, const double& c1, const double& c2);

} // namespace mess2_flir_conversions

#endif // MESS2_FLIR_CONVERSIONS_HPP