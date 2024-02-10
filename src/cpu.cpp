#include <raylib.h>
#include "cpu.h"

void Cpu::Update(int ball_y){
    if (getY() + getHeight()/2 > ball_y)
    {
        setY(getY() - getSpeed());
    }
    if (getY() + getHeight()/2 <= ball_y)
    {
        setY(getY() + getSpeed());
    }
    
}