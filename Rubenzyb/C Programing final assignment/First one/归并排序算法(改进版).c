//��δ���ʵ���˹鲢����
//�鲢������һ�ַ����㷨�����Ĺ���ԭ���ǽ�һ��������ֽ������С���飬Ȼ���������С���������������������������С����ϲ���һ�������顣
#include <stdio.h>
#include <string.h>
typedef struct
{
    char major[22];
    char Class[10];
    char stdID[11];
    int tlscore;
    int objscore;
    int sbjscore;
} type;
type data[195];
// ���������������ȼ���ͬ�ĺ���
void tlscore_mergeSort( int,int);
void tlscore_merge(int,int,int);
void objscore_mergeSort( int,int);
void objscore_merge(int,int,int);
void sbjscore_mergeSort( int,int);
void sbjscore_merge(int,int,int);
void print(int);
// �ܹ�ѡ������Ĺ��������ݵĴ�С
int main()
{
	int chose = 0, limit = 0,i=0;
	//���ļ��ж�ȡ���ݴ����ڽṹ��������
	FILE *file = fopen("Mid-term_exam_score.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }
    while (i < 195 && fscanf(file, "%21s %9s %10s %d %d %d", data[i].major, data[i].Class, data[i].stdID, &data[i].tlscore, &data[i].objscore, &data[i].sbjscore) == 6) {
        i++;
    }
    
    fclose(file);

again1:
	// ѯ����δ�������ݵ�����
	printf("How many sets of data do you need to process this time?(2~195)\n");
	scanf("%d", &limit);
	// ��һ���̶��Ϸ�ֹ�Ƿ�����ʹ�������
	if (limit < 2 || limit > 195)
	{
		printf("What you entered does not conform to the specification,!Please try again!\n\n");
		goto again1;
	}

again2:
	// ѯ�������ֵ÷���������������
	printf("Which type of data do you want to sort based on?\n"
		   "Please use the serial number to select from the three types below:\n"
		   " 1.tlscore; 2.objscore; 3.sbjscore.\n ");
	scanf("%d", &chose);

	switch (chose)
	{
	case 1:
		tlscore_mergeSort(0,limit-1);
		print(limit);
		break;
	case 2:
		objscore_mergeSort(0,limit-1);
		print(limit);
		break;
	case 3:
		sbjscore_mergeSort(0,limit-1);
		print(limit);
		break;
		// ��һ���̶��Ϸ�ֹ�Ƿ�����ʹ�������
	default:
		printf("What you entered does not conform to the specification,!Please try again!\n\n");
		goto again2;
	}
	return 0;
}

// �Ա�����ʽ�������������
void print(int limit)
{
	int i = 0;
    printf("%-19s%-13sstudent ID   tlscore objscore sbjscore\n", "Major", "Class");
	for (i = 0; i < limit; i++)
	{
		printf("%-15s	", data[i].major);
		printf("%10s	", data[i].Class);
		printf("%10s	", data[i].stdID);
		printf("%-8d", data[i].tlscore);
		printf("%-8d", data[i].objscore);
		printf("%-8d\n", data[i].sbjscore);
	}
}
//��������ǹ鲢�������Ҫ���֡�
//�����ȼ������ĳ����Ƿ����1������ǣ���������м�����m�����ݹ�ض��������벿�ֺ��Ұ벿�ֽ�������
//Ȼ�������ö�Ӧ��merge�������������������������ϲ���һ�������顣
void tlscore_mergeSort( int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

       tlscore_mergeSort( l, m);
       tlscore_mergeSort(m + 1, r);

        tlscore_merge(l, m, r);
    }
}
//��������ǹ鲢�������Ҫ���֡�
//�����ȼ������ĳ����Ƿ����1������ǣ���������м�����m�����ݹ�ض��������벿�ֺ��Ұ벿�ֽ�������
//Ȼ�������ö�Ӧ��merge�������������������������ϲ���һ�������顣
void objscore_mergeSort( int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        objscore_mergeSort( l, m);
        objscore_mergeSort(m + 1, r);

        objscore_merge(l, m, r);
    }
}
//��������ǹ鲢�������Ҫ���֡�
//�����ȼ������ĳ����Ƿ����1������ǣ���������м�����m�����ݹ�ض��������벿�ֺ��Ұ벿�ֽ�������
//Ȼ�������ö�Ӧ��merge�������������������������ϲ���һ�������顣
void sbjscore_mergeSort( int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sbjscore_mergeSort( l, m);
        sbjscore_mergeSort(m + 1, r);

        sbjscore_merge(l, m, r);
    }
}
//����������ںϲ�����������������顣
//�����ȼ����������ĳ��ȣ�Ȼ�󴴽�������ʱ����L��R���洢�����������顣
//Ȼ����ʹ������ָ��i��j�ֱ���������������飬������С��Ԫ�ظ��Ƶ�ԭʼ�����С�
//��һ�������������Ԫ�ض������ƺ�������һ���������ʣ��Ԫ�ظ��Ƶ�ԭʼ�����С�
void tlscore_merge(int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    type L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
// �ܵ÷ָ����������򣬹����ܵ÷�>������÷�>�͹���÷�
        if ( L[i].tlscore > R[j].tlscore || (L[i].tlscore == R[j].tlscore && L[i].sbjscore >R[j].sbjscore) || (L[i].tlscore == R[j].tlscore && L[i].sbjscore == R[j].sbjscore && L[i].objscore>R[j].objscore)||(L[i].tlscore == R[j].tlscore && L[i].sbjscore == R[j].sbjscore && L[i].objscore==R[j].objscore&&strncmp(L[i].stdID+6,R[j].stdID+6,4)<0) ) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

//����������ںϲ�����������������顣
//�����ȼ����������ĳ��ȣ�Ȼ�󴴽�������ʱ����L��R���洢�����������顣
//Ȼ����ʹ������ָ��i��j�ֱ���������������飬������С��Ԫ�ظ��Ƶ�ԭʼ�����С�
//��һ�������������Ԫ�ض������ƺ�������һ���������ʣ��Ԫ�ظ��Ƶ�ԭʼ�����С�
void objscore_merge(int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    type L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
// �͹���÷ָ����������򣬹��򣺿͹���÷�>�ܵ÷�>������÷�
        if ( L[i].objscore > R[j].objscore || (L[i].objscore == R[j].objscore && L[i].tlscore >R[j].tlscore) || (L[i].tlscore == R[j].tlscore && L[i].objscore == R[j].objscore && L[i].sbjscore>R[j].sbjscore)||(L[i].tlscore == R[j].tlscore && L[i].sbjscore == R[j].sbjscore && L[i].objscore==R[j].objscore&&strncmp(L[i].stdID+6,R[j].stdID+6,4)<0) ) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

//����������ںϲ�����������������顣
//�����ȼ����������ĳ��ȣ�Ȼ�󴴽�������ʱ����L��R���洢�����������顣
//Ȼ����ʹ������ָ��i��j�ֱ���������������飬������С��Ԫ�ظ��Ƶ�ԭʼ�����С�
//��һ�������������Ԫ�ض������ƺ�������һ���������ʣ��Ԫ�ظ��Ƶ�ԭʼ�����С�
void sbjscore_merge(int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    type L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
// ������÷ָ����������򣬹���������÷�>�ܵ÷�>�͹���÷�
        if ( L[i].sbjscore > R[j].sbjscore || (L[i].sbjscore == R[j].sbjscore && L[i].tlscore >R[j].tlscore) || (L[i].tlscore == R[j].tlscore && L[i].sbjscore == R[j].sbjscore && L[i].objscore>R[j].objscore)||(L[i].tlscore == R[j].tlscore && L[i].sbjscore == R[j].sbjscore && L[i].objscore==R[j].objscore&&strncmp(L[i].stdID+6,R[j].stdID+6,4)<0) ) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}
