#include "grid.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new grid to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Grid::Draw() {
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            cv::rectangle(raster, CellTopLeft(col, row), CellBotRight(col, row), lineColor, thickness, lineType);
    cv::imshow(wndName, raster);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a filled rectangle to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Grid::Erase() {
    cv::rectangle(raster, cv::Point(x, y), cv::Point(x + width, y + height), eraseColor, cv::FILLED, lineType);
    cv::imshow(wndName, raster);
}
}
