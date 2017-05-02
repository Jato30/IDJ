#ifndef _TIMER_HPP_
#define _TIMER_HPP_

class Timer{
    private:
        float time;

    public:
        Timer();
        void Update(float);
        void Restart();
        float Get();
};

#endif // __TIMER_HPP_