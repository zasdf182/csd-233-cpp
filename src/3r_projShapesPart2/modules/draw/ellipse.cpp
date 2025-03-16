#include "ellipse.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Calculates the size and width of the rotated bounding rect.
///        This rotated rect fits entirely within the original bounding rect.
////////////////////////////////////////////////////////////////////////////////
cv::Size2f Ellipse::RotatedRectSize() {
    float unscaledWidth =
        width * std::abs(std::cos(RotationRad())) +
        height * std::abs(std::sin(RotationRad()));
    float unscaledHeight =
        width * std::abs(std::sin(RotationRad())) +
        height * std::abs(std::cos(RotationRad()));
    float scaleFactor = std::min(width / unscaledWidth, height / unscaledHeight);
    return cv::Size2f(unscaledWidth * scaleFactor, unscaledHeight * scaleFactor);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new ellipse to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Ellipse::Draw() {

}
}
