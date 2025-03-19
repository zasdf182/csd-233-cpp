#include "init.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Initializes the main program's context object.
/// @note This is the first program step. Next is DrawGrid().
////////////////////////////////////////////////////////////////////////////////
ExitCode InitContext(Context* context) {
    context->wndUpdatePeriod = 4000;
    context->wndRaster = cv::Mat(cv::Size(WND_WIDTH, WND_HEIGHT), GFX_PALETTE);
    context->drawShapeFuncs = new Main::Context::DrawFunc*[5];
    *(context->drawShapeFuncs + Draw::Types::Shape::Circle) = DrawCircle;
    *(context->drawShapeFuncs + Draw::Types::Shape::Ellipse) = DrawEllipse;
    *(context->drawShapeFuncs + Draw::Types::Shape::Rectangle) = DrawRect;
    *(context->drawShapeFuncs + Draw::Types::Shape::Triangle) = DrawTriangle;
    *(context->drawShapeFuncs + Draw::Types::Shape::Line) = DrawLine;
    return ExitCode::drawGrid;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Deallocates memory.
/// @note This is the fourth and last program step.
////////////////////////////////////////////////////////////////////////////////
ExitCode CollectGarbage(Context* context) {
    delete[] context->drawShapeFuncs;
    delete context->grid;
    for (auto ptr : context->shapes) delete ptr;
    return ExitCode::NIL;
}
}
