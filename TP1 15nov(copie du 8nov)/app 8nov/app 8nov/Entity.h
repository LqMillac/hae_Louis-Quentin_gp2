#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::Vector2f position;
	sf::Vector2f ViseurSize;
	sf::Vector2f SpawnBall;
	sf::RectangleShape tank;
	sf::RectangleShape Viseur;
	sf::RectangleShape BoxCollider;
	sf::Texture *texture;
	int TankLife;

	sf::FloatRect Box;
	Entity(sf::Vector2f pos,sf::Vector2f size,sf::Texture* tex)
	{
		BoxCollider.setSize(size);
		tank.setOrigin((size.x / 2), (size.y / 2));
		Viseur.setOrigin((Viseur.getSize().x / 2), 0);
		tank.setSize(size);
		position = pos;
		tank.setFillColor(sf::Color::Magenta);
		tank.setPosition(pos);
		texture = tex;
		if (texture) {
			tank.setTexture(texture);
			tank.setFillColor(sf::Color::White);
		}
		
		Viseur.setPosition(pos);
		
		Viseur.setFillColor(sf::Color::Cyan);
		Viseur.setSize(sf::Vector2f(5,44));
		
	
		
	};
	void SetPosition()
	{
		tank.setPosition(position);
		Viseur.setPosition(position);
	}
	
};



