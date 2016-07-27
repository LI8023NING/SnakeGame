#include"SnakeGame.h"


int Score = 0;          //每次得分
int Add = 15;           //吃掉食物的分
snakenode *lastfood = NULL;  //最终会被吃掉的食物节点
snakenode *snakehead = NULL; //蛇头
int ButtonState = 4;         //上下左右按键的状态 
int sleepingtime = 200;      //每次运行时间间隔暂定200


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

//遇到问题：蛇身初始化只能竖着打印 不可横着 原因是，横直打印的结束符一直覆盖前边一直打印的
//初始化蛇自身
void InitSnakeBody()
{
	snakenode *snaketail = (snakenode*)malloc(sizeof(snakenode));
	snaketail->x = 20;
	snaketail->y = 4;
	snaketail->next = NULL;
	for (int i = 1; i <= 4; ++i)
	{
		snakehead = (snakenode*)malloc(sizeof(snakenode));
		snakehead->next = snaketail;   //节点头插
		snakehead->x = 20 + 2*i;
		snakehead->y = 4;

		snaketail = snakehead;         //尾巴指向头
	}

	while (snaketail != NULL)    //蛇输出
	{
		Position(snaketail->x,snaketail->y);
		printf("■");
		snaketail = snaketail->next;
	}
}


//蛇咬到自己
bool EatSelf()
{
	snakenode* self = snakehead->next;
	while(self != NULL)
	{
		if (self->x == snakehead->x && self->y == snakehead->y)
			return true;     //表示咬到自己
		self = self->next;
	}
	return false;            //没有咬到自己
}

//碰到墙壁了
bool HitTheWall()
{
	if (snakehead->y == 0 || snakehead->y == 36 || snakehead->x == 0 || snakehead->x == 78)
		return true;
	else
		return false;
}

//随机出现食物
void CreateFood()
{
	srand((unsigned)time(NULL)); //随机数发生器的初始化

	snakenode* food = (snakenode*)malloc(sizeof(snakenode));
	while ((food->x % 2) != 0)      //面板中 x轴蛇一次走两格，Y中蛇一次走一格 此得保证x是偶数
	{
		food->x = rand() % 76 + 2; //2是强的宽
	}
	food->y = rand() % 34 + 1;     //x和y随机定好位置

	//可能出现的食物和蛇身重叠 不允许
	snakenode* cur = snakehead;
	while (cur->next!=NULL)  //等于空
	{
		if (food->x == cur->x && food->y == cur->y)
		{
			free(food);   //发现重合 释放节点 重来
			CreateFood();
		}
		cur = cur->next;
	}

	Position(food->x,food->y);
	lastfood = food;
	printf("■");
}


//蛇会移动
void SnakeMove()
{
	snakenode* nexthead = (snakenode*)malloc(sizeof(snakenode)); //蛇走向下一个节点
	nexthead->next = NULL;

	if (ButtonState == UP)
	{
		nexthead->x = snakehead->x;
		nexthead->y = snakehead->y - 1;   //向上走，y-1

		SameAction(nexthead, lastfood);
	}
	if (ButtonState == DOWN)
	{
		nexthead->x = snakehead->x;
		nexthead->y = snakehead->y + 1;   //向下走，y+1

		SameAction(nexthead, lastfood);
	}
	if (ButtonState == LEFT)
	{
		nexthead->x = snakehead->x - 2;
		nexthead->y = snakehead->y;   

		SameAction(nexthead, lastfood);
	}
	if(ButtonState == RIGHT)
	{
		nexthead->x = snakehead->x + 2;
		nexthead->y = snakehead->y;  

		SameAction(nexthead, lastfood);
	}
}

