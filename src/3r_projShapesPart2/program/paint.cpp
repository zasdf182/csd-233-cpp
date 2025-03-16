#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int div = std::ceil(std::sqrt(context->shapeCount));
    context->grid = new Draw::Grid(0, 0, WND_WIDTH, WND_HEIGHT, div, div, WND_NAME, context->wndRaster);
    context->grid->Draw();

    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::drawShapes;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws selected shapes with random positions, sizes, and colors.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawShapes(Context* context) {
    for (int row = 0; row < context->grid->rows; row++) {
        for (int col = 0; col < context->grid->cols; col++) {
            if (context->shapes.size() >= context->shapeCount)
                return ExitCode::quit;

            // Test maximum size circle.
            int x = context->grid->CellX(col);
            int y = context->grid->CellY(row);
            int width = context->grid->CellWidth();
            int height = context->grid->CellHeight();

            // Draw shape.
            Draw::Circle* circle = new Draw::Circle(x, y, width, height, WND_NAME, context->wndRaster);
            context->shapes.insert(context->shapes.begin(), circle);
            circle->Draw();

            // Pause before drawing next shape.
            cv::waitKey(context->wndUpdatePeriod);
        }
    } return ExitCode::quit;
}
}
