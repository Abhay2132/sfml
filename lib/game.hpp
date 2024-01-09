#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "fps.hpp"
#include "util.hpp"
#include "player.hpp"
#include <iostream>
#include <vector>
#include "EventEmitter.hpp"

using std::cout, std::endl;

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

class Updatable {
	public:
		virtual void update(){}
};

class Game : public EventListener
{
public:
	Game(float, float);
	void run();
	sf::Vector2f getDim(){return dim;}

private:
	void processEvents();
	void update(sf::Time);
	void render();

private:
	sf::Event e;
	// std::vector<sf::Drawable *> drawables;
	sf::RenderWindow mWindow;
	// sf::CircleShape mPlayer;
	Player mPlayer;
	FPS fps;
	sf::Vector2f dim = {690.f, 420.f};

	float px = 0;
	float py = 0;
	int speed = 100;
	float radius = 5.f;
};



Game::Game(float w, float h)
	: mWindow(sf::VideoMode(w, h), "SFML Application"), 
	fps(w - 100, 10),
	dim({w,h}),
	mPlayer()
{
	mPlayer.setRadius(5.f);
	mPlayer.setPosition(10.f,10.f);
	mPlayer.setFillColor(sf::Color::Green);
	mPlayer.setSpeed(100.f);
	mPlayer.setDim(dim);
	on("key-pressed", [this](){
		mPlayer.handlePlayerInput(e.key.code, true);
	});
	on("key-released", [this](){
		mPlayer.handlePlayerInput(e.key.code, false);
	});

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// Main GAME loop
	// while (mWindow.isOpen())
	// {
	// 	sf::Time tick = clock.restart();
	// 	fps.updateFPS(tick);
	// 	processEvents();
	// 	timeSinceLastUpdate += tick;
	// 	while (timeSinceLastUpdate > TimePerFrame)
	// 	{
	// 		timeSinceLastUpdate -= TimePerFrame;
	// 		processEvents();
	// 		update(TimePerFrame);
	// 	}
	// 	render();
	// }

	while(mWindow.isOpen()){
		sf::Time tick = clock.restart();
		fps.updateFPS(tick);
		processEvents();
		update(tick);
		render();
	}
}

void Game::processEvents()
{
	while (mWindow.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::KeyPressed:
			emit("key-pressed");
			break;
		case sf::Event::KeyReleased:
			emit("key-released");
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
	}
}


void Game::render()
{
	mWindow.clear();

	mWindow.draw(mPlayer);
	fps.render(mWindow);

	mWindow.display();
}

void Game::update(sf::Time tick)
{
	mPlayer.update(tick);
}

#endif