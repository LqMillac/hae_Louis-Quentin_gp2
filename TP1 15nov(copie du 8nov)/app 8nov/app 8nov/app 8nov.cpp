// app 8nov.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include<Box2D/Box2D.h>

#include "Lib.h"
#include <direct.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Ball.h"
#include "Mur.h"

using namespace sf;
/*Vector2i Point1(100, 100);
Vector2i Point2(200, 200);
Vector2i Point3(300, 300);
Vector2i Point4(400, 400);
Vector2i Point5(500, 500);
Vector2i Point6(600, 600);
Vector2i Point7(700, 700);*/
static std::vector<Entity> CharList;
static std::vector<Ball> BallList;
static std::vector<Mur> WallList;
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
static Vector2f shPos(0,0);
//static Vector2f ballpos(shPos);

int squareSpeed = 8;

int Left=-1;
int Right=1;
int BallLife = 0;
int TankLife = 0;
bool Shoot = false;
bool Shoot2 = false;

sf::FloatRect boundingBox;
Vector2f Alpha;
sf::FloatRect otherBox;
float U = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
float V = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
float angle = (atan2(U, V) * 180 / 3.141592654);


Vector2f Beta;

void world(sf::RenderWindow &win)
{
	
	for (int i = 0; i < WallList.size(); i++)
	{
		if (CharList[0].tank.getGlobalBounds().intersects(WallList[i].mur.getGlobalBounds()))
		{
			CharList[0].position.x = Beta.x;
			CharList[0].position.y = Beta.y;
			squareSpeed = 0;
		}
	}
	if (CharList[0].tank.getGlobalBounds().intersects(CharList[1].tank.getGlobalBounds()))
	{
		CharList[0].position.x = Beta.x;
		CharList[0].position.y = Beta.y;
		squareSpeed = 0;
	}
	else
	{
		Beta.x = CharList[0].position.x;
		Beta.y = CharList[0].position.y;
		squareSpeed = 3;
	}

	for (int i = 0; i < BallList.size(); i++)
	{
		
		if (WallList[0].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
		{
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
		Elem.ball.move((Elem.U)/10,(Elem.V)/10);

		
	}
}
void drawWALL(sf::RenderWindow &win)
{
	for (Mur & Elem : WallList)
	{
		win.draw(Elem.mur);
	}
}

int main()
{
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	static RectangleShape sh;
	

	sf::RenderWindow window(sf::VideoMode(1920,1080), "SFML works!", sf::Style::Default, settings);
	
	int height = window.getSize().y;
	Mur MTop = Mur(Vector2f(0, 0), Vector2f(window.getSize().x, 3));
	Mur MDown = Mur(Vector2f(0, (window.getSize().y) - 3), Vector2f(window.getSize().x, 3));
	Mur MLeft = Mur(Vector2f(0, 0), Vector2f(3, height));
	Mur MRight = Mur(Vector2f(window.getSize().x - 3, 0), Vector2f(3, height));
	
	WallList.push_back(MTop);
	WallList.push_back(MDown);
	WallList.push_back(MLeft);
	WallList.push_back(MRight);
#pragma region MyRegion




	window.setVerticalSyncEnabled(true);
	sf::Clock clock;

	sf::Time appStart = clock.getElapsedTime();
	sf::Time frameStart = clock.getElapsedTime();
	sf::Time prevFrameStart = clock.getElapsedTime();

	float fps[4] = { 0.f,0.f,0.f,0.f };
	int step = 0;
	sf::Font * font = new sf::Font();
	sf::Texture texture;
	sf::Texture textureViseur;
	sf::Texture textureR;
	sf::Texture textureViseurR;
	if (!texture.loadFromFile("res/tank sans canon bleu.png"))
		printf("pasTank");
	if (!textureViseur.loadFromFile("res/canon tank bleu.png"))
		printf("pasTank");
	if (!textureR.loadFromFile("res/tank sans canon rouge.png"))
		printf("pasTank");
	if (!textureViseurR.loadFromFile("res/canon tank rouge.png"))
		printf("pasTank");

	

	Entity Player = Entity(Vector2f(150, 800), Vector2f(65, 65),&texture,&textureViseur);
	Entity Ennemy = Entity(Vector2f(1200, 100), Vector2f(65, 65), &textureR,&textureViseurR);

	CharList.push_back(Player);
	CharList.push_back(Ennemy);

	
	
	if (font->loadFromFile("Fonts/DejaVuSans.ttf") == false) {
		printf("no such font\n");
	}

	sf::Text myFpsCounter;
	int every = 0;
#pragma endregion
	while (window.isOpen())//on passe tout le temps DEBUT DE LA FRAME 
	{
		sf::Event event;//recup les evenement clavier/pad
		frameStart = clock.getElapsedTime();
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::KeyReleased:

				if (event.key.code == sf::Keyboard::I)
					printf("instant fps %f\n", fps[(step - 1) % 4]);

				if (event.key.code == sf::Keyboard::F)
					printf("fps %f\n", 0.25f*(fps[0] + fps[1] + fps[2] + fps[3]));

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
		//-------------------------------------------------------------
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			shPos.y -= squareSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			shPos.y += squareSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			shPos.x -= squareSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			shPos.x += squareSpeed;
		}*/
		if (sf::Joystick::isConnected(0))
		{
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			float angle = (atan2(x, y) * 180 / 3.141592654);
			
		
			if (x > 25 )
			{
				
				CharList[0].position.x += squareSpeed;
				CharList[0].tank.setRotation(-angle);
			
			}
			
		}
		if (sf::Joystick::isConnected(0))
		{
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			float angle = (atan2(x, y) * 180 / 3.141592654);
			
			
			if (x < -25)
			{
				
				CharList[0].position.x -= squareSpeed;
				CharList[0].tank.setRotation(-angle);
			

			}

		}
		if (sf::Joystick::isConnected(0))
		{
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float angle = (atan2(x, y) * 180 / 3.141592654);
		
			
			if (y > 25 )
			{
				
				CharList[0].position.y += squareSpeed;
				CharList[0].tank.setRotation(-angle);
			

			}

		}
		if (sf::Joystick::isConnected(0))
		{
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			
			float angle = (atan2(x, y) * 180 / 3.141592654);
			if (y < -25)
			{
				CharList[0].tank.setRotation(-angle);
				CharList[0].position.y -= squareSpeed;
			}

		}
	
		if (sf::Joystick::isConnected(0))
		{
			float U = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
			float V = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
			float angle = (atan2(U, V) * 180 / 3.141592654);
			if (U > 25 || U < -25 || V>25 || V < -25)
			{

				CharList[0].Viseur.setRotation(-angle);




				if (Shoot2 == false && sf::Joystick::isButtonPressed(0,5))
				{

					Ball Balle = Ball(Vector2f(CharList[0].Viseur.getPosition().x-5, CharList[0].Viseur.getPosition().y), 10);
					Balle.U = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
					Balle.V = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
					Balle.BallLife = 0;
					BallList.push_back(Balle);
					
					


				}
				if (sf::Joystick::isButtonPressed(0, 5))
				{
					Shoot2 = true;

				}
				else
				{
					Shoot2 = false;
				}
			}


		}

		if (sf::Joystick::isConnected(1))
		{
			float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
			float angle = (atan2(x, y) * 180 / 3.141592654);
			if (x > 25 )
			{
				CharList[1].tank.setRotation(-angle);
				CharList[1].position.x += squareSpeed;
				
			}

		}
		if (sf::Joystick::isConnected(1))
		{
			float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
			float angle = (atan2(x, y) * 180 / 3.141592654);
			if (x < -25 )
			{
				CharList[1].tank.setRotation(-angle);
				CharList[1].position.x -= squareSpeed;
			
			}

		}
		if (sf::Joystick::isConnected(1))
		{
			float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
			float angle = (atan2(x, y) * 180 / 3.141592654);
			if (y > 25 )
			{
				CharList[1].tank.setRotation(-angle);
				CharList[1].position.y += squareSpeed;
			
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

		if (sf::Joystick::isConnected(1))
		{
			float U = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
			float V = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
			float angle = (atan2(U, V) * 180 / 3.141592654);
			if (U > 25 || U < -25 || V>25 || V < -25)
			{

				CharList[1].Viseur.setRotation(-angle);
				CharList[1].Viseur.setRotation(-angle);




				if (Shoot == false && sf::Joystick::isButtonPressed(1, 5))
				{

					Ball Balle = Ball(Vector2f(CharList[1].Viseur.getPosition().x, CharList[1].Viseur.getPosition().y), 10);
					Balle.U = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
					Balle.V = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
					Balle.BallLife = 0;
					BallList.push_back(Balle);




				}
				if (sf::Joystick::isButtonPressed(1, 5))
				{
					Shoot = true;

				}
				else
				{
					Shoot = false;
				}
			}


		}



		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ballpos.y += fireball;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			ballpos.y -= fireball;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		{
			ballpos.x += fireball;
		}*/

		myFpsCounter.setPosition(8, 8);
		myFpsCounter.setFillColor(sf::Color::Red);
		myFpsCounter.setFont(*font);

		if (every == 0) {
			myFpsCounter.setString(std::string("FPS:") + std::to_string(fps[(step - 1) % 4]));
			every = 30;
		}
		every--;

		window.clear();//nettoie la frame
		//window.draw(shape);//on demande le dessin d' une forme
		//drawCurve(window,clock.getElapsedTime().asSeconds());
		//drawCatmull(window,clock.getElapsedTime().asSeconds());
		drawWALL(window);
		drawBall(window);
		drawTank(window);
	
		window.draw(myFpsCounter);
		

		//drawMovingSquare(window);
		//Firegun(window);
		window.display();//ca dessine et ca attend la vsync
		

		fps[step % 4] = 1.0f / (frameStart - prevFrameStart).asSeconds();
		prevFrameStart = frameStart;

		step++;
	}

	return 0;
}

