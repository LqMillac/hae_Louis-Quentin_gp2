#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
	
	
public:
	sf::Vector2f position;
	sf::CircleShape ball;
	sf::CircleShape BallCollider;
	sf::Texture *texture;
	int BallLife;
	bool spawned = true;
	float U;
	float V;
	Ball(sf::Vector2f pos,float size,sf::Texture *tex)
	{
		ball.setRadius(size+7);
		position = pos;
		//ball.setFillColor(sf::Color::Red);
		ball.setPosition(pos);
		ball.setOrigin(ball.getRadius(), ball.getRadius());
		
		texture = tex;
		if (texture)
		{
			ball.setTexture(texture);

		}


	}
	void SetPosition()
	{
		ball.setPosition(position);
	}

	
};

