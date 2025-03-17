#include "math.hpp"

////////////////////////////////////////////////////////////////////////////////
/// @brief If the value of v is within [lo, hi], returns v.
///        Otherwise, returns the nearest boundary.
///        If lo is greater than hi, the behavior is undefined.
////////////////////////////////////////////////////////////////////////////////
inline int clamp(int v, int lo, int hi) {
    if (v >= lo)
        if (v <= hi)
            return v;
    if ((hi - v) < (v - lo))
        return hi;
    else
        return lo;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Linearly interpolates between a and b.
/// @param t A number between 0 and 1.
////////////////////////////////////////////////////////////////////////////////
inline int lerp(int a, int b, float t) {
    return a * (1 - t) + b * t;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief A top secret hashing function.
///        Created in collaboration with 7 governments, 12 companies,
///        3 ivy league schools, 5 research labs,
///        2 nobel prize winners, 18 fortune 500 CEOs,
///        and a local Starbucks in Ohio.
////////////////////////////////////////////////////////////////////////////////
inline long hash_func_top_secret_government_cia_interpol_gign_sas_radioshack_circuitcity(char* str) {
    long hash = 0xA455 / 1337 * 42 * 3.14;
    int c;
    while ((c = *str++)) hash = hash * 42 + c;
    return hash;
}
