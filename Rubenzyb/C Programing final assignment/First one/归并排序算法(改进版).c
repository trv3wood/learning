//这段代码实现了归并排序，
//归并排序是一种分治算法。它的工作原理是将一个大数组分解成两个小数组，然后对这两个小数组进行排序，最后将这两个已排序的小数组合并成一个大数组。
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
// 定义三种排序优先级不同的函数
void tlscore_mergeSort( int,int);
void tlscore_merge(int,int,int);
void objscore_mergeSort( int,int);
void objscore_merge(int,int,int);
void sbjscore_mergeSort( int,int);
void sbjscore_merge(int,int,int);
void print(int);
// 能够选择排序的规则与数据的大小
int main()
{
	int chose = 0, limit = 0,i=0;
	//从文件中读取数据储存在结构体数组中
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
	// 询问这次处理的数据的组数
	printf("How many sets of data do you need to process this time?(2~195)\n");
	scanf("%d", &limit);
	// 在一定程度上防止非法输入使程序崩溃
	if (limit < 2 || limit > 195)
	{
		printf("What you entered does not conform to the specification,!Please try again!\n\n");
		goto again1;
	}

again2:
	// 询问以哪种得分优先来进行排序
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
		// 在一定程度上防止非法输入使程序崩溃
	default:
		printf("What you entered does not conform to the specification,!Please try again!\n\n");
		goto again2;
	}
	return 0;
}

// 以表格的形式输出排序后的数据
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
//这个函数是归并排序的主要部分。
//它首先检查数组的长度是否大于1。如果是，它计算出中间索引m，并递归地对数组的左半部分和右半部分进行排序。
//然后，它调用对应的merge函数将这两个已排序的子数组合并成一个大数组。
void tlscore_mergeSort( int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

       tlscore_mergeSort( l, m);
       tlscore_mergeSort(m + 1, r);

        tlscore_merge(l, m, r);
    }
}
//这个函数是归并排序的主要部分。
//它首先检查数组的长度是否大于1。如果是，它计算出中间索引m，并递归地对数组的左半部分和右半部分进行排序。
//然后，它调用对应的merge函数将这两个已排序的子数组合并成一个大数组。
void objscore_mergeSort( int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        objscore_mergeSort( l, m);
        objscore_mergeSort(m + 1, r);

        objscore_merge(l, m, r);
    }
}
//这个函数是归并排序的主要部分。
//它首先检查数组的长度是否大于1。如果是，它计算出中间索引m，并递归地对数组的左半部分和右半部分进行排序。
//然后，它调用对应的merge函数将这两个已排序的子数组合并成一个大数组。
void sbjscore_mergeSort( int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sbjscore_mergeSort( l, m);
        sbjscore_mergeSort(m + 1, r);

        sbjscore_merge(l, m, r);
    }
}
//这个函数用于合并两个已排序的子数组。
//它首先计算出子数组的长度，然后创建两个临时数组L和R来存储这两个子数组。
//然后，它使用两个指针i和j分别遍历这两个子数组，并将较小的元素复制到原始数组中。
//当一个子数组的所有元素都被复制后，它将另一个子数组的剩余元素复制到原始数组中。
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
// 总得分高者优先排序，规则：总得分>主观题得分>客观题得分
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

//这个函数用于合并两个已排序的子数组。
//它首先计算出子数组的长度，然后创建两个临时数组L和R来存储这两个子数组。
//然后，它使用两个指针i和j分别遍历这两个子数组，并将较小的元素复制到原始数组中。
//当一个子数组的所有元素都被复制后，它将另一个子数组的剩余元素复制到原始数组中。
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
// 客观题得分高者优先排序，规则：客观题得分>总得分>主观题得分
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

//这个函数用于合并两个已排序的子数组。
//它首先计算出子数组的长度，然后创建两个临时数组L和R来存储这两个子数组。
//然后，它使用两个指针i和j分别遍历这两个子数组，并将较小的元素复制到原始数组中。
//当一个子数组的所有元素都被复制后，它将另一个子数组的剩余元素复制到原始数组中。
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
// 主观题得分高者优先排序，规则：主观题得分>总得分>客观题得分
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
