#include "Collision.hpp"

bool Collision::IsColliding(Rect& a, Rect& b, float angleOfA, float angleOfB){
    Vec2 A[] = {    Vec2(a.x, a.y + a.h),
                    Vec2(a.x + a.w, a.y + a.h),
                    Vec2(a.x + a.w, a.y),
                    Vec2(a.x, a.y)
                };
    Vec2 B[] = {    Vec2(b.x, b.y + b.h),
                    Vec2(b.x + b.w, b.y + b.h),
                    Vec2(b.x + b.w, b.y),
                    Vec2(b.x, b.y)
                };

    for(auto& v : A){
        v = Rotate(v - a.GetCenter(), angleOfA) + a.GetCenter();
    }

    for(auto& v : B){
        v = Rotate(v - b.GetCenter(), angleOfB) + b.GetCenter();
    }

    Vec2 axes[] =   {   (A[0] - A[1]).Unit(),
                        (A[1] - A[2]).Unit(),
                        (B[0] - B[1]).Unit(),
                        (B[1] - B[2]).Unit()
                    };

    for(auto& axis : axes){
        float P[4];

        for(int i = 0; i < 4; ++i){
            P[i] = Dot(A[i], axis);
        }

        float minA = *std::min_element(P, P + 4);
        float maxA = *std::max_element(P, P + 4);

        for(int i = 0; i < 4; ++i){
            P[i] = Dot(B[i], axis);
        }

        float minB = *std::min_element(P, P + 4);
        float maxB = *std::max_element(P, P + 4);

        if(maxA < minB || minA > maxB){
            return false;
        }
    }
    return true;
}

float Collision::Dot(const Vec2& a, const Vec2& b){
    return a.x * b.x + a.y * b.y;
}

Vec2 Collision::Rotate(const Vec2& p, float angle){
    float cs = std::cos(angle), sn = std::sin(angle);

    return Vec2(p.x * cs - p.y * sn, p.x * sn + p.y * cs);
}