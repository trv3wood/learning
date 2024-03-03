// 本程序使用快速排序算法。
// 选取每组数据最右侧的数据作为基准，再设置前后两个指针交替向左移动来选中数据。
// 依据规则判定指针所指的数据位于基准的哪一侧，如果需要移动数据，将数据移动到左侧。
// 为了与其他算法输出的结果保持一致，该程序中的规则增加了有关学号的判定，学号具有唯一性，这使得排序结果变得稳定。
// 直到前面的指针遍历完数组后，将基准数据放入后面的指针所指位置的前面，则一次操作结束。
// 在函数的最后继续调用同一个函数，判定新形成的两组数据是否只含有一个元素，如果不是，重复上述操作。
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
void sort_score(int,int,int);
int score_partition (int,int,int);
void sort_tlscore(int*,int,int);
void sort_objscore(int*,int,int);
void sort_sbjscore(int*,int,int);
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
	// 询问以哪种得分优先来进行排序
	printf("Which type of data do you want to sort based on?\n"
		   "Please use the serial number to select from the three types below:\n"
		   " 1.tlscore; 2.objscore; 3.sbjscore.\n ");
	scanf("%d", &chose);
	
	sort_score(0,limit-1,chose);
	print(limit);
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
//该函数是快速排序算法的主体部分，它使用了分治的策略。以下是该函数的详细步骤：
//1.函数接受两个参数lowlimit和uplimit，它们分别是要进行划分的数组部分的起始和结束索引。
//2. 在函数内部，我们首先检查lowlimit是否小于uplimit。如果不是，那么这个数组部分已经是有序的，我们就直接返回。
//3. 如果lowlimit小于uplimit，我们就调用partition函数，对数组进行划分，并获取基准元素的位置pivot。
//4. 然后，我们对基准元素左边的子数组进行快速排序，即调用sort_score(lowlimit, pivot - 1)。
//5. 接着，我们对基准元素右边的子数组进行快速排序，即调用sort_score(pivot + 1, uplimit);。
//6. 这样，整个数组就被排序了。
void sort_score(int lowlimit,int uplimit,int chose)
{ 	
	if (lowlimit<uplimit) {
        int pivot = score_partition(lowlimit,uplimit,chose);
        sort_score(lowlimit, pivot - 1,chose);
        sort_score(pivot + 1, uplimit,chose);
    }
}
//函数接受两个参数lowlimit和uplimit，它们分别是要进行划分的数组部分的起始和结束索引。
//在函数内部，我们首先选择一个基准元素，这里我们选择的是数组部分的最后一个元素data[uplimit]。
//然后，我们创建一个索引i，并将其初始化为lowlimit - 1。这个索引用于追踪最后一个小于基准的元素的位置。
//接着，我们开始一个循环，从lowlimit到uplimit - 1。在每次迭代中，如果当前元素小于基准元素，我们就将i加1，然后交换data[i]和data[j];
//循环结束后，我们将基准元素放到正确的位置，即data[i + 1]和data[uplimit]的位置交换。这样，基准元素左边的所有元素都小于它，右边的所有元素都大于它。
//最后，函数返回基准元素的位置i + 1。
int score_partition (int lowlimit, int uplimit,int chose)
{
    type agency[1];
	int i = (lowlimit - 1),j=0; 
    for ( j = lowlimit; j <= uplimit- 1; j++) {
       switch(chose)
	   {
		case 1:
			sort_tlscore(&i,j,uplimit);
			break;
		case 2:
			sort_objscore(&i,j,uplimit);
			break;
		case 3:
			sort_sbjscore(&i,j,uplimit);
			break;
	   }
    }
    agency[0]=data[i + 1]; 
	data[i + 1]=data[uplimit];
	data[uplimit]= agency[0];
	return (i + 1);
}
// 总得分高者优先排序，规则：总得分>主观题得分>客观题得分。
void sort_tlscore(int *i,int j,int uplimit)
{
	 type agency[1];
	 if( data[j].tlscore > data[uplimit].tlscore || (data[j].tlscore == data[uplimit].tlscore && data[j].sbjscore >data[uplimit].sbjscore) || (data[j].tlscore == data[uplimit].tlscore && data[j].sbjscore==data[uplimit].sbjscore && data[j].objscore>data[uplimit].objscore) ||(data[j].tlscore == data[uplimit].tlscore && data[j].sbjscore==data[uplimit].sbjscore && data[j].objscore==data[uplimit].objscore &&strncmp(data[j].stdID+6,data[uplimit].stdID+6,4)<0) )
		{
            (*i)++; 
            agency[0]=data[*i];
			data[*i]=data[j];
			data[j]=agency[0];
        }
}
// 客观题得分高者优先排序，规则：客观题得分>总得分>主观题得分。 
void sort_objscore(int *i,int j,int uplimit)
{
	 type agency[1];
	 if( data[j].objscore > data[uplimit].objscore || (data[j].objscore == data[uplimit].objscore && data[j].tlscore >data[uplimit].tlscore) || (data[j].objscore == data[uplimit].objscore && data[j].tlscore==data[uplimit].tlscore && data[j].sbjscore>data[uplimit].sbjscore) ||(data[j].tlscore == data[uplimit].tlscore && data[j].sbjscore==data[uplimit].sbjscore && data[j].objscore==data[uplimit].objscore &&strncmp(data[j].stdID+6,data[uplimit].stdID+6,4)<0) )
		{
            (*i)++; 
            agency[0]=data[*i];
			data[*i]=data[j];
			data[j]=agency[0];
        }
}
// 主观题得分高者优先排序，规则：主观题得分>总得分>客观题得分。
void sort_sbjscore(int *i,int j,int uplimit)
{
	 type agency[1];
	 if( data[j].sbjscore > data[uplimit].sbjscore || (data[j].sbjscore == data[uplimit].sbjscore && data[j].tlscore >data[uplimit].tlscore) || (data[j].sbjscore == data[uplimit].sbjscore && data[j].tlscore==data[uplimit].tlscore && data[j].objscore>data[uplimit].objscore) ||(data[j].tlscore == data[uplimit].tlscore && data[j].sbjscore==data[uplimit].sbjscore && data[j].objscore==data[uplimit].objscore &&strncmp(data[j].stdID+6,data[uplimit].stdID+6,4)<0) )
		{
            (*i)++; 
            agency[0]=data[*i];
			data[*i]=data[j];
			data[j]=agency[0];
        }
}

