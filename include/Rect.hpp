#ifndef _RECT_HPP_
#define _RECT_HPP_

class Rect;

#include "Vec2.hpp"

class Rect{
    public:
        float x;
        float y;
        float w;
        float h;

        Rect();
        Rect(float, float, float, float);
        // retorno SumRectVec2(Rect, Vec2);
        Vec2 GetCenter();
        float CenterDistance(Rect);
        bool IsInside(float, float);
};

#endif // _RECT_HPP_