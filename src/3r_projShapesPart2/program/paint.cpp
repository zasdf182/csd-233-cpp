#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
/// @note This is the second program step. Next is DrawShapes().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int div = std::ceil(std::sqrt(context->shapeCount));
    int x = 0 + WND_PAD;
    int y = 0 + WND_PAD;
    int width = WND_WIDTH - 2 * WND_PAD;
    int height = WND_HEIGHT - 2 * WND_PAD;
    context->grid = new Draw::Grid(x, y, width, height, div, div, WND_NAME, context->wndRaster);
    context->grid->Erase();
    context->grid->Draw();

    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::drawShapes;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws selected shapes with random positions, sizes, and colors.
/// @note This is the third program step. Next is CollectGarbage().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawShapes(Context* context) {
    int shapeIndex = 0;

    // Loop through argv and draw each shape.
    for (int row = 0; row < context->grid->rows; row++) {
        for (int col = 0; col < context->grid->cols; col++) {
            if (shapeIndex >= context->shapeCount)
                return ExitCode::quit;

            // Get pointer increment amount for array of function pointers.
            char* shapeName = *(context->shapeNames + shapeIndex);
            ToLower(shapeName);
            Draw::Types::Shape drawFuncIndex = GetShape(shapeName);

            // Get random position and size.
            int x = context->grid->CellRandInX(col);
            int y = context->grid->CellRandInY(row);
            int width = context->grid->MinFromEdgeX(col, x);
            int height = context->grid->MinFromEdgeY(row, y);
            cv::Mat raster = context->wndRaster;

            // Get random color.
            int blue = rand() % 255;
            int green = rand() % 255;
            int red = rand() % 255;
            cv::Scalar color(blue, green, red);

            // Find draw func in array of function pointers. Draw then pause.
            Draw::Sprite* shape = (*(context->drawShapeFuncs + drawFuncIndex))(x, y, width, height, raster, color);
            context->shapes.insert(context->shapes.begin(), shape);
            cv::waitKey(context->wndUpdatePeriod);
            shapeIndex++;
        }
    } return ExitCode::quit;
}
}
