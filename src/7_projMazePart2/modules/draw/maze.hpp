#ifndef MAZE_HPP
#define MAZE_HPP
#include <string>
#include "include/opencv.hpp"
#include "mazeSquare.hpp"
namespace Draw {

class Maze {
    private: //Encapsulated read-only properties.
        int rows;
        int cols;
        int cellWidth;
        int cellHeight;
        std::string wndName;
        cv::Mat raster;

    private: //Encapsulated properties. Read-only if const.
        MazeSquare*** grid;

    public: //Constructors and destructors.
        Maze(int cols, int rows, int cellWidth, int cellHeight, std::string wndName, cv::Mat raster);
        ~Maze();

    private: //Forbidden copy constructor and assignment operator.
        Maze(const Maze&) = delete;
        Maze& operator=(const Maze&) = delete;

    public: //Getters of encapsulated read-only properties.
        const int& Cols() {return cols;}
        const int& Rows() {return rows;}
        const int& CellWidth() {return cellWidth;}
        const int& CellHeight() {return cellHeight;}
        const std::string WndName() {return wndName;}
        const cv::Mat Raster() {return raster;}

        const int& Cols() const {return cols;}
        const int& Rows() const {return rows;}
        const int& CellWidth() const {return cellWidth;}
        const int& CellHeight() const {return cellHeight;}
        const std::string WndName() const {return wndName;}
        const cv::Mat Raster() const {return raster;}

    public: //Getters of encapsulated properties. Read-only if const.
        MazeSquare*** Grid() {return grid;}
        MazeSquare const* const* const* Grid() const {return grid;}
};
}
#endif
