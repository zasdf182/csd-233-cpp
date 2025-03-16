#ifndef LIB_DRAW_RECT
#define LIB_DRAW_RECT
#include "sprite.hpp"
#include <cmath>
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D rectangle to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of rectangle.
////////////////////////////////////////////////////////////////////////////////
class Rect : public Sprite {
    public: //Constructors and destructors.
        virtual ~Rect() override {}
        Rect(int x, int y, int width, int height, std::string wndName, cv::Mat raster):
            Sprite(x, y, width, height, wndName, raster) {}

    private: //Forbidden copy constructor and assignment operator.
        Rect(const Rect&) = delete;
        Rect& operator=(const Rect&) = delete;

    public: //Math methods.
        int Min() {return std::min(width, height);}

    public: //OpenCV drawing methods.
        virtual void Draw() override;
};
}
#endif
