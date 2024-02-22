#include <raylib.h>
#include <iostream>
#include "Ball.h"
#include "Player.h"
#include "cpu.h"

std::string whoIsWinner(Player *tab){
    for (int i = 0; i < 3; i++)
    {
        if (tab[i].getScore() == 15)
        {
            return tab[i].getName();
        }
        
    }
    
    return "none";
}

void fullScreen(int w, int h){
    if (!IsWindowFullscreen())
    {
        int screen = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(screen), GetMonitorHeight(screen));
        ToggleFullscreen();
    }else{
        ToggleFullscreen();
        SetWindowSize(w, h);
    }
    
}

int main()
{
    const int screen_w = 1200;
    const int screen_h = 800;
    bool isCpu = true;
    bool isGameOver = false;
    std::string winner;

    InitAudioDevice();   
    Sound gameOverTheme = LoadSound("src/sounds/over.mp3");
    Sound paddle = LoadSound("src/sounds/paddle.mp3");
    Sound wall = LoadSound("src/sounds/wall.mp3");
    Sound point = LoadSound("src/sounds/point.mp3");

    Ball ball = Ball(screen_w/2, screen_h/2, 13, 10, 10, wall);
    Player player2;

    player2.setWidth(12.5);
    player2.setHeight(120);
    player2.setX(screen_w - player2.getWidth() - 10);
    player2.setY(screen_h/2 - player2.getHeight()/2);
    player2.setSpeed(12);
    player2.setName("Gracz 2");
    player2.setControlType("arrow");

    Player player1;

    player1.setWidth(12.5);
    player1.setHeight(120);
    player1.setX(10);
    player1.setY(screen_h/2 - 60);
    player1.setSpeed(12);
    player1.setControlType("wsad");
    player1.setName("Gracz 1");

    Cpu cpu;

    cpu.setWidth(12.5);
    cpu.setHeight(120);
    cpu.setX(10);
    cpu.setY(screen_h/2 - cpu.getHeight()/2);
    cpu.setSpeed(7);
    cpu.setName("Komputer");


    
    InitWindow(screen_w, screen_h, "Upong");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

       
        

        if (!isGameOver)
        {

            if (ball.getX() - ball.getRadius() <= 0){
                PlaySound(point);
                player2.setScore(player2.getScore() + 1);
                std::cout << "x: " << ball.getX() << " y: " << ball.getY() << std::endl;
                ball.Reset();
            }
            else if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{player1.getX(), player1.getY(), player1.getWidth(), player1.getHeight()})){
                ball.setSpeedX(ball.getSpeedX() *-1);
                PlaySound(paddle);
            }
            else if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{player2.getX(), player2.getY(), player2.getWidth(), player2.getHeight()}) || ball.getX() == 5){
                ball.setSpeedX(ball.getSpeedX() *-1);
                PlaySound(paddle);
            }
            else if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{cpu.getX(), cpu.getY(), cpu.getWidth(), cpu.getHeight()}) || ball.getX() == 5){
                ball.setSpeedX(ball.getSpeedX() *-1);
                PlaySound(paddle);
            }
            else if (ball.getX() + ball.getRadius() >= GetScreenWidth())
            {
                PlaySound(point);
                cpu.setScore(cpu.getScore() +1);
                player1.setScore(player1.getScore() +1);
                ball.Reset();
            }

            if(player1.getScore() == 15 || player2.getScore() == 15 || cpu.getScore() == 15){
                BeginDrawing();
                ClearBackground(BLACK);
                Player arr[3] = {player1, player2, cpu};
                winner = "Wygral: " + whoIsWinner(arr);
                const char *c = winner.c_str();
                PlaySound(gameOverTheme);
                DrawText(c, screen_w - MeasureText(winner.c_str(), 80), screen_h/2, 80, WHITE);
                EndDrawing();
            }

            BeginDrawing();



            ClearBackground(BLACK);
            //przemieszczanie się kółka
            ball.Move();
            if (!isCpu){
                player1.Move();
                player2.Move();
                cpu.setScore(0);
            }else{
                cpu.Update(ball.getY());
                player1.setScore(0);
                player2.Move();
            }
            //rysuj linie na połowie
            DrawLine(screen_w/2, 0, screen_w/2, screen_h, WHITE);
            //rysuj kółko
            ball.Draw();
            //rysuj panele
            if (!isCpu)
            {
                player1.Draw();
                player2.Draw();
            }else{
                cpu.Draw();
                player2.Draw();
            }
             if (IsKeyDown(KEY_SPACE))
            {                              
                ball.setStart(true);
            }

            if (IsKeyDown(KEY_F5))
            {
                isCpu = true;
                player1.setScore(0);
            }

            if (IsKeyDown(KEY_F6))
            {
                isCpu = false;
                cpu.setScore(0);
            }

            if (!isCpu){
                DrawText(TextFormat("%i", player1.getScore()), screen_w/4 - 20, 20, 80, WHITE);
            }else{
                DrawText(TextFormat("%i", cpu.getScore()), screen_w/4 - 20, 20, 80, WHITE);
            }

            DrawText(TextFormat("%i", player2.getScore()), 3 * screen_w/4 - 20, 20, 80, WHITE);
            EndDrawing();
        }   
        if (player1.getScore() == 15 || player2.getScore() == 15 || cpu.getScore() == 15)
        {
            isGameOver = true;

            BeginDrawing();
            ClearBackground(BLACK);

            // Draw the winner information
            Player arr[3] = {player1, player2, cpu};
            winner = "Wygral: " + whoIsWinner(arr);
            const char *c = winner.c_str();
            DrawText(c, (screen_w - MeasureText(c, 80))/2, screen_h/2, 80, WHITE);


            if (IsKeyPressed(KEY_ENTER))
            {
                StopSound(gameOverTheme);
                cpu.setScore(0);
                player2.setScore(0);
                player1.setScore(0); 
                isGameOver = false;
            }
            
            EndDrawing();
        }
        if (IsKeyPressed(KEY_F11))
        {
            //fullScreen(screen_w, screen_h);
        }
    }
    UnloadSound(gameOverTheme);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}