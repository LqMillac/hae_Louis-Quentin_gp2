// app 8nov.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Lib.h"
#include <direct.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Ball.h"
#include "Mur.h"
#include <Box2D/Box2D.h>
#include <iostream>

using namespace sf;
static std::vector<Entity> CharList;
static std::vector<Ball> BallList;
static std::vector<Wall> WallList;
sf::Color hsv(int hue, float sat, float val)
{
	hue %= 360;
	while (hue < 0) hue += 360;

	if (sat < 0.f) sat = 0.f;
	if (sat > 1.f) sat = 1.f;

	if (val < 0.f) val = 0.f;
	if (val > 1.f) val = 1.f;

	int h = hue / 60;
	float f = float(hue) / 60 - h;
	float p = val * (1.f - sat);
	float q = val * (1.f - sat * f);
	float t = val * (1.f - sat * (1 - f));

	switch (h)
	{
	default:
	case 0:
	case 6: return sf::Color(val * 255, t * 255, p * 255);
	case 1: return sf::Color(q * 255, val * 255, p * 255);
	case 2: return sf::Color(p * 255, val * 255, t * 255);
	case 3: return sf::Color(p * 255, q * 255, val * 255);
	case 4: return sf::Color(t * 255, p * 255, val * 255);
	case 5: return sf::Color(val * 255, p * 255, q * 255);
	}
}
static Vector2f shPos(0, 0);
static int height;
static int width;
//static Vector2f ballpos(shPos);

int squareSpeed = 3;
int BallSpeed = 5;
int Left = -1;
int Right = 1;
int ScoreBleu = 0;
int ScoreRouge = 0;

sf::FloatRect boundingBox;
Vector2f Alpha;
sf::FloatRect otherBox;

Vector2f Beta;
Vector2f Beta2;
sf::Text VictoryText;
sf::Text ScoreTextR;
sf::Text ScoreTextB;

