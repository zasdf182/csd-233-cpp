#include "maze.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructor that initializes a 2D array of MazeSquare pointers,
///        and calls Draw() on each MazeSquare.
////////////////////////////////////////////////////////////////////////////////
Maze::Maze(int cols, int rows, int cellWidth, int cellHeight, std::string wndName, cv::Mat raster):
    cols(cols), rows(rows), cellWidth(cellWidth), cellHeight(cellHeight),
    wndName(wndName), raster(raster) {

    // Create dynamic 2D array
    grid = new MazeSquare** [cols];
    for (int col = 0; col < cols; col++) {
        grid[col] = new MazeSquare*[rows];

        // Populate 2D array with new MazeSquare pointers.
        for (int row = 0; row < rows; row++) {
            int x = col * cellWidth;
            int y = row * cellHeight;
            grid[col][row] = new Draw::MazeSquare(x, y, cellWidth, cellHeight, wndName, raster);

            // For CSD233 assignment, demonstrate polymorphism by casting to Square* and calling Square::Draw().
            Square* squarePointer = (Square*) grid[col][row];
            squarePointer->Draw();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Destructor that deallocates 2D array of MazeSquare pointers.
////////////////////////////////////////////////////////////////////////////////
Maze::~Maze() {
    for (int i = 0; i < rows; i++)
        delete[] grid[i];
    delete[] grid;
}
}
