#ifndef MAIN_FUNCS_HPP
#define MAIN_FUNCS_HPP
#include <tuple>
#include <queue>
#include <set>
#include "../modules/draw/types/shapes.hpp"
#include "../modules/draw/maze.hpp"
#include "../program.hpp"
#include "buildMaze.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws a grid of MazeSquares.
///        Proceeds to EditGrid(), which will loop back to this, in an endless loop.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief A subprogram that randomly erases MazeSquare sides to build a maze.
///        Loops back to DrawGrid(), in an endless loop.
////////////////////////////////////////////////////////////////////////////////
ExitCode EditGrid(Context* context);
}
#endif
