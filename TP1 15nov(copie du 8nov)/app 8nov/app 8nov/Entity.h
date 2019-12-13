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
	sf::Texture *textureViseur;
	int TankLife;

	sf::FloatRect Box;
	Entity(sf::Vector2f pos,sf::Vector2f size,sf::Texture* tex,sf::Texture*texV)
	{
		BoxCollider.setSize(size);
		tank.setOrigin((size.x / 2), (size.y / 2));
		Viseur.setOrigin((Viseur.getSize().x / 2)+20, 0+14);
		tank.setSize(size);
		position = pos;
		tank.setFillColor(sf::Color::Magenta);
		tank.setPosition(pos);
		Viseur.setPosition(pos);
		//Viseur.setFillColor(sf::Color::Cyan);
		Viseur.setSize(sf::Vector2f(44,50));
		texture = tex;
		textureViseur = texV;
		if (texture ) {
			tank.setTexture(texture);
			tank.setFillColor(sf::Color::White);
		
			
		}
		if (textureViseur)
		{
			Viseur.setTexture(textureViseur);
			Viseur.setFillColor(sf::Color::White);
		}
		
		
		
		
	
		
	};
	void SetPosition()
	{
		tank.setPosition(position);
		Viseur.setPosition(position);
	}
	
};



