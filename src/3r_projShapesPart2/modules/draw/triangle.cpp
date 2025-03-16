#include "triangle.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new triangle to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Triangle::Draw() {
    const cv::Point points[3] = {
        cv::Point(x, y + height),
        cv::Point(x + width, y + height),
        cv::Point(x + width / 2, y)
    };
    cv::fillConvexPoly(raster, points, 3, fillColor, lineType);
    cv::imshow(wndName, raster);
}
}
