#ifndef LIB_DRAW_ELLIPSE
#define LIB_DRAW_ELLIPSE
#include <cmath>
#include "shape.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D ellipse to be written to an OpenCV raster matrix.
///        The constructor sets the width and height of the bounding rect.
///        The rotated ellipse will fit perfectly inside the bounding rect.
///        Is automatically drawn when constructed.
///        Is automatically erased when deconstructed.
////////////////////////////////////////////////////////////////////////////////
class Ellipse : Shape {
    protected: //Encapsulated read-only properties.
        float rotationDeg;

    public: //Constructors and destructors.
        Ellipse(int x, int y, int boxWidth, int boxHeight, float rotationDeg,
                cv::Scalar fillColor, cv::Scalar eraseColor,
                std::string wndName, cv::Mat raster):
            Shape(x, y, boxWidth, boxHeight, fillColor, eraseColor, wndName, raster),
            rotationDeg(rotationDeg) {}

    private: //Forbidden copy constructor and assignment operator.
        Ellipse(const Ellipse&) = delete;
        Ellipse& operator=(const Ellipse&) = delete;

    public: //Math methods.
        cv::Size2f RotatedRectSize();
        cv::RotatedRect RotatedRect() {return cv::RotatedRect(Center(), RotatedRectSize(), rotationDeg);}

    protected: //OpenCV drawing methods.
        virtual void Draw() override;
        virtual void Erase() override;

    public: //Getters of encapsulated read-only properties.
        int RotationDeg() {return rotationDeg;}
};
}
#endif
