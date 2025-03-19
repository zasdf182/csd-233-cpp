#include "init.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Initializes the main program's context object.
////////////////////////////////////////////////////////////////////////////////
ExitCode InitContext(Context* context) {
    context->wndWidth = 400;
    context->wndHeight = 240;
    context->wndChannelBitDepth = CV_8UC3;
    context->wndUpdatePeriod = 20000;
    context->wndRaster = cv::Mat(cv::Size(400, 240), CV_8UC3);
    context->wndName = "TurtleWindow";

    context->gridRows = 5;
    context->gridCols = 3;
    context->gridCellWidth = 80;
    context->gridCellHeight = 80;
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
