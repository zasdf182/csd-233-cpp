#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
/// @note This is the second program step. Next is DrawShapes().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int div = std::ceil(std::sqrt(context->shapeCount));
    context->grid = new Draw::Grid(0, 0, WND_WIDTH, WND_HEIGHT, div, div, WND_NAME, context->wndRaster);
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
    for (int row = 0; row < context->grid->rows; row++) {
        for (int col = 0; col < context->grid->cols; col++) {
            if (shapeIndex >= context->shapeCount)
                return ExitCode::quit;

            char* shapeName = *(context->shapeNames + shapeIndex);
            ToLower(shapeName);
            Draw::Types::Shape drawFuncIndex = GetShape(shapeName);

            int x = context->grid->CellRandInX(col);
            int y = context->grid->CellRandInY(row);
            int width = context->grid->MinFromEdgeX(col, x);
            int height = context->grid->MinFromEdgeY(row, y);
            cv::Mat raster = context->wndRaster;

            Draw::Sprite* shape = (*(context->drawShapeFuncs + drawFuncIndex))(x, y, width, height, raster);
            context->shapes.insert(context->shapes.begin(), shape);
            cv::waitKey(context->wndUpdatePeriod);
            shapeIndex++;
        }
    } return ExitCode::quit;
}
}
