#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

enum class TypeOfGround
{
	dirt,
	water,
	gravel,
	asphalt,
	grass
};
class Ground : public sf::Sprite, public Entity
{
public:
	Ground(sf::Texture&, sf::Vector2f, TypeOfGround);
	void SetPosition(sf::Vector2f);
	TypeOfGround GetTypeOfGround();
	void Move(sf::Vector2f) override;

private:
	TypeOfGround podloze;
};

