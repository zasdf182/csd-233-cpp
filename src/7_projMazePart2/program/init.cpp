#include "init.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Initializes the main program's context object.
///        Change values to customize the program.
////////////////////////////////////////////////////////////////////////////////
ExitCode InitContext(Context* context) {
    context->wndName = "TurtleWindow";

    context->tickRate = 5;
    context->endDelay = 4000;

    context->wndWidth = 800;
    context->wndHeight = 800;

    context->gridCols = 20;
    context->gridRows = 20;

    context->gridCellWidth = context->wndWidth / context->gridCols;
    context->gridCellHeight = context->wndHeight / context->gridRows;

    context->wndChannelBitDepth = CV_8UC3;
    context->wndRaster = cv::Mat(cv::Size(context->wndWidth, context->wndHeight), context->wndChannelBitDepth);
    context->maze = nullptr;
    return ExitCode::drawGrid;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Deallocates memory.
////////////////////////////////////////////////////////////////////////////////
ExitCode CollectGarbage(Context* context) {
    delete context->maze;
    return ExitCode::NIL;
}
}
