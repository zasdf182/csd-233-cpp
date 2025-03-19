#include "modules/manager/engine.cpp"
#include "modules/all/draw.cpp"
#include "program/all/actions.cpp"
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
