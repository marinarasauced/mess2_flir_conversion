
#include "mess2_flir_conversions/conversions.hpp"
#include "mess2_flir_conversions/demo_frame.hpp"

namespace mess2_flir_conversions
{
FrameConversion::FrameConversion() : Node("frame_conversion")
{
    // declare parameters
    this->declare_parameter("mode_gain", "high");
    this->declare_parameter("path_frame", "/home/marinarasauced/Projets/test_ws/install/mess2_flir_conversions/share/mess2_flir_conversions/config/template.jpg");
    this->declare_parameter("units_temperature", "C");
    
    // retrieve parameters
    this->get_parameter("mode_gain", mode_gain_);
    this->get_parameter("path_frame", path_frame_);
    this->get_parameter("units_temperature", units_temperature_);

    // set attributes for temperature units and gain mode
    if (mode_gain_ == "high") {
        c1_ = 0.01;
    } else if (mode_gain_ == "low") {
        c1_ = 0.1;
    } else {
        throw std::runtime_error("mode_gain must be high or low");
    }

    if (units_temperature_ == "K") {
        c2_ = 0.0;
    } else if (units_temperature_ == "C") {
        c2_ = -273.15;
    } else {
        throw std::runtime_error("units_temperature must be K or C");
    }

    // execute node
    (void) execute(path_frame_);
}

void FrameConversion::execute(const std::string& path_frame)
{
    // get frame
    const auto image = get_frame(path_frame);

    // convert frame to thermal map
    (void) convert_frame_to_thermal_map(image, c1_, c2_);
}

} // namespace mess2_flir_conversions

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<mess2_flir_conversions::FrameConversion>();
    // rclcpp::spin(node)
    rclcpp::shutdown();
    return 0;
}
