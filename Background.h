#pragma once
#include "Ground.h"
#include <vector>

class Background
{
public:
	Background();
	Background(std::vector<Ground*>, sf::Vector2f pos);
	void Draw(sf::RenderWindow&);
	void AddGround(Ground*);
	void AddGround(std::vector<Ground*>);
	void SetInOrder();
	void SetDrawingPosition(int, sf::Vector2f);
	sf::Vector2f GetDrawingPosition(int);
	static std::vector<Ground*> init(sf::Texture&, sf::Texture& finish, sf::Vector2f windowsize, float,
		TypeOfGround, sf::Vector2f pos);
	void SetDrawingTexture(int, sf::Texture&);
	int GetVectorSize();

private:
	std::vector<Ground*> vec;
	float gap = 100;
	sf::Vector2f position = sf::Vector2f(0, 0);
};

