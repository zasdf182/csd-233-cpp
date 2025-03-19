#ifndef PROGRAM_TYPES
#define PROGRAM_TYPES
#include <string>
#include "../../include/opencv.hpp"
#include "../../modules/manager/engine.hpp"
#include "../../modules/draw/maze.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief An object used to pass data between steps of the main program.
////////////////////////////////////////////////////////////////////////////////
struct Context {
    int wndWidth;
    int wndHeight;
    int wndChannelBitDepth;
    int wndUpdatePeriod;
    cv::Mat wndRaster;
    std::string wndName;

    int gridCols;
    int gridRows;
    int gridCellWidth;
    int gridCellHeight;
    Draw::Maze* maze;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A status key used to tell the main program which step to visit next.
////////////////////////////////////////////////////////////////////////////////
enum ExitCode {
    NIL = -2,
    quit = -1,
    initContext = 0,
    drawGrid = 1,
    editGrid = 2,
    clearVisited = 3,
    markDeadEnds = 4,
    markPath = 5,
    clearDeadEnds = 6,
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A singleton that drives the main program.
///        Executes a program step that returns an exit code.
///        A map of exit codes determines the next program step.
////////////////////////////////////////////////////////////////////////////////
typedef Singletons::Engine<Context, ExitCode> Program;
}
#endif
