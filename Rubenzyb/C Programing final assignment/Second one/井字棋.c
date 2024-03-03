// ����һ����C���Ա�д�ľ�������Ϸ����Ϸ�Ĺ��������������һ��n*n�������������������ӣ��Ƚ��Լ���n����������һ��ֱ�ߵ���һ�ʤ��
// ��ֱ���������������Ӻ���δ�ֳ�ʤ������ƽ�֡�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int currentPlayer = 0, player1Wins = 0, player2Wins = 0, roundCount = 0, size = 0;
int player1score = 0, player2score = 0, noplayerscore = 0, attitude = 0;
void start(int **chessBoard), process(int **chessBoard), record(int **chessBoard), judge(void), result(void);
void check(int *data), printfBoard(int **chessBoard);

// main���������ǳ������ڵ㡣
// �����ȳ�ʼ����Ϸ��״̬��Ȼ����һ����֣����лغ�ѭ��ֱ������þֽ�����
// ��Ϸ����������ѯ������Ƿ���Ҫ����һ�Σ������Ҵ�Ӧ���ͻ��ؿ�һ����֡�
int main()
{
	int i = 0, j = 0;
	int **chessBoard;
again:
	// ��������ʼ���Ա�����������Ϸ��
	player1Wins = 0;
	player2Wins = 0;
	roundCount = 1;
	printf("�װ�������ǣ���ӭ������������Ϸ���������������ǵ�nXn���̵�nֵ��");
	check(&size);

	// Ϊ���̷����ڴ�ռ䲢��ʼ����
	chessBoard = (int **)malloc(size * sizeof(int *));
	if (chessBoard == NULL)
	{
		printf("�������ֵ̫����Ϸ�޷���ʼ��������\n");
		exit(1);
	}
	for (i = 0; i < size; i++)
	{
		chessBoard[i] = (int *)malloc(size * sizeof(int));
		if (chessBoard[i] == NULL)
		{
			printf("�������ֵ̫����Ϸ�޷���ʼ��������\n");
			exit(1);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			chessBoard[i][j] = 0;
		}
	}

	// ��Ϸ�Ľ��У��ȼ�����ʼ�������ٲ��Ͻ�����Ϸ�غ�ֱ����������������������ж�ʤ����
	start(chessBoard);

	while (player1Wins + player2Wins == 0 && roundCount <= size * size)
	{
		process(chessBoard);
		record(chessBoard);
		roundCount++;
	}

	judge();

	// �ͷ����̵��ڴ�ռ䡣
	for (i = 0; i < size; i++)
	{
		free(chessBoard[i]);
		chessBoard[i] = NULL;
	}
	free(chessBoard);
	chessBoard = NULL;
	// ѯ������Ƿ�Ը�������Ϸ�������ݷ���������Ӧ��
	result();
	if (attitude)
		goto again;
	else
		return 0;
}

// check������
//  �����������ȷ����ҵ����벻��С��1������Ӣ����ĸ�ͱ����š�����ǣ��ͻ�Ҫ������������롣
//  ���������������1��С��������ֻ���ȡ�����������֣�
// ��Ҳ���ܿ���������ֵ�����ޡ�
void check(int *data)
{
	int number = 0;
back:
	if (scanf("%d", &number) != 1 || number <= 0)
	{
		printf("\n���벻�Ϸ������������룺");
		while (getchar() != '\n'); // ������뻺����
		goto back; 
		
	}
	else
		*data = number;
}

// printfBoard������
// ����������ڴ�ӡ��ǰ������״̬���Ա���ҽ�����Ϸ��
void printfBoard(int **chessBoard)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%+d", chessBoard[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

// start������
// ����������ڸ����չʾ��Ϸ�Ļ�����Ϣ���������̵Ĵ�С��˭���ߡ�
void start(int **chessBoard)
{
	// �����������˭���ߡ�
	srand(time(NULL));
	currentPlayer = rand() % 100;
	if (currentPlayer >= 0 && currentPlayer <= 49)
		currentPlayer = 1;
	else
		currentPlayer = -1;

	// ��ӡ��Ϸ�Ļ�����Ϣ��
	printf("û���⣡������һ��%dX%d�����̣�+0�����λ��", size, size);
	printf("���������ǽ�ʹ��+1��-1��Ϊ����ȥ����λ��ֱ����һ���ɹ���%d����������ֱ�ߡ�\n", size, size);
	printf("����ȷ����Ϸ˳��......\n��ϲ�����%+d�����ߣ�\n", currentPlayer);
	printf("��ܰ��ʾ��\n1.����һ��Ϊ��һ�У�����һ��Ϊ��һ�У�\n2.һ����λֻ�ܱ����һ�Σ�\n");
	printf("ף���Ǻ��ˣ�\n\n");
	printfBoard(chessBoard);
}