void Startwin(sf::RenderWindow &win, int NPlayer)
{
	std::string Player;

	VictoryText.setCharacterSize(70);
	if (NPlayer == 1)
	{
		VictoryText.setFillColor(sf::Color::Blue);
		Player = "Bleu";
	}
	if (NPlayer == 2)
	{
		VictoryText.setFillColor(sf::Color::Red);
		Player = "Rouge";
	}
	VictoryText.setString("Victoire du joueur " + Player);
	FloatRect Alpha = VictoryText.getLocalBounds();
	VictoryText.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	VictoryText.setPosition(Vector2f(win.getSize().x / 2, win.getSize().y - win.getSize().y / 1.1f));
	
	int i = 0;
}
void ScoreTB(sf::RenderWindow &win)
{
	int ScoreB;
	ScoreTextB.setCharacterSize(30);
	ScoreTextB.setFillColor(sf::Color::Blue);
	ScoreB = ScoreBleu;
	
	ScoreTextB.setString("Score : " +ScoreB );

	FloatRect Alpha = VictoryText.getLocalBounds();
	ScoreTextB.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	ScoreTextB.setPosition(Vector2f(win.getSize().x / 29, win.getSize().y - win.getSize().y /1.02f));
	
   
}
void ScoreTR(sf::RenderWindow &win)
{
	int ScoreR;
	ScoreTextR.setCharacterSize(30);
	ScoreTextR.setFillColor(sf::Color::Red);
	ScoreR = ScoreRouge;

	ScoreTextR.setString("Score : " + ScoreR);

	FloatRect Alpha = VictoryText.getLocalBounds();
	ScoreTextR.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	ScoreTextR.setPosition(Vector2f(win.getSize().x / 29, win.getSize().y - win.getSize().y / 1.05f));


}
void world(sf::RenderWindow &win)
{
	ScoreTB(win);
	ScoreTR(win);
	for (int i = 0; i < WallList.size(); i++)
	{
		if (CharList.size() > 1)
		{
			if (CharList[0].tank.getGlobalBounds().intersects(WallList[i].mur.getGlobalBounds()))
			{
				CharList[0].position.x = Beta.x;
				CharList[0].position.y = Beta.y;
				//squareSpeed = 0;
			}
			if (CharList[1].tank.getGlobalBounds().intersects(WallList[i].mur.getGlobalBounds()))
			{
				CharList[1].position.x = Beta2.x;
				CharList[1].position.y = Beta2.y;
			}
		}
	}
	if (CharList.size() > 1)
	{
		if (CharList[0].tank.getGlobalBounds().intersects(CharList[1].tank.getGlobalBounds()))
		{
			CharList[0].position.x = Beta.x;
			CharList[0].position.y = Beta.y;
			CharList[1].position.x = Beta2.x;
			CharList[1].position.y = Beta2.y;
			squareSpeed = 0;
		}
		else
		{
			Beta.x = CharList[0].position.x;
			Beta.y = CharList[0].position.y;
			Beta2.x = CharList[1].position.x;
			Beta2.y = CharList[1].position.y;
			squareSpeed = 3;
		}
		for (int i = 0; i < BallList.size(); i++)
		{
			if (WallList[0].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				BallList[i].ball.setPosition(Vector2f(BallList[i].ball.getPosition().x, BallList[i].ball.getPosition().y + 15));
				BallList[i].V = -BallList[i].V;
				if (BallList[i].BallLife == 1)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[1].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				BallList[i].ball.setPosition(Vector2f(BallList[i].ball.getPosition().x, BallList[i].ball.getPosition().y - 15));
				BallList[i].V = -BallList[i].V;
				if (BallList[i].BallLife == 1)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[2].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				BallList[i].ball.setPosition(Vector2f(BallList[i].ball.getPosition().x + 15, BallList[i].ball.getPosition().y));
				BallList[i].U = -BallList[i].U;
				if (BallList[i].BallLife == 1)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[3].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				BallList[i].ball.setPosition(Vector2f(BallList[i].ball.getPosition().x - 15, BallList[i].ball.getPosition().y));
				BallList[i].U = -BallList[i].U;
				if (BallList[i].BallLife == 1)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (CharList.size() > 1)
			{
				if (!CharList[0].tank.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()) && !CharList[1].tank.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
				{
					if (BallList[i].spawned == true)
					{
						BallList[i].spawned = false;
					}
				}
				if (CharList[0].tank.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
				{
					if (BallList[i].spawned == false)
					{
						printf("Hello");
						ScoreBleu++;
						Startwin(win, 2);
						CharList.erase(CharList.begin());
						
						break;
					}
				}

				if (CharList[1].tank.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
				{
					if (BallList[i].spawned == false)
					{
						ScoreRouge++;
						Startwin(win, 1);
						CharList.erase(CharList.begin() + 1);
						
					}
				}
			}
		}

	}
}

void drawMur(sf::RenderWindow &win)
{
	for (Wall &Elem : WallList)
	{
		win.draw(Elem.mur);
		Elem.SetPosition();

	}
}
void drawTank(sf::RenderWindow &win)
{
	for (Entity &Elem : CharList)
	{
		win.draw(Elem.tank);
		win.draw(Elem.Viseur);
		Elem.SetPosition();
	
	}
}

void drawBall(sf::RenderWindow &win)
{
	for (Ball &Elem : BallList)
	{
		win.draw(Elem.ball);
		Elem.ball.move(Elem.U / 8, Elem.V / 8);
		Elem.ball.rotate(3);

	}
}

int main()
{
	bool Shoot = false;
	bool Shoot2 = false;
	sf::Font * font = new sf::Font();
	sf::Font * FontScore = new sf::Font();
	sf::Font * FontScore2 = new sf::Font();
	sf::Texture texture;
	sf::Texture textureViseur;
	sf::Texture textureR;
	sf::Texture textureViseurR;
	sf::Texture textureWall;
	sf::Texture textureBall;
	sf::Texture textureBall2;

	if (!textureWall.loadFromFile("res/wall.png"))
		printf("pas mur");
	if (!texture.loadFromFile("res/tank sans canon bleu.png"))
		printf("pasTank");
	if (!textureViseur.loadFromFile("res/canon tank bleu.png"))
		printf("pasTank");
	if (!textureR.loadFromFile("res/tank sans canon rouge.png"))
		printf("pasTank");
	if (!textureViseurR.loadFromFile("res/canon tank rouge.png"))
		printf("pasTank");
	if (!textureBall.loadFromFile("res/fireball.png"))
		printf("pas ball");
	if (!textureBall2.loadFromFile("res/fireball2.png"))
		printf("pas ball");
	if (font->loadFromFile("res/DejaVuSans.ttf") == false)
	{
		printf("no such font");

	}
	if (FontScore->loadFromFile("res/arial.ttf") == false)
	{
		printf("no such font");
	}
	if (FontScore2->loadFromFile("res/arial.ttf") == false)
	{
		printf("no such font");
	}
	
	VictoryText.setFont(*font);
	ScoreTextB.setFont(*FontScore);
	ScoreTextR.setFont(*FontScore2);
	Entity Player = Entity(Vector2f(150, 800), Vector2f(65, 65), &texture, &textureViseur);
	Entity Ennemy = Entity(Vector2f(1200, 100), Vector2f(65, 65), &textureR, &textureViseurR);


	CharList.push_back(Player);
	CharList.push_back(Ennemy);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	static RectangleShape sh;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, settings);
	height = window.getSize().y;
	width = window.getSize().x;
	Wall Up = Wall(Vector2f(0, 0), Vector2f(window.getSize().x, 10), &textureWall);
	Wall Down = Wall(Vector2f(0, (window.getSize().y) - 3), Vector2f(window.getSize().x, 3), &textureWall);
	Wall Left = Wall(Vector2f(0, 0), Vector2f(10, height), &textureWall);
	Wall Right = Wall(Vector2f(window.getSize().x - 3, 0), Vector2f(3, height), &textureWall);
	WallList.push_back(Up);
	WallList.push_back(Down);
	WallList.push_back(Left);
	WallList.push_back(Right);

	window.setVerticalSyncEnabled(true);

	while (window.isOpen())//on passe tout le temps DEBUT DE LA FRAME 
	{
		sf::Event event;//recup les evenement clavier/pad
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::KeyReleased:

				break;


			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		world(window);
		sf::Vector2i globalPosition = sf::Mouse::getPosition();


#pragma region Controls
		if (CharList.size() > 1)
		{
			if (sf::Joystick::isConnected(0))
			{
				float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (x > 25)
				{
					CharList[0].tank.setRotation(-angle);
					CharList[0].position.x += squareSpeed;
				}

			}
			if (sf::Joystick::isConnected(1))
			{
				float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (x > 25)
				{
					CharList[1].tank.setRotation(-angle);
					CharList[1].position.x += squareSpeed;
				}

			}
			if (sf::Joystick::isConnected(0))
			{
				float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (x < -25)
				{
					CharList[0].tank.setRotation(-angle);
					CharList[0].position.x -= squareSpeed;

				}

			}
			if (sf::Joystick::isConnected(1))
			{
				float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (x < -25)
				{
					CharList[1].tank.setRotation(-angle);
					CharList[1].position.x -= squareSpeed;

				}

			}
			if (sf::Joystick::isConnected(0))
			{
				float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (y > 25)
				{
					CharList[0].tank.setRotation(-angle);
					CharList[0].position.y += squareSpeed;

				}

			}
			if (sf::Joystick::isConnected(1))
			{
				float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (y > 25)
				{
					CharList[1].tank.setRotation(-angle);
					CharList[1].position.y += squareSpeed;

				}

			}
			if (sf::Joystick::isConnected(0))
			{
				float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (y < -25)
				{
					CharList[0].tank.setRotation(-angle);
					CharList[0].position.y -= squareSpeed;
				}

			}
			if (sf::Joystick::isConnected(1))
			{
				float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
				float angle = (atan2(x, y) * 180 / 3.141592654);
				if (y < -25)
				{
					CharList[1].tank.setRotation(-angle);
					CharList[1].position.y -= squareSpeed;
				}

			}
			if (sf::Joystick::isConnected)
			{

				float u = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
				float r = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
				if (u > 25 || u < -25 || r>25 || r < -25)
				{
					float angle = (atan2(u, r) * 180) / 3.141592654;
					CharList[0].Viseur.setRotation(-angle);


					if (!Shoot && sf::Joystick::getAxisPosition(0, Joystick::Z) < -50)
					{
						Ball Balle = Ball(sf::Vector2f(CharList[0].Viseur.getPosition().x - 5, CharList[0].Viseur.getPosition().y), 15,&textureBall);
						Balle.U = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
						Balle.V = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
						Balle.BallLife = 0;
						BallList.push_back(Balle);
					}
					if (sf::Joystick::getAxisPosition(0, Joystick::Z) < -50)
					{
						Shoot = true;
					}
					else
					{
						Shoot = false;
					}
				}

			}
			if (sf::Joystick::isConnected)
			{
				float u = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
				float r = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
				
				if (u > 25 || u < -25 || r>25 || r < -25)
				{
					float angle = (atan2(u, r) * 180) / 3.141592654;
					CharList[1].Viseur.setRotation(-angle);

					if (!Shoot2 && sf::Joystick::getAxisPosition(1, Joystick::Z) < -50)
					{
						Ball Balle = Ball(sf::Vector2f(CharList[1].Viseur.getPosition().x - 5, CharList[1].Viseur.getPosition().y), 15, &textureBall2);
						Balle.U = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
						Balle.V = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
						Balle.BallLife = 0;
						BallList.push_back(Balle);
					}
					if (sf::Joystick::getAxisPosition(1, Joystick::Z) < -50)
					{
						Shoot2 = true;
					}
					else
					{
						Shoot2 = false;
					}
				}

			}
		}
		

		
#pragma endregion
		window.clear();

		
		drawBall(window);
		drawMur(window);
		drawTank(window);
		window.draw(ScoreTextB);
		window.draw(ScoreTextR);
		window.draw(VictoryText);
		window.display();//ca dessine et ca attend la vsync

	}

	return 0;
}

