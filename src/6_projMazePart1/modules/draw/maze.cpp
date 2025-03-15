#include "maze.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructor that initializes a 2D array of MazeSquare pointers,
///        and calls Draw() on each MazeSquare.
////////////////////////////////////////////////////////////////////////////////
Maze::Maze(int rows, int cols, int cellWidth, int cellHeight, std::string wndName, cv::Mat raster):
    rows(rows), cols(cols), cellWidth(cellWidth), cellHeight(cellHeight),
    wndName(wndName), raster(raster) {

    // Create dynamic 2D array
    grid = new MazeSquare** [rows];
    for (int row = 0; row < rows; row++) {
        grid[row] = new MazeSquare*[cols];

        // Populate 2D array with new MazeSquare pointers.
        for (int col = 0; col < cols; col++) {
            int x = row * cellWidth;
            int y = col * cellHeight;
            grid[row][col] = new Draw::MazeSquare(x, y, cellWidth, cellHeight, wndName, raster);

            // For CSD233 assignment, demonstrate polymorphism by casting to Square* and calling Square::Draw().
            Square* squarePointer = (Square*) grid[row][col];
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
