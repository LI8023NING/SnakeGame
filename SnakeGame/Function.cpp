#include"SnakeGame.h"


int Score = 0;          //ÿ�ε÷�
int Add = 15;           //�Ե�ʳ��ķ�
snakenode *snakehead = NULL; //��ͷ


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
	for (int i = 1; i < 36; i++)
	{
		Position(0,i);
		printf("��");
		Position(78,i);
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

//��ʼ��������
void InitSnakeBody()
{
	snakenode *snaketail = (snakenode*)malloc(sizeof(snakenode));
	snaketail->x = 20;
	snaketail->y = 4;
	snaketail->next = NULL;
	for (int i = 0; i <= 4; ++i)
	{
		snakehead = (snakenode*)malloc(sizeof(snakenode));
		snakehead->next = snaketail;   //�ڵ�ͷ��
		snakehead->x = 20 ;
		snakehead->y = 4 + i;

		snaketail = snakehead;         //β��ָ��ͷ
	}

	while (snaketail != NULL)    //�����
	{
		Position(snaketail->x,snaketail->y);
		printf("��");
		snaketail = snaketail->next;
	}
}

