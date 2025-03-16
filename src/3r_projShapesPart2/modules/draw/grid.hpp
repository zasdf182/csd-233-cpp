#ifndef LIB_DRAW_GRID
#define LIB_DRAW_GRID
#include <string>
#include "include/opencv.hpp"
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
        int blue;
        int green;
        int red;
        int thickness;

    public: //Constructors and destructors.
        Grid(int x, int y, int width, int height, int rows, int cols, std::string wndName, cv::Mat raster):
            x(x), y(y), width(width), height(height), rows(rows), cols(cols),
            wndName(wndName), raster(raster),
            blue(255), green(255), red(255), thickness(2) {};

    private: //Forbidden copy constructor and assignment operator.
        Grid(const Grid&) = delete;
        Grid& operator=(const Grid&) = delete;

    public: //Math methods.
        int CellWidth() {return width / rows;}
        int CellHeight() {return height / cols;}
        int CellX(int row) {return x + row * CellWidth();}
        int CellY(int col) {return y + col * CellHeight();}
        cv::Point CellTopLeft(int row, int col) {return cv::Point(CellX(row), CellY(col));}
        cv::Point CellBotRight(int row, int col) {return cv::Point(CellX(row + 1), CellY(col + 1));}
        cv::Scalar Color() {return cv::Scalar(blue, green, red);}

    public: //OpenCV drawing methods.
        void Draw();
};
}
#endif
