#ifndef MAIN_PROGRAM_PAINT
#define MAIN_PROGRAM_PAINT
#include "ctx.hpp"
#include "../define/app.hpp"
#include "../modules/draw.hpp"
#include "../inline/cstr.hpp"
#include "../inline/render.hpp"
#include <cmath>
#include <cstdlib>
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Divides the screen into a grid of rects, with one cell per shape.
///        There may be empty cells, depending on the number of shapes.
/// @note This is the second program step. Next is DrawShapes().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws selected shapes with random positions, sizes, and colors.
/// @note This is the third program step. Next is CollectGarbage().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawShapes(Context* context);

}
#endif
