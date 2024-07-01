#include "Juego.h"
#include <iostream>

Juego::Juego()
    : window(sf::VideoMode(850, 500), "Pong"),
      ball(425, 250, "./assets/imagenes/ball.png"),
      paddleLeft(25, 250, "./assets/imagenes/paddle.png"),
      paddleRight(825, 250, "./assets/imagenes/paddle.png"),
      scoreLeft(40, "./assets/font/Minecraft.ttf"),
      scoreRight(40, "./assets/font/Minecraft.ttf"),
      soundManager("./assets/sounds/Fondo.mp3"), // Añadido para manejar la música de fondo
      ballVelocityX(2), ballVelocityY(2), countLeft(0), countRight(0) {

    window.setFramerateLimit(120);
    paddleRight.SetRotation(-90);
    paddleLeft.SetRotation(90);
    paddleRight.SetScale(0.15f, 0.17f);
    paddleLeft.SetScale(0.15f, 0.17f);
    ball.SetScale(0.05f, 0.05f);

    scoreLeft.SetPosition((850/2)/2, 25);
    scoreRight.SetPosition((850/2)+(850/2)/2, 25);
    UpdateScores();
    
    soundManager.PlayBackgroundMusic(); // Iniciar la música de fondo
}

void Juego::Run() {
    while (window.isOpen()) {
        ProcessEvents();
        Update();
        Render();
    }
}

void Juego::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Juego::Update() {
    // Movimiento de la pelota
    ball.Move(ballVelocityX, ballVelocityY);

    // Colisiones con las paletas
    if (paddleRight.GetGlobalBounds().contains(ball.GetPosition().x, ball.GetPosition().y) || 
        paddleLeft.GetGlobalBounds().contains(ball.GetPosition().x, ball.GetPosition().y)) {
        ballVelocityX *= -1;
    }

    // Colisiones con los bordes izquierdo y derecho (Puntos)
    if (ball.GetPosition().x > 850) {
        countLeft++;
        ballVelocityX *= -1;
        ResetBall();
        UpdateScores();
    } else if (ball.GetPosition().x < 0) {
        countRight++;
        ballVelocityX *= -1;
        ResetBall();
        UpdateScores();
    }

    // Colisiones con los bordes superior e inferior
    if (ball.GetPosition().y > 500 || ball.GetPosition().y < 0) {
        ballVelocityY *= -1;
    }

    // Movimiento de las paletas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddleRight.GetPosition().y > 0) {
        paddleRight.Move(0, -4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddleRight.GetPosition().y < 500) {
        paddleRight.Move(0, 4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddleLeft.GetPosition().y > 0) {
        paddleLeft.Move(0, -4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddleLeft.GetPosition().y < 500) {
        paddleLeft.Move(0, 4);
    }
}

void Juego::Render() {
    window.clear();
    ball.Draw(window);
    paddleLeft.Draw(window);
    paddleRight.Draw(window);
    scoreLeft.Draw(window);
    scoreRight.Draw(window);
    window.display();
}

void Juego::ResetBall() {
    ball.SetPosition(425, 250);
    ballVelocityX *= -1;
}

void Juego::UpdateScores() {
    scoreLeft.SetString(std::to_string(countLeft));
    scoreRight.SetString(std::to_string(countRight));
}
