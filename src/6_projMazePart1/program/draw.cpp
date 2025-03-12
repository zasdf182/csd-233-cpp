#include "draw.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws a grid of MazeSquares.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawMaze(Context* context) {
    int rows = context->gridRows;
    int cols = context->gridCols;
    int cellWidth = context->gridCellWidth;
    int cellHeight = context->gridCellHeight;
    std::string wndName = context->wndName;
    cv::Mat raster = context->wndRaster;

    Draw::Maze maze(rows, cols, cellWidth, cellHeight, wndName, raster);
    return ExitCode::quit;
}
}
