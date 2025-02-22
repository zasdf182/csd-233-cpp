#include "schedulePoll.hpp"
#ifndef MAIN_HPP
#define MAIN_HPP

/** A status message returned after each engine loop */
enum enginegoto {
    intro = 1,
    part1 = 'd',
    part2 = 'e',
    quit = '0',
    null = '\0'
};

/** A function that updates the engine and returns a status key */
typedef const enginegoto (enginefunc) (SchedulePoll * ctx);
typedef const enginegoto (*engineptr) (SchedulePoll * ctx);

// Engine loop functions
static enginefunc intromsg;
static enginefunc getschedules;
static enginefunc queryschedules;
static void quitprogram(SchedulePoll* ctx);

#endif
