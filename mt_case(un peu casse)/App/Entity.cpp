#include "Entity.hpp"
#include "Game.hpp"
#include "Particle.h"
#include "FadingParticle.h"

using namespace std;
using namespace sf;

void Entity::setPosPixel(float pixelX, float pixelY) {
	cx = (int)pixelX / CELL_WIDTH;
	cy = (int)pixelY / CELL_WIDTH;

	rx = (pixelX - (cx*CELL_WIDTH)) / CELL_WIDTH;//reste de cx pour aller a rx
	ry = (pixelY - (cy*CELL_WIDTH)) / CELL_WIDTH;

	syncCoord();
}


void Entity::update(double dt) {
	updateControl();
	updateState();
	rx += dx;


	///////X BLOCK 
	//maintain X cell coherency
	if (dx > 0)
		while (rx > 1) {
			if (!willCollide(cx + 1, cy)) {
				rx--;
				cx++;

			}
			else {
				//dx = -dx *0.8;
				rx = 1;
				changeState(ES_TOUCH);


				break;
			}
		}
	else if (dx < 0)
		while (rx < 0) {
			if (!willCollide(cx - 1, cy)) {
				rx++;
				cx--;
			}
			else {
				//dx = -dx * 0.8;
				rx = 0;
				changeState(ES_TOUCH);

				break;
			}
		}

	//apply friction
	dx *= 0.92f;


	//cap dx min val to avoid sliding
	if (abs(dx) < 0.05) dx = 0;
	///////end bloc x

	if (applyGravity) dy += gy;

	ry += dy;
	//maintain Y cell coherency
	if (dy > 0)
		while (ry > 1) {
			if (!willCollide(cx, cy + 1)) {
				ry--;
				cy++;
			}
			else {
				dy = 0;
				ry = 1;
				changeState(ES_TOUCH);

				break;
			}
		}
	else if (dy < 0)
		while (ry < 0) {
			if (!willCollide(cx, cy - 1)) {
				ry++;
				cy--;
			}
			else {
				dy = 0;
				ry = 0;
				changeState(ES_TOUCH);




			}

		}

	dy *= 0.92f;
	if (abs(dy) < 0.05) dy = 0;

	auto max_vert_velocity = 2.0;
	if (dy >= max_vert_velocity)//cap vertical speed
		dy = max_vert_velocity;


	if (getState() == ES_FALLING) {
		dropParticles();

	}
	if (getState() == ES_RUNNING)
	{
		spr->setFillColor(sf::Color::Blue);
	}
	if (getState() == ES_TOUCH)
	{
		spr->setFillColor(sf::Color::Green);
	}
	if (getState() == ES_COVER)
	{
		spr->setFillColor(sf::Color::Yellow);
	}


	syncCoord();
}
void Entity::updateState()
{
	switch (state)
	{
	case ES_IDLE:{
			spr->setFillColor(sf::Color::White);
			//bool isnearWall = ( willCollide(cx + 1, cy) || willCollide(cx - 1, cy) || willCollide(cx, cy + 1) || willCollide(cx, cy - 1));
			/*if (stateLife >= 60 && isnearWall)
			{
				printf("statelife %d\n", stateLife);
				changeState(ES_COVER);
			}*/
			
		}
		break;
	case ES_RUNNING:
		spr->setFillColor(sf::Color::Blue);
		break;

	case ES_TOUCH: {
		spr->setFillColor(sf::Color::Green);
		bool isnearWall = (willCollide(cx + 1, cy) || willCollide(cx - 1, cy) || willCollide(cx, cy + 1) || willCollide(cx, cy - 1));
		if (stateLife >= 60 && isnearWall)
		{
			printf("statelife %d\n", stateLife);
			changeState(ES_COVER);
		}
	}
		break;
	case ES_COVER:
		spr->setFillColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
	stateLife++;
}

void Entity::dropParticles() {
	int life = 30;
	float sp = Lib::rd() + 0.5;
	auto & g = *Game::me;

	float rdx = Lib::rd() * 6;
	float rdy = Lib::rd() * 6 - 8;
	{
		auto c = new CircleShape(8, 64);
		c->setOrigin(8, 8);
		c->setPosition(pixelX + rdx, pixelY + rdy);
		c->setFillColor(sf::Color(0xE580EB1a));
		auto p = new FadingParticle(c);
		p->life = 30;
		p->speed.y = sp;
		p->bhv = Particle::applySpeed;
		g.pvec.push_back(p);

	}

	{
		auto c = new CircleShape(2, 32);
		c->setOrigin(2, 2);
		c->setPosition(pixelX + rdx, pixelY + rdy);
		c->setFillColor(sf::Color(0xE580EBff));

		auto p = new FadingParticle(c);
		p->life = 30;
		p->speed.y = sp;
		p->bhv = Particle::applySpeed;
		g.pvec.push_back(p);
	}
}

void Entity::draw(sf::RenderWindow & win) {

	sf::Text coords;
	coords.setFont(*Game::me->fnt);
	coords.setPosition(pixelX + 20, pixelY - 20);
	coords.setFillColor(sf::Color::Red);
	coords.setString(
		std::to_string(cx) + "," + std::to_string(cy)
		+ " " + std::to_string(rx) + "," + std::to_string(ry)
		+ " " + getStateName());

	win.draw(*spr);
	win.draw(coords);
}

void Entity::changeState(EntityState nes)
{
	EntityState oldState = state;
	if (nes == state)
		return;

	switch (oldState)
	{
	default:
		break;
	}

	switch (nes)
	{
	default:
		break;
	}
	stateLife = 0;
	state = nes;


}

void Entity::updateControl()
{
	auto lat_acc = 0.075;
	auto max_lat_speed = 0.55;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dx += lat_acc;
		if (dx > max_lat_speed)dx = max_lat_speed;
		changeState(ES_RUNNING);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dx -= lat_acc;
		if (dx < -max_lat_speed)dx = -max_lat_speed;
		changeState(ES_RUNNING);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dy += lat_acc;
		if (dy > max_lat_speed) dy = max_lat_speed;
		changeState(ES_RUNNING);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dy -= lat_acc;
		if (dy < -max_lat_speed)dy = -max_lat_speed;
		changeState(ES_RUNNING);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		setPosPixel(100, 600);
		dx = dy = 0.0f;
		applyGravity = false;
		changeState(ES_IDLE);
	}

}


bool Entity::willCollide(int cx, int cy)
{

	return Game::me->willCollide(this, cx, cy);

}

std::string Entity::getStateName() {
	switch (state)
	{
	case ES_IDLE:
		return "idle";
		break;
	case ES_RUNNING:
		return "run";
		break;
	case ES_FALLING:
		return "fall";
		break;
	case ES_TOUCH:
		return"Touch";
		break;
	case ES_COVER:
		return"Cover";
		break;

	}
}
