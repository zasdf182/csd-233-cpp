#include "buildMaze.hpp"
namespace Main {
namespace BuildMaze {








////////////////////////////////////////////////////////////////////////////////
/// @brief Marks top left as visited. Removes it's left wall. Adds it to queue.
///        Removes right wall of bottom right.
/// @note Executed once at start.
/// @note Next: SelectQueueBack().
////////////////////////////////////////////////////////////////////////////////
ExitCode BeginMaze(Context* context) {
    Draw::MazeSquare* topLeft = context->maze->Grid()[0][0];
    Draw::MazeSquare* botRight = context->maze->Grid()[context->maze->Rows() - 1][context->maze->Cols() - 1];
    botRight->RemoveSide(Draw::Side::Right);

    topLeft->MarkVisited();
    cv::waitKey(context->wndUpdatePeriod);
    topLeft->RemoveSide(Draw::Side::Left);
    cv::waitKey(context->wndUpdatePeriod);

    context->squareQueue.push_back(topLeft);
    context->rowQueue.push_back(0);
    context->colQueue.push_back(0);
    context->selectedQueueEnd = QueueSelection::Back;
    return ExitCode::loopStartValid;
}








////////////////////////////////////////////////////////////////////////////////
/// @brief Selects back of queue. Pauses window.
/// @note Next: ResetContext().
////////////////////////////////////////////////////////////////////////////////
ExitCode SelectQueueBack(Context* context) {
    context->squareQueue.back()->MarkSelected();
    context->selectedSquare = context->squareQueue.back();
    context->selectedRow = context->rowQueue.back();
    context->selectedCol = context->colQueue.back();
    context->selectedQueueEnd = QueueSelection::Back;
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::loopConfigure;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Selects front of queue. Pauses window.
/// @note Next: ResetContext().
////////////////////////////////////////////////////////////////////////////////
ExitCode SelectQueueFront(Context* context) {
    context->squareQueue.front()->MarkSelected();
    context->selectedSquare = context->squareQueue.front();
    context->selectedRow = context->rowQueue.front();
    context->selectedCol = context->colQueue.front();
    context->selectedQueueEnd = QueueSelection::Front;
    cv::waitKey(context->wndUpdatePeriod);
    return ExitCode::loopConfigure;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Resets loop variables.
/// @note Next: ChooseRandomNeighbor().
////////////////////////////////////////////////////////////////////////////////
ExitCode ResetContext(Context* context) {
    context->checkedRow = -1;
    context->checkedCol = -1;
    context->checkedSide = Draw::Side::NIL;
    context->checkedSquare = nullptr;
    context->uncheckedSides = {
        Draw::Side::Top,
        Draw::Side::Right,
        Draw::Side::Bottom,
        Draw::Side::Left
    }; return ExitCode::searchRandomUniqueChoice;
}








////////////////////////////////////////////////////////////////////////////////
/// @brief Chooses random unchosen neighbor of selected square.
/// @note Next: CheckNeighborBounds().
/// @note Next: PopQueue() if all sides already chosen.
////////////////////////////////////////////////////////////////////////////////
ExitCode ChooseRandomNeighbor(Context* context) {
    if (context->uncheckedSides.size() <= 0)
        return ExitCode::loopAdvanceInvalid;

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
/// @brief Checks if chosen neighbor out of bounds.
/// @note Next: CheckNeighborVisited().
/// @note Back: ChooseRandomNeighbor() if check fails.
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
/// @brief Checks if chosen neighbor already visited.
/// @note Next: RemoveNeighborWall().
/// @note Back: ChooseRandomNeighbor() if check fails.
////////////////////////////////////////////////////////////////////////////////
ExitCode CheckNeighborVisited(Context* context) {
    context->checkedSquare = context->maze->Grid()[context->checkedRow][context->checkedCol];
    if (context->checkedSquare->IsVisited())
        return ExitCode::searchRandomUniqueChoice;
    return ExitCode::parseValidatedChoice;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Erases wall to neighbor. Marks it visited.
/// @note Next: PushQueue().
////////////////////////////////////////////////////////////////////////////////
ExitCode RemoveNeighborWall(Context* context) {
    context->selectedSquare->RemoveSide(context->checkedSide);
    context->checkedSquare->RemoveSide(Draw::MazeSquare::Opposite(context->checkedSide));
    context->checkedSquare->MarkVisited();
    return ExitCode::loopAdvanceValid;
}








////////////////////////////////////////////////////////////////////////////////
/// @brief Pauses window. Adds chosen neighbor to back of queue.
/// @note Next: SelectQueueBack().
////////////////////////////////////////////////////////////////////////////////
ExitCode PushQueue(Context* context) {
    cv::waitKey(context->wndUpdatePeriod);
    context->selectedSquare->MarkDeselected();
    context->squareQueue.push_back(context->checkedSquare);
    context->rowQueue.push_back(context->checkedRow);
    context->colQueue.push_back(context->checkedCol);
    return ExitCode::loopStartValid;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Pauses window. Removes selected square from back of queue.
///        Selected square could be at front or back.
/// @note Next: SelectQueueFront().
////////////////////////////////////////////////////////////////////////////////
ExitCode PopQueue(Context* context) {
    if (context->selectedQueueEnd == QueueSelection::Back) {
        context->squareQueue.pop_back();
        context->rowQueue.pop_back();
        context->colQueue.pop_back();
    } else {
        context->squareQueue.pop_front();
        context->rowQueue.pop_front();
        context->colQueue.pop_front();
    }

    context->selectedSquare->MarkDeselected();
    if (context->squareQueue.size() > 0)
        return ExitCode::loopStartInvalid;
    return ExitCode::NIL;
}
}
}
