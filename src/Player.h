#pragma once
#include <iostream>

class Player
{
    private:
        float x, y;
        float width, height;
        int speed;
        unsigned int score = 0;
        std::string name;
        std::string controlType;
    public:
        Player(int posX, int posY, float width, float height, int speed);
        Player();

        void Draw();
        void Move();

        void setX(float xx);
        void setY(float yy);
        void setWidth(float a);
        void setHeight(float a);
        void setSpeed(float a);
        void setControlType(std::string a);
        void setScore(int a);
        void setName(std::string a);

        float getX();
        float getY();
        float getWidth();
        float getHeight();
        int getSpeed();
        std::string getControlType();
        int getScore();
        std::string getName();
};

