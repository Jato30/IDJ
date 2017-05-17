#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "TitleState.hpp"

int main(int argc, char* argv[]){
    std::srand(std::time(NULL));
    Game* g1 = new Game("Daniel Marcos Botelho Barbosa - 17/0052427", 1024, 600);
    TitleState* titleState = new TitleState();
    g1->Push(titleState);
    g1->Run();
    delete g1;
    return 0;
}