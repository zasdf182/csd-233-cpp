#include "grid.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new grid to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Grid::Draw() {
    int cellWidth = width / rows;
    int cellHeight = height / cols;
    cv::Scalar color(blue, green, red);

    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++) {
            int cellX = x + row * cellWidth;
            int cellY = y + col * cellHeight;
            cv::Point topLeft(cellX, cellY);
            cv::Point botRight(cellX + cellWidth, cellY + cellHeight);
            cv::rectangle(raster, topLeft, botRight, color, thickness, lineType);
        } cv::imshow(wndName, raster);
}
}
