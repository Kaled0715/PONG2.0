#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <string>

class SoundManager {
public:
    SoundManager(const std::string& musicFile);
    void PlayBackgroundMusic();
    void StopBackgroundMusic();

private:
    sf::Music backgroundMusic;
};

#endif
