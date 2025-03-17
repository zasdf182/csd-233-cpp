#ifndef LIB_DRAW_GRID
#define LIB_DRAW_GRID
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "include/opencv.hpp"
#include "inline/math.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D grid of rectangles to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of grid.
///        Width and Height = size of entire grid.
////////////////////////////////////////////////////////////////////////////////
class Grid {
    public: //Static properties.
        static const int lineType = cv::LINE_4;

    public: //Mutable properties.
        int x;
        int y;
        int width;
        int height;
        int rows;
        int cols;
        std::string wndName;
        cv::Mat raster;
        cv::Scalar lineColor;
        cv::Scalar eraseColor;
        int thickness;

    public: //Constructors and destructors.
        ~Grid() {}
        Grid(int x, int y, int width, int height, int rows, int cols, std::string wndName, cv::Mat raster):
            x(x), y(y), width(width), height(height), rows(rows), cols(cols),
            wndName(wndName), raster(raster),
            lineColor(cv::Scalar(255, 255, 255)), eraseColor(cv::Scalar(0, 0, 0)),
            thickness(2) {};

    private: //Forbidden copy constructor and assignment operator.
        Grid(const Grid&) = delete;
        Grid& operator=(const Grid&) = delete;

    public: //Math methods.
        int CellWidth() {return width / rows;}
        int CellHeight() {return height / cols;}
        int CellX(int col) {return x + col * CellWidth();}
        int CellY(int row) {return y + row * CellHeight();}
        int CellRandInX(int col) {return std::rand() % CellWidth() + CellX(col);}
        int CellRandInY(int row) {return std::rand() % CellHeight() + CellY(row);}
        int CellLerpX(int col, float t) {return lerp(CellX(col), CellX(col + 1), t);}
        int CellLerpY(int row, float t) {return lerp(CellY(row), CellY(row + 1), t);}
        cv::Point CellTopLeft(int col, int row) {return cv::Point(CellX(col), CellY(row));}
        cv::Point CellBotRight(int col, int row) {return cv::Point(CellX(col + 1), CellY(row + 1));}
        cv::Point CellRandIn(int col, int row) {return cv::Point(CellRandInX(col), CellRandInY(row));}
        int MinFromEdgeX(int col, int inX) {return std::min(inX - CellX(col), CellX(col + 1) - inX);}
        int MinFromEdgeY(int row, int inY) {return std::min(inY - CellY(row), CellY(row + 1) - inY);}
        int MinFromEdge(int col, int row, int inX, int inY) {return std::min(MinFromEdgeX(col, inX), MinFromEdgeY(row, inY));}
        int MaxFromEdgeX(int col, int inX) {return std::max(inX - CellX(col), CellX(col + 1) - inX);}
        int MaxFromEdgeY(int row, int inY) {return std::max(inY - CellY(row), CellY(row + 1) - inY);}
        int MaxFromEdge(int col, int row, int inX, int inY) {return std::max(MaxFromEdgeX(col, inX), MaxFromEdgeY(row, inY));}

    public: //OpenCV drawing methods.
        void Draw();
        void Erase();
};
}
#endif
