#include "mazeSquare.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new shape to an OpenCV raster matrix.
///        If marked as visited, paints a symbol in bottom left of shape.
///        If marked as selected, paints a symbol in bottom right of shape.
///        If not marked, erase previous symbol.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::Draw() {
    cv::Point topLeft(x, y);
    cv::Point topRight(x + width, y);
    cv::Point botRight(x + width, y + height);
    cv::Point botLeft(x, y + height);

    cv::Point symbol1_botLeft(x + padding, y + height - padding);
    cv::Point symbol1_topRight(x + padding + charSize(), y + height - padding - charSize());

    cv::Point symbol2_botLeft(x + width - padding - charSize(), y + height - padding);
    cv::Point symbol2_topRight(x + width - padding, y + height - padding - charSize());

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

    if (isVisited) cv::putText(raster, std::string(1, visitSymbol), symbol1_botLeft, font, fontScale, color, thickness, lineType);
    else cv::rectangle(raster, symbol1_botLeft, symbol1_topRight, eraseColor, thickness, lineType);

    if (isSelected) cv::putText(raster, std::string(1, selectSymbol), symbol1_botLeft, font, fontScale, color, thickness, lineType);
    else cv::rectangle(raster, symbol2_botLeft, symbol2_topRight, eraseColor, thickness, lineType);

    cv::imshow(wndname, raster);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Erases a side from the square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::RemoveSide(Side side) {
    switch (side) {
        case Side::Top: hasTop = false; break;
        case Side::Right: hasRight = false; break;
        case Side::Bottom: hasBottom = false; break;
        case Side::Left: hasLeft = false; break;
        default: return;
    } Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Adds a symbol to bottom-left of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::MarkVisited() {
    isVisited = true;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Adds a symbol to bottom-right of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::MarkSelected() {
    isSelected = true;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Removes symbol from bottom-right of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::MarkUnselected() {
    isSelected = false;
    Draw();
}
}
