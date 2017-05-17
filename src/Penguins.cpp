#include "Penguins.hpp"

Penguins* Penguins::player = nullptr;

Penguins::Penguins(float x, float y) : GameObject(), bodySp("./resources/img/penguin.png"), cannonSp("./resources/img/cubngun.png"){
    box = Rect(x, y, bodySp.GetWidth(), bodySp.GetHeight());
    rotation = 0;

    speed = Vec2(0.0, 0.0);
    linearSpeed = 5; // Aceleração
    cannonAngle = 0;
    hp = 50;
    player = this;
    cooldown = Timer();
}

Penguins::~Penguins(){
    player = nullptr;
}

void Penguins::Update(float dt){
    cooldown.Update(dt);

    // Rotação
    if(INPUT_M.IsKeyDown(A_KEY)){
        rotation -= OBJECT_ANGULAR_SPEED * 6 * dt;
        if(rotation < 0){
            rotation += 2 * M_PI;
        }
    }
    if(INPUT_M.IsKeyDown(D_KEY)){
        rotation += OBJECT_ANGULAR_SPEED * 6 * dt;
        if(rotation >= 2 * M_PI){
            rotation -= 2 * M_PI;
        }
    }

    // Movimento
    if(INPUT_M.IsKeyDown(W_KEY)){
        if(speed.x >= -(OBJECT_LINEAR_MAX_SPEED * dt) && speed.x <= (OBJECT_LINEAR_MAX_SPEED * dt)){
            if(speed.x < 0){
                speed.x += linearSpeed * 3 * dt;
            }
            else{
                speed.x += linearSpeed * dt;
            }
        }
        if(speed.y >= -(OBJECT_LINEAR_MAX_SPEED * dt) && speed.y <= (OBJECT_LINEAR_MAX_SPEED * dt)){
            if(speed.y < 0){
                speed.y += linearSpeed * 3 * dt;
            }
            else{
                speed.y += linearSpeed * dt;
            }
        }
    }
    if(INPUT_M.IsKeyDown(S_KEY)){
        if(speed.x >= -(OBJECT_LINEAR_MAX_SPEED * dt) && speed.x <= (OBJECT_LINEAR_MAX_SPEED * dt)){
            if(speed.x > 0){
                speed.x -= linearSpeed * 3 * dt;
            }
            else{
                speed.x -= linearSpeed * dt;
            }
        }
        if(speed.y >= -(OBJECT_LINEAR_MAX_SPEED * dt) && speed.y <= (OBJECT_LINEAR_MAX_SPEED * dt)){
            if(speed.y > 0){
                speed.y -= linearSpeed * 3 * dt;
            }
            else{
                speed.y -= linearSpeed * dt;
            }
        }
    }
    if(!INPUT_M.IsKeyDown(W_KEY) && !INPUT_M.IsKeyDown(S_KEY)){
        if(speed.x < 0){
            speed.x += linearSpeed * dt;
            if(speed.x > 0){
                speed.x = 0;
            }
        }
        if(speed.x > 0){
            speed.x -= linearSpeed * dt;
            if(speed.x < 0){
                speed.x = 0;
            }
        }

        if(speed.y < 0){
            speed.y += linearSpeed * dt;
            if(speed.y > 0){
                speed.y = 0;
            }
        }
        if(speed.y > 0){
            speed.y -= linearSpeed * dt;
            if(speed.y < 0){
                speed.y = 0;
            }
        }
    }

    box.x += speed.x * std::cos(rotation);
    box.y += speed.y * std::sin(rotation);

    if(box.GetCenter().x > 1408){
        box.x = 1408 - (box.w / 2);
    }
    if(box.GetCenter().x < 0){
        box.x = 0 - (box.w / 2);
    }
    if(box.GetCenter().y > 1280){
        box.y = 1280 - (box.h / 2);
    }
    if(box.GetCenter().y < 0){
        box.y = 0 - (box.h / 2);
    }

    cannonAngle = Vec2(box.GetCenter().x + Camera::pos.x, box.GetCenter().y + Camera::pos.y).ToAngle(Vec2(INPUT_M.GetMouseX(), INPUT_M.GetMouseY()));

    if(INPUT_M.IsMouseDown(LEFT_MOUSE_BUTTON)){
        Shoot();
    }
}

void Penguins::Render(){
    bodySp.Render((int) box.x + Camera::pos.x, (int) box.y + Camera::pos.y, rotation);
    cannonSp.Render((int) box.x + Camera::pos.x, (int) box.y + Camera::pos.y, cannonAngle);
}

bool Penguins::IsDead(){
    if(hp <= 0){
        Camera::UnFollow();
        return true;
    }
    else{
        return false;
    }
}

void Penguins::Shoot(){
    if(cooldown.Get() >= 1){
        Bullet* penguinBullet = new Bullet(box.GetCenter().x - rotation, box.GetCenter().y - rotation, cannonAngle, OBJECT_LINEAR_MAX_SPEED, 750, "./resources/img/penguinbullet.png", 0.5, 4, false);
        Game::GetInstance().GetCurrentState().AddObject(penguinBullet);
        cooldown.Restart();
    }
}

void Penguins::NotifyCollision(GameObject& other){
    if(other.Is("Bullet")){
        if(((Bullet&) other).targetsPlayer){
            hp -= 15;
        }
    }
    if(other.Is("Alien")){
        hp -= 3;
    }
    if(hp <= 0){
        Animation* animation = new Animation(box.x, box.y, rotation, "./resources/img/penguindeath.png", 5, 0.1, true);
        Game::GetInstance().GetCurrentState().AddObject(animation);
        Sound* soundExplosion = new Sound("./resources/audio/boom.wav");
        soundExplosion->Play(0);
    }
}

bool Penguins::Is(std::string type){
    return (type == "Penguins");
}