#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
	
	
public:
	sf::Vector2f position;
	sf::CircleShape ball;
	sf::CircleShape BallCollider;
	int BallLife;
	float U;
	float V;
	Ball(sf::Vector2f pos,float size)
	{
		ball.setRadius(size);
		position = pos;
		ball.setFillColor(sf::Color::Red);
		ball.setPosition(pos);
		ball.setOrigin((size/2),(size/2));


	}
	void SetPosition()
	{
		ball.setPosition(position);
	}

	
};

