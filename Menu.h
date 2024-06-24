#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

enum class Options {
    Play,
    Option,
    Close,
    Default
};

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void setBackground(sf::Texture&);
    void PressSth(sf::Event);
    void moveUp();
    void moveDown();
    Options getSelectedItem() const;
    int getSelectedItemIndex() const;
    void handleClick(float x, float y);
    void OpenWindow(bool);
    bool isOpen() const;

private:
    unsigned selectedItemIndex;
    sf::Font font;
    sf::Sprite Background;
    std::vector<sf::Text> menuItems;
    
    bool _isOpen = true;


    const sf::Color selectedColor = sf::Color::Yellow;
    const sf::Color defaultColor = sf::Color::White;
};

