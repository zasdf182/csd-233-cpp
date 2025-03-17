#include "main.hpp"
#include "main/inline.cpp"
#include "main/modules.cpp"
#include "main/program.cpp"
using namespace std;
using namespace Main;

////////////////////////////////////////////////////////////////////////////////
/// @brief Parses up to eight command line arguments.
///        Each argument should be a C string with a shape name to draw.
///        Allowed: nullptr, "circle", "ellipse", "rectangle", "triangle", "line"
///        Draws a shape on-screen for each argument.
///        Each shape will have a random size, position, and color.
///        Each shape will fit on the screen and will not overlap.
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
    Program engine;

    // Combine all command line arguments into a C string.
    // Hash the C string and use it to seed rand().
    vector<char> buffer;
    char* argsConcat;

    for (int i = 1; i < argc; i++)
        for (int j = 0; j < strlen(*(argv + i)); j++)
            buffer.insert(buffer.end(), *(*(argv + i) + j));

    argsConcat = new char[buffer.size() + 1];
    *(argsConcat + buffer.size()) = '\0';
    for (int i = 0; i < buffer.size(); i++)
        *(argsConcat + i) = buffer.at(i);

    long hash = hash_func_top_secret_government_cia_interpol_gign_sas_radioshack_circuitcity(argsConcat);
    srand(hash);
    delete[] argsConcat;

    // Get command line args. If less than 8, fill the rest with nullptrs.
    for (int i = 1; i < argc; i++) {
        char** insertionPoint = engine.CurrentState->shapeNames + i - 1;
        if (i > 8) break;
        if (i >= argc) *insertionPoint = nullptr;
        else *insertionPoint = *(argv + i);
    } engine.CurrentState->shapeCount = argc - 1;

    // Set up the program flow.
    engine.MapAction(ExitCode::quit, CollectGarbage);
    engine.MapAction(ExitCode::initContext, InitContext);
    engine.MapAction(ExitCode::drawGrid, DrawGrid);
    engine.MapAction(ExitCode::drawShapes, DrawShapes);

    // Run the program.
    engine.Start(InitContext);
    return 0;
}
