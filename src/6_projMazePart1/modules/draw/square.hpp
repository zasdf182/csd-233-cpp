#ifndef SQUARE_HPP
#define SQUARE_HPP
#include <string>
#include "include/opencv.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D shape to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
////////////////////////////////////////////////////////////////////////////////
class Square {
    public: //Static properties.
        static const int lineType = cv::LINE_4;

    public: //Mutable properties.
        int x;
        int y;
        int width;
        int height;
        std::string wndname;
        cv::Mat raster;
        int blue;
        int green;
        int red;
        int thickness;

    public: //Constructors and destructors.
        Square(int x, int y, int width, int height, std::string wndname, cv::Mat raster):
            x(x), y(y), width(width), height(height),
            wndname(wndname), raster(raster),
            blue(255), green(255), red(255), thickness(2) {};

    public: //OpenCV drawing methods.
        virtual void Draw();
};
}
#endif
