#include "render.hpp"

////////////////////////////////////////////////////////////////////////////////
/// @brief Get the enum equivalent of a shape string.
///        Has undefined behavior if there is no null character.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Types::Shape GetShape(char* shapeName) {
    Draw::Types::Shape output;
    char* buffer = Clone(shapeName);
    ToLower(buffer);

    char circle[] = "circle";
    char ellipse[] = "ellipse";
    char rectangle[] = "rectangle";
    char triangle[] = "triangle";
    char line[] = "line";

    if (Equals(buffer, circle)) output = Draw::Types::Shape::Circle;
    else if (Equals(buffer, ellipse)) output = Draw::Types::Shape::Ellipse;
    else if (Equals(buffer, rectangle)) output = Draw::Types::Shape::Rectangle;
    else if (Equals(buffer, triangle)) output = Draw::Types::Shape::Triangle;
    else if (Equals(buffer, line)) output = Draw::Types::Shape::Line;
    else output = Draw::Types::Shape::NIL;
    delete[] buffer;
    return output;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs a new Circle object and calls Draw().
/// @return A pointer to the new Circle object.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Sprite* DrawCircle(int x, int y, int width, int height, cv::Mat raster, cv::Scalar color) {
    Draw::Circle* circle = new Draw::Circle(x, y, width, height, WND_NAME, raster);
    circle->fillColor = color;
    circle->Draw();
    return circle;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs a new Ellipse object and calls Draw().
///        The ellipse is rotated 90 degrees.
/// @return A pointer to the new Ellipse object.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Sprite* DrawEllipse(int x, int y, int width, int height, cv::Mat raster, cv::Scalar color) {
    int rotationDeg = 90;
    Draw::Ellipse* ellipse = new Draw::Ellipse(x, y, width, height, rotationDeg, WND_NAME, raster);
    ellipse->fillColor = color;
    ellipse->Draw();
    return ellipse;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs a new Rect object and calls Draw().
/// @return A pointer to the new Rect object.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Sprite* DrawRect(int x, int y, int width, int height, cv::Mat raster, cv::Scalar color) {
    Draw::Rect* rect = new Draw::Rect(x, y, width, height, WND_NAME, raster);
    rect->fillColor = color;
    rect->Draw();
    return rect;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs a new Triangle object and calls Draw().
/// @return A pointer to the new Triangle object.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Sprite* DrawTriangle(int x, int y, int width, int height, cv::Mat raster, cv::Scalar color) {
    Draw::Triangle* triangle = new Draw::Triangle(x, y, width, height, WND_NAME, raster);
    triangle->fillColor = color;
    triangle->Draw();
    return triangle;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs a new Line object and calls Draw().
/// @return A pointer to the new Line object.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Sprite* DrawLine(int x, int y, int width, int height, cv::Mat raster, cv::Scalar color) {
    Draw::Line* line = new Draw::Line(x, y, width, height, WND_NAME, raster);
    line->fillColor = color;
    line->Draw();
    return line;
}
