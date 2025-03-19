#ifndef SUBPROGRAM_TYPES
#define SUBPROGRAM_TYPES
#include <deque>
#include <set>
#include "../../include/opencv.hpp"
#include "../../modules/all/draw.hpp"
#include "../../modules/manager/engine.hpp"
namespace Main {
namespace BuildMaze {

////////////////////////////////////////////////////////////////////////////////
/// @brief Tracks which end of the queue is currently selected by the subprogram.
///        It selects the back if an unvisited neighbor was found.
///        If not, it selects the front.
////////////////////////////////////////////////////////////////////////////////
enum QueueSelection {Front, Back};

////////////////////////////////////////////////////////////////////////////////
/// @brief An object used to pass data between steps of the BuildMaze subprogram.
////////////////////////////////////////////////////////////////////////////////
struct Context {
    Draw::Maze* maze;
    int wndUpdatePeriod;

    std::deque<Draw::MazeSquare*> squareQueue;
    std::deque<int> rowQueue;
    std::deque<int> colQueue;

    Draw::MazeSquare* selectedSquare;
    int selectedRow;
    int selectedCol;
    QueueSelection selectedQueueEnd;

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
    programInit = 0,

    loopStartValid = 11,
    loopStartInvalid = 12,
    loopConfigure = 13,

    searchRandomUniqueChoice = 21,
    validateChoicePartOne = 22,
    validateChoicePartTwo = 23,
    parseValidatedChoice = 24,

    loopAdvanceValid = 30,
    loopAdvanceInvalid = 31,

    NIL = -1,
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
