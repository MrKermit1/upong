#include "Ball.h"
#include <raylib.h>

Ball::Ball(float posX, float posY, int speed_X, int speed_Y, int radius){
    x = posX;
    y = posY;
    speedX = speed_X;
    speedY = speed_Y;
    this->radius = radius;
}


void Ball::Draw(){
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Move(){
    y += speedY;
    x += speedX;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speedY *= -1;
    }

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
    {
        speedX *= -1;
    }
    
    
}

void Ball::Reset(){
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speeds[2] = {-1, 1};

    speedX *= speeds[GetRandomValue(0, 1)];
    speedX *= speeds[GetRandomValue(0, 1)];
}

void Ball::setX(float xx){
    x = xx;
}

void Ball::setY(float yy){
    y = yy;
}

void Ball::setSpeedX(int a){
    speedX = a;
}

void Ball::setSpeedY(int a){
    speedY = a;
}

void Ball::setRadius(int a){
    radius = a;
}

float Ball::getX(){
    return x;
}

float Ball::getY(){
    return y;
}

int Ball::getSpeedX(){
    return speedX;
}

int Ball::getSpeedY(){
    return speedY;
}

int Ball::getRadius(){ 
    return radius;
}