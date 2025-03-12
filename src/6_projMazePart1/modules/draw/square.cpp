#include "square.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new shape to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Square::Draw() {
    cv::Point topLeft(x, y);
    cv::Point botRight(x + width, y + height);
    cv::Scalar color(blue, green, red);
    cv::rectangle(raster, topLeft, botRight, color, thickness, lineType);
    cv::imshow(wndname, raster);
}
}
