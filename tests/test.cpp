#include <SFML/Graphics.hpp>
#include<iostream>
#include<filesystem>
#include <cmath>

const sf::Color colors [] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue};

using namespace std;

int main(){

	sf::RenderWindow mWindow(sf::VideoMode(600, 400), "SFML Application");
	sf::ConvexShape polygon;

	polygon.setPointCount(4);
	polygon.setPoint(0, sf::Vector2f(0,0));
	polygon.setPoint(1, sf::Vector2f(0,0));
	polygon.setPoint(2, sf::Vector2f(100,0));
	polygon.setPoint(3, sf::Vector2f(100,0));

	polygon.setOutlineColor(sf::Color::Red);
	polygon.setOutlineThickness(2);
	polygon.setPosition(300,200);

	sf::Clock clock;
	sf::Clock timer;

	double angle = 0;
	float angularVelocity = 90;
	int i=0;

	while(mWindow.isOpen()){
		sf::Time elapsed = clock.restart();
		sf::Int64 tick = elapsed.asMicroseconds();

		int a0 = angle;
		angle = (angle + angularVelocity*tick*0.000001);

		// cout << "angular speed : "<<(angle-a0)/(tick) <<"\nangle : "<< angle <<"\n\n" ;
		if(angle > 360){ 

			angle -= 360;
			polygon.setOutlineColor(colors[++i%3]);

			sf::Time time = timer.restart();
			sf::Int32 e = time.asMilliseconds();
			float timeTaken = time.asMilliseconds() * 0.001;
			cout<<"TIME : " << e << " ms" << endl;
		}

		polygon.setRotation(angle);

		mWindow.clear();
		mWindow.draw(polygon);
		mWindow.display();

	}

	return 0;
}