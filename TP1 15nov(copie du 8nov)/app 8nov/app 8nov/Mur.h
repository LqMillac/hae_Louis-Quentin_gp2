#pragma once
#include <SFML/Graphics.hpp>
class Mur
{
public:
	sf::RectangleShape mur;
	sf::RectangleShape MurCollider;
	sf::Vector2f position;
	sf::Texture *texture;

	Mur(sf::Vector2f pos,sf::Vector2f size,sf::Texture *tex)
	{

		MurCollider.setSize(size);
		mur.setSize(size);
		position = pos;
		//mur.setFillColor(sf::Color::Green);
		mur.setPosition(pos);
		texture = tex;
		if (texture)
		{
			mur.setTexture(texture);
		}

	}
	void SetPosition()
	{
		mur.setPosition(position);
		
	}
	
};

