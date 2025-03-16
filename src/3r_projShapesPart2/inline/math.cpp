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
