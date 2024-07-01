#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameObject {
public:
    virtual void loadTexture(const string& filePath) = 0;
    virtual void setProperties() = 0;
    virtual void draw(RenderWindow& window) = 0;
};

#endif // GAMEOBJECT_H
