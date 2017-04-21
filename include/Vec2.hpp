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
        float Magnitude(); // Norma, tamanho
        void operator=(float); // THIS = escalar
        void operator+=(float); // THIS + escalar
        void operator-=(float); // THIS - escalar
        void operator*=(float); // THIS * escalar
        void operator/=(float); // THIS / escalar
        Vec2 Center(); // Coordenadas do centro de (0, 0) até THIS
        void Unit(); // Vetor unitário na mesma direção e sentido que THIS
        float Distance(Vec2); // Distância entre THIS e Vec2
        Vec2 AngleX(Vec2); // Inclinação entre [THIS, vec2] em relação ao eixo X
        float ToAngle(Vec2); // Ângulo entre dois pontos e o eixo X
        //float AngleOrignX(); // Inclinação entre [(0, 0), THIS] e o eixo X
        // FALTAM OUTROS MÉTODOS: explícitos no T2
};

#include <cmath>

#endif // _VEC2_HPP_