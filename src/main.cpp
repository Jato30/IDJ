#include "Game.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]){
    std::srand(std::time(NULL));
    Game* g1 = new Game("Daniel Marcos Botelho Barbosa - 17/0052427", 1024, 600);
    g1->Run();
    delete g1;
    return 0;
}