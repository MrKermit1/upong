#pragma once

class Ball
{
    private:
        float x, y;
        int speedX, speedY;
        int radius;
        bool start = false;
    public:
        Ball(float posX, float posY, int speed_X, int speed_Y, int radius);

        //rysuj koło
        void Draw();
        //poruszaj koło
        void Move();

        void Reset();

        //gettery i settery
        void setX(float xx);
        void setY(float yy);
        void setSpeedX(int a);
        void setSpeedY(int a);
        void setRadius(int a);
        void setStart(bool a);

        float getX();
        float getY();
        int getSpeedX();
        int getSpeedY();
        int getRadius();
        bool getStart();

};

