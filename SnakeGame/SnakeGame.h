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
#define W UP      
#define S DOWN
#define L LEFT
#define R RIGHT

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