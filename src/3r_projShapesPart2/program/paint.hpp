#ifndef MAIN_PROGRAM_PAINT
#define MAIN_PROGRAM_PAINT
#include "ctx.hpp"
#include "../define/app.hpp"
#include "../modules/draw.hpp"
#include "../inline/cstr.hpp"
#include "../inline/render.hpp"
#include <cmath>
#include <cstdlib>
#include <cstdarg>
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
/// @note This is the second program step. Next is DrawShapes().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context);

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
ExitCode DrawShapes(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs new shape objects in the cells of a grid.
/// @return A vector container of pointers to the new shape objects.
/// @param va_list Case-insensitive C strings of the shape names to construct.
///                Allowed: circle, ellipse, rectangle, triangle, line
////////////////////////////////////////////////////////////////////////////////
void displayShapes(Context* context, int n, ...);

}
#endif
