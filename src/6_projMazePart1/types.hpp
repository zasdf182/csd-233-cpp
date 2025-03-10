#ifndef MAIN_TYPES_HPP
#define MAIN_TYPES_HPP
#include <string>
#include "include/opencv.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief An object used to pass data between steps of the main program.
////////////////////////////////////////////////////////////////////////////////
struct Context {
    cv::Mat wndRaster;
    std::string wndName;
    int wndWidth;
    int wndHeight;
    int wndChannelBitDepth;
    int wndUpdatePeriod;
};
}
#endif
