#include"SnakeGame.h"

//�Զ�����λ��
void Position(int x,int y)
{
	COORD position;
	HANDLE hOutput;
	position.X = x;
	position.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, position);
}

//������ͼ
void CreateMap()
{
	//����
	for (int i = 0; i < 80; i += 2)
	{
		Position(i,0);
		printf("��");
		Position(i,36);
		printf("��");
	}

	//����
	for (int i = 0; i < 37; i += 1)
	{
		Position(0,i);
		printf("��");
		Position(80,i);
		printf("��");
	}
}

//���ؽ���
void Schedule(int x)             
{
	const int NUM = 50;                       //�����������  
	for (int i = 0; i < NUM; i++)
	{
		Sleep(x);
		Position(50, 23);//��Sleep()������һЩ��ʱ�Ĳ���. 
		printf("%.2lf%%\r", i * 100.0 / NUM); //����ٷֱ� 
	}
}