// process������
// ���������������ҵ�һ�������ж���
// ������ѯ�ʵ�ǰ�����Ҫ������������ӣ��ڵõ���Ч�������������̵�״̬�����л�����һ����ҡ�
void process(int **chessBoard)
{
	int i = 0, j = 0;
back:
	// ѯ�������Ҫ������������ӣ��������ҵ������Ƿ���Ч��
	printf("�ֵ�%+d����\n��������ϣ�������λ�õ�������", currentPlayer);
	check(&i);
	if (i > size )
	{
		printf("�������ֵ̫�������ԣ�\n\n");
		goto back;
	}
	printf("������ϣ�������λ�õ�������"); 
	check(&j);
	printf("\n");
	if ( j > size)
	{
		printf("�������ֵ̫�������ԣ�\n\n");
		goto back;
	}
	if (chessBoard[i - 1][j - 1] != 0)
	{
		printf("����û�п�λ�ˣ������ԣ�\n\n");
		goto back;
	}
	else
		chessBoard[i - 1][j - 1] = currentPlayer;

	// ��ӡ��ǰ���̵�״̬��
	printfBoard(chessBoard);

	// �л�����һ����ҡ�
	currentPlayer = -currentPlayer;
}

// record������
// �������������̵ĵ�ǰ״̬���ж��Ƿ�������Ѿ���ʤ���������������һ�֡�
void record(int **chessBoard)
{
	int i = 0, j = 0;
	if (roundCount >= size)
	{

		// ������̵ĶԽ���
		int sum3 = 0, sum4 = 0;
		for (i = 0; i < size; i++)
		{	
			sum3 += chessBoard[i][i];
			sum4 += chessBoard[i][size - i - 1];
			if (sum3 == size || sum4 == size)
				player1Wins = 1;
			else if (sum3 == -size || sum4 == -size)
				player2Wins = 1;
		}
		// ������̵��к��С�
		for (i = 0; i < size; i++)
		{
			int sum1 = 0, sum2 = 0;
			for (j = 0; j < size; j++)
			{
				sum1 += chessBoard[i][j];
				sum2 += chessBoard[j][i];
			}
			if (sum1 == size || sum2 == size)
				player1Wins = 1;
			else if (sum1 == -size || sum2 == -size)
				player2Wins = 1;
		}
	}
}

// judge������
// �����������record�����Ľ�����ж�˭Ӯ����Ϸ��
void judge(void)
{
	if (player1Wins == 1 && player2Wins == 0)
	{
		printf("+1��ʤ��\n\n");
		player1score++;
	}
	else if (player1Wins == 0 && player2Wins == 1)
	{
		printf("-1��ʤ��\n\n");
		player2score++;
	}
	else if (player1Wins + player2Wins == 0)
	{
		printf("���˻�ʤ\n\n");
		noplayerscore++;
	}
}

// result������
// �������ѯ������Ƿ���Ҫ����һ�Σ���¼��ҵĻظ����ж����Ƿ����Ҫ��
void result(void)
{
	printf("�㻹ϣ������һ���𣿣���1�����ǣ�0�����");
	scanf("%d", &attitude);
	printf("\n");
	// �����ҵĻظ�Ϊ��򲻷���Ҫ�󣬾ͻ������Ϸ������ӡ��Ϸ��ͳ����Ϣ��
	if (attitude == 0 || attitude != 1)
	{
		printf("\n�ܹ�������%d�֣�+1����ʤ%d�Σ�-1����ʤ%d�Ρ�\n", (player1score + player2score + noplayerscore), player1score, player2score);
		printf("лл���棡�´��ټ���\n");
		getchar(); 
		exit(0);
	}
}
