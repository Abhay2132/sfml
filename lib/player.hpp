#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<SFML/Graphics.hpp>

typedef struct Pos2D{
    float x; float y;
};

class Player {
public:
    Player();

    Player setPosition();
    Player setSize();
    Player setSpeed();

    Pos2D getPosition(){return pos;}
    float getSize(){return size;}
    float getSpeed(){return speed;}

private:
    sf::Sprite sprite;
    Pos2D pos={0.f,0.f};
    float speed=0.f;
    float size=5.f;
};




#endif