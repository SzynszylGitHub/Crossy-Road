#include "HeartDisplay.h"

HeartDisplay::HeartDisplay(const std::string& textureFile, int numHearts, float heartSpacing) {
    if (!heartTexture.loadFromFile(textureFile)) {
        printf("incorect image adres\n");
    }

    for (int i = 0; i < numHearts; ++i) {
        sf::Sprite heart(heartTexture);
        heart.setPosition(i * -heartSpacing, 0);
        hearts.push_back(heart);
    }
}

void HeartDisplay::draw(sf::RenderWindow& window) {
    for (const auto& heart : hearts) {
        window.draw(heart);
    }
}

void HeartDisplay::addHeart() {
    hearts.emplace_back(sf::Sprite(heartTexture));
}

void HeartDisplay::deleteHeart() {
    if(hearts.size() > 0)
    hearts.erase(hearts.end() - 1);
}

void HeartDisplay::setPosition(sf::Vector2f position) {
    _position = position;

    for (auto& el : hearts)
        el.setPosition(el.getPosition() + _position);
}


sf::Vector2f HeartDisplay::getPosition() {
    return _position;
}

int HeartDisplay::getHp() {
    return hearts.size();
}
