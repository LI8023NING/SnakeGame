/************************************
 ** Auth: ����
 ** Date: 2016/7/25 11:50
 ** Desc: ̰������Ϸ
 ************************************/

#pragma once

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

//���������Ҷ�
#define W UP      
#define S DOWN
#define L LEFT
#define R RIGHT

//����Ľڵ�
struct snakenode
{
	int x;
	int y;
	snakenode *next;
};

//��������
void Position(int x, int y);
void CreateMap();
void Schedule(int x);
void InitSnakeBody();
void GameStart();
void GameControl();
void GameOver();