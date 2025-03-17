#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
///        Sets the color of grid lines to invisible.
/// @note This is the second program step. Next is DrawShapes().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int div = std::ceil(std::sqrt(context->shapeCount));
    int x = 0 + WND_PAD;
    int y = 0 + WND_PAD;
    int width = WND_WIDTH - 2 * WND_PAD;
    int height = WND_HEIGHT - 2 * WND_PAD;
    cv::Scalar color(0, 0, 0);

    context->grid = new Draw::Grid(x, y, width, height, div, div, WND_NAME, context->wndRaster);
    context->grid->lineColor = color;
    context->grid->Erase();
    context->grid->Draw();

    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::drawShapes;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Parses up to eight command line arguments.
///        Each argument should be a C string with a shape name to draw.
///        Allowed: nullptr, "circle", "ellipse", "rectangle", "triangle", "line"
///
///        Draws a shape on-screen for each argument.
///        Each shape will have a random size, position, and color.
///        Each shape will fit on the screen and will not overlap.
///
/// @note This is the third program step. Next is CollectGarbage().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawShapes(Context* context) {
    char* c0 = *(context->shapeNames + 0);
    char* c1 = *(context->shapeNames + 1);
    char* c2 = *(context->shapeNames + 2);
    char* c3 = *(context->shapeNames + 3);
    char* c4 = *(context->shapeNames + 4);
    char* c5 = *(context->shapeNames + 5);
    char* c6 = *(context->shapeNames + 6);
    char* c7 = *(context->shapeNames + 7);
    displayShapes(context, 8, c0, c1, c2, c3, c4, c5, c6, c7);
    return ExitCode::quit;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs new shape objects in the cells of the context grid.
///        Records the new shape pointers in the context object.
/// @param n The number of variadic arguments passed to the function.
/// @param va_list Case-insensitive C strings of the shape names to construct.
///                Allowed: nullptr, "circle", "ellipse", "rectangle", "triangle", "line"
////////////////////////////////////////////////////////////////////////////////
void displayShapes(Context* context, int n, ...) {
    va_list args;
    va_start(args, n);
    int shapeIndex = 0;

    // Loop through args and draw each shape.
    for (int row = 0; row < context->grid->rows; row++) {
        for (int col = 0; col < context->grid->cols; col++) {
            if (shapeIndex >= context->shapeCount) {
                va_end(args);
                return;
            }

            // Get pointer increment amount for array of function pointers.
            char* shapeName = va_arg(args, char*);
            if (shapeName == nullptr) continue;
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
    }
    va_end(args);
}
}
