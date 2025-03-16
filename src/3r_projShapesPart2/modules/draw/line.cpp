#include "line.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new line to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Line::Draw() {
    int lineThickness = 4;
    cv::Point topLeft(x, y);
    cv::Point botRight(x + width, y + height);
    cv::line(raster, topLeft, botRight, fillColor, lineThickness, lineType);
    cv::imshow(wndName, raster);
}
}
