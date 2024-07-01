#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(int x, int y, const std::string& textureFile);
    void Move(float offsetX, float offsetY);
    void Draw(sf::RenderWindow& window);
    void SetRotation(float angle);
    void SetScale(float factorX, float factorY);
    sf::Vector2f GetPosition() const;
    sf::FloatRect GetGlobalBounds() const;
private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif
