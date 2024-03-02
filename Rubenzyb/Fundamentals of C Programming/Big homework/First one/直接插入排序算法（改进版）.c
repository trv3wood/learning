// 本程序使用直接插入排序算法。
//通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
#include <stdio.h>
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
void sort_tlscore(int);
void sort_objscore(int);
void sort_sbjscore(int);
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
		sort_tlscore(limit);
		break;
	case 2:
		sort_objscore(limit);
		break;
	case 3:
		sort_sbjscore(limit);
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
// 总得分高者优先排序，规则：总得分>主观题得分>客观题得分
void sort_tlscore(int limit)
{
//函数接受一个表示数组的长度的参数。
//函数开始一个外部循环，从数组的第二个元素开始（索引为1），因为我们假设第一个元素（索引为0）已经被排序。
//对于每个当前元素，我们将其值保存在变量agency中，并将其前一个元素的索引保存在变量j中。
//然后，我们开始一个内部循环，从当前元素的前一个元素开始，如果这个元素（data[j]）比agency小，我们就将它向右移动一位（即将data[j]复制到data[j + 1]），然后将j减1，以便在下一次迭代中检查前一个元素。
//当我们找到一个不比agency小的元素或者已经检查到数组的开始时（即j变为-1），我们就在这个位置的右边插入agency（即将key的值复制到data[j + 1]）。
//我们重复这个过程，直到整个数组都被排序。
	int i=0,j=0;
	type agency[1]; 
    for (i = 1; i < limit; i++) {
        agency[0]=data[i];
        j = i - 1;
        while ( j >= 0 && ( data[j].tlscore < agency[0].tlscore || (data[j].tlscore == agency[0].tlscore && data[j].sbjscore <agency[0].sbjscore) || (data[j].tlscore == agency[0].tlscore && data[j].sbjscore==agency[0].sbjscore && data[j].objscore<agency[0].objscore) ) ){
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] =  agency[0];
    }
    print(limit);
}
// 客观题得分高者优先排序，规则：客观题得分>总得分>主观题得分
void sort_objscore(int limit)
{
//函数接受一个表示数组的长度的参数。
//函数开始一个外部循环，从数组的第二个元素开始（索引为1），因为我们假设第一个元素（索引为0）已经被排序。
//对于每个当前元素，我们将其值保存在变量agency中，并将其前一个元素的索引保存在变量j中。
//然后，我们开始一个内部循环，从当前元素的前一个元素开始，如果这个元素（data[j]）比agency小，我们就将它向右移动一位（即将data[j]复制到data[j + 1]），然后将j减1，以便在下一次迭代中检查前一个元素。
//当我们找到一个不比agency小的元素或者已经检查到数组的开始时（即j变为-1），我们就在这个位置的右边插入agency（即将key的值复制到data[j + 1]）。
//我们重复这个过程，直到整个数组都被排序。
	int i=0,j=0;
	type agency[1]; 
    for (i = 1; i < limit; i++) {
        agency[0]=data[i];
        j = i - 1;
        while ( j >= 0 && ( data[j].objscore < agency[0].objscore || (data[j].objscore == agency[0].objscore && data[j].tlscore <agency[0].tlscore) || (data[j].objscore == agency[0].objscore && data[j].tlscore==agency[0].tlscore && data[j].sbjscore<agency[0].sbjscore) ) ){
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] =  agency[0];
    }
    print(limit);
}
// 主观题得分高者优先排序，规则：主观题得分>总得分>客观题得分
void sort_sbjscore(int limit)
{
//函数接受一个表示数组的长度的参数。
//函数开始一个外部循环，从数组的第二个元素开始（索引为1），因为我们假设第一个元素（索引为0）已经被排序。
//对于每个当前元素，我们将其值保存在变量agency中，并将其前一个元素的索引保存在变量j中。
//然后，我们开始一个内部循环，从当前元素的前一个元素开始，如果这个元素（data[j]）比agency小，我们就将它向右移动一位（即将data[j]复制到data[j + 1]），然后将j减1，以便在下一次迭代中检查前一个元素。
//当我们找到一个不比agency小的元素或者已经检查到数组的开始时（即j变为-1），我们就在这个位置的右边插入agency（即将key的值复制到data[j + 1]）。
//我们重复这个过程，直到整个数组都被排序。
	int i=0,j=0;
	type agency[1]; 
    for (i = 1; i < limit; i++) {
        agency[0]=data[i];
        j = i - 1;
        while ( j >= 0 && ( data[j].sbjscore < agency[0].sbjscore || (data[j].sbjscore == agency[0].sbjscore && data[j].tlscore <agency[0].tlscore) || (data[j].sbjscore == agency[0].sbjscore && data[j].tlscore==agency[0].tlscore && data[j].objscore<agency[0].objscore) ) ){
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] =  agency[0];
    }
    print(limit);
}
