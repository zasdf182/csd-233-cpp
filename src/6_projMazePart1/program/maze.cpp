#include "maze.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws a grid of MazeSquares.
/// @note This is a temporary implementation for testing.
///       Refactor this into a Maze class later.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawMaze(Context* context) {
    int& rows = context->gridRows;
    int& cols = context->gridCols;
    Draw::MazeSquare* mazeSquares[rows][cols];

    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++) {
            int x = row * context->gridCellWidth;
            int y = col * context->gridCellHeight;
            int width = context->gridCellWidth;
            int height = context->gridCellHeight;
            std::string wndname = context->wndName;
            cv::Mat raster = context->wndRaster;
            mazeSquares[row][col] = new Draw::MazeSquare(x, y, width, height, wndname, raster);
            mazeSquares[row][col]->Draw();
        } return ExitCode::quit;
}
}
