#ifndef MAIN_PROGRAM_CTX
#define MAIN_PROGRAM_CTX
#include <string>
#include <vector>
#include "../modules/manager.hpp"
#include "../include/opencv.hpp"
#include "../modules/draw/grid.hpp"
#include "../modules/draw/sprite.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief An object used to pass data between steps of the main program.
////////////////////////////////////////////////////////////////////////////////
struct Context {
    char** shapeNames;
    int shapeCount;
    int wndUpdatePeriod;
    cv::Mat wndRaster;

    typedef Draw::Sprite* (DrawFunc)(int x, int y, int width, int height, cv::Mat raster, cv::Scalar color);
    DrawFunc** drawShapeFuncs;

    Draw::Grid* grid;
    std::vector<Draw::Sprite*> shapes;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A status key used to tell the main program which step to visit next.
////////////////////////////////////////////////////////////////////////////////
enum ExitCode {
    NIL = -2,
    quit = -1,
    initContext = 0,
    drawGrid = 1,
    drawShapes = 2,
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A singleton that drives the main program.
///        Executes a program step that returns an exit code.
///        A map of exit codes determines the next program step.
////////////////////////////////////////////////////////////////////////////////
typedef Singletons::Engine<Context, ExitCode> Program;
}
#endif
