#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>

class Score {
public:
    Score(int charSize, const std::string& fontFile);
    void SetPosition(float x, float y);
    void SetString(const std::string& str);
    void Draw(sf::RenderWindow& window);
private:
    sf::Text text;
    sf::Font font;
};

#endif
