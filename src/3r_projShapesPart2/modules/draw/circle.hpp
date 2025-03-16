#ifndef LIB_DRAW_CIRCLE
#define LIB_DRAW_CIRCLE
#include "sprite.hpp"
#include <cmath>
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D circle to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of bounding rect.
///        Width and Height = size of bounding rect.
///        A circle touching at least two edges will be centered inside bounds.
////////////////////////////////////////////////////////////////////////////////
class Circle : public Sprite {
    public: //Constructors and destructors.
        virtual ~Circle() override {}
        Circle(int x, int y, int width, int height,
               std::string wndName, cv::Mat raster):
            Sprite(x, y, width, height, wndName, raster) {}

    private: //Forbidden copy constructor and assignment operator.
        Circle(const Circle&) = delete;
        Circle& operator=(const Circle&) = delete;

    public: //Math methods.
        int Min() {return std::min(width, height);}
        int Radius() {return Min() / 2;}

    public: //OpenCV drawing methods.
        virtual void Draw() override;
};
}
#endif
