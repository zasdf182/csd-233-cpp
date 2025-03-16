#include "rect.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new rectangle to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Rect::Draw() {
    cv::Point topLeft(x, y);
    cv::Point botRight(x + width, y + height);
    cv::rectangle(raster, topLeft, botRight, fillColor, thickness, lineType);
    cv::imshow(wndName, raster);
}
}
