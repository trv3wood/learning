// 虽然定义一个含有195组数据的全局数组会使程序显得很臃肿，但本人水平着实有限，只能靠这种不入流的手段来将数据送入程序之中
struct type
{
	char major[22];
	char Class[10];
	int stdID;
	char tlscore;
	char objscore;
	char sbjscore;
};
struct type data[195] = {
	{"航空航天类", "	DL012301", 2023300399, 100, 30, 70},
	{"航空航天类", "	DL012301", 2023300408, 100, 30, 70},
	{"航空航天类", "	DL012303", 2023300448, 87, 21, 66},
	{"航空航天类", "	DL012303", 2023300472, 84, 27, 57},
	{"航空航天类", "	DL012304", 2023300497, 92, 27, 65},
	{"航空航天类", "	DL012305", 2023300499, 96, 27, 69},
	{"航空航天类", "	DL012305", 2023300502, 93, 27, 66},
	{"航空航天类", "	DL012305", 2023300507, 84, 27, 57},
	{"航空航天类", "	DL012306", 2023300537, 100, 30, 70},
	{"航空航天类", "	DL012307", 2023300557, 79, 24, 55},
	{"航空航天类", "	DL012308", 2023300576, 96, 30, 66},
	{"航空航天类", "	DL012308", 2023300582, 96, 30, 66},
	{"航空航天类", "	DL012309", 2023300600, 83, 30, 53},
	{"航空航天类", "	DL012309", 2023300609, 85, 27, 58},
	{"航空航天类", "	DL012311", 2023300653, 94, 24, 70},
	{"航空航天类", "	DL012311", 2023300655, 96, 30, 66},
	{"航空航天类", "	DL012312", 2023300673, 93, 27, 66},
	{"航空航天类", "	DL012312", 2023300675, 85, 27, 58},
	{"航空航天类", "	DL012312", 2023300676, 90, 24, 66},
	{"航空航天类", "	DL012312", 2023300688, 95, 30, 65},
	{"航空航天类", "	DL012313", 2023300700, 90, 24, 66},
	{"航空航天类", "	DL012314", 2023300732, 81, 27, 54},
	{"航空航天类", "	DL012315", 2023300748, 95, 30, 65},
	{"航空航天类", "	DL012315", 2023300753, 100, 30, 70},
	{"航空航天类", "	DL012315", 2023300756, 100, 30, 70},
	{"航空航天类", "	DL012316", 2023300774, 89, 27, 62},
	{"航空航天类", "	DL012316", 2023300778, 74, 21, 53},
	{"航空航天类", "	DL012317", 2023300801, 93, 27, 66},
	{"航空航天类", "	DL012318", 2023300816, 72, 24, 48},
	{"航空航天类", "	DL012318", 2023300824, 81, 24, 57},
	{"航空航天类", "	DL012318", 2023300830, 78, 21, 57},
	{"航空航天类", "	DL012318", 2023300838, 85, 21, 64},
	{"航空航天类", "	DL012319", 2023300844, 90, 24, 66},
	{"航空航天类", "	DL012319", 2023300856, 91, 21, 70},
	{"航空航天类", "	DL012320", 2023300871, 97, 27, 70},
	{"航空航天类", "	DL012320", 2023300875, 68, 24, 44},
	{"航空航天类", "	DL012320", 2023300881, 97, 27, 70},
	{"航空航天类", "	DL012320", 2023300886, 81, 24, 57},
	{"航空航天类", "	DL012321", 2023300899, 96, 30, 66},
	{"航空航天类", "	DL012321", 2023300902, 76, 18, 58},
	{"航空航天类", "	DL012321", 2023300914, 75, 18, 57},
	{"航空航天类", "	DL012321", 2023300918, 81, 24, 57},
	{"智能制造类", "	DL042301", 2023301510, 70, 18, 52},
	{"智能制造类", "	DL042301", 2023301513, 100, 30, 70},
	{"智能制造类", "	DL042301", 2023301521, 93, 27, 66},
	{"智能制造类", "	DL042302", 2023301535, 100, 30, 70},
	{"智能制造类", "	DL042302", 2023301543, 82, 24, 58},
	{"智能制造类", "	DL042302", 2023301548, 63, 24, 39},
	{"智能制造类", "	DL042302", 2023301553, 97, 27, 70},
	{"智能制造类", "	DL042303", 2023301555, 78, 24, 54},
	{"智能制造类", "	DL042303", 2023301577, 90, 30, 60},
	{"智能制造类", "	DL042304", 2023301580, 100, 30, 70},
	{"智能制造类", "	DL042304", 2023301599, 80, 27, 53},
	{"智能制造类", "	DL042304", 2023301600, 97, 27, 70},
	{"智能制造类", "	DL042305", 2023301608, 93, 27, 66},
	{"智能制造类", "	DL042305", 2023301612, 79, 27, 52},
	{"智能制造类", "	DL042305", 2023301619, 96, 30, 66},
	{"智能制造类", "	DL042305", 2023301620, 89, 27, 62},
	{"智能制造类", "	DL042306", 2023301629, 100, 30, 70},
	{"智能制造类", "	DL042306", 2023301635, 96, 30, 66},
	{"智能制造类", "	DL042306", 2023301643, 96, 30, 66},
	{"智能制造类", "	DL042307", 2023301653, 96, 27, 69},
	{"智能制造类", "	DL042307", 2023301664, 100, 30, 70},
	{"智能制造类", "	DL042307", 2023301665, 85, 27, 58},
	{"智能制造类", "	DL042308", 2023301670, 100, 30, 70},
	{"智能制造类", "	DL042308", 2023301671, 85, 24, 61},
	{"智能制造类", "	DL042308", 2023301686, 100, 30, 70},
	{"智能制造类", "	DL042308", 2023301688, 97, 27, 70},
	{"智能制造类", "	DL042309", 2023301694, 100, 30, 70},
	{"智能制造类", "	DL042309", 2023301695, 77, 24, 53},
	{"智能制造类", "	DL042309", 2023301706, 86, 21, 65},
	{"智能制造类", "	DL042309", 2023301708, 100, 30, 70},
	{"智能制造类", "	DL042310", 2023301722, 99, 30, 69},
	{"智能制造类", "	DL042310", 2023301733, 96, 30, 66},
	{"智能制造类", "	DL042311", 2023301742, 92, 27, 65},
	{"智能制造类", "	DL042311", 2023301749, 93, 27, 66},
	{"智能制造类", "	DL042311", 2023301761, 82, 30, 52},
	{"信息类", "	DL062301", 2023302016, 81, 24, 57},
	{"信息类", "	DL062301", 2023302021, 97, 27, 70},
	{"信息类", "	DL062302", 2023302026, 88, 30, 58},
	{"信息类", "	DL062302", 2023302036, 91, 30, 61},
	{"信息类", "	DL062303", 2023302050, 100, 30, 70},
	{"信息类", "	DL062303", 2023302066, 92, 30, 62},
	{"信息类", "	DL062304", 2023302086, 87, 27, 60},
	{"信息类", "	DL062304", 2023302091, 100, 30, 70},
	{"信息类", "	DL062305", 2023302096, 90, 24, 66},
	{"信息类", "	DL062305", 2023302116, 74, 21, 53},
	{"信息类", "	DL062306", 2023302128, 96, 30, 66},
	{"信息类", "	DL062306", 2023302130, 89, 27, 62},
	{"信息类", "	DL062306", 2023302140, 85, 27, 58},
	{"信息类", "	DL062307", 2023302143, 100, 30, 70},
	{"信息类", "	DL062308", 2023302170, 100, 30, 70},
	{"信息类", "	DL062308", 2023302186, 88, 27, 61},
	{"信息类", "	DL062309", 2023302191, 82, 24, 58},
	{"信息类", "	DL062309", 2023302194, 88, 27, 61},
	{"信息类", "	DL062310", 2023302212, 97, 27, 70},
	{"信息类", "	DL062313", 2023302284, 95, 30, 65},
	{"信息类", "	DL062313", 2023302299, 82, 27, 55},
	{"信息类", "	DL062314", 2023302311, 97, 27, 70},
	{"信息类", "	DL062316", 2023302362, 63, 18, 45},
	{"信息类", "	DL062316", 2023302363, 93, 27, 66},
	{"信息类", "	DL062316", 2023302365, 88, 27, 61},
	{"信息类", "	DL062316", 2023302366, 69, 21, 48},
	{"信息类", "	DL062316", 2023302367, 71, 21, 50},
	{"信息类", "	DL062316", 2023302369, 88, 27, 61},
	{"信息类", "	DL062317", 2023302382, 97, 27, 70},
	{"信息类", "	DL062317", 2023302385, 96, 30, 66},
	{"信息类", "	DL062317", 2023302390, 78, 24, 54},
	{"信息类", "	DL062317", 2023302396, 100, 30, 70},
	{"信息类", "	DL062318", 2023302417, 97, 27, 70},
	{"信息类", "	DL062319", 2023302432, 79, 24, 55},
	{"信息类", "	DL062320", 2023302456, 83, 27, 56},
	{"信息类", "	DL062320", 2023302461, 90, 27, 63},
	{"信息类", "	DL062320", 2023302464, 76, 21, 55},
	{"信息类", "	DL062320", 2023302470, 75, 27, 48},
	{"信息类", "	DL062321", 2023302491, 80, 27, 53},
	{"信息类", "	DL062322", 2023302507, 97, 27, 70},
	{"信息类", "	DL062322", 2023302510, 79, 27, 52},
	{"信息类", "	DL062322", 2023302520, 89, 27, 62},
	{"信息类", "	DL062322", 2023302523, 93, 27, 66},
	{"信息类", "	DL062333", 2023302795, 53, 18, 35},
	{"信息类", "	DL062333", 2023302806, 74, 21, 53},
	{"信息类", "	DL062334", 2023302839, 56, 18, 38},
	{"信息类", "	DL062335", 2023302842, 75, 24, 51},
	{"信息类", "	DL062335", 2023302845, 92, 27, 65},
	{"信息类", "	DL062335", 2023302848, 100, 30, 70},
	{"信息类", "	DL062335", 2023302852, 96, 30, 66},
	{"信息类", "	DL062336", 2023302867, 92, 30, 62},
	{"信息类", "	DL062336", 2023302868, 88, 27, 61},
	{"信息类", "	DL062336", 2023302881, 94, 24, 70},
	{"信息类", "	DL062337", 2023302895, 82, 27, 55},
	{"信息类", "	DL062337", 2023302896, 67, 24, 43},
	{"信息类", "	DL062337", 2023302899, 97, 27, 70},
	{"信息类", "	DL062337", 2023302904, 95, 30, 65},
	{"信息类", "	DL062337", 2023302905, 95, 30, 65},
	{"信息类", "	DL062338", 2023302927, 96, 30, 66},
	{"信息类", "	DL062338", 2023302928, 83, 27, 56},
	{"信息类", "	DL062338", 2023302929, 74, 27, 47},
	{"信息类", "	DL062338", 2023302941, 75, 21, 54},
	{"信息类", "	DL062339", 2023302968, 84, 24, 60},
	{"信息类", "	DL062340", 2023302978, 96, 30, 66},
	{"信息类", "	DL062340", 2023302979, 90, 24, 66},
	{"信息类", "	DL062340", 2023302984, 85, 27, 58},
	{"信息类", "	DL062340", 2023302993, 87, 27, 60},
	{"信息类", "	DL062341", 2023303008, 96, 30, 66},
	{"信息类", "	DL062341", 2023303009, 93, 27, 66},
	{"信息类", "	DL062341", 2023303021, 75, 24, 51},
	{"信息类", "	DL062342", 2023303036, 100, 30, 70},
	{"信息类", "	DL062342", 2023303040, 73, 21, 52},
	{"信息类", "	DL062342", 2023303044, 95, 30, 65},
	{"信息类", "	DL062343", 2023303048, 91, 30, 61},
	{"信息类", "	DL062343", 2023303053, 97, 27, 70},
	{"信息类", "	DL062343", 2023303059, 76, 24, 52},
	{"信息类", "	DL062343", 2023303069, 96, 27, 69},
	{"信息类", "	DL062344", 2023303083, 92, 27, 65},
	{"信息类", "	DL062344", 2023303088, 96, 30, 66},
	{"信息类", "	DL062344", 2023303090, 87, 27, 60},
	{"信息类", "	DL062344", 2023303095, 96, 30, 66},
	{"信息类", "	DL062344", 2023303097, 56, 15, 41},
	{"信息类", "	DL062345", 2023303099, 97, 27, 70},
	{"信息类", "	DL062345", 2023303108, 84, 27, 57},
	{"信息类", "	DL062345", 2023303109, 73, 21, 52},
	{"信息类", "	DL062345", 2023303111, 86, 24, 62},
	{"信息类", "	DL062345", 2023303112, 99, 30, 69},
	{"信息类", "	DL062346", 2023303127, 87, 24, 63},
	{"信息类", "	DL062346", 2023303135, 81, 30, 51},
	{"信息类", "	DL062346", 2023303136, 97, 27, 70},
	{"信息类", "	DL062346", 2023303137, 70, 24, 46},
	{"信息类", "	DL062346", 2023303141, 94, 24, 70},
	{"信息类", "	DL062347", 2023303157, 96, 30, 66},
	{"信息类", "	DL062347", 2023303158, 65, 18, 47},
	{"信息类", "	DL062347", 2023303172, 90, 24, 66},
	{"信息类", "	DL062347", 2023303173, 82, 27, 55},
	{"信息类", "	DL062347", 2023303176, 84, 27, 57},
	{"信息类", "	DL062348", 2023303181, 100, 30, 70},
	{"信息类", "	DL062348", 2023303190, 97, 27, 70},
	{"信息类", "	DL062348", 2023303198, 92, 27, 65},
	{"信息类", "	DL062349", 2023303206, 98, 30, 68},
	{"信息类", "	DL062349", 2023303210, 96, 30, 66},
	{"信息类", "	DL062349", 2023303228, 96, 30, 66},
	{"信息类", "	DL062349", 2023303229, 68, 24, 44},
	{"哲学社会科学类", "	DL092307", 2023303819, 93, 27, 66},
	{"力学类", "	DL102301", 2023303875, 75, 27, 48},
	{"力学类", "	DL102301", 2023303876, 96, 30, 66},
	{"力学类", "	DL102302", 2023303885, 91, 27, 64},
	{"力学类", "	DL102302", 2023303887, 91, 27, 64},
	{"力学类", "	DL102302", 2023303889, 100, 30, 70},
	{"力学类", "	DL102302", 2023303892, 100, 30, 70},
	{"力学类", "	DL102302", 2023303904, 100, 30, 70},
	{"力学类", "	DL102303", 2023303909, 86, 24, 62},
	{"力学类", "	DL102303", 2023303915, 93, 27, 66},
	{"力学类", "	DL102304", 2023303928, 88, 30, 58},
	{"力学类", "	DL102304", 2023303933, 86, 21, 65},
	{"力学类", "	DL102305", 2023303959, 90, 24, 66},
	{"力学类", "	DL102305", 2023303966, 90, 24, 66},
};
// 本程序使用选择排序算法。依据优先级顺序，将第一位同学的得分与之后同学的得分依次进行比较。
// 如果后者得分更高则两者交换排位，再将新的第一位同学的得分继续与之后的同学比较，直至末尾。
// 这样得分最高的同学一定排在第一位，以此类推从第二位开始就可以将数据按从大到小的顺序进行排列了。
#include <stdio.h>
// 定义三种排序优先级不同的函数
void sort_tlscore(int);
void sort_objscore(int);
void sort_sbjscore(int);
void print(int);
// 能够选择排序的规则与数据的大小
int main()
{
	int chose = 0, limit = 0;
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
	printf("%-25s%-15sstudent ID  tlscore objscore sbjscore\n", "Major", "Class");
	for (i = 0; i < limit; i++)
	{
		printf("%-15s	", data[i].major);
		printf("%10s	", data[i].Class);
		printf("%10d	", data[i].stdID);
		printf("%-8d", data[i].tlscore);
		printf("%-8d", data[i].objscore);
		printf("%-8d\n", data[i].sbjscore);
	}
}
// 总得分高者优先排序，规则：总得分>主观题得分>客观题得分
void sort_tlscore(int limit)
{
	int i = 0, j = 0;
	struct type agency[1];
	for (i = 0; i < limit - 1; i++)
	{
		for (j = i + 1; j < limit; j++)
		{
			// 依据规则交换位置
			if (data[i].tlscore < data[j].tlscore || (data[i].tlscore == data[j].tlscore && data[i].sbjscore < data[j].sbjscore))
			{
				agency[0] = data[i];
				data[i] = data[j];
				data[j] = agency[0];
			}
			else if (data[i].tlscore == data[j].tlscore && data[i].sbjscore == data[j].sbjscore && data[i].objscore < data[j].objscore)
			{
				agency[0] = data[i];
				data[i] = data[j];
				data[j] = agency[0];
			}
		}
	}
	print(limit);
}
// 客观题得分高者优先排序，规则：客观题得分>总得分>主观题得分
void sort_objscore(int limit)
{
	int i = 0, j = 0;
	struct type agency[1];
	for (i = 0; i < limit - 1; i++)
	{
		for (j = i + 1; j < limit; j++)
		{
			// 依据规则交换位置
			if (data[i].objscore < data[j].objscore || (data[i].objscore == data[j].objscore && data[i].tlscore < data[j].tlscore))
			{
				agency[0] = data[i];
				data[i] = data[j];
				data[j] = agency[0];
			}
			else if (data[i].objscore == data[j].objscore && data[i].tlscore == data[j].tlscore && data[i].sbjscore < data[j].sbjscore)
			{
				agency[0] = data[i];
				data[i] = data[j];
				data[j] = agency[0];
			}
		}
	}
	print(limit);
}
// 主观题得分高者优先排序，规则：主观题得分>总得分>客观题得分
void sort_sbjscore(int limit)
{
	int i = 0, j = 0;
	struct type agency[1];
	for (i = 0; i < limit - 1; i++)
	{
		for (j = i + 1; j < limit; j++)
		{
			// 依据规则交换位置
			if (data[i].sbjscore < data[j].sbjscore || (data[i].sbjscore == data[j].sbjscore && data[i].tlscore < data[j].tlscore))
			{
				agency[0] = data[i];
				data[i] = data[j];
				data[j] = agency[0];
			}
			else if (data[i].sbjscore == data[j].sbjscore && data[i].tlscore == data[j].tlscore && data[i].objscore < data[j].objscore)
			{
				agency[0] = data[i];
				data[i] = data[j];
				data[j] = agency[0];
			}
		}
	}
	print(limit);
}
