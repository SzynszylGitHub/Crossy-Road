#pragma once
#include "Entity.h"
#include <random>

class Enemy : public Entity
{
public:
	
	Enemy(sf::Texture&, sf::Vector2f position);
	virtual void Move(sf::Vector2f) override;
	virtual void Update(sf::Time); // delay
	void SetVelocity(sf::Vector2f force);
	void changeDirection(sf::Vector2f);
	sf::Vector2f GetVelocity();
	void draw(sf::RenderWindow&);
	void SetDelay(sf::Time t1);
	sf::Vector2f getRandomVelocity();
	sf::Time GetDelay();
	void setPosition(sf::Vector2f);
protected:
	sf::Sprite obj;
	sf::Vector2f velocity = sf::Vector2f(15, 0);
	sf::Vector2f _direction = sf::Vector2f(1, 0);
private:
	sf::Time delay = sf::milliseconds(50);
	sf::Time LastUpdate = sf::Time::Zero;
};

