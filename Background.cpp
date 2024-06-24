#include "Background.h"

Background::Background()
{
}

Background::Background(std::vector<Ground*> v1 = std::vector<Ground*>(), sf::Vector2f pos = sf::Vector2f(0, 0))
	: vec(v1), position(pos)
{
}


void Background::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < vec.size(); i++)
	{
		window.draw(*vec[i]);
	}
}

void Background::AddGround(Ground* g1)
{
	vec.emplace_back(g1);
}

void Background::AddGround(std::vector<Ground*> ground)
{
	for (int i = 0; i < ground.size(); i++)
	{
		vec.emplace_back(ground[i]);
	}
}

void Background::SetInOrder()
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->SetPosition(position + sf::Vector2f(0, gap * i));
	}
}

void Background::SetDrawingPosition(int iter, sf::Vector2f pos)
{
	vec[iter]->setPosition(position + pos);
}

sf::Vector2f Background::GetDrawingPosition(int iter)
{
	return vec[iter] -> getPosition();
}

std::vector<Ground*> Background::init(sf::Texture &tek,sf::Texture &finish, sf::Vector2f windowsize, 
	float gap1, TypeOfGround type1, sf::Vector2f pos)
{
	float l = (windowsize.y - (finish.getSize().y * 2)) / gap1;
	std::vector<Ground*> g;
	g.emplace_back(new Ground(finish, sf::Vector2f(0, 0), TypeOfGround::grass));
	for(int i=1; i<l+1; i++)
	{
		g.emplace_back(new Ground(tek, sf::Vector2f(0, gap1*i)+pos, type1));
	}
	g.emplace_back(new Ground(finish, sf::Vector2f(0, gap1*(l+2)),TypeOfGround::grass));
	return g;
}

void Background::SetDrawingTexture(int iter, sf::Texture &tekstura)
{
	vec[iter]->setTexture(tekstura);
}

int Background::GetVectorSize()
{
	return vec.size();
}