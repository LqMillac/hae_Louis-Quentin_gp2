#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::Vector2f position;
	sf::RectangleShape tank;
	sf::RectangleShape BoxCollider;
	sf::FloatRect Box;
	Entity(sf::Vector2f pos,sf::Vector2f size)
	{
		BoxCollider.setSize(size);
		tank.setSize(size);
		position = pos;
		tank.setFillColor(sf::Color::Magenta);
		tank.setPosition(pos);
		
	};
	void SetPosition()
	{
		tank.setPosition(position);
	}
	
};



