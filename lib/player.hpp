#ifndef _PLAYER_H_
#define _PLAYER_H_

#include"util.hpp"
#include<SFML/Graphics.hpp>
#include"game.hpp"

class Player : public sf::CircleShape {
public:
    void update(sf::Time );
	void setSpeed(float s){speed = s;}
	void setDim (sf::Vector2f d){dim =d ;}
	void handlePlayerInput(sf::Keyboard::Key, bool isPressed);

private:
	sf::Vector2f dim;
    float speed;

	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
	bool isBoost = false;

};

void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

	switch (key)
	{
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		isMovingUp = isPressed;
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		isMovingDown = isPressed;
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		isMovingLeft = isPressed;
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		isMovingRight = isPressed;
		break;

	case sf::Keyboard::Space:
		isBoost = isPressed;
		break;

	default:
		break;
	}
}

void Player::update(sf::Time tick){
	sf::Vector2f pos = getPosition();
	const float size = getRadius();
	const float ds = getDist(tick, speed + (isBoost ? 5*speed : 0));

	if (isMovingUp)
		pos.y -= ds;
	if (isMovingDown)
		pos.y += ds;
	if (isMovingLeft)
		pos.x -= ds;
	if (isMovingRight)
		pos.x += ds;

	pos.x = cycle(pos.x, - size, dim.x + size);
	pos.y = cycle(pos.y, - size, dim.y + size);

	setPosition(pos.x, pos.y);
}
#endif