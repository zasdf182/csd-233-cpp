#include "maze.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws a grid of MazeSquares.
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
            mazeSquares[row][col] = new Draw::MazeSquare(x, y, width, height);
            mazeSquares[row][col]->Draw(context->wndName, context->wndRaster);
        } return ExitCode::quit;
}
}
