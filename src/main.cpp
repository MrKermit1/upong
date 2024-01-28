#include <raylib.h>
#include <iostream>
#include "Ball.h"
#include "Player.h"

int main()
{
    const int screen_w = 1200;
    const int screen_h = 800;
    Ball ball = Ball(screen_w/2, screen_h/2, 7, 7, 20);
    Player player2;

    player2.setWidth(25);
    player2.setHeight(120);
    player2.setX(screen_w - player2.getWidth() - 10);
    player2.setY(screen_h/2 - player2.getHeight()/2);
    player2.setSpeed(6);
    player2.setControlType("arrow");

    Player player1;

    player1.setWidth(25);
    player1.setHeight(120);
    player1.setX(10);
    player1.setY(screen_h/2 - 60);
    player1.setSpeed(6);
    player1.setControlType("wsad");

    InitWindow(screen_w, screen_h, "Upong");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (IsKeyDown(KEY_SPACE))
        {
            ball.setStart(true);
        }
        

        //sprawdź kolizję
        if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{player1.getX(), player1.getY(), player1.getWidth(), player1.getHeight()})){
            ball.setSpeedX(ball.getSpeedX() *-1);
        }
        if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{player2.getX(), player2.getY(), player2.getWidth(), player2.getHeight()})){
            ball.setSpeedX(ball.getSpeedX() *-1);
        }
        if (ball.getX() - ball.getRadius() <= 0 )
        {
            player2.setScore(player2.getScore() +1);
            ball.Reset();
        }
        if (ball.getX() + ball.getRadius() >= screen_w)
        {
            player1.setScore(player1.getScore() +1);
            ball.Reset();
        }
        
        

        ClearBackground(BLACK);
        //przemieszczanie się kółka
        ball.Move();
        player1.Move();
        player2.Move();
        //rysuj linie na połowie
        DrawLine(screen_w/2, 0, screen_w/2, screen_h, WHITE);

        //rysuj kółko
        ball.Draw();

        //rysuj panele
        player1.Draw();
        player2.Draw();
        DrawText(TextFormat("%i", player1.getScore()), screen_w/4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player2.getScore()), 3 * screen_w/4 - 20, 20, 80, WHITE);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}