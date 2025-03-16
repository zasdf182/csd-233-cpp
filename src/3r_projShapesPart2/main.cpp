#include "main.hpp"
#include "main/inline.cpp"
#include "main/modules.cpp"
#include "main/program.cpp"
using namespace std;
using namespace Main;

int main(int argc, char** argv) {
    // srand(0xA455);
    srand(333);
    if (argc <= 1) {
        cout << "ERROR: please run the program with command line arguments.";
        return 1;
    }

    Program engine;
    engine.CurrentState->shapeNames = argv + 1;
    engine.CurrentState->shapeCount = argc - 1;
    engine.MapAction(ExitCode::quit, CollectGarbage);
    engine.MapAction(ExitCode::initContext, InitContext);
    engine.MapAction(ExitCode::drawGrid, DrawGrid);
    engine.MapAction(ExitCode::drawShapes, DrawShapes);
    engine.Start(InitContext);
    return 0;
}
