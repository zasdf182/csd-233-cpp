#ifndef LIB_DRAW_CIRCLE
#define LIB_DRAW_CIRCLE
#include "sprite.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D circle to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of circle.
////////////////////////////////////////////////////////////////////////////////
class Circle : Sprite {
    public: //Constructors and destructors.
        Circle(int x, int y, int radius,
               cv::Scalar fillColor, cv::Scalar eraseColor,
               std::string wndName, cv::Mat raster):
            Sprite(x, y, radius * 2, radius * 2, fillColor, eraseColor, wndName, raster) {}

    private: //Forbidden copy constructor and assignment operator.
        Circle(const Circle&) = delete;
        Circle& operator=(const Circle&) = delete;

    public: //Math methods.
        int Radius() {return width / 2;}

    protected: //OpenCV drawing methods.
        virtual void Draw() override;
};
}
#endif
