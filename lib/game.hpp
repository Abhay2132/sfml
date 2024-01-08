#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "fps.hpp"

class Game 
{
public:
	Game();
	void run();

private:
	void processEvents();
    void handlePlayerInput(sf::Keyboard::Key, bool isPressed);
    void update(sf::Time);
    void render();

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	FPS fps;

	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;

	float px=0;
	float py=0;
	int speed = 100;
	float radius=5.f;
};

#endif