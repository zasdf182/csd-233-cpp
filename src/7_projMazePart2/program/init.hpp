#ifndef PROGRAM_INIT
#define PROGRAM_INIT
#include "types/program.hpp"
namespace Main {

////////////////////////////////////////////////////////////////////////////////
/// @brief Initializes the main program's context object.
////////////////////////////////////////////////////////////////////////////////
ExitCode InitContext(Context* context);

////////////////////////////////////////////////////////////////////////////////
/// @brief Deallocates memory.
////////////////////////////////////////////////////////////////////////////////
ExitCode CollectGarbage(Context* context);
}
#endif
