#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <map>
namespace Singletons {




////////////////////////////////////////////////////////////////////////////////
/// @brief A pointer to a function that executes a step of the program.
///        Takes in a context, performs some tasks, returns a status message.
/// @tparam ctx An object used to pass data between program steps.
/// @tparam returnMessage An enum telling the engine which step to do next.
////////////////////////////////////////////////////////////////////////////////
template <class ctxType, class returnMessageType>
using Action = returnMessageType (*) (ctxType* context);




////////////////////////////////////////////////////////////////////////////////
/// @brief A singleton.
///        Manages a map of messages and corresponding actions.
///        The engine starts by executing an action.
///        After it's done, it will check the map for the next action to do.
///        The engine continues until a returned message is not found in the map.
/// @tparam ctxType An object used to pass data between actions.
/// @tparam returnMessageType A key used to map actions.
////////////////////////////////////////////////////////////////////////////////
template <class ctxType, class returnMessageType> class Engine {
    public: //Typedefs and aliases.
        typedef Action<ctxType, returnMessageType> EngineAction;
        typedef std::map<returnMessageType, EngineAction> EngineMap;

    public: //Mutable properties.
        ctxType* CurrentState;
        EngineMap Actions;

    public: //Constructors and destructors.
        Engine();
        ~Engine();

    public: //Singleton management methods.
        returnMessageType Start(EngineAction action);
};
}
#endif
