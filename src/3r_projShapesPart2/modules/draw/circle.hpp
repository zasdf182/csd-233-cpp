#ifndef LIB_DRAW_CIRCLE
#define LIB_DRAW_CIRCLE
#include "shape.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D circle to be written to an OpenCV raster matrix.
///        Is automatically drawn when constructed.
///        Is automatically erased when deconstructed.
////////////////////////////////////////////////////////////////////////////////
class Circle : Shape {
    public: //Constructors and destructors.
        Circle(int x, int y, int radius,
               cv::Scalar fillColor, cv::Scalar eraseColor,
               std::string wndName, cv::Mat raster):
            Shape(x, y, radius * 2, radius * 2, fillColor, eraseColor, wndName, raster) {}

    private: //Forbidden copy constructor and assignment operator.
        Circle(const Circle&) = delete;
        Circle& operator=(const Circle&) = delete;

    public: //Math methods.
        int Radius() {return width / 2;}

    protected: //OpenCV drawing methods.
        virtual void Draw() override;
        virtual void Erase() override;
};
}
#endif
