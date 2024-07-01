#include "Score.h"
#include <iostream>

Score::Score(int charSize, const std::string& fontFile) {
    if (!font.loadFromFile(fontFile)) {
        std::cerr << "Error loading font" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(charSize);
}

void Score::SetPosition(float x, float y) {
    text.setPosition(x, y);
}

void Score::SetString(const std::string& str) {
    text.setString(str);
}

void Score::Draw(sf::RenderWindow& window) {
    window.draw(text);
}
