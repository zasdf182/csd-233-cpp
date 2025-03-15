#include "ellipse.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Calculates the size and width of the rotated bounding rect.
///        This rotated rect fits entirely within the original bounding rect.
////////////////////////////////////////////////////////////////////////////////
cv::Size2f Ellipse::RotatedRectSize() {
    float rotationRad = rotationDeg * M_PI / 180;
    float unscaledWidth =
        width * std::abs(std::cos(rotationRad)) +
        height * std::abs(std::sin(rotationRad));
    float unscaledHeight =
        width * std::abs(std::sin(rotationRad)) +
        height * std::abs(std::cos(rotationRad));
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
