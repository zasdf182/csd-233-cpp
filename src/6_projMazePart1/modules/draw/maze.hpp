#ifndef MAZE_HPP
#define MAZE_HPP
#include <string>
#include "include/opencv.hpp"
#include "mazeSquare.hpp"
namespace Draw {

class Maze {
    private: //Encapsulated read-only properties.
        MazeSquare*** grid;
        int rows;
        int cols;
        int cellWidth;
        int cellHeight;
        std::string wndName;
        cv::Mat raster;

    private: //Forbidden copy constructor.
        Maze(const Maze&) = delete;

    public: //Constructors and destructors.
        Maze(int rows, int cols, int cellWidth, int cellHeight, std::string wndName, cv::Mat raster);
        ~Maze();

    public: //Getters of encapsulated read-only properties.
        const MazeSquare* const* const* Grid() {return grid;}
        const int& Rows() {return rows;}
        const int& Cols() {return cols;}
        const MazeSquare* const* const* Grid() const {return grid;}
        const int& Rows() const {return rows;}
        const int& Cols() const {return cols;}
};
}
#endif
