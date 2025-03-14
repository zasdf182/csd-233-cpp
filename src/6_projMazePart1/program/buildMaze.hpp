#ifndef BUILDMAZE_HPP
#define BUILDMAZE_HPP
#include <queue>
#include <set>
#include "../include/opencv.hpp"
#include "../modules/manager/engine.hpp"
#include "../modules/draw/types/shapes.hpp"
#include "../modules/draw/mazeSquare.hpp"
#include "../modules/draw/maze.hpp"
namespace Main {
namespace BuildMaze {








////////////////////////////////////////////////////////////////////////////////
/// @brief An object used to pass data between steps of the BuildMaze subprogram.
////////////////////////////////////////////////////////////////////////////////
struct Context {
    Draw::Maze* maze;
    int wndUpdatePeriod;

    std::queue<Draw::MazeSquare*> squareQueue;
    std::queue<int> rowQueue;
    std::queue<int> colQueue;

    Draw::MazeSquare* selectedSquare;
    int selectedRow;
    int selectedCol;

    std::set<Draw::Side> uncheckedSides;
    Draw::MazeSquare* checkedSquare;
    Draw::Side checkedSide;
    int checkedRow;
    int checkedCol;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A status key to tell the BuildMaze subprogram the next step to visit.
////////////////////////////////////////////////////////////////////////////////
enum ExitCode {
    loopInit = -10,

    searchRandomUniqueChoice = 11,
    validateChoicePartOne = 12,
    validateChoicePartTwo = 13,
    parseValidatedChoice = 14,

    loopAdvance = 20,
    loopReset = 0,
    loopStart = 10,
    NIL = -2,
};

////////////////////////////////////////////////////////////////////////////////
/// @brief A singleton that drives the BuildMaze subprogram.
///        Executes a subprogram step that returns an exit code.
///        A map of exit codes determines the next subprogram step.
////////////////////////////////////////////////////////////////////////////////
typedef Singletons::Engine<Context, ExitCode> Program;








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
ExitCode QueueRandomSquares(Context* context);








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
ExitCode ChooseRandomNeighbor(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Checks if the chosen neighbor is within the maze boundaries.
///
///        If not, goes back to ChooseRandomNeighbor().
///        Otherwise, proceeds to CheckNeighborVisited().
////////////////////////////////////////////////////////////////////////////////
ExitCode CheckNeighborBounds(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Records the checked side's MazeSquare in the context object.
///        Checks if the chosen neighbor is already visited.
///
///        If it is, goes back to ChooseRandomNeighbor().
///        Otherwise, proceeds to RemoveNeighborWall().
////////////////////////////////////////////////////////////////////////////////
ExitCode CheckNeighborVisited(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Erases the wall between the selected square and the chosen neighbor.
///        Marks the neighbor as visited. In future loops, it will be skipped.
///        Finally, proceeds to PopQueue().
////////////////////////////////////////////////////////////////////////////////
ExitCode RemoveNeighborWall(Context* context);








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
ExitCode PopQueue(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Resets the context object if it was modified by past loops.
///        The loop then begins at SelectQueueFront().
////////////////////////////////////////////////////////////////////////////////
ExitCode ResetContext(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief A step of the BuildMaze subprogram.
///        Selects the next square at the front of the queue. Marks it selected.
///        Records it's pointer, row, and col, in the context object.
///        Pauses for the window update period.
///
///        This begins a loop that parses all randomly selected squares in queue.
///        The loop continues at ChooseRandomNeighbor().
////////////////////////////////////////////////////////////////////////////////
ExitCode SelectQueueFront(Context* context);
}
}
#endif
