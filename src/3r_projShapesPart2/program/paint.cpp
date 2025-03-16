#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int div = std::ceil(std::sqrt(context->argc));
    Draw::Grid grid(0, 0, WND_WIDTH, WND_HEIGHT, div, div, WND_NAME, context->wndRaster);
    grid.Draw();
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::drawShapes;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws selected shapes with random positions, sizes, and colors.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawShapes(Context* context) {
    // Draw::Circle circle()
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::quit;
}
}
