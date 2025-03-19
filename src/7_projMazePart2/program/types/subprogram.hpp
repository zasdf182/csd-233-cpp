#ifndef subprogram_TYPES
#define subprogram_TYPES
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
    int tickRate;

    std::deque<Draw::MazeSquare*> squareQueue;
    std::deque<int> colQueue;
    std::deque<int> rowQueue;

    Draw::MazeSquare* selectedSquare;
    int selectedCol;
    int selectedRow;
    QueueSelection selectedQueueEnd;

    std::set<Draw::Side> uncheckedSides;
    Draw::MazeSquare* checkedSquare;
    Draw::Side checkedSide;
    int checkedCol;
    int checkedRow;
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
