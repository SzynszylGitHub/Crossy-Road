#pragma once
#include <SFML/Graphics.hpp>


class Entity
{
public:
	Entity(sf::Vector2f size = sf::Vector2f(100, 100));
	virtual void Move(sf::Vector2f) = 0;
	void SetSizeHitbox(sf::Vector2f);
	bool Contact(sf::RectangleShape);
	void DrawHitbox(sf::RenderWindow&);
	void SetHitboxColor(sf::Color);
	void SetHitboxPosition(sf::Vector2f);
	sf::Vector2f GetHitboxPosition();
	sf::Vector2f GetSizeHitbox();
	void MoveHitbox(sf::Vector2f);
	sf::RectangleShape GetHitbox();

private:
	sf::RectangleShape hitbox;
};

