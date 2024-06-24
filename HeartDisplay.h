#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>



class HeartDisplay {
public:
    HeartDisplay(const std::string& textureFile, int numHearts, float heartSpacing);
    void draw(sf::RenderWindow& window);
    void addHeart();
    void deleteHeart();
    void setPosition(sf::Vector2f position);
    int getHp();
    sf::Vector2f getPosition();

private:
    sf::Texture heartTexture;
    std::vector<sf::Sprite> hearts;
    sf::Vector2f _position = sf::Vector2f(0,0);
};
