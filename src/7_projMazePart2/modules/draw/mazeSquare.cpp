#include "mazeSquare.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Gets the opposite side of a side.
////////////////////////////////////////////////////////////////////////////////
const Side MazeSquare::Opposite(Side side) {
    switch (side) {
        case Side::Top: return Side::Bottom;
        case Side::Right: return Side::Left;
        case Side::Bottom: return Side::Top;
        case Side::Left: return Side::Right;
        default: return Side::NIL;
    }
}

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

    cv::Point botLeftChar(x + padding, y + height - padding);
    cv::Point botRightChar(x + width - padding - charSize(), y + height - padding);
    cv::Point topRightChar(x + width - padding - charSize(), y + padding + charSize());
    cv::Point topLeftChar(x + padding, y + padding + charSize());

    cv::Scalar color(blue, green, red);
    cv::Scalar eraseColor(eraseBlue, eraseGreen, eraseRed);
    cv::Scalar vc(visitBlue, visitGreen, visitRed);
    cv::Scalar sc(selectBlue, selectGreen, selectRed);
    cv::Scalar pc(pathBlue, pathGreen, pathRed);
    cv::Scalar dc(deadBlue, deadGreen, deadRed);

    std::string vsym = std::string(1, visitSymbol);
    std::string ssym = std::string(1, selectSymbol);
    std::string psym = std::string(1, pathSymbol);
    std::string dsym = std::string(1, deadSymbol);

    // To erase sides and symbols it does not have, erase entire square at start.
    cv::Rect eraseRect(x - thickness, y - thickness, width + thickness * 2, height + thickness * 2);
    cv::rectangle(raster, eraseRect, eraseColor, cv::FILLED, lineType);

    // Draw sides that the square still has.
    if (hasTop) cv::line(raster, topLeft, topRight, color, thickness, lineType);
    if (hasRight) cv::line(raster, topRight, botRight, color, thickness, lineType);
    if (hasBottom) cv::line(raster, botRight, botLeft, color, thickness, lineType);
    if (hasLeft) cv::line(raster, botLeft, topLeft, color, thickness, lineType);

    // Draw symbols that the square still has.
    if (isVisited) cv::putText(raster, vsym, botLeftChar, font, fontScale, vc, thickness, lineType);
    if (isSelected) cv::putText(raster, ssym, botRightChar, font, fontScale, sc, thickness, lineType);
    if (isPathed) cv::putText(raster, psym, topRightChar, font, fontScale, pc, thickness, lineType);
    if (isDead) cv::putText(raster, dsym, topLeftChar, font, fontScale, dc, thickness, lineType);

    // Render the final raster to the OpenCV window.
    cv::imshow(wndName, raster);
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
/// @brief Adds a symbol to top-right of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::MarkPathed() {
    isPathed = true;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Adds a symbol to top-left of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::MarkDead() {
    isDead = true;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Removes symbol from bottom-left of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::UnmarkVisited() {
    isVisited = false;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Removes symbol from bottom-right of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::UnmarkSelected() {
    isSelected = false;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Removes symbol from top-right of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::UnmarkPathed() {
    isPathed = false;
    Draw();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Removes symbol from top-left of square, and calls Draw() again.
////////////////////////////////////////////////////////////////////////////////
void MazeSquare::UnmarkDead() {
    isDead = false;
    Draw();
}
}
