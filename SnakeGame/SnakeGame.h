/************************************
 ** Auth: 李宁
 ** Date: 2016/7/25 11:50
 ** Desc: 贪吃蛇游戏
 ************************************/

#pragma once

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

//蛇上下左右动
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


//蛇身的节点
struct snakenode
{
	int x;
	int y;
	snakenode *next;
};

//函数申明
void Position(int x, int y);
void CreateMap();
void Schedule(int x);
void InitSnakeBody();
void GameStart();
void GameControl();
void GameOver();
bool EatSelf();
bool HitTheWall();
void CreateFood();

void SnakeMove();
void Pause();
void GameRecycle();
void ClearCorpse();
void SureRes();
void GameGuide();
void SameAction(snakenode* nexthead, snakenode* lastfood);
void Mark();