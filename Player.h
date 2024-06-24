#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(sf::Texture&, sf::Vector2f pos);
	void Move(sf::Vector2f) override;
	void setPosition(sf::Vector2f);
	void draw(sf::RenderWindow&);
	sf::Sprite GetSprite();
	void Control(sf::Event);
	void ResizeHitbox(sf::Vector2f);

private:
	sf::Sprite obj;

};

