#ifndef __BRIDGE_PATTERN_H__
#define __BRIDGE_PATTERN_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

//  Реализовать интерфейс класса Implementor
class Game
{
public:
    Game(){}
    virtual ~Game(){}
    virtual void play() = 0;
private:
};

//  Конкретный класс реализации GameA
class GameA:public Game
{
public:
    GameA(){}
    void play(){
        printf("Играю в игру A\n");
    }
};

//  Конкретный класс реализации GameB
class GameB :public Game
{
public:
    GameB(){}
    void play(){
        printf("Играю в игру B\n");
    }
};

//абстрактный класс Phone
class Phone
{
public:
    Phone(){
    }
    virtual ~Phone(){}
    // Setup game
    virtual void setupGame(Game *igame) = 0;
    virtual void play() = 0;
private:
    Game *game;
};

// Расширяем абстрактный класс PhoneA
class PhoneA:public Phone
{
public:
    PhoneA(){
    }
    // Setup game
    void setupGame(Game *igame){
        this->game = igame;
    }
    void play(){
        this->game->play();
    }
private:
    Game *game;
};

//Расширяем абстрактный класс PhoneB
class PhoneB :public Phone
{
public:
    PhoneB(){
    }
    // Setup game
    void setupGame(Game *igame){
        this->game = igame;
    }
    void play(){
        this->game->play();
    }
private:
    Game *game;
};


#endif //__BRIDGE_PATTERN_H__
