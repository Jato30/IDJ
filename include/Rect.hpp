#ifndef _RECT_
#define _RECT_

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
        Vec2 CenterRect();
        float CenterDistRects(Rect);
        bool IsInside(float, float);
};

#endif // _RECT_