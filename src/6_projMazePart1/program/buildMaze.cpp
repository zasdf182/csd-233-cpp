#include "buildMaze.hpp"
namespace Main {
namespace BuildMaze {








////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Randomly picks squares to erase walls from.
///        The same square can be picked multiple times.
///        Stores the square and it's row and col in queues, with matching indices.
///
///        This is an initialization step. After, the subprogram loops.
///        The loop is initialized/advanced at ResetContext().
///        Then, the loop begins at SelectQueueFront().
////////////////////////////////////////////////////////////////////////////////
ExitCode QueueRandomSquares(Context* context) {
    int rows = context->maze->Rows();
    int cols = context->maze->Cols();
    int iterations = rows * cols * 2;

    for (int i = 0; i < iterations; i++) {
        int randRow = std::rand() % rows;
        int randCol = std::rand() % cols;
        Draw::MazeSquare* randSquare = context->maze->Grid()[randRow][randCol];
        context->squareQueue.push(randSquare);
        context->rowQueue.push(randRow);
        context->colQueue.push(randCol);
    } return ExitCode::loopReset;
}








////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Randomly choose a neighbor to check that hasn't been chosen yet.
///        Neighbors must share a side (diagonals are not neighbors).
///        Record the neighbor's side, row, and col, in the context object.
///        Remove the chosen side from the tracker in the context object.
///
///        If all neighbors were already chosen, skips to PopQueue().
///        Otherwise, goes to CheckNeighborBounds() then CheckNeighborVisited().
////////////////////////////////////////////////////////////////////////////////
ExitCode ChooseRandomNeighbor(Context* context) {
    if (context->uncheckedSides.size() <= 0)
        return ExitCode::loopAdvance;

    std::set<Draw::Side>::iterator iter = context->uncheckedSides.begin();
    int randomIndex = rand() % context->uncheckedSides.size();
    for (int i = 0; i < randomIndex; i++) iter++;

    context->checkedSide = *iter;
    context->uncheckedSides.erase(iter);

    switch (context->checkedSide) {
        case Draw::Side::Top:
            context->checkedRow = context->selectedRow;
            context->checkedCol = context->selectedCol - 1;
            break;
        case Draw::Side::Right:
            context->checkedRow = context->selectedRow + 1;
            context->checkedCol = context->selectedCol;
            break;
        case Draw::Side::Bottom:
            context->checkedRow = context->selectedRow;
            context->checkedCol = context->selectedCol + 1;
            break;
        case Draw::Side::Left:
            context->checkedRow = context->selectedRow - 1;
            context->checkedCol = context->selectedCol;
            break;
        default: break;
    } return ExitCode::validateChoicePartOne;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Checks if the chosen neighbor is within the maze boundaries.
///
///        If not, goes back to ChooseRandomNeighbor().
///        Otherwise, proceeds to CheckNeighborVisited().
////////////////////////////////////////////////////////////////////////////////
ExitCode CheckNeighborBounds(Context* context) {
    if (context->checkedRow < 0)
        return ExitCode::searchRandomUniqueChoice;
    if (context->checkedRow >= context->maze->Rows())
        return ExitCode::searchRandomUniqueChoice;
    if (context->checkedCol < 0)
        return ExitCode::searchRandomUniqueChoice;
    if (context->checkedCol >= context->maze->Cols())
        return ExitCode::searchRandomUniqueChoice;
    return ExitCode::validateChoicePartTwo;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Records the checked side's MazeSquare in the context object.
///        Checks if the chosen neighbor is already visited.
///
///        If it is, goes back to ChooseRandomNeighbor().
///        Otherwise, proceeds to RemoveNeighborWall().
////////////////////////////////////////////////////////////////////////////////
ExitCode CheckNeighborVisited(Context* context) {
    int row = context->checkedRow;
    int col = context->checkedCol;
    context->checkedSquare = context->maze->Grid()[row][col];
    if (context->checkedSquare->IsVisited())
        return ExitCode::searchRandomUniqueChoice;
    return ExitCode::parseValidatedChoice;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Erases the wall between the selected square and the chosen neighbor.
///        Marks the neighbor as visited. In future loops, it will be skipped.
///        Finally, proceeds to PopQueue().
////////////////////////////////////////////////////////////////////////////////
ExitCode RemoveNeighborWall(Context* context) {
    context->selectedSquare->RemoveSide(context->checkedSide);
    context->checkedSquare->RemoveSide(Draw::MazeSquare::Opposite(context->checkedSide));
    context->checkedSquare->MarkVisited();
    return ExitCode::loopAdvance;
}








////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Pauses for the window update period.
///        Then, deselects and removes the selected square from the queue.
///
///        Then, if queue is not empty, advances the loop at ResetContext().
///        Otherwise, ends the subprogram by returning BuildMazeExitCode::NIL.
///
///        Visits this step when done operating on the selected square.
///        Waits for a delay before proceeding to the next subprogram step.
////////////////////////////////////////////////////////////////////////////////
ExitCode PopQueue(Context* context) {
    cv::waitKey(context->wndUpdatePeriod);
    context->selectedSquare->MarkDeselected();
    context->squareQueue.pop();
    context->rowQueue.pop();
    context->colQueue.pop();
    if (context->squareQueue.size() > 0)
        return ExitCode::loopReset;
    return ExitCode::NIL;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Resets the context object if it was modified by past loops.
///        The loop then begins at SelectQueueFront().
////////////////////////////////////////////////////////////////////////////////
ExitCode ResetContext(Context* context) {
    context->selectedSquare = nullptr;
    context->selectedRow = -1;
    context->selectedCol = -1;

    context->checkedRow = -1;
    context->checkedCol = -1;
    context->checkedSide = Draw::Side::NIL;
    context->checkedSquare = nullptr;
    context->uncheckedSides = {
        Draw::Side::Top,
        Draw::Side::Right,
        Draw::Side::Bottom,
        Draw::Side::Left
    }; return ExitCode::loopStart;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Selects the next square at the front of the queue. Mark it selected.
///        Records it's pointer, row, and col, in the context object.
///
///        This begins a loop that parses all randomly selected squares in queue.
///        The loop continues at ChooseRandomNeighbor().
////////////////////////////////////////////////////////////////////////////////
ExitCode SelectQueueFront(Context* context) {
    context->squareQueue.front()->MarkSelected();
    context->selectedSquare = context->squareQueue.front();
    context->selectedRow = context->rowQueue.front();
    context->selectedCol = context->colQueue.front();
    return ExitCode::searchRandomUniqueChoice;
}
}
}
