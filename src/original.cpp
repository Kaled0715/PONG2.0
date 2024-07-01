#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "SoundManager.h"

using namespace std;
using namespace sf;

class PongGame {
private:
    Ball ball;
    Paddle paddleLeft;
    Paddle paddleRight;
    Score scoreLeft;
    Score scoreRight;
    SoundManager soundManager;
    RenderWindow window;

public:
    PongGame()
        : ball(2, 2),
          paddleLeft(90, Vector2f(25, 250), Vector2f(0.15f, 0.17f)),
          paddleRight(-90, Vector2f(825, 250), Vector2f(0.15f, 0.17f)),
          scoreLeft(Vector2f((850 / 2) / 2, 25)),
          scoreRight(Vector2f((850 / 2) + (850 / 2) / 2, 25)),
          window(VideoMode(850, 500), "Pong") {
        window.setFramerateLimit(120);
    }

    void run() {
        ball.loadTexture("./assets/imagenes/ball.png");
        paddleLeft.loadTexture("./assets/imagenes/paddle.png");
        paddleRight.loadTexture("./assets/imagenes/paddle.png");
        soundManager.loadSound("bounce", "./assets/sonidos/bounce.wav");
        soundManager.loadSound("score", "./assets/sonidos/score.wav");

        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

private:
    void handleEvents() {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
    }

    void update() {
        ball.move();
        // Colisiones Bola (Rebotes)
        if (paddleRight.getBounds().contains(ball.getPosition()) || paddleLeft.getBounds().contains(ball.getPosition())) {
            ball.bounceX();
            soundManager.playSound("bounce");
        } else if (ball.getPosition().x > 850) {
            // Punto Izquierda
            scoreLeft.increment();
            ball.bounceX();
            ball.resetPosition();
            soundManager.playSound("score");
        } else if (ball.getPosition().x < 0) {
            // Punto Derecha
            scoreRight.increment();
            ball.bounceX();
            ball.resetPosition();
            soundManager.playSound("score");
        }

        if (ball.getPosition().y > 500 || ball.getPosition().y < 0) {
            ball.bounceY();
            soundManager.playSound("bounce");
        }
        // Paleta Derecha
        if (Keyboard::isKeyPressed(Keyboard::Up) && paddleRight.getPosition().y > 0) {
            paddleRight.move(0, -4);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && paddleRight.getPosition().y < 500) {
            paddleRight.move(0, 4);
        }
        // Paleta Izquierda
        if (Keyboard::isKeyPressed(Keyboard::W) && paddleLeft.getPosition().y > 0) {
            paddleLeft.move(0, -4);
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && paddleLeft.getPosition().y < 500) {
            paddleLeft.move(0, 4);
        }
    }

    void render() {
        window.clear();
        ball.draw(window);
        paddleLeft.draw(window);
        paddleRight.draw(window);
        scoreLeft.draw(window);
        scoreRight.draw(window);
        window.display();
    }
};

int main() {
    PongGame game;
    game.run();
    return 0;
}
