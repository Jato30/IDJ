#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <vector>
#include <memory>

class State;

#include "GameObject.hpp"

class State{
    protected:
        bool popRequested;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;

        virtual void UpdateArray(float);
        virtual void RenderArray();

    public:
        State();
        virtual ~State();
        virtual void Update(float) = 0;
        virtual void Render() = 0;
        virtual void LoadAssets() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;
        virtual void AddObject(GameObject*);
        bool PopRequested();
        bool QuitRequested();
};

#include "Collision.hpp"
#include "Timer.hpp"
#include "Camera.hpp"
#include "Text.hpp"

#endif // _STATE_HPP_