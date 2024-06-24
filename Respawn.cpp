#include "Respawn.h"

Respawn::Respawn()
{
};

Respawn::Respawn(std::vector <Enemy*> enem, sf::Vector2f pos) : enemies(enem), position(pos)
{
};

void Respawn::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i] -> draw(window);
	}
}

unsigned int Respawn::GetSize()
{
	return enemies.size();
}

void Respawn::AddEnemies(Enemy* en)
{
	enemies.emplace_back(en);
}

void Respawn::Update(sf::Time t1)
{
	for (auto& el : enemies)
	{
		el->Update(t1);
	}
}

std::vector<Enemy*> Respawn::init
(std::vector <sf::Texture*> textures, sf::Vector2f windowSize, sf::Vector2f position, float gap)
{
	// Inicjalizacja generatora liczb losowych za pomoc¹ ziarna
	std::random_device rd;  // Obiekt do generowania losowego ziarna
	std::mt19937 gen(rd()); // Generator Mersenne Twister z ziarna

	// Ustalanie zakresu generowanych liczb
	std::uniform_int_distribution<> dis(10, 40); // Zakres od 10 do 40
	std::uniform_int_distribution<> dis1(0, 1); // Zakres od 0 do 1
	std::uniform_int_distribution<> dis2(0, textures.size()-1); 
	std::uniform_int_distribution<> dis3(3, 6); 

	const int r = 50;
	int _left = -r;
	int _right = windowSize.x + r;
	int pos;

	float l = (windowSize.y) / gap;
	std::vector<Enemy*> g;
	for (int i = 1; i < l-1; i++)
	{
		if (dis1(gen)) pos = _left;
		else pos = _right;
		
		sf::Vector2f velocity = sf::Vector2f(dis(gen), 0);
		int numOfVehicle = dis3(gen);
	
		if(pos == _left)
			for (int j = 0; j < numOfVehicle; j++) {
				g.emplace_back(new Auta(*textures[dis2(gen)]
					, sf::Vector2f(pos + (300 * dis3(gen) / 2), gap * i)));
				g[g.size() - 1]->SetVelocity(velocity);
			}
		if (pos == _right) {
			for (int j = 0; j < numOfVehicle; j++) {
				g.emplace_back(new Auta(*textures[dis2(gen)]
					, sf::Vector2f(pos - (300 * dis3(gen) / 2), gap * i)));
				g[g.size() - 1]->SetVelocity(velocity);
				g[g.size() - 1]->changeDirection(sf::Vector2f(-1,0));
			}
		}

	}

	return g;
}

std::vector<Enemy*>::iterator Respawn::begin()
{
	return enemies.begin();
}

std::vector<Enemy*>::iterator Respawn::end()
{
	return enemies.end();
}
//std::vector<Enemy*> Respawn::init
//(std::vector<Enemy*>(*f)(std::vector<sf::Texture*>),std::vector<sf::Texture> textures)
//{
//	enemies = f(textures);
//}

