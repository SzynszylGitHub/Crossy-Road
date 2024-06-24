#pragma once
#include "Auta.h"
#include <vector>
#include <random>

class Respawn
{
public:
	Respawn();
	Respawn(std::vector <Enemy*> enem, sf::Vector2f pos);
	void Draw(sf::RenderWindow&);
	void Update(sf::Time);
	void AddEnemies(Enemy*);
	unsigned int GetSize();
	static std::vector<Enemy*> init(std::vector <sf::Texture*> textures, 
		sf::Vector2f windowSize, sf::Vector2f position = sf::Vector2f(0, 0), 
		float gap = 100 );
	static std::vector<Enemy*> init
	(std::vector<Enemy*> (*f)(std::vector<sf::Texture*>), 
		std::vector<sf::Texture> textures);
	std::vector<Enemy*>::iterator begin();
	std::vector<Enemy*>::iterator end();
private:
	std::vector <Enemy*> enemies;
	sf::Vector2f position;

public:
	float gap = 100;
};

