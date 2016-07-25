#include"SnakeGame.h"

//自定义光标位置
void Position(int x,int y)
{
	COORD position;
	HANDLE hOutput;
	position.X = x;
	position.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, position);
}

//创建地图
void CreateMap()
{
	//上下
	for (int i = 0; i < 80; i += 2)
	{
		Position(i,0);
		printf("■");
		Position(i,36);
		printf("■");
	}

	//左右
	for (int i = 0; i < 37; i += 1)
	{
		Position(0,i);
		printf("■");
		Position(80,i);
		printf("■");
	}
}

//加载进度
void Schedule(int x)             
{
	const int NUM = 50;                       //任务完成总量  
	for (int i = 0; i < NUM; i++)
	{
		Sleep(x);
		Position(50, 23);//用Sleep()来代替一些费时的操作. 
		printf("%.2lf%%\r", i * 100.0 / NUM); //输出百分比 
	}
}

