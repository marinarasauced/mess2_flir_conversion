#ifndef MESS2_FLIR_CONVERSION_FRAME_HPP
#define MESS2_FLIR_CONVERSION_FRAME_HPP

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
class FrameConversion : public rclcpp::Node
{
public:
    /**
     * 
     */
    FrameConversion();

private:
    /**
     * 
     */
    void execute(const std::string& path_frame);

    std::string mode_gain_;
    std::string path_frame_;
    std::string units_temperature_;
    double c1_;
    double c2_;
};
} // namespace mess2_flir_conversions

#endif // MESS2_FLIR_CONVERSION_FRAME_HPP