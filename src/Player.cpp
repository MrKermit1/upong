#include "Player.h"
#include <raylib.h>
#include <iostream>

Player::Player(){}

Player::Player(int posX, int posY, float width, float height, int speed){
    x = posX;
    y = posY;
    this->width = width;
    this->height = height;
    this->speed = speed;
}

void Player::Draw(){
    DrawRectangle(x ,y, width, height, WHITE);
}

void Player::Move(){
    if (controlType == "arrow"){
        if (IsKeyDown(KEY_UP)){
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN)){
            y = y + speed;
        }
        if (y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
        
    }
    if (controlType == "wsad"){
        if (IsKeyDown(KEY_W)){
            y = y - speed;
        }
        if (IsKeyDown(KEY_S)){
            y = y + speed;
        }
        if (y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }
    
    
}

void Player::setX(float xx){
    x = xx;
}

void Player::setY(float yy){
    y = yy;
}

void Player::setHeight(float a){
    height = a;
}

void Player::setWidth(float a){
    width = a;
}

void Player::setSpeed(float a){
    speed = a;
}

void Player::setControlType(std::string a){
    controlType = a;
}

void Player::setScore(int a){
    score = a;
}

float Player::getX(){
    return x;
}

float Player::getY(){
    return y;
}

float Player::getHeight(){
    return height;
}

float Player::getWidth(){
    return width;
}

int Player::getSpeed(){
    return speed;
}

std::string Player::getControlType(){
    return controlType;
}

int Player::getScore(){
    return score;
}

