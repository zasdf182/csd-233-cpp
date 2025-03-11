#include "modules/draw/square.cpp"
#include "modules/draw/mazeSquare.cpp"
#include "modules/manager/engine.cpp"
#include "program/init.cpp"
#include "program/maze.cpp"
#include "main.hpp"
using namespace std;
using namespace cv;
using namespace Draw;

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a grid of MazeSquares.
////////////////////////////////////////////////////////////////////////////////
int main() {
    Main::Program engine;

    engine.Actions[Main::ExitCode::initContext] = Main::InitContext;
    engine.Actions[Main::ExitCode::drawMaze] = Main::DrawMaze;

    engine.Start(Main::InitContext);
    waitKey(engine.CurrentState->wndUpdatePeriod);
    return 0;
}
