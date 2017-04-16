#ifndef _VEC2_
#define _VEC2_

class Vec2{
    public:
        float x;
        float y;

        Vec2();
        Vec2(float, float);
        void operator+(Vec2);
        void operator-(Vec2);
        void operator*(Vec2);
        void operator/(Vec2);
        float Magnitude(); // Norma, tamanho
        void Soma(float);
        void Subtrai(float);
        void Multiplica(float);
        void Divide(float);
        Vec2 Centro();
        void Unit();
        float Distancia(Vec2);
        /*
        float InclinacaoX(); // Ou float x, float y
        float InclinacaoPontos(Vec2);*/ // Ou float x, float y (2 vezes)
        // FALTAM OUTROS MÉTODOS: explícitos no T2
};

#include <cmath>

#endif // _VEC2_