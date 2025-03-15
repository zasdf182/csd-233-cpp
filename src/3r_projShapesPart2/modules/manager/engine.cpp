#include "engine.hpp"
namespace Singletons {

////////////////////////////////////////////////////////////////////////////////
/// @brief Executes an action, using Engine.CurrentState as a context object.
///        Keeps executing actions, until a returned message is not found in map.
/// @return The message of the last executed action.
////////////////////////////////////////////////////////////////////////////////
template <class ctxType, class returnMessageType>
returnMessageType Engine<ctxType, returnMessageType>::

Start(EngineAction action) {
    returnMessageType returnMessage;
    bool mapContainsMessage; do {
        returnMessage = action(CurrentState);
        mapContainsMessage = Actions.count(returnMessage);
        if (mapContainsMessage) action = Actions[returnMessage];
    } while (mapContainsMessage);
    return returnMessage;
}
}
