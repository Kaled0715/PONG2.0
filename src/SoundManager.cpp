#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager(const std::string& musicFile) {
    if (!backgroundMusic.openFromFile(musicFile)) {
        std::cerr << "Error loading background music from " << musicFile << std::endl;
    }
}

void SoundManager::PlayBackgroundMusic() {
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}

void SoundManager::StopBackgroundMusic() {
    backgroundMusic.stop();
}
