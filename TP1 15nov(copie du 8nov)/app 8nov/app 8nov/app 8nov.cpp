// app 8nov.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Lib.h"
#include <direct.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Ball.h"
#include "Mur.h"
#include <iostream>

using namespace sf;
static std::vector<Entity> CharList;
static std::vector<Ball> BallList;
static std::vector<Wall> WallList;


static Vector2f shPos(0, 0);
static int height;
static int width;


int squareSpeed = 3;
int BallSpeed = 5;
int ballcad= 0;
int ballcad2 = 0;


int ScoreBleu = 0;
int ScoreRouge = 0;
bool EndGame = false;
bool BlueWin = false;
bool RedWin = false;
bool Pause = false;
bool menu = true;
bool mort = false;
bool mort2 = false;
bool boumballon = false;
bool boumballon2 = false;




sf::FloatRect boundingBox;
Vector2f Alpha;
sf::FloatRect otherBox;

sf::Texture texture;
sf::Texture textureViseur;
sf::Texture textureR;
sf::Texture textureViseurR;
sf::Texture textureWall;
sf::Texture textureBall;
sf::Texture textureBall2;
sf::SoundBuffer Boom;
sf::Sound Destruction;
sf::Texture ExploBallon;
Sprite BallonBoom(ExploBallon);


sf::RenderWindow window;

Entity Player = Entity(Vector2f(150, 800), Vector2f(65, 65), &texture, &textureViseur);
Entity Ennemy = Entity(Vector2f(1200, 100), Vector2f(65, 65), &textureR, &textureViseurR);

Wall Up = Wall(Vector2f(0, 0), Vector2f(window.getSize().x, 10), &textureWall);
Wall Down = Wall(Vector2f(0, (window.getSize().y) - 3), Vector2f(window.getSize().x, 3), &textureWall);
Wall Left = Wall(Vector2f(0, 0), Vector2f(10, height), &textureWall);
Wall Right = Wall(Vector2f(window.getSize().x - 3, 0), Vector2f(3, height), &textureWall);
Wall Bordure1 = Wall(Vector2f(50, 50), Vector2f(500,500), &textureWall);
Wall Bordure2 = Wall(Vector2f(50, 50), Vector2f(500, 500), &textureWall);
Wall Bordure3 = Wall(Vector2f(50, 50), Vector2f(500, 500), &textureWall);
Wall Bordure4 = Wall(Vector2f(50, 50), Vector2f(500, 500), &textureWall);
Wall Bordure5 = Wall(Vector2f(50, 50), Vector2f(500, 500), &textureWall);
Wall Bordure6 = Wall(Vector2f(50, 50), Vector2f(500, 500), &textureWall);

Ball Balle = Ball(sf::Vector2f(), 15, &textureBall);

Vector2f Beta;
Vector2f Beta2;
sf::Text VictoryText;
sf::Text VictoryRoundText;
sf::Text NextRoundText;
sf::Text ScoreTextR;
sf::Text ScoreTextB;
sf::Text MenuText;

