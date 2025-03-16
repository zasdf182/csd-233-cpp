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

    public: //Mutable properties.
        int x;
        int y;
        int width;
        int height;
        std::string wndName;
        cv::Mat raster;
        int blue;
        int green;
        int red;

    public: //Constructors and destructors.
        Sprite(int x, int y, int width, int height,
               std::string wndName, cv::Mat raster):
            x(x), y(y), width(width), height(height),
            wndName(wndName), raster(raster),
            blue(255), green(255), red(255) {}

    private: //Forbidden copy constructor and assignment operator.
        Sprite(const Sprite&) = delete;
        Sprite& operator=(const Sprite&) = delete;

    public: //Math methods.
        cv::Point Center() {return cv::Point((x + width) / 2, (y + height) / 2);}
        cv::Scalar Color() {return cv::Scalar(blue, green, red);}

    protected: //OpenCV drawing methods.
        virtual void Draw() = 0;
};
}
#endif
