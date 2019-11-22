#pragma once
#include <SFML/Graphics.hpp>
class Mur
{
public:
	sf::RectangleShape mur;
	sf::RectangleShape MurCollider;
	sf::Vector2f position;

	Mur(sf::Vector2f pos,sf::Vector2f size)
	{
		MurCollider.setSize(size);
		mur.setSize(size);
		position = pos;
		mur.setFillColor(sf::Color::Green);
		mur.setPosition(pos);

	}
	void SetPosition()
	{
		mur.setPosition(position);
		
	}
	
};

