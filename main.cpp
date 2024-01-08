#include "lib/game.hpp"
#include "lib/util.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include "lib/game.hpp"

using std::cout , std::endl;

// #define TimePerFrame sf::seconds(1.f/60.f)
const sf::Time TimePerFrame = sf::seconds(1.f/60.f);

std::filesystem::path pwd = std::filesystem::current_path();

const double _1us = 0.000001;
const int height = 620;
const int width = 840;

const std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White, sf::Color::Yellow};

int colorIndex = 0;
int main()
{

    Game game;
    game.run();

    return 0;
}

Game::Game()
:mWindow(sf::VideoMode(width, height), "SFML Application")
,mPlayer()
, fps(width-100, 10)
{   
    radius = 5.f;
    speed = 200.f;
    mPlayer.setRadius(radius);
    mPlayer.setPosition(px, py);
    mPlayer.setFillColor(sf::Color::Green);
}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // Main GAME loop
    while(mWindow.isOpen()){
        sf::Time tick = clock.restart();
        fps.updateFPS(tick);

        processEvents();
        timeSinceLastUpdate += tick;
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents(){
    sf::Event e;
    while(mWindow.pollEvent(e)){
        switch (e .type)
        {
        case sf::Event::KeyPressed :handlePlayerInput(e.key.code, true);break;
        case sf::Event::KeyReleased :handlePlayerInput(e.key.code, false);break;
        case sf::Event::Closed : mWindow.close(); break;
        default:
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){

    switch (key)
    {
    case sf::Keyboard::W:
    case sf::Keyboard::Up:
        mIsMovingUp = isPressed;
        break;
    case sf::Keyboard::S:
    case sf::Keyboard::Down:
        mIsMovingDown = isPressed;
        break;
    case sf::Keyboard::A:
    case sf::Keyboard::Left:
        mIsMovingLeft = isPressed;
        break;
    case sf::Keyboard::D:
    case sf::Keyboard::Right:
        mIsMovingRight = isPressed;
        break;
    
    default:
        break;
    }

}

void Game::render(){
    mWindow.clear();

    mWindow.draw(mPlayer);
    fps.render(mWindow);

    mWindow.display();
}

void Game::update(sf::Time tick){

    float ds = getDist(tick, speed);

    if(mIsMovingUp) py -= ds;
    if(mIsMovingDown) py += ds;
    if(mIsMovingLeft) px -= ds;
    if(mIsMovingRight) px += ds;

    px = cycle(px, -radius, width+radius);
    py = cycle(py, -radius, height+radius);
    mPlayer.setPosition(px,py);
}

// end of file : main.cpp