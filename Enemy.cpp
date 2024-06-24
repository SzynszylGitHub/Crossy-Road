#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Texture& tekstura, sf::Vector2f position) 
	: Entity(sf::Vector2f(tekstura.getSize()))
{
	obj.setTexture(tekstura);
	obj.setPosition(position);
	SetHitboxPosition(position);
}

sf::Vector2f Enemy::getRandomVelocity() {
	std::random_device rd;  // Obiekt do generowania losowego ziarna
	std::mt19937 gen(rd()); // Generator Mersenne Twister z ziarna

	// Ustalanie zakresu generowanych liczb
	std::uniform_int_distribution<> dis(10, 40); // Zakres od 10 do 40
	
	return sf::Vector2f(dis(gen), 0);
}

void Enemy::Move(sf::Vector2f force)
{
	obj.move(force);
	MoveHitbox(force);
}

void Enemy::Update(sf::Time d1)
{
	if (d1 >= LastUpdate + delay)
	{
		LastUpdate = d1;
		if (obj.getPosition().x + velocity.x > 1550) {
			setPosition(sf::Vector2f(-50, obj.getPosition().y));
			//velocity = sf::Vector2f(getRandomVelocity().x * _direction.x,0 );
		}
		
		if (obj.getPosition().x - velocity.x < -100) {
			setPosition(sf::Vector2f(1550, obj.getPosition().y));
			
			//velocity = sf::Vector2f(getRandomVelocity().x * _direction.x, 0);
		}

		Move(velocity);
		if (velocity.x < 0)
			SetHitboxPosition(obj.getPosition() + sf::Vector2f(-50, -50));
			
	}
	
}

void Enemy::SetVelocity(sf::Vector2f force)
{
	velocity = force;
	velocity = sf::Vector2f(velocity.x * _direction.x, velocity.y * _direction.y);
}

void Enemy::changeDirection(sf::Vector2f direction) {
	_direction = direction;
	velocity = sf::Vector2f(velocity.x * _direction.x, velocity.y * _direction.y);
	
	obj.setOrigin(sf::Vector2f((obj.getTexture()->getSize().x) / 2
		, (obj.getTexture()->getSize().y) / 2));

	if(_direction.x == -1)
		obj.setRotation(180);
	else 
		obj.setRotation(0);

	setPosition(sf::Vector2f(obj.getPosition().x, obj.getPosition().y + 50));
}

sf::Vector2f Enemy::GetVelocity()
{
	return velocity;
}

void Enemy::draw(sf::RenderWindow& handle)
{
	handle.draw(obj);
}

void Enemy::SetDelay(sf::Time t1)
{
	delay = t1;
}

sf::Time Enemy::GetDelay()
{
	return delay;
}

void Enemy::setPosition(sf::Vector2f v1)
{
	obj.setPosition(v1);
	SetHitboxPosition(v1 + sf::Vector2f(0,0));
}