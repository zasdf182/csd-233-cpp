#ifndef INLINE_RENDER
#define INLINE_RENDER
#include "../modules/draw.hpp"
#include "../define/app.hpp"
#include "cstr.hpp"
#include <cstring>

////////////////////////////////////////////////////////////////////////////////
/// @brief Get the enum equivalent of a shape string.
///        Has undefined behavior if there is no null character.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Types::Shape GetShape(char* shapeName);

////////////////////////////////////////////////////////////////////////////////
/// @brief Constructs a new Circle object and calls Draw().
/// @return A pointer to the new Circle object.
////////////////////////////////////////////////////////////////////////////////
inline Draw::Sprite* DrawCircle(int x, int y, int width, int height, cv::Mat raster);
#endif
