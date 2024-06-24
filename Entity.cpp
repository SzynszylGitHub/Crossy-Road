#include "Entity.h"

Entity::Entity(sf::Vector2f size)
{
	hitbox.setSize(size);
}

void Entity::SetSizeHitbox(sf::Vector2f size)
{
	hitbox.setSize(size);
}

bool Entity::Contact(sf::RectangleShape hitbox1)
{
	return hitbox.getGlobalBounds().intersects(hitbox1.getGlobalBounds());
}

void Entity::DrawHitbox(sf::RenderWindow& handle)
{
	handle.draw(hitbox);
}

void Entity::SetHitboxColor(sf::Color kolor)
{
	hitbox.setFillColor(kolor);
}

sf::Vector2f Entity::GetHitboxPosition()
{
	return hitbox.getPosition();
}

sf::Vector2f Entity::GetSizeHitbox()
{
	return hitbox.getSize();
}

void Entity::SetHitboxPosition(sf::Vector2f pos)
{
	hitbox.setPosition(pos);
}

void Entity::MoveHitbox(sf::Vector2f force)
{
	hitbox.move(force);
}

sf::RectangleShape Entity::GetHitbox()
{
	return hitbox;
}