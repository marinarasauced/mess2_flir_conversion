
#include "mess2_flir_conversions/conversions.hpp"

namespace mess2_flir_conversions
{
    cv::Mat get_frame(const std::string& path_file)
    {
        // read image file
        cv::Mat image = cv::imread(path_file, cv::IMREAD_UNCHANGED);
        
        // return cv image
        return image;
    }

    double convert_pixel_to_temperature(const double& pixel, const double& c1, const double& c2)
    {
        double temperature;
        temperature = pixel * c1 + c2;
        return temperature;
    }

    void convert_frame_to_thermal_map(const cv::Mat& image, const double& c1, const double& c2)
    {
        // check if image is empty
        if (image.empty()) {
            throw std::runtime_error("image cannot be empty");
        }

        //
        const auto n_cols = image.cols;
        const auto n_rows = image.rows;
        std::vector<double> thermal;

        //
        for (auto iter = 0; iter < n_cols; ++iter) {
            for (auto jter = 0; jter < n_rows; ++jter) {
                if (image.channels() == 1) {
                    double pixel = static_cast<double>(image.at<uchar>(iter, jter));
                    double temperature = convert_pixel_to_temperature(pixel, c1, c2);
                    std::cout << temperature << std::endl;
                    thermal.push_back(temperature);
                } else if (image.channels() == 3) {
                    // not currently supported
                }
            }
        }
    }

} // namespace mess2_flir_conversions
