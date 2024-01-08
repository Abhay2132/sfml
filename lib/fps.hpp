#ifndef _FPS_H_
#define _FPS_H_

#include<iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include<string.h>

class FPS
{

public:
    FPS(int x=0, int y=0,int fontSize = 15)
    {   
        fpsInterval =0;
        fpsFont.loadFromFile("res/fonts/FreeSans.ttf");
        sf::Text _fpsLabel("FPS: 0", this->fpsFont, 15);
        _fpsLabel.setPosition(x,y);
        _fpsLabel.setFillColor(sf::Color::Red);

        this->fpsLabel = _fpsLabel;
    }

    void render(sf::RenderWindow & mWindow){
        mWindow.draw(fpsLabel);
    }

    void updateFPS (sf::Time tick){
        fpsInterval += (int) tick.asMicroseconds();
        if(fpsInterval < 500000) return;
        fpsInterval = 0;
        this->fpsLabel.setString("FPS : "+std::to_string(this->calcFPS(tick)));
    }

private:
    sf::Font fpsFont;
    sf::Text fpsLabel;
    int fpsInterval;
    int calcFPS(sf::Time tick)
    {
        double t = tick.asMicroseconds();
        return floor(1000000 / t);
    }
};

#endif