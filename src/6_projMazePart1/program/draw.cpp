#include "draw.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Draws a grid of MazeSquares.
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
    engine.Actions[BuildMaze::ExitCode::loopInit] = BuildMaze::QueueRandomSquares;

    engine.Actions[BuildMaze::ExitCode::searchRandomUniqueChoice] = BuildMaze::ChooseRandomNeighbor;
    engine.Actions[BuildMaze::ExitCode::validateChoicePartOne] = BuildMaze::CheckNeighborBounds;
    engine.Actions[BuildMaze::ExitCode::validateChoicePartTwo] = BuildMaze::CheckNeighborVisited;
    engine.Actions[BuildMaze::ExitCode::parseValidatedChoice] = BuildMaze::RemoveNeighborWall;

    engine.Actions[BuildMaze::ExitCode::loopAdvance] = BuildMaze::PopQueue;
    engine.Actions[BuildMaze::ExitCode::loopReset] = BuildMaze::ResetContext;
    engine.Actions[BuildMaze::ExitCode::loopStart] = BuildMaze::SelectQueueFront;

    engine.Start(BuildMaze::QueueRandomSquares);
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::drawGrid;
}
}
