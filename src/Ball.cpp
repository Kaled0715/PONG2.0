#include "Ball.h"
#include <iostream>

Ball::Ball(int x, int y, const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error loading ball texture" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Ball::Move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

void Ball::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Ball::SetPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void Ball::SetScale(float factorX, float factorY) {
    sprite.setScale(factorX, factorY);
}

sf::Vector2f Ball::GetPosition() const {
    return sprite.getPosition();
}
