#include "main.hpp"
#include "main/inline.cpp"
#include "main/modules.cpp"
#include "main/program.cpp"
using namespace std;
using namespace Main;

int main(int argc, char** argv) {
    if (argc <= 0) {
        cout << "ERROR: please run the program with command line arguments.";
        return 1;
    }

    Program engine;
    engine.CurrentState->argc = argc;
    engine.CurrentState->argv = argv;
    engine.Actions[ExitCode::quit] = CollectGarbage;
    engine.Actions[ExitCode::initContext] = InitContext;
    engine.Actions[ExitCode::drawGrid] = DrawGrid;
    engine.Actions[ExitCode::drawShapes] = DrawShapes;
    engine.Start(InitContext);
    return 0;
}
