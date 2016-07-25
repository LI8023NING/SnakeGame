#include"SnakeGame.h"

void GameStart()
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
}




