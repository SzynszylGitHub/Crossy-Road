#include "Menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("Assets/font/EnglishTowne.ttf")) {
        printf("nie znaleziono font'a \n");
    }

    std::vector<std::string> items = { "Play", "Options", "Exit" };
    for (int i = 0; i < items.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(items[i]);
        text.setFillColor(i == 0 ? selectedColor : defaultColor);
        text.setPosition(sf::Vector2f(width / 2 - text.getGlobalBounds().width / 2 - (0),
            height / (items.size() + 1) * (i + 1) - text.getCharacterSize() * items.size()));
        text.setCharacterSize(60);
        menuItems.push_back(text);
    }

    selectedItemIndex = 0;
}

Menu::~Menu() {}

void Menu::setBackground(sf::Texture& t1) {
    Background.setTexture(t1);
}

void Menu::draw(sf::RenderWindow& window) {
    if (!_isOpen) return;
    
    window.draw(Background);

    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menuItems[selectedItemIndex].setFillColor(defaultColor);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(selectedColor);
    }
}

void Menu::moveDown() {
    
    if (selectedItemIndex + 1 < menuItems.size()) {
        menuItems[selectedItemIndex].setFillColor(defaultColor);
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(selectedColor);
    }
}

Options Menu::getSelectedItem() const {
    switch (selectedItemIndex)
    {
    case 0: {
        return Options::Play;
    }break;
    case 1: {
        return Options::Option;
    }break;
    case 2: {
        return Options::Close;
    }break;
    default:
        return Options::Default;
        break;
    }
}

int Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}

void Menu::handleClick(float x, float y) {
    if (!_isOpen) return;

    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i].getGlobalBounds().contains(x, y)) {
            menuItems[selectedItemIndex].setFillColor(defaultColor);
            selectedItemIndex = i;
            menuItems[selectedItemIndex].setFillColor(selectedColor);
            break;
        }
    }
}

void Menu::OpenWindow(bool fl) {
    _isOpen = fl;
}

bool Menu::isOpen()const{
    return _isOpen;
}

void Menu::PressSth(sf::Event event) {
    if(_isOpen)
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();
        }
        if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        }
    }
}