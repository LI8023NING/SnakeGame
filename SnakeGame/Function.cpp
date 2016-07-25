#include"SnakeGame.h"


int Score = 0;          //每次得分
int Add = 15;           //吃掉食物的分
snakenode *snakehead = NULL; //蛇头


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
	for (int i = 1; i < 36; i++)
	{
		Position(0,i);
		printf("■");
		Position(78,i);
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

//初始化蛇自身
void InitSnakeBody()
{
	snakenode *snaketail = (snakenode*)malloc(sizeof(snakenode));
	snaketail->x = 20;
	snaketail->y = 4;
	snaketail->next = NULL;
	for (int i = 0; i <= 4; ++i)
	{
		snakehead = (snakenode*)malloc(sizeof(snakenode));
		snakehead->next = snaketail;   //节点头插
		snakehead->x = 20 ;
		snakehead->y = 4 + i;

		snaketail = snakehead;         //尾巴指向头
	}

	while (snaketail != NULL)    //蛇输出
	{
		Position(snaketail->x,snaketail->y);
		printf("■");
		snaketail = snaketail->next;
	}
}

