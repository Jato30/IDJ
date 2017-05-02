#ifndef _VEC2_HPP_
#define _VEC2_HPP_

class Vec2{
    public:
        float x;
        float y;

        Vec2();
        Vec2(float, float);
        void operator=(Vec2); // THIS = vec2
        void operator+=(Vec2); // THIS + vec2
        void operator-=(Vec2); // THIS - vec2
        void operator*=(Vec2); // THIS * vec2
        void operator/=(Vec2); // THIS / vec2
        bool operator==(Vec2); // (bool) if THIS == vec2
        float Magnitude(); // Norma, tamanho
        void operator=(float); // THIS = escalar
        void operator+=(float); // THIS + escalar
        void operator-=(float); // THIS - escalar
        void operator*=(float); // THIS * escalar
        void operator/=(float); // THIS / escalar
        Vec2 Center(); // Coordenadas do centro de (0, 0) até THIS
        Vec2& Unit(); // Vetor unitário na mesma direção e sentido que THIS
        float Distance(Vec2); // Distância entre THIS e Vec2
        Vec2 AngleX(Vec2); // Inclinação entre [THIS, vec2] em relação ao eixo X
        float ToAngle(Vec2); // Ângulo entre dois pontos e o eixo X
        //float AngleOrignX(); // Inclinação entre [(0, 0), THIS] e o eixo X
        Vec2 operator+(const Vec2& rhs) const;
        Vec2 operator-(const Vec2& rhs) const;
        Vec2 operator*(const float rhs) const;
        bool NearBy(Vec2);
};

#include <cmath>

#endif // _VEC2_HPP_