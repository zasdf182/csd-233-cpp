#ifndef LIB_DRAW_TRIANGLE
#define LIB_DRAW_TRIANGLE
#include "sprite.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D triangle to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of bounding rectangle.
////////////////////////////////////////////////////////////////////////////////
class Triangle : public Sprite {
    public: //Constructors and destructors.
        virtual ~Triangle() override {}
        Triangle(int x, int y, int width, int height, std::string wndName, cv::Mat raster):
            Sprite(x, y, width, height, wndName, raster) {}

    private: //Forbidden copy constructor and assignment operator.
        Triangle(const Triangle&) = delete;
        Triangle& operator=(const Triangle&) = delete;

    public: //OpenCV drawing methods.
        virtual void Draw() override;
};
}
#endif
