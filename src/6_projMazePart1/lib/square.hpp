#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "include/opencv.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D shape to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
////////////////////////////////////////////////////////////////////////////////
class Square {
    public: //Constructors and destructors.
        Square(int x, int y, int width, int height):
            x(x), y(y), width(width), height(height),
            blue(255), green(255), red(255), thickness(2) {};

    public: //Static properties.
        static const int lineType = cv::LINE_8;

    public: //Mutable properties.
        int x;
        int y;
        int width;
        int height;
        int blue;
        int green;
        int red;
        int thickness;

    public: //OpenCV drawing methods.
        void Draw(std::string wndname, cv::Mat raster);
};
}
#endif
