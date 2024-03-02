#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 15
#define MAX_COL 15
#define BLANK 0
#define BLACK 1
#define WHITE 2

// 绘制棋盘
void draw_chessboardn(int row, int col, int chessboard[][MAX_COL])
{
	printf("   ");
	for (int i = 0; i < col; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		printf("%2d ", i);
		for (int j = 0; j < col; j++)
		{
			switch (chessboard[i][j])
			{
			case BLANK:
				printf(" . ");
				break;
			case BLACK:
				printf(" ○");
				break;
			case WHITE:
				printf(" ●");
				break;
			}
		}
		printf("\n");
	}
}

// 判断棋盘是否已满
int is_full(int chessboard[][MAX_COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (chessboard[i][j] == BLANK)
			{
				return 0; // 棋盘未满
			}
		}
	}
	return 1; // 棋盘已满
}

// 判断胜负
int is_win(int chessboard[][MAX_COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (chessboard[i][j] == BLANK)
			{
				continue;
			}
			if (j < col - 4 && chessboard[i][j] == chessboard[i][j + 1] && chessboard[i][j] == chessboard[i][j + 2] && chessboard[i][j] == chessboard[i][j + 3] && chessboard[i][j] == chessboard[i][j + 4])
			{
				return chessboard[i][j]; // 横向连成五子
			}
			if (i < row - 4 && chessboard[i][j] == chessboard[i + 1][j] && chessboard[i][j] == chessboard[i + 2][j] && chessboard[i][j] == chessboard[i + 3][j] && chessboard[i][j] == chessboard[i + 4][j])
			{
				return chessboard[i][j]; // 纵向连成五子
			}
			if (i < row - 4 && j < col - 4 && chessboard[i][j] == chessboard[i + 1][j + 1] && chessboard[i][j] == chessboard[i + 2][j + 2] && chessboard[i][j] == chessboard[i + 3][j + 3] && chessboard[i][j] == chessboard[i + 4][j + 4])
			{
				return chessboard[i][j]; // 右斜向连成五子
			}
			if (i < row - 4 && j > 4 && chessboard[i][j] == chessboard[i + 1][j - 1] && chessboard[i][j] == chessboard[i + 2][j - 2] && chessboard[i][j] == chessboard[i + 3][j - 3] && chessboard[i][j] == chessboard[i + 4][j - 4])
			{
				return chessboard[i][j]; // 左斜向连成五子
			}
		}
	}
	return BLANK; // 无人胜出
}

// 存盘
void save_chess(int chessboard[][MAX_COL], int row, int col)
{
	int choice;
	FILE *fp;
	printf("是否选择结束游戏，并保存当前棋局\n");
	printf("*********1.存盘并退出***********\n");
	printf("*********2.继续游戏*************\n");
	printf("请选择: ");
	while (1)
	{
		scanf("%d", &choice);
		if (choice > 2)
		{
			printf("输入错误，请重新选择\n");
			continue;
		}
		break;
	}
	if (choice == 1)
	{
		if ((fp = fopen("Save_chess.txt", "w")) == NULL)
		{
			printf("保存失败\n");
		}
		else
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					fprintf(fp, "%d", chessboard[i][j]);
				}
			}
			fclose(fp);
			printf("恭喜您，保存成功\n");
		}
		exit(0);
	}
}

// 复盘
void replay_chess(int chessboard[][MAX_COL])
{
    FILE *fp;
    
    fp = fopen("Save_chess.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "复盘失败: 文件打开错误\n");
        return;
    }

    // 修正：改为按字符读取，并转换为棋盘元素
    int k = 0;
    for (int i = 0; i < MAX_ROW; ++i)
    {
        for (int j = 0; j < MAX_COL; ++j)
        {
            fscanf(fp, "%1d", &chessboard[i][j]);
            // 防止非法输入（比如非数字）
            if (chessboard[i][j] < BLANK || chessboard[i][j] > WHITE) {
                chessboard[i][j] = BLANK;
            }
        }
    }

    fclose(fp);
    draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
}
// 人人对战
void person_person(int chessboard[][MAX_COL])
{
	int i, j;
	draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
	for (int step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 == 1)
		{
			printf("请黑棋落子: ");
			while (1)
			{
				scanf("%d %d", &i, &j);
				if (chessboard[i][j] != BLANK)
				{
					printf("该位置已有棋子，请重新输入\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("输入超出棋盘范围，请重新输入\n");
					continue;
				}
				break;
			}
			chessboard[i][j] = BLACK;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK)
			{
				printf("黑棋胜\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
		else if (step % 2 == 0)
		{
			printf("请白棋落子: ");
			while (1)
			{
				scanf("%d %d", &i, &j);
				if (chessboard[i][j] != BLANK)
				{
					printf("该位置已有棋子，请重新输入\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("输入超出棋盘范围，请重新输入\n");
					continue;
				}
				break;
			}
			chessboard[i][j] = WHITE;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == WHITE)
			{
				printf("白棋胜\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
	}
	if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
	{
		printf("棋盘已满\n");
	}
}


// 人机对战（随机算法）
void person_computer_random(int chessboard[][MAX_COL])
{
	int i, j;
	draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
	for (int step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 == 1)
		{
			printf("请黑棋落子: ");
			while (1)
			{
				scanf("%d %d", &i, &j);
				if (chessboard[i][j] != BLANK)
				{
					printf("该位置已有棋子，请重新输入\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("输入超出棋盘范围，请重新输入\n");
					continue;
				}
				break;
			}
			chessboard[i][j] = BLACK;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK)
			{
				printf("黑棋胜\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
		else if (step % 2 == 0)
		{
			while (1)
			{
				i = rand() % MAX_ROW;
				j = rand() % MAX_COL;
				if (chessboard[i][j] == BLANK)
				{
					break;
				}
			}
			chessboard[i][j] = WHITE;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == WHITE)
			{
				printf("白棋胜\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
	}
	if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
	{
		printf("棋盘已满\n");
	}
}

int main()
{
	srand(time(NULL)); // 初始化随机数种子
	int choice;
	int chessboard[MAX_ROW][MAX_COL] = {BLANK};
	while (1)
	{
		printf("******************************\n");
		printf("*      1.人-人对战           *\n");
		printf("*      2.人-机对战(随机算法) *\n");
		printf("*      3.复盘                *\n");
		printf("*      4.退出                *\n");
		printf("******************************\n");
		printf("请选择：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			person_person(chessboard);
			break;
		case 2:
			person_computer_random(chessboard);
			break;
		case 3:
			replay_chess(chessboard);
			break;
		case 4:
			exit(0);
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	}
	return 0;
}
