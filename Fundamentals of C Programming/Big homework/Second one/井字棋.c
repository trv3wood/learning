// 这是一个用C语言编写的井字棋游戏。游戏的规则是两个玩家在一个n*n的棋盘上轮流放置棋子，先将自己的n个棋子连成一条直线的玩家获胜。
// 若直到把棋盘填满棋子后仍未分出胜负，则平局。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int currentPlayer = 0, player1Wins = 0, player2Wins = 0, roundCount = 0, size = 0;
int player1score = 0, player2score = 0, noplayerscore = 0, attitude = 0;
void start(int **chessBoard), process(int **chessBoard), record(int **chessBoard), judge(void), result(void);
void check(int *data), printfBoard(int **chessBoard);

// main函数：这是程序的入口点。
// 它首先初始化游戏的状态，然后开启一次棋局，进行回合循环直到满足该局结束。
// 游戏结束后，它会询问玩家是否想要再玩一次，如果玩家答应，就会重开一次棋局。
int main()
{
	int i = 0, j = 0;
	int **chessBoard;
again:
	// 将变量初始化以便正常进行游戏。
	player1Wins = 0;
	player2Wins = 0;
	roundCount = 1;
	printf("亲爱的玩家们，欢迎来到井字棋游戏！请输入你们心仪的nXn棋盘的n值：");
	check(&size);

	// 为棋盘分配内存空间并初始化。
	chessBoard = (int **)malloc(size * sizeof(int *));
	if (chessBoard == NULL)
	{
		printf("输入的数值太大！游戏无法开始！！！！\n");
		exit(1);
	}
	for (i = 0; i < size; i++)
	{
		chessBoard[i] = (int *)malloc(size * sizeof(int));
		if (chessBoard[i] == NULL)
		{
			printf("输入的数值太大！游戏无法开始！！！！\n");
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

	// 游戏的进行，先加载起始环境，再不断进行游戏回合直到满足条件后结束，最终判定胜负。
	start(chessBoard);

	while (player1Wins + player2Wins == 0 && roundCount <= size * size)
	{
		process(chessBoard);
		record(chessBoard);
		roundCount++;
	}

	judge();

	// 释放棋盘的内存空间。
	for (i = 0; i < size; i++)
	{
		free(chessBoard[i]);
		chessBoard[i] = NULL;
	}
	free(chessBoard);
	chessBoard = NULL;
	// 询问玩家是否愿意继续游戏，并根据反馈作出回应。
	result();
	if (attitude)
		goto again;
	else
		return 0;
}

// check函数：
//  这个函数用于确保玩家的输入不是小于1的数，英文字母和标点符号。如果是，就会要求玩家重新输入。
//  但如果玩家输入大于1的小数，函数只会读取它的整数部分，
// 它也不能控制输入数值的上限。
void check(int *data)
{
	int number = 0;
back:
	if (scanf("%d", &number) != 1 || number <= 0)
	{
		printf("\n输入不合法！请重新输入：");
		while (getchar() != '\n'); // 清空输入缓冲区
		goto back; 
		
	}
	else
		*data = number;
}

// printfBoard函数：
// 这个函数用于打印当前的棋盘状态，以便玩家进行游戏。
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

// start函数：
// 这个函数用于给玩家展示游戏的基本信息，包括棋盘的大小和谁先走。
void start(int **chessBoard)
{
	// 用随机数决定谁先走。
	srand(time(NULL));
	currentPlayer = rand() % 100;
	if (currentPlayer >= 0 && currentPlayer <= 49)
		currentPlayer = 1;
	else
		currentPlayer = -1;

	// 打印游戏的基本信息。
	printf("没问题！下面是一张%dX%d的棋盘，+0代表空位。", size, size);
	printf("接下来你们将使用+1和-1作为棋子去填充空位，直到有一方成功将%d个棋子连成直线。\n", size, size);
	printf("正在确定游戏顺序......\n恭喜！这次%+d方先走！\n", currentPlayer);
	printf("温馨提示：\n1.最上一行为第一行，最左一列为第一列；\n2.一个空位只能被填充一次！\n");
	printf("祝你们好运！\n\n");
	printfBoard(chessBoard);
}

// process函数：
// 这个函数负责处理玩家的一次落子行动。
// 它首先询问当前玩家想要在哪里放置棋子，在得到有效的命令后更新棋盘的状态，并切换到下一个玩家。
void process(int **chessBoard)
{
	int i = 0, j = 0;
back:
	// 询问玩家想要在哪里放置棋子，并检查玩家的输入是否有效。
	printf("轮到%+d方：\n请输入你希望填入的位置的行数：", currentPlayer);
	check(&i);
	if (i > size )
	{
		printf("输入的数值太大！请重试！\n\n");
		goto back;
	}
	printf("输入你希望填入的位置的列数："); 
	check(&j);
	printf("\n");
	if ( j > size)
	{
		printf("输入的数值太大！请重试！\n\n");
		goto back;
	}
	if (chessBoard[i - 1][j - 1] != 0)
	{
		printf("这里没有空位了！请重试！\n\n");
		goto back;
	}
	else
		chessBoard[i - 1][j - 1] = currentPlayer;

	// 打印当前棋盘的状态。
	printfBoard(chessBoard);

	// 切换到下一个玩家。
	currentPlayer = -currentPlayer;
}

// record函数：
// 这个函数检查棋盘的当前状态，判断是否有玩家已经获胜，但不负责结束这一局。
void record(int **chessBoard)
{
	int i = 0, j = 0;
	if (roundCount >= size)
	{

		// 检查棋盘的对角线
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
		// 检查棋盘的行和列。
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

// judge函数：
// 这个函数根据record函数的结果，判断谁赢了游戏。
void judge(void)
{
	if (player1Wins == 1 && player2Wins == 0)
	{
		printf("+1方胜利\n\n");
		player1score++;
	}
	else if (player1Wins == 0 && player2Wins == 1)
	{
		printf("-1方胜利\n\n");
		player2score++;
	}
	else if (player1Wins + player2Wins == 0)
	{
		printf("无人获胜\n\n");
		noplayerscore++;
	}
}

// result函数：
// 这个函数询问玩家是否想要再玩一次，记录玩家的回复并判断它是否符合要求。
void result(void)
{
	printf("你还希望再来一局吗？：（1代表是；0代表否）");
	scanf("%d", &attitude);
	printf("\n");
	// 如果玩家的回复为否或不符合要求，就会结束游戏。并打印游戏的统计信息。
	if (attitude == 0 || attitude != 1)
	{
		printf("\n总共进行了%d局：+1方获胜%d次；-1方获胜%d次。\n", (player1score + player2score + noplayerscore), player1score, player2score);
		printf("谢谢游玩！下次再见！\n");
		getchar(); 
		exit(0);
	}
}
