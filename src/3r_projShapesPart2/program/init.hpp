#ifndef MAIN_PROGRAM_INIT
#define MAIN_PROGRAM_INIT
#include "ctx.hpp"
#include "../include/opencv.hpp"
#include "../define/app.hpp"
#include "../modules/draw/types/shapes.hpp"
#include "../inline/render.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Initializes the main program's context object.
/// @note This is the first program step. Next is DrawGrid().
////////////////////////////////////////////////////////////////////////////////
ExitCode InitContext(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief Deallocates memory.
/// @note This is the fourth and last program step.
////////////////////////////////////////////////////////////////////////////////
ExitCode CollectGarbage(Context* context);
}
#endif
