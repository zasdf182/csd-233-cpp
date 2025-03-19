#include "paint.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Overwrites the entire screen with a grid of MazeSquares.
/// @note Start of endless loop.
/// @note Next: EditGrid().
////////////////////////////////////////////////////////////////////////////////
ExitCode DrawGrid(Context* context) {
    int cols = context->gridCols;
    int rows = context->gridRows;
    int cellWidth = context->gridCellWidth;
    int cellHeight = context->gridCellHeight;
    std::string wndName = context->wndName;
    cv::Mat raster = context->wndRaster;

    context->maze = new Draw::Maze(cols, rows, cellWidth, cellHeight, wndName, raster);
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::editGrid;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A subprogram that randomly erases MazeSquare sides to build a maze.
///        Pauses window after each erased side.
/// @note Next: SolveMaze().
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
    return ExitCode::clearVisited;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Clears 'visited' status from all squares. Pauses window.
/// @note Next: MarkDeadEnds().
////////////////////////////////////////////////////////////////////////////////
ExitCode ClearVisited(Context* context) {
    for (int row = 0; row < context->gridRows; row++)
        for (int col = 0; col < context->gridCols; col++)
            context->maze->Grid()[col][row]->UnmarkVisited();
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::markDeadEnds;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Loops through all squares in maze.
///        Marks dead all squares with only 1 side that isn't closed or dead.
///        If a square was found last loop cycle, repeats until none are found.
///        Pauses window after every marked square.
/// @note Next: MarkPath().
////////////////////////////////////////////////////////////////////////////////
ExitCode MarkDeadEnds(Context* context) {
    int cols = context->gridCols;
    int rows = context->gridRows;
    bool newDeadEndFound = false;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (context->maze->Grid()[col][row]->IsDead()) continue;
            int openSides = 4;

            bool atGridTop = row == 0;
            bool atGridLeft = col == 0;
            bool atGridBottom = row == rows - 1;
            bool atGridRight = col == cols - 1;

            Draw::MazeSquare* cell = context->maze->Grid()[col][row];
            Draw::MazeSquare* top = nullptr;
            Draw::MazeSquare* left = nullptr;
            Draw::MazeSquare* bottom = nullptr;
            Draw::MazeSquare* right = nullptr;

            if (!atGridTop) top = context->maze->Grid()[col][row - 1];
            if (!atGridLeft) left = context->maze->Grid()[col - 1][row];
            if (!atGridBottom) bottom = context->maze->Grid()[col][row + 1];
            if (!atGridRight) right = context->maze->Grid()[col + 1][row];

            if (cell->HasTop()) openSides--;
            else if (!atGridTop) if (top->IsDead()) openSides--;

            if (cell->HasRight()) openSides--;
            else if (!atGridRight) if (right->IsDead()) openSides--;

            if (cell->HasBottom()) openSides--;
            else if (!atGridBottom) if (bottom->IsDead()) openSides--;

            if (cell->HasLeft()) openSides--;
            else if (!atGridLeft) if (left->IsDead()) openSides--;

            if (openSides <= 1) {
                cell->MarkDead();
                newDeadEndFound = true;
                cv::waitKey(context->wndUpdatePeriod);
            }
        }
    }

    if (newDeadEndFound) return ExitCode::markDeadEnds;
    return ExitCode::markPath;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Marks the solved path. Pauses window after every marked square.
/// @note Next: ClearDeadEnds()
////////////////////////////////////////////////////////////////////////////////
ExitCode MarkPath(Context* context) {
    int col = 0;
    int row = 0;
    int endCol = context->gridCols - 1;
    int endRow = context->gridRows - 1;
    Draw::MazeSquare* current = context->maze->Grid()[col][row];
    Draw::MazeSquare* end = context->maze->Grid()[endCol][endRow];

    while (current != end) {
        current->MarkPathed();
        cv::waitKey(context->wndUpdatePeriod);

        bool atGridTop = row == 0;
        bool atGridLeft = col == 0;
        bool atGridBottom = row == endRow;
        bool atGridRight = col == endCol;

        Draw::MazeSquare* top = nullptr;
        Draw::MazeSquare* left = nullptr;
        Draw::MazeSquare* bottom = nullptr;
        Draw::MazeSquare* right = nullptr;

        if (!atGridTop) top = context->maze->Grid()[col][row - 1];
        if (!atGridLeft) left = context->maze->Grid()[col - 1][row];
        if (!atGridBottom) bottom = context->maze->Grid()[col][row + 1];
        if (!atGridRight) right = context->maze->Grid()[col + 1][row];

        if (!atGridTop)
            if (!current->HasTop())
                if (!top->IsPathed())
                    if (!top->IsDead()) {current = top; continue;}

        if (!atGridLeft)
            if (!current->HasLeft())
                if (!left->IsPathed())
                    if (!left->IsDead()) {current = left; continue;}

        if (!atGridBottom)
            if (!current->HasBottom())
                if (!bottom->IsPathed())
                    if (!bottom->IsDead()) {current = bottom; continue;}

        if (!atGridRight)
            if (!current->HasRight())
                if (!right->IsPathed())
                    if (!right->IsDead()) {current = right; continue;}
    }
    current->MarkPathed();
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::clearDeadEnds;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Clears 'dead' status from all squares. Pauses window for 3x time.
/// @note Loop Back To: DrawGrid().
////////////////////////////////////////////////////////////////////////////////
ExitCode ClearDeadEnds(Context* context) {
    for (int row = 0; row < context->gridRows; row++)
        for (int col = 0; col < context->gridCols; col++)
            context->maze->Grid()[col][row]->UnmarkDead();
    cv::waitKey(context->wndUpdatePeriod * 3);
    return ExitCode::drawGrid;
}
}
