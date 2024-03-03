#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 15
#define MAX_COL 15
#define BLANK 0
#define BLACK 1
#define WHITE 2

// ��������
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
				printf(" ��");
				break;
			case WHITE:
				printf(" ��");
				break;
			}
		}
		printf("\n");
	}
}

// �ж������Ƿ�����
int is_full(int chessboard[][MAX_COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (chessboard[i][j] == BLANK)
			{
				return 0; // ����δ��
			}
		}
	}
	return 1; // ��������
}

// �ж�ʤ��
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
				return chessboard[i][j]; // ������������
			}
			if (i < row - 4 && chessboard[i][j] == chessboard[i + 1][j] && chessboard[i][j] == chessboard[i + 2][j] && chessboard[i][j] == chessboard[i + 3][j] && chessboard[i][j] == chessboard[i + 4][j])
			{
				return chessboard[i][j]; // ������������
			}
			if (i < row - 4 && j < col - 4 && chessboard[i][j] == chessboard[i + 1][j + 1] && chessboard[i][j] == chessboard[i + 2][j + 2] && chessboard[i][j] == chessboard[i + 3][j + 3] && chessboard[i][j] == chessboard[i + 4][j + 4])
			{
				return chessboard[i][j]; // ��б����������
			}
			if (i < row - 4 && j > 4 && chessboard[i][j] == chessboard[i + 1][j - 1] && chessboard[i][j] == chessboard[i + 2][j - 2] && chessboard[i][j] == chessboard[i + 3][j - 3] && chessboard[i][j] == chessboard[i + 4][j - 4])
			{
				return chessboard[i][j]; // ��б����������
			}
		}
	}
	return BLANK; // ����ʤ��
}

// ����
void save_chess(int chessboard[][MAX_COL], int row, int col)
{
	int choice;
	FILE *fp;
	printf("�Ƿ�ѡ�������Ϸ�������浱ǰ���\n");
	printf("*********1.���̲��˳�***********\n");
	printf("*********2.������Ϸ*************\n");
	printf("��ѡ��: ");
	while (1)
	{
		scanf("%d", &choice);
		if (choice > 2)
		{
			printf("�������������ѡ��\n");
			continue;
		}
		break;
	}
	if (choice == 1)
	{
		if ((fp = fopen("Save_chess.txt", "w")) == NULL)
		{
			printf("����ʧ��\n");
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
			printf("��ϲ��������ɹ�\n");
		}
		exit(0);
	}
}

// ����
void replay_chess(int chessboard[][MAX_COL])
{
    FILE *fp;
    
    fp = fopen("Save_chess.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "����ʧ��: �ļ��򿪴���\n");
        return;
    }

    // ��������Ϊ���ַ���ȡ����ת��Ϊ����Ԫ��
    int k = 0;
    for (int i = 0; i < MAX_ROW; ++i)
    {
        for (int j = 0; j < MAX_COL; ++j)
        {
            fscanf(fp, "%1d", &chessboard[i][j]);
            // ��ֹ�Ƿ����루��������֣�
            if (chessboard[i][j] < BLANK || chessboard[i][j] > WHITE) {
                chessboard[i][j] = BLANK;
            }
        }
    }

    fclose(fp);
    draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
}
// ���˶�ս
void person_person(int chessboard[][MAX_COL])
{
	int i, j;
	draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
	for (int step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 == 1)
		{
			printf("���������: ");
			while (1)
			{
				scanf("%d %d", &i, &j);
				if (chessboard[i][j] != BLANK)
				{
					printf("��λ���������ӣ�����������\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("���볬�����̷�Χ������������\n");
					continue;
				}
				break;
			}
			chessboard[i][j] = BLACK;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK)
			{
				printf("����ʤ\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
		else if (step % 2 == 0)
		{
			printf("���������: ");
			while (1)
			{
				scanf("%d %d", &i, &j);
				if (chessboard[i][j] != BLANK)
				{
					printf("��λ���������ӣ�����������\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("���볬�����̷�Χ������������\n");
					continue;
				}
				break;
			}
			chessboard[i][j] = WHITE;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == WHITE)
			{
				printf("����ʤ\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
	}
	if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
	{
		printf("��������\n");
	}
}


// �˻���ս������㷨��
void person_computer_random(int chessboard[][MAX_COL])
{
	int i, j;
	draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
	for (int step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 == 1)
		{
			printf("���������: ");
			while (1)
			{
				scanf("%d %d", &i, &j);
				if (chessboard[i][j] != BLANK)
				{
					printf("��λ���������ӣ�����������\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("���볬�����̷�Χ������������\n");
					continue;
				}
				break;
			}
			chessboard[i][j] = BLACK;
			draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
			if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK)
			{
				printf("����ʤ\n");
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
				printf("����ʤ\n");
				exit(0);
			}
			save_chess(chessboard, MAX_ROW, MAX_COL);
		}
	}
	if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
	{
		printf("��������\n");
	}
}

int main()
{
	srand(time(NULL)); // ��ʼ�����������
	int choice;
	int chessboard[MAX_ROW][MAX_COL] = {BLANK};
	while (1)
	{
		printf("******************************\n");
		printf("*      1.��-�˶�ս           *\n");
		printf("*      2.��-����ս(����㷨) *\n");
		printf("*      3.����                *\n");
		printf("*      4.�˳�                *\n");
		printf("******************************\n");
		printf("��ѡ��");
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
			printf("�������������ѡ��\n");
			break;
		}
	}
	return 0;
}
