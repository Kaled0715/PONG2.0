#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(int x, int y, const std::string& textureFile);
    void Move(float offsetX, float offsetY);
    void Draw(sf::RenderWindow& window);
    void SetPosition(int x, int y);
    void SetScale(float factorX, float factorY);
    sf::Vector2f GetPosition() const;
private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif
