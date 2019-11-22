#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::Vector2f position;
	sf::Vector2f ViseurSize;
	sf::RectangleShape tank;
	sf::RectangleShape Viseur;
	sf::RectangleShape BoxCollider;
	sf::FloatRect Box;
	Entity(sf::Vector2f pos,sf::Vector2f size)
	{
		BoxCollider.setSize(size);
		tank.setOrigin((size.x / 2), (size.y / 2));
		Viseur.setOrigin((Viseur.getSize().x / 2), 0);
		tank.setSize(size);
		position = pos;
		tank.setFillColor(sf::Color::Magenta);
		tank.setPosition(pos);

		
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



