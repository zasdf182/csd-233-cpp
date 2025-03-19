#include "circle.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new circle to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Circle::Draw() {
    cv::circle(raster, Center(), Radius(), fillColor, thickness, lineType);
    cv::imshow(wndName, raster);
}
}
