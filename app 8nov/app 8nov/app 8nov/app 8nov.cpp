// app 8nov.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Lib.h"
#include <direct.h>
#include <SFML/Graphics.hpp>

using namespace sf;
Vector2i Point1(100, 100);
Vector2i Point2(200, 200);
Vector2i Point3(300, 300);
Vector2i Point4(400, 400);
Vector2i Point5(500, 500);
Vector2i Point6(600, 600);
Vector2i Point7(700, 700);
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
static Vector2f ballpos(shPos);
int fireball = 20;
int squareSpeed = 3;
void Firegun(sf::RenderWindow&win)
{
	sf::RectangleShape ball(Vector2f(20, 20));
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(ballpos);
	win.draw(ball);
	
}

void drawMovingSquare(sf::RenderWindow &win)
{
	sf::RectangleShape carre(Vector2f(100, 100));
	carre.setFillColor(sf::Color::Red);
	carre.setPosition(shPos);
	win.draw(carre);
}
void drawCatmull(sf::RenderWindow &win, float now) {
	sf::VertexArray va(sf::LineStrip);
	sf::Color red = sf::Color::Red;
	sf::Color blue = sf::Color::Blue;
	int nb = 320;
	
	float stride = 1280.0 / nb;

	std::vector<Vector2f> points;

	for (int j = 0; j < 8; ++j) {
		/*Vector2f v(j * 100, j * 100);
		if (j == 0)v.x += 50;
		if (j == 3)v.x += 350;
		points.push_back(v);*/
		Vector2f v(j * 100, j * 100);
		if (j == 1) { v.x = Point1.x; v.y = Point1.y; }
		if (j == 2) { v.x = Point2.x; v.y = Point2.y; }
		if (j == 3) { v.x = Point3.x; v.y = Point3.y; }
		if (j == 4) { v.x = Point4.x; v.y = Point4.y; }
		if (j == 5) { v.x = Point5.x; v.y = Point5.y; }
		if (j == 6) { v.x = Point6.x; v.y = Point6.y; }
		if (j == 7) { v.x = Point7.x; v.y = Point7.y; }
		
		points.push_back(v);
	}
	


		sf::CircleShape shape(20.f, (int)(2 * 3.141569 * 100));
		shape.setOrigin(Vector2f(16, 16));
		shape.setFillColor(sf::Color::Magenta);
		
		
	for (int i = 0; i < nb + 1; ++i) {
		double ratio = 1.0 * i / nb;
		double x = 0.0;
		double y = 0.0;
		
		sf::Color c = hsv(ratio * 360, 0.8, 0.8);

		Vector2f pos = Lib::plot2(ratio, points);
		x = pos.x;
		y = pos.y;

		sf::Vertex vertex(Vector2f(x, y), c);
		va.append(vertex);
		
	}
	//float cRatio = (fmodf(now, 2.0f) / 2.0f);
	static float cRatio = 0.0;
	static bool reverse = true;
	//Vector2f pos = Lib::plot2(cRatio,points);
	Vector2f pos = Lib::plot2(reverse?cRatio:(1-cRatio),points);
	shape.setPosition(pos);
	cRatio += 0.001;
	if (cRatio > 1.0) {
		cRatio = 0.0;
		reverse = !reverse;
	}
	

	//win.draw(va);
	//win.draw(shape);
}

void drawCurve(sf::RenderWindow &win,float now) {
	sf::VertexArray va(sf::LinesStrip);
	sf::Color red = sf::Color::Red;
	sf::Color blue = sf::Color::Blue;
	int nb = 100;
	int change = 1;
	
	float stride = 1000 / (nb + 1);
	int ofsx = 0;
	for (int i = 0; i < nb+1; ++i)
	{
		double ratio = 1.0*i / nb;
		double x = ofsx + stride * i;
		double y = 400;
		int rayon = 50;
		if (change == 1)
		{
			y += (cos(ratio*8.0 + now * 3) * 120) + cos(now + 2) * 20;
			change=0;
		}
		if (change == 0)
		{
			x += (sin(ratio*8.0 - now * 3) * 120) + cos(now - 50) * 100;
			change=2;
		}
		if (change == 2)
		{
			x += (cos(ratio*5.0 + now * 3) * 120) + cos(now - 100) * 500;
			change = 1;
		}
		
		//y += sin(now) * 200;
		//x += sin(now) * 200;
		//x =( 500 + cos(ratio * 2 * 3.141569) * rayon) ;
		//y = (500 + sin(ratio * 2 * 3.141569) * rayon) ;
			sf::Vertex vertex(Vector2f(x,y), i % 2 == 0 ? blue : red);
			va.append(vertex);
	}
	win.draw(va);
}
int main()
{
	//std::cout << "Hello World!\n";

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	static RectangleShape sh;
	

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, settings);
	/*sf::CircleShape shape(100.f, (int)(2 * 3.141569 * 100));
	shape.setPosition(30, 30);
	shape.setFillColor(sf::Color(0xE884D4ff));
	shape.setOutlineThickness(4);
	shape.setOutlineColor(sf::Color(0xFF8A70ff));*/
	window.setVerticalSyncEnabled(true);

	sf::Clock clock;

	sf::Time appStart = clock.getElapsedTime();
	sf::Time frameStart = clock.getElapsedTime();
	sf::Time prevFrameStart = clock.getElapsedTime();

	float fps[4] = { 0.f,0.f,0.f,0.f };
	int step = 0;
	sf::Font * font = new sf::Font();
	
	if (font->loadFromFile("Fonts/DejaVuSans.ttf") == false) {
		printf("no such font\n");
	}

	sf::Text myFpsCounter;
	int every = 0;
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
		sf::Vector2i globalPosition = sf::Mouse::getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			Point1 = globalPosition;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		{
			Point2 = globalPosition;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		{
			Point3 = globalPosition;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
		{
			Point4 = globalPosition;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		{
			Point5 = globalPosition;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
		{
			Point6 = globalPosition;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7))
		{
			Point7 = globalPosition;
		}
		//--------------------------------------------------------------

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
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
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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
		}

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
		drawCatmull(window,clock.getElapsedTime().asSeconds());
		
		window.draw(myFpsCounter);
		drawMovingSquare(window);
		Firegun(window);
		window.display();//ca dessine et ca attend la vsync
		

		fps[step % 4] = 1.0f / (frameStart - prevFrameStart).asSeconds();
		prevFrameStart = frameStart;

		step++;
	}

	return 0;
}