//游戏循环
void GameRecycle()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && ButtonState != DOWN)
			ButtonState = UP;
		else if (GetAsyncKeyState(VK_DOWN) && ButtonState != UP)
			ButtonState = DOWN;
		else if (GetAsyncKeyState(VK_LEFT) && ButtonState != RIGHT)
			ButtonState = LEFT;
		else if (GetAsyncKeyState(VK_RIGHT) && ButtonState != LEFT)
			ButtonState = RIGHT;
		else if (GetAsyncKeyState(VK_SPACE))
			Pause();
		else if (GetAsyncKeyState(VK_ESCAPE))
			SureRes();
		else if (GetAsyncKeyState(VK_F1))
		{
			if (sleepingtime >= 50)
			{
				sleepingtime = sleepingtime - 80;
				Add = Add + 5;
				if (sleepingtime == 320)
				{
					Add = 2;
				}
			}
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			if (sleepingtime < 350)
			{
				sleepingtime = sleepingtime + 100;
				Add = Add - 5;
				if (sleepingtime == 350)
				{
					Add = 1;
				}
			}
		}
		Sleep(sleepingtime);
		SnakeMove();
	}
}


//游戏暂停
void Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}


//询问是否要这样
void SureRes()
{
	int num;
	Position(30, 14);
	printf("********************");
	Position(30, 16);
	printf("*    1.重新开始    *");
	Position(30, 18);
	printf("*    2.退出游戏    *");
	Position(30, 20);
	printf("********************");
	Position(30, 22);
	printf("请选择：\n");
	Position(30, 24);
	scanf("%d", &num);
	switch (num)
	{
	case 1:{system("cls"); GameStart(); }; break;
	case 2:{ ClearCorpse(); exit(1); }; break;
	default:{printf("选择有误，请重新选择！\n"); SureRes(); }; break;
	}
}

//尸体清理
void ClearCorpse()
{
	while (snakehead)
	{
		snakenode* destroy = snakehead;
		snakehead = snakehead->next;
		free(destroy);
		destroy = NULL;
	}
}


//游戏指南：
void GameGuide()
{
	Position(100, 6);
	printf("一、游戏说明：");
	Position(102, 8);
	printf("1.规则：蛇吃食物，撞墙和咬伤自己，游戏结束！");
	Position(102, 10);
	printf("2.操作：上下左右键控制蛇的移动方向！");
	Position(100, 12);
	printf("二、按键说明：");
	Position(102, 14);
	printf("1.F1键：中速！");
	Position(102, 16);
	printf("2.F2键：快速，得分高！");
	Position(102, 18);
	printf("3.ESC键：游戏结束！");
	Position(102, 20);
	printf("4.空格键：游戏暂停！");
}

//蛇移动动作
void SameAction(snakenode* nexthead,snakenode* lastfood)
{
	if (nexthead->x == lastfood->x && nexthead->y == lastfood->y)
	{
		nexthead->next = snakehead;
		snakehead = nexthead;
		GameOver();
		snakenode* cur = snakehead;
		while (cur != NULL)
		{
			Position(cur->x, cur->y);
			printf("■");
			cur = cur->next;
		}
		Score = Score + Add;   //Score 总分 Add 是加成
		Mark();
		CreateFood();          //继续构造食物
	}
	else
	{
		nexthead->next = snakehead;
		snakehead = nexthead;
		GameOver();
		snakenode* cur = snakehead;
		while (cur->next->next != NULL)
		{
			Position(cur->x, cur->y);
			printf("■");
			cur = cur->next;
		}

		Position(cur->next->x, cur->next->y);
		printf(" ");
		free(cur->next);
		cur->next = NULL;
	}
}


void Mark()
{
	Position(90, 24);
	printf("以下是你本轮得分：");
	Position(90, 26);
	printf("┏━━━━━━━━━━━━┓");
	Position(90, 27);
	printf("┃                        ┃");
	Position(90, 28);
	printf("┃ Score: %d              ┃", Score);
	Position(90, 29);
	printf("┃                        ┃");
	Position(90, 30);
	printf("┗━━━━━━━━━━━━┛");
}



