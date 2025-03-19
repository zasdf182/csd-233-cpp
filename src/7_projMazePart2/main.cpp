#include "modules/manager/engine.cpp"
#include "modules/all/draw.cpp"
#include "program/all/actions.cpp"
#include "main.hpp"
using namespace std;
using namespace cv;
using namespace Draw;

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a new maze and solves it. Loops endlessly.
////////////////////////////////////////////////////////////////////////////////
int main() {
    srand(0xA455);
    Main::Program engine;
    engine.Actions[Main::ExitCode::quit] = Main::CollectGarbage;
    engine.Actions[Main::ExitCode::initContext] = Main::InitContext;
    engine.Actions[Main::ExitCode::drawGrid] = Main::DrawGrid;
    engine.Actions[Main::ExitCode::editGrid] = Main::EditGrid;
    engine.Actions[Main::ExitCode::clearVisited] = Main::ClearVisited;
    engine.Actions[Main::ExitCode::markDeadEnds] = Main::MarkDeadEnds;
    engine.Actions[Main::ExitCode::markPath] = Main::MarkPath;
    engine.Actions[Main::ExitCode::clearDeadEnds] = Main::ClearDeadEnds;
    engine.Start(Main::InitContext);
}
