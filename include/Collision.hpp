#ifndef _COLLISION_HPP_
#define _COLLISION_HPP_

#include <cmath>
#include <algorithm>

class Collision;

#include "Rect.hpp"

class Collision {
    private:
        static float Dot(const Vec2&, const Vec2&);
        static Vec2 Rotate(const Vec2&, float);

    public:
        // Observação: IsColliding espera ângulos em radianos!
        // Para usar graus, forneça a sua própria implementação de Rotate,
        // ou transforme os ângulos no corpo de IsColliding.
        static bool IsColliding(Rect&, Rect&, float, float);
};

// Aqui estão três operadores que sua classe Vec2 deve precisar, se já não tiver. 
// Se sua classe tiver métodos para Mag, Norm, Dot e/ou Rotate, você pode substituir
// os usos desses métodos por usos dos seus, mas garanta que deem resultados corretos.

// Vec2 operator+(const Vec2& rhs) const {
//    return Vec2(x + rhs.x, y + rhs.y);
// }

// Vec2 operator-(const Vec2& rhs) const {
//    return Vec2(x - rhs.x, y - rhs.y);
// }

// Vec2 operator*(const float rhs) const {
//    return Vec2(x * rhs, y * rhs);
// }

#endif // _COLLISION_HPP_