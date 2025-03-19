#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Overwrites the entire screen with a grid of MazeSquares.
///        Proceeds to EditGrid(), which will loop back to this, in an endless loop.
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int rows = context->gridRows;
    int cols = context->gridCols;
    int cellWidth = context->gridCellWidth;
    int cellHeight = context->gridCellHeight;
    std::string wndName = context->wndName;
    cv::Mat raster = context->wndRaster;

    context->maze = new Draw::Maze(rows, cols, cellWidth, cellHeight, wndName, raster);
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::editGrid;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A subprogram that randomly erases MazeSquare sides to build a maze.
///        Loops back to DrawGrid(), in an endless loop.
////////////////////////////////////////////////////////////////////////////////
ExitCode EditGrid(Context* context) {
    BuildMaze::Program engine;
    engine.CurrentState->maze = context->maze;
    engine.CurrentState->wndUpdatePeriod = context->wndUpdatePeriod;

    engine.Actions[BuildMaze::ExitCode::programInit] = BuildMaze::BeginMaze;

    engine.Actions[BuildMaze::ExitCode::loopStartValid] = BuildMaze::SelectQueueBack;
    engine.Actions[BuildMaze::ExitCode::loopStartInvalid] = BuildMaze::SelectQueueFront;
    engine.Actions[BuildMaze::ExitCode::loopConfigure] = BuildMaze::ResetContext;

    engine.Actions[BuildMaze::ExitCode::searchRandomUniqueChoice] = BuildMaze::ChooseRandomNeighbor;
    engine.Actions[BuildMaze::ExitCode::validateChoicePartOne] = BuildMaze::CheckNeighborBounds;
    engine.Actions[BuildMaze::ExitCode::validateChoicePartTwo] = BuildMaze::CheckNeighborVisited;
    engine.Actions[BuildMaze::ExitCode::parseValidatedChoice] = BuildMaze::RemoveNeighborWall;

    engine.Actions[BuildMaze::ExitCode::loopAdvanceValid] = BuildMaze::PushQueue;
    engine.Actions[BuildMaze::ExitCode::loopAdvanceInvalid] = BuildMaze::PopQueue;

    engine.Start(BuildMaze::BeginMaze);
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::drawGrid;
}
}
