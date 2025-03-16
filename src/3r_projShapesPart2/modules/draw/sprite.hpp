#ifndef LIB_DRAW_SPRITE
#define LIB_DRAW_SPRITE
#include <string>
#include "include/opencv.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D sprite to be written to an OpenCV raster matrix.
///        X and Y = top left of shape.
///        Set properties then call Draw() to render to window.
////////////////////////////////////////////////////////////////////////////////
class Sprite {
    public: //Static properties.
        static const int thickness = cv::FILLED;
        static const int lineType = cv::LINE_8;

    protected: //Encapsulated read-only properties.
        int x;
        int y;
        int width;
        int height;
        std::string wndName;
        cv::Mat raster;
        cv::Scalar fillColor;
        cv::Scalar eraseColor;

    public: //Constructors and destructors.
        Sprite(int x, int y, int width, int height,
               cv::Scalar fillColor, cv::Scalar eraseColor,
               std::string wndName, cv::Mat raster):
            x(x), y(y), width(width), height(height),
            wndName(wndName), raster(raster),
            fillColor(fillColor), eraseColor(eraseColor) {}

    private: //Forbidden copy constructor and assignment operator.
        Sprite(const Sprite&) = delete;
        Sprite& operator=(const Sprite&) = delete;

    public: //Math methods.
        cv::Point Center() {return cv::Point((x + width) / 2, (y + height) / 2);}

    protected: //OpenCV drawing methods.
        virtual void Draw() = 0;

    public: //Getters of encapsulated read-only properties.
        int X() {return x;}
        int Y() {return y;}
        int Width() {return width;}
        int Height() {return height;}
        std::string WndName() {return wndName;}
        cv::Mat const& Raster() {return raster;}
        cv::Scalar const& FillColor() {return fillColor;}
        cv::Scalar const& EraseColor() {return eraseColor;}
};
}
#endif
