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
	
	//Schedule(200);
}

//开始游戏
void GameStart()
{
	//1.列表
	GameMenu();

	//2.创建地图
	system("cls");
	CreateMap();

	//3.初始化蛇身
	InitSnakeBody();

}

//控制游戏
void GameControl()
{

}

//游戏结束
void GameOver()
{

}