void Startwin(sf::RenderWindow &win, int NPlayer)
{
	std::string Player;

	VictoryText.setCharacterSize(70);
	NextRoundText.setCharacterSize(50);
	if (NPlayer == 1)
	{
		VictoryText.setFillColor(sf::Color(0x42DBD6ff));
		NextRoundText.setFillColor(sf::Color(0x42DBD6ff));
		Player = "Bleu";
		
	}
	if (NPlayer == 2)
	{
		VictoryText.setFillColor(sf::Color(0xD29EF5ff));
		NextRoundText.setFillColor(sf::Color(0xD29EF5ff));
		Player = "Rose";
		
	}
	
		VictoryText.setString("Victoire du joueur " + Player);
		NextRoundText.setString("Appuyer sur B pour lancer la partie suivante");

	FloatRect Alpha = VictoryText.getLocalBounds();
	VictoryText.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	VictoryText.setPosition(Vector2f(win.getSize().x / 2, win.getSize().y - win.getSize().y / 1.7f));
	NextRoundText.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	NextRoundText.setPosition(Vector2f(win.getSize().x / 2.2, win.getSize().y - win.getSize().y / 1.95f));

	
	int i = 0;
}
void WinRound(sf::RenderWindow &win, int NPlayer)
{
	std::string Player;

	VictoryRoundText.setCharacterSize(70);
	NextRoundText.setCharacterSize(50);
	if (NPlayer == 1)
	{
		VictoryRoundText.setFillColor(sf::Color(0x42DBD6ff));
		NextRoundText.setFillColor(sf::Color(0x42DBD6ff));
		Player = "Bleu";

	}
	if (NPlayer == 2)
	{
		VictoryRoundText.setFillColor(sf::Color(0xD29EF5ff));
		NextRoundText.setFillColor(sf::Color(0xD29EF5ff));
		Player = "Rose";

	}
	
	if (ScoreBleu != 3 || ScoreRouge != 3)
	{
		VictoryRoundText.setString("Round gagne par joueur " + Player);
		NextRoundText.setString("Appuyer sur B pour lancer la round suivante");

	}

	FloatRect Alpha = VictoryRoundText.getLocalBounds();
	VictoryRoundText.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	VictoryRoundText.setPosition(Vector2f(win.getSize().x / 2, win.getSize().y - win.getSize().y / 1.05f));
	NextRoundText.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	NextRoundText.setPosition(Vector2f(win.getSize().x / 1.98f, win.getSize().y - win.getSize().y / 1.2f));
	
	

	int i = 0;
}
void ScoreTB(sf::RenderWindow &win)
{
	std::string ScoreB;
	ScoreTextB.setCharacterSize(30);
	ScoreTextB.setFillColor(sf::Color(0x42DBD6ff));
	
	ScoreB = std::to_string(ScoreBleu);
	ScoreTextB.setString("Score : " + ScoreB);

	FloatRect Alpha = VictoryText.getLocalBounds();
	ScoreTextB.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	ScoreTextB.setPosition(Vector2f(win.getSize().x / 22, win.getSize().y - win.getSize().y /1.02f));
	
   
}
void ScoreTR(sf::RenderWindow &win)
{
	std::string ScoreR;
	ScoreTextR.setCharacterSize(30);
	ScoreTextR.setFillColor(sf::Color(0xD29EF5ff));
	ScoreR = ScoreRouge;

	ScoreR = std::to_string(ScoreRouge);
	ScoreTextR.setString("Score : " + ScoreR);

	FloatRect Alpha = VictoryText.getLocalBounds();
	ScoreTextR.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	ScoreTextR.setPosition(Vector2f(win.getSize().x / 22, win.getSize().y - win.getSize().y / 1.05f));


}
void Menu(sf::RenderWindow & win)
{
	std::string menu;
	MenuText.setCharacterSize(90);
	MenuText.setFillColor(sf::Color(0xFF2EDCff));
	MenuText.setString("     Madden Tank NFL\n Le premier a 3points \nStart pour commencer");
	
	FloatRect Alpha = MenuText.getLocalBounds();
	MenuText.setOrigin(Vector2f(Alpha.width / 2, Alpha.height / 2));
	MenuText.setPosition(Vector2f(win.getSize().x / 2.16f, win.getSize().y - win.getSize().y / 1.7f));
	Pause = true;

	
}
void world(sf::RenderWindow &win)
{
	
	ScoreTB(win);
	ScoreTR(win);
	
	
	if (Pause == false && menu == true)
	{
		Menu(win);
		
	}
	for (int i = 0; i < WallList.size(); i++)
	{
		if (CharList.size() > 1)
		{
			if (CharList[0].tank.getGlobalBounds().intersects(WallList[i].mur.getGlobalBounds()))
			{
				CharList[0].position.x = Beta.x;
				CharList[0].position.y = Beta.y;
				
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
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
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
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
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
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
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
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[4].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				

				BallList[i].U = -BallList[i].U;
				if (BallList[i].BallLife == 1)
				{
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[5].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				
				BallList[i].U = -BallList[i].U;
				if (BallList[i].BallLife == 1)
				{
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[6].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				
				BallList[i].U = -BallList[i].U;
				if (BallList[i].BallLife == 1)
				{
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[7].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				
				BallList[i].V = -BallList[i].V;
				if (BallList[i].BallLife == 1)
				{
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[8].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				
				BallList[i].U = -BallList[i].U;
				if (BallList[i].BallLife == 1)
				{
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[9].mur.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				
				BallList[i].V = -BallList[i].V;
				if (BallList[i].BallLife == 1)
				{
					boumballon = true;
					BallonBoom.setOrigin(25, 25);
					BallonBoom.setPosition(BallList[i].ball.getPosition());
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
						
						
						
						if (ScoreBleu == 2 || ScoreRouge == 2)
						{
							Startwin(win, 2);

						}
						else
						{
							WinRound(win, 2);
						}

						Destruction.play();
						mort = true;
						Pause = true;
						RedWin = true;
						EndGame = true;
						CharList[0].visible = false; 
						break;
					}
				}

				if (CharList[1].tank.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
				{
					if (BallList[i].spawned == false)
					{
						
						
						if (ScoreBleu == 2 || ScoreRouge == 2)
						{
							Startwin(win, 1);

						}
						else
						{
							WinRound(win, 1);
						}
						Destruction.play();
						mort2 = true;
						Pause = true;
						BlueWin = true;
						EndGame = true;
						CharList[1].visible = false;

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
		if (Elem.visible == true)
		{
	      win.draw(Elem.tank);
		  win.draw(Elem.Viseur);
		}
	
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

void Reset(sf::RenderWindow &win)
{
	
	CharList[0].visible = true;
	CharList[1].visible = true;
	WallList.push_back(Up);
	WallList.push_back(Down);
	WallList.push_back(Left);
	WallList.push_back(Right);
	WallList.push_back(Bordure1);
	WallList.push_back(Bordure2);
	WallList.push_back(Bordure3);
	WallList.push_back(Bordure4);
	WallList.push_back(Bordure5);
	WallList.push_back(Bordure6);
	BallList.push_back(Balle);	
	
}


int main()
{
	sf::RectangleShape Map(Vector2f(1920, 1080));
	
	
	bool Shoot = false;
	bool Shoot2 = false;
	sf::Font * font = new sf::Font();
	sf::Font * fontRound = new sf::Font();
	sf::Font * FontScore = new sf::Font();
	sf::Font * FontScore2 = new sf::Font();
	

	sf::Texture textureR;
	sf::Texture textureViseurR;
	sf::Texture textureWall;
	sf::Texture textureBall;
	sf::Texture textureBall2;
	sf::Texture FootballAmericain;
	sf::Texture Explosion;
	
	
	
	sf::Music NFL;


	if (!textureWall.loadFromFile("res/mur.jpg"))
		printf("pas mur");
	if (!texture.loadFromFile("res/tank sans canon.png"))
		printf("pasTank");
	if (!textureViseur.loadFromFile("res/canon sans tank2.png"))
		printf("pasTank");
	if (!textureR.loadFromFile("res/tank sans canon2.png"))
		printf("pasTank");
	if (!textureViseurR.loadFromFile("res/canon sans tank2.png"))
		printf("pasTank");
	if (!textureBall.loadFromFile("res/ballon2.png"))
		printf("pas ball");
	if (!textureBall2.loadFromFile("res/ballon1.png"))
		printf("pas ball");
	if (font->loadFromFile("res/DOWNCOME.TTF") == false)
		printf("no such font");
	if (fontRound->loadFromFile("res/DOWNCOME.TTF") == false)
		printf("no such font");
	if (FontScore->loadFromFile("res/DOWNCOME.TTF") == false)
		printf("no such font");
	if (FontScore2->loadFromFile("res/DOWNCOME.TTF") == false)
		printf("no such font");
	if (!FootballAmericain.loadFromFile("res/FootballAmericain.png"))
		printf("pas de terrain");
	if (!Explosion.loadFromFile("res/explosion.png"))
		printf("pas BOOM");
	if(!ExploBallon.loadFromFile("res/exploballon.png"))
	if (!Boom.loadFromFile("res/explosion.wav"))
		printf("pas detruit");
	if (!NFL.openFromFile("res/NFL.ogg"))
		printf("pas NFL");
	Destruction.setVolume(5);
	Destruction.setPitch(1.2f);
	Destruction.setBuffer(Boom);
	NFL.setVolume(5);
	NFL.setLoop(true);
	NFL.play();
	



	Map.setTexture(&FootballAmericain);
	//Bordure.setTexture(&textureWall);
	Sprite Explo(Explosion);
	
	float frame = 0;
	float animspeed = 0.5;
	int framecount = 25;
	
	
	VictoryText.setFont(*font);
	VictoryRoundText.setFont(*fontRound);
	NextRoundText.setFont(*fontRound);
	MenuText.setFont(*fontRound);
	
	ScoreTextB.setFont(*FontScore);
	ScoreTextR.setFont(*FontScore2);
	Entity Player = Entity(Vector2f(150, 800), Vector2f(65, 65), &texture, &textureViseur);
	Entity Ennemy = Entity(Vector2f(1600, 100), Vector2f(65, 65), &textureR, &textureViseurR);


	CharList.push_back(Player);
	CharList.push_back(Ennemy);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	static RectangleShape sh;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, settings);
	height = window.getSize().y;
	width = window.getSize().x;
	Up = Wall(Vector2f(0, 0), Vector2f(window.getSize().x, 10), &textureWall);
	Down = Wall(Vector2f(0, (window.getSize().y) - 3), Vector2f(window.getSize().x, 3), &textureWall);
	Left = Wall(Vector2f(0, 0), Vector2f(10, height), &textureWall);
	Right = Wall(Vector2f(window.getSize().x - 3, 0), Vector2f(3, height), &textureWall);
    Bordure1 = Wall(Vector2f(585,120), Vector2f(15,180), &textureWall);
    Bordure2 = Wall(Vector2f(1165, 770), Vector2f(15,180), &textureWall);
    Bordure3 = Wall(Vector2f(1320, 290), Vector2f(20,300), &textureWall);
    Bordure4 = Wall(Vector2f(1160,290), Vector2f(300,20), &textureWall);
    Bordure5 = Wall(Vector2f(450,470), Vector2f(20,300), &textureWall);
    Bordure6 = Wall(Vector2f(450,770), Vector2f(300,20), &textureWall);

	WallList.push_back(Up);
	WallList.push_back(Down);
	WallList.push_back(Left);
	WallList.push_back(Right);
	WallList.push_back(Bordure1);
	WallList.push_back(Bordure2);
	WallList.push_back(Bordure3);
	WallList.push_back(Bordure4);
	WallList.push_back(Bordure5);
	WallList.push_back(Bordure6);

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
	
		
		if (EndGame == true && sf::Joystick::isButtonPressed(0,1) || sf::Joystick::isButtonPressed(1, 1) && Pause==true)
		{
			
			EndGame = false;
			window.clear();
			if (BlueWin == true)
			{
				ScoreBleu++;
				BlueWin = false;
			}
			if (RedWin == true)
			{
			
				ScoreRouge++;
				RedWin = false;
			}
			Pause = false;
			if (ScoreBleu == 1 || ScoreRouge == 1)
			{
				CharList[0].position = Vector2f(150,800);
				CharList[1].position = Vector2f(1600,100);
			}
			if (ScoreBleu == 1 && ScoreRouge == 1)
			{
				CharList[0].position = Vector2f(100,500);
				CharList[1].position = Vector2f(1800,500);
			}
			if (ScoreBleu == 2 || ScoreRouge == 2)
			{
				CharList[1].position = Vector2f(150, 800);
				CharList[0].position = Vector2f(1600,100);
			}
			if (ScoreBleu == 2 && ScoreRouge == 2)
			{
				CharList[1].position = Vector2f(100, 500);
				CharList[0].position = Vector2f(1800, 500);
			}
			if (ScoreBleu == 3 || ScoreRouge == 3)
			{
				Menu(window);
				ScoreBleu = 0;
				ScoreRouge = 0;
			}
			

			BallList.clear();
			WallList.clear();
			VictoryText.setString("");
			VictoryRoundText.setString("");
			NextRoundText.setString("");
			frame = 0;
			Reset(window);
		

		}
		
		if (Pause == true && sf::Joystick::isButtonPressed(0, 7))
		{
			Pause = false;
			menu = false;
			MenuText.setString("");
		}

#pragma region Controls
	

			if (Pause == false)
			{
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
							if (ballcad < 20) ballcad++;


							if (!Shoot && sf::Joystick::getAxisPosition(0, Joystick::Z) < -50 &&ballcad>=20)
							{
								Ball Balle = Ball(sf::Vector2f(CharList[0].Viseur.getPosition().x - 5, CharList[0].Viseur.getPosition().y), 15, &textureBall);
								Balle.U = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
								Balle.V = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
								Balle.BallLife = 0;
								BallList.push_back(Balle);
								
								ballcad = 0;
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
							if (ballcad2<20) ballcad2++;

							if (!Shoot2 && sf::Joystick::getAxisPosition(1, Joystick::Z) < -50 && ballcad2>= 20)
							{
								Ball Balle = Ball(sf::Vector2f(CharList[1].Viseur.getPosition().x - 5, CharList[1].Viseur.getPosition().y), 15, &textureBall2);
								Balle.U = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
								Balle.V = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
								Balle.BallLife = 0;
								BallList.push_back(Balle);
								
								ballcad2 = 0;
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
			}
		
		

		
#pragma endregion
		window.clear();

		window.draw(Map);
		
		if (mort == true)
		{
			Explo.setScale(sf::Vector2f(1.5,1.5));
			Explo.setTextureRect(IntRect(int(frame) * 40,0,35,35));
			frame += animspeed;
			Explo.setPosition(CharList[0].position);
			if (frame < framecount)
			{
				window.draw(Explo);
			}
			mort = false;
			if (frame == 25)
				frame = 0;
			
		}
		if (mort2 == true)
		{
			Explo.setScale(sf::Vector2f(1.5, 1.5));
			Explo.setTextureRect(IntRect(int(frame) * 40, 0, 35, 35));
			frame += animspeed;
			Explo.setPosition(CharList[1].position);
			if (frame < framecount)
			{
				window.draw(Explo);
			}
			mort2 = false;
			if (frame == 25)
				frame = 0;

		}
		if (boumballon == true)
		{
			
			BallonBoom.setScale(sf::Vector2f(1.5, 1.5));
			BallonBoom.setTextureRect(IntRect(int(frame) * 50,0,50,50));
			frame += animspeed;
			
			if (frame < framecount)
			{
				window.draw(BallonBoom);
			}
			boumballon = false;
			if (frame == 25)
				frame = 0;

		}
	
		//window.draw(Bordure);
		drawBall(window);
		drawMur(window);
		drawTank(window);
		window.draw(MenuText);
		window.draw(ScoreTextB);
		window.draw(ScoreTextR);
		window.draw(VictoryText);
		window.draw(VictoryRoundText);
		window.draw(NextRoundText);
		
		window.display();//ca dessine et ca attend la vsync

	}

	return 0;
}

//Envoi projet