#include "Ground.h"


Ground::Ground(sf::Texture &tekstura, sf::Vector2f pozycja, TypeOfGround tlo) 
	: sf::Sprite(tekstura), Entity(sf::Vector2f(tekstura.getSize()))
{
	setPosition(pozycja);
	podloze = tlo;
	sf::Vector2f size = sf::Vector2f(tekstura.getSize());
	SetHitboxColor(sf::Color::Cyan);
	SetHitboxPosition(pozycja);

}

void Ground::SetPosition(sf::Vector2f pozycja)
{
	setPosition(pozycja);
	SetHitboxPosition(pozycja);
}

TypeOfGround Ground::GetTypeOfGround()
{
	return podloze;
}

void Ground::Move(sf::Vector2f v1)
{
	//nie implementujemy ruchu dla ziemi
}

