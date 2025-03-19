#ifndef LIB_DRAW_LINE
#define LIB_DRAW_LINE
#include "sprite.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D line to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of line.
///        Width and Height = size of bounding rectangle.
////////////////////////////////////////////////////////////////////////////////
class Line : public Sprite {
    public: //Constructors and destructors.
        virtual ~Line() override {}
        Line(int x, int y, int width, int height, std::string wndName, cv::Mat raster):
            Sprite(x, y, width, height, wndName, raster) {}

    private: //Forbidden copy constructor and assignment operator.
        Line(const Line&) = delete;
        Line& operator=(const Line&) = delete;

    public: //OpenCV drawing methods.
        virtual void Draw() override;
};
}
#endif
