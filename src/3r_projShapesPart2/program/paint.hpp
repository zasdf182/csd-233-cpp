#ifndef MAIN_PROGRAM_PAINT
#define MAIN_PROGRAM_PAINT
#include "ctx.hpp"
#include "../define/app.hpp"
#include "../modules/draw.hpp"
#include <cmath>
#include <cstdlib>
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws selected shapes with random positions, sizes, and colors.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawShapes(Context* context);

}
#endif
