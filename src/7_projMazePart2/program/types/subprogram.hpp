#ifndef SUBPROGRAM_TYPES
#define SUBPROGRAM_TYPES
#include <queue>
#include <set>
#include "../../include/opencv.hpp"
#include "../../modules/all/draw.hpp"
#include "../../modules/manager/engine.hpp"
namespace Main {
namespace BuildMaze {

////////////////////////////////////////////////////////////////////////////////
/// @brief An object used to pass data between steps of the BuildMaze subprogram.
////////////////////////////////////////////////////////////////////////////////
struct Context {
    Draw::Maze* maze;
    int wndUpdatePeriod;

    std::queue<Draw::MazeSquare*> squareQueue;
    std::queue<int> rowQueue;
    std::queue<int> colQueue;

    Draw::MazeSquare* selectedSquare;
    int selectedRow;
    int selectedCol;

    std::set<Draw::Side> uncheckedSides;
    Draw::MazeSquare* checkedSquare;
    Draw::Side checkedSide;
    int checkedRow;
    int checkedCol;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A status key to tell the BuildMaze subprogram the next step to visit.
////////////////////////////////////////////////////////////////////////////////
enum ExitCode {
    loopInit = -10,

    searchRandomUniqueChoice = 11,
    validateChoicePartOne = 12,
    validateChoicePartTwo = 13,
    parseValidatedChoice = 14,

    loopAdvance = 20,
    loopReset = 0,
    loopStart = 10,
    NIL = -2,
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A singleton that drives the BuildMaze subprogram.
///        Executes a subprogram step that returns an exit code.
///        A map of exit codes determines the next subprogram step.
////////////////////////////////////////////////////////////////////////////////
typedef Singletons::Engine<Context, ExitCode> Program;
}
}
#endif
