#pragma once
#include <SFML/Graphics.hpp>
#include "Lib.h"
#include <math.h>
class Particule
{
public:
	int timer;
	int timermax;
	CircleShape shape1;
	Vector2f Position;
	bool Mort;

	bool operator == (const Particule& s) const { return (Position == s.Position && timer == s.timer); }
	bool operator != (const Particule& s) const { return !operator==(s); }

	Particule(Vector2f pos, sf::Texture * texture, int size, bool mort) {
		Position = pos;

		shape1.setRadius(rand() % ((size + 2) - (size - 2) + 1) + (size - 2));

		shape1.setTexture(texture);

		shape1.setRotation(rand() % ((180) - (-180) + 1) + (-180));
		shape1.setOrigin(shape1.getRadius(), shape1.getRadius());
		shape1.setPosition(pos);
		IntRect Rect(Vector2i(512 / 4, 0), Vector2i(125, 125));

		shape1.setTextureRect(Rect);

		timermax = rand() % (6 * size - 4 * size + 1) + 4 * size;
		timer = timermax;
		Mort=mort;
	}
	void UpdateParticule()
	{
		if (Mort)
		{

		}
	}

	
	
};

