#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int x, int y, const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error loading paddle texture" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Paddle::Move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

void Paddle::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Paddle::SetRotation(float angle) {
    sprite.setRotation(angle);
}

void Paddle::SetScale(float factorX, float factorY) {
    sprite.setScale(factorX, factorY);
}

sf::Vector2f Paddle::GetPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Paddle::GetGlobalBounds() const {
    return sprite.getGlobalBounds();
}
