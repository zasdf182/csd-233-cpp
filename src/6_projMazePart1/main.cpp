#include "modules/draw/maze.cpp"
#include "modules/draw/mazeSquare.cpp"
#include "modules/draw/square.cpp"
#include "modules/manager/engine.cpp"
#include "program/init.cpp"
#include "program/draw.cpp"
#include "program/buildMaze.cpp"
#include "main.hpp"
using namespace std;
using namespace cv;
using namespace Draw;

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a grid of MazeSquares.
////////////////////////////////////////////////////////////////////////////////
int main() {
    Main::Program engine;
    engine.Actions[Main::ExitCode::quit] = Main::CollectGarbage;
    engine.Actions[Main::ExitCode::initContext] = Main::InitContext;
    engine.Actions[Main::ExitCode::drawGrid] = Main::DrawGrid;
    engine.Actions[Main::ExitCode::editGrid] = Main::EditGrid;

    srand(0xA455);
    engine.Start(Main::InitContext);
    waitKey(engine.CurrentState->wndUpdatePeriod);
    return 0;
}
