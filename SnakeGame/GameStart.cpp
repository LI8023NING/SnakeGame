#include"SnakeGame.h"

//游戏菜单
void GameMenu()
{
	Position(50, 13);
	printf("**************************************************************\n");
	Position(50, 15);
	printf("**                     -->欢迎进入游戏                      **\n");
	Position(50, 17);
	printf("**************************************************************\n");
	Position(50, 19);
	printf("按任意开始游戏...");
	getchar();
	Position(50, 21);
	printf("正在加载游戏，请稍后...");
	
	Schedule(200);
	system("cls");
}

//开始游戏
void GameStart()
{
	//1.列表
	GameMenu();
	
	//2.创建地图
	CreateMap();

	GameGuide();

	//3.初始化蛇身
	InitSnakeBody();

	//创建食物
	CreateFood();
}

//控制游戏
void GameControl()
{
	GameRecycle();
}

//游戏结束
void GameOver()
{
	if (EatSelf() || HitTheWall())
	{
		Position(30,10);
		printf("难道你撞墙了？或者咬了自己？:)\n"); 
		Position(30, 12);
		printf("请选择:)\n");

		//游戏结束，链表清理
		ClearCorpse();
		SureRes();
	}
}



