#include"SnakeGame.h"

//��Ϸ�˵�
void GameMenu()
{
	Position(50, 13);
	printf("**************************************************************\n");
	Position(50, 15);
	printf("**                     -->��ӭ������Ϸ                      **\n");
	Position(50, 17);
	printf("**************************************************************\n");
	Position(50, 19);
	printf("�����⿪ʼ��Ϸ...");
	getchar();
	Position(50, 21);
	printf("���ڼ�����Ϸ�����Ժ�...");
	
	//Schedule(200);
}

//��ʼ��Ϸ
void GameStart()
{
	//1.�б�
	GameMenu();

	//2.������ͼ
	system("cls");
	CreateMap();

	//3.��ʼ������
	InitSnakeBody();

}

//������Ϸ
void GameControl()
{

}

//��Ϸ����
void GameOver()
{

}



