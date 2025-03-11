#include "mazeSquare.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new shape to an OpenCV raster matrix.
///        If marked as visited, paints a symbol in bottom left of shape.
///        If marked as selected, paints a symbol in bottom right of shape.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::Draw(std::string wndname, cv::Mat raster) {
    cv::Point topLeft(x, y);
    cv::Point topRight(x + width, y);
    cv::Point botRight(x + width, y + height);
    cv::Point botLeft(x, y + height);

    cv::Point symbolPoint1(x + padding, y + height - padding);
    cv::Point symbolPoint2(x + width - padding - charWidth(), y + height - padding);

    cv::Scalar color(blue, green, red);
    cv::Scalar eraseColor(eraseBlue, eraseGreen, eraseRed);

    if (hasTop) cv::line(raster, topLeft, topRight, color, thickness, lineType);
    else cv::line(raster, topLeft, topRight, eraseColor, thickness, lineType);

    if (hasRight) cv::line(raster, topRight, botRight, color, thickness, lineType);
    else cv::line(raster, topRight, botRight, eraseColor, thickness, lineType);

    if (hasBottom) cv::line(raster, botRight, botLeft, color, thickness, lineType);
    else cv::line(raster, botRight, botLeft, eraseColor, thickness, lineType);

    if (hasLeft) cv::line(raster, botLeft, topLeft, color, thickness, lineType);
    else cv::line(raster, botLeft, topLeft, eraseColor, thickness, lineType);

    if (isVisited) cv::putText(raster, std::string(1, visitSymbol), symbolPoint1, font, fontScale, color, thickness, lineType);
    if (isSelected) cv::putText(raster, std::string(1, selectSymbol), symbolPoint2, font, fontScale, color, thickness, lineType);

    cv::imshow(wndname, raster);
}
}
