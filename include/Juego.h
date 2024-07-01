#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "SoundManager.h"

class Juego {
public:
    Juego();
    void Run();

private:
    void ProcessEvents();
    void Update();
    void Render();
    void ResetBall();
    void UpdateScores();

    sf::RenderWindow window;
    Ball ball;
    Paddle paddleLeft;
    Paddle paddleRight;
    Score scoreLeft;
    Score scoreRight;
    SoundManager soundManager; // Añadido para manejar la música de fondo
    float ballVelocityX;
    float ballVelocityY;
    int countLeft;
    int countRight;
};

#endif

