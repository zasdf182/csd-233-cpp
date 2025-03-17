#ifndef LIB_DRAW_ELLIPSE
#define LIB_DRAW_ELLIPSE
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include "sprite.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief A 2D ellipse to be written to an OpenCV raster matrix.
///        Set properties then call Draw() to render to window.
///        X and Y = top left of ellipse.
///        Width and Height = size of bounding rect.
////////////////////////////////////////////////////////////////////////////////
class Ellipse : public Sprite {
    protected: //Encapsulated read-only properties.
        float rotationDeg;

    public: //Constructors and destructors.
        virtual ~Ellipse() override {}
        Ellipse(int x, int y, int width, int height, float rotationDeg,
                std::string wndName, cv::Mat raster):
            Sprite(x, y, width, height, wndName, raster),
            rotationDeg(rotationDeg) {}

    private: //Forbidden copy constructor and assignment operator.
        Ellipse(const Ellipse&) = delete;
        Ellipse& operator=(const Ellipse&) = delete;

    public: //Math methods.
        float RotationRad() {return rotationDeg * M_PI / 180;}
        cv::Size2f RotatedRectSize();
        cv::RotatedRect RotatedRect() {return cv::RotatedRect(Center(), RotatedRectSize(), rotationDeg);}

    public: //OpenCV drawing methods.
        virtual void Draw() override;

    public: //Getters of encapsulated read-only properties.
        int RotationDeg() {return rotationDeg;}
};
}
#endif
