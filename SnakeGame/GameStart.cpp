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
	
	Schedule(200);
	system("cls");
}

//��ʼ��Ϸ
void GameStart()
{
	//1.�б�
	GameMenu();
	
	//2.������ͼ
	CreateMap();

	GameGuide();

	//3.��ʼ������
	InitSnakeBody();

	//����ʳ��
	CreateFood();
}

//������Ϸ
void GameControl()
{
	GameRecycle();
}

//��Ϸ����
void GameOver()
{
	if (EatSelf() || HitTheWall())
	{
		Position(30,10);
		printf("�ѵ���ײǽ�ˣ�����ҧ���Լ���:)\n"); 
		Position(30, 12);
		printf("��ѡ��:)\n");

		//��Ϸ��������������
		ClearCorpse();
		SureRes();
	}
}



