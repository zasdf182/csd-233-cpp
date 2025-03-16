#include "grid.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes a new grid to an OpenCV raster matrix.
///        Renders the final raster to an OpenCV window.
////////////////////////////////////////////////////////////////////////////////
void Grid::Draw() {
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            cv::rectangle(raster, CellTopLeft(col, row), CellBotRight(col, row), Color(), thickness, lineType);
    cv::imshow(wndName, raster);
}
}
