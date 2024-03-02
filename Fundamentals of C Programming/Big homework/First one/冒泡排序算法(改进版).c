//本程序使用冒泡排序算法。依据优先级顺序，将前一位同学的得分与后一位同学的得分进行比较。
//如果后者得分更高则两者交换排位，再将后一位同学的得分继续与再后一位同学的得分比较，直至末尾。
//重复这样的操作若干次，直到某次遍历数组时没有数据的位置发生交换，即表示数据已按从大到小的顺序排列好了。
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
//函数接受一个表示数组长度的参数。
//函数开始一个外部循环，从数组的第一个元素开始（索引为0），直到倒数第二个元素（索引为limit-2）。这个循环用于控制需要排序的部分。
//对于每个当前元素，我们开始一个内部循环，从当前元素开始，直到未排序部分的最后一个元素。这个循环用于比较和交换元素。
//在内部循环中，如果当前元素（data[j]）小于下一个元素（data[j+1]），我们就交换它们。交换是通过创建一个临时变量agency来完成的。
//我们重复这个过程，直到整个数组都被排序。   
	int i=0, j=0;
    type agency[1];
    for (i = 0; i < limit-1; i++) {     
        for (j = 0; j < limit-i-1; j++) {
           	if (data[j].tlscore < data[j+ 1].tlscore || (data[j].tlscore == data[j + 1].tlscore && data[j].sbjscore < data[j + 1].sbjscore) || (data[j].tlscore == data[j + 1].tlscore && data[j].sbjscore == data[j + 1].sbjscore && data[j].objscore < data[j + 1].objscore))
			{
				agency[0] = data[j];
				data[j] = data[j + 1];
				data[j + 1] = agency[0];
			}
        }
    }
    print(limit);
}
// 客观题得分高者优先排序，规则：客观题得分>总得分>主观题得分
void sort_objscore(int limit)
{
//函数接受一个表示数组长度的参数。
//函数开始一个外部循环，从数组的第一个元素开始（索引为0），直到倒数第二个元素（索引为limit-2）。这个循环用于控制需要排序的部分。
//对于每个当前元素，我们开始一个内部循环，从当前元素开始，直到未排序部分的最后一个元素。这个循环用于比较和交换元素。
//在内部循环中，如果当前元素（data[j]）小于下一个元素（data[j+1]），我们就交换它们。交换是通过创建一个临时变量agency来完成的。
//我们重复这个过程，直到整个数组都被排序。   
	int i=0, j=0;
    type agency[1];
    for (i = 0; i < limit-1; i++) {     
        for (j = 0; j < limit-i-1; j++) {
           	if (data[j].objscore < data[j+ 1].objscore || (data[j].objscore == data[j+ 1].objscore && data[j].tlscore < data[j + 1].tlscore) || (data[j].objscore == data[j+ 1].objscore && data[j].tlscore == data[j + 1].tlscore && data[j].sbjscore < data[j + 1].sbjscore))
			{
				agency[0] = data[j];
				data[j] = data[j + 1];
				data[j + 1] = agency[0];
			}
        }
    }
    print(limit);
}
// 主观题得分高者优先排序，规则：主观题得分>总得分>客观题得分
void sort_sbjscore(int limit)
{
//函数接受一个表示数组长度的参数。
//函数开始一个外部循环，从数组的第一个元素开始（索引为0），直到倒数第二个元素（索引为limit-2）。这个循环用于控制需要排序的部分。
//对于每个当前元素，我们开始一个内部循环，从当前元素开始，直到未排序部分的最后一个元素。这个循环用于比较和交换元素。
//在内部循环中，如果当前元素（data[j]）小于下一个元素（data[j+1]），我们就交换它们。交换是通过创建一个临时变量agency来完成的。
//我们重复这个过程，直到整个数组都被排序。   
	int i=0, j=0;
    type agency[1];
    for (i = 0; i < limit-1; i++) {     
        for (j = 0; j < limit-i-1; j++) {
           	if (data[j].sbjscore < data[j+ 1].sbjscore || (data[j].sbjscore == data[j+ 1].sbjscore && data[j].tlscore < data[j + 1].tlscore) || (data[j].sbjscore == data[j+ 1].sbjscore && data[j].tlscore == data[j + 1].tlscore && data[j].objscore < data[j + 1].objscore))
			{
				agency[0] = data[j];
				data[j] = data[j + 1];
				data[j + 1] = agency[0];
			}
        }
    }
    print(limit);
}
