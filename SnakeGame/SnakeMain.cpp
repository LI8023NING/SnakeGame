#include"SnakeGame.h"

int main()
{
	GameStart();
	GameControl();

	return 0;
}

/*
*注意问题：
*1.游戏结束，蛇身链表需要销毁
*2.随机产生的食物节点，如果蛇没吃到，游戏结束了，此食物节点也需要清理
*3.待定
*/