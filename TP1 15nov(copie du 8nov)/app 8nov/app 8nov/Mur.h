#pragma once
#include <SFML/Graphics.hpp>
class Wall
{
public:
	sf::Vector2f position;
	sf::RectangleShape mur;
	sf::Texture *texture;
	Wall(sf::Vector2f pos, sf::Vector2f size, sf::Texture *tex)
	{
		mur.setSize(size);
		position = pos;
		//mur.setFillColor(sf::Color::Magenta);
		mur.setPosition(pos);
		texture = tex;
		if (texture)
		{
			mur.setTexture(texture);
		}

	};
	void SetPosition()
	{
		mur.setPosition(position);
	}
};

