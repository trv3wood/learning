// ������ʹ�ÿ��������㷨��
// ѡȡÿ���������Ҳ��������Ϊ��׼��������ǰ������ָ�뽻�������ƶ���ѡ�����ݡ�
// ���ݹ����ж�ָ����ָ������λ�ڻ�׼����һ�࣬�����Ҫ�ƶ����ݣ��������ƶ�����ࡣ
// Ϊ���������㷨����Ľ������һ�£��ó����еĹ����������й�ѧ�ŵ��ж���ѧ�ž���Ψһ�ԣ���ʹ������������ȶ���
// ֱ��ǰ���ָ�����������󣬽���׼���ݷ�������ָ����ָλ�õ�ǰ�棬��һ�β���������
// �ں���������������ͬһ���������ж����γɵ����������Ƿ�ֻ����һ��Ԫ�أ�������ǣ��ظ�����������
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
// ���������������ȼ���ͬ�ĺ���
void sort_score(int,int,int);
int score_partition (int,int,int);
void sort_tlscore(int*,int,int);
void sort_objscore(int*,int,int);
void sort_sbjscore(int*,int,int);
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
	// ѯ�������ֵ÷���������������
	printf("Which type of data do you want to sort based on?\n"
		   "Please use the serial number to select from the three types below:\n"
		   " 1.tlscore; 2.objscore; 3.sbjscore.\n ");
	scanf("%d", &chose);
	
	sort_score(0,limit-1,chose);
	print(limit);
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
//�ú����ǿ��������㷨�����岿�֣���ʹ���˷��εĲ��ԡ������Ǹú�������ϸ���裺
//1.����������������lowlimit��uplimit�����Ƿֱ���Ҫ���л��ֵ����鲿�ֵ���ʼ�ͽ���������
//2. �ں����ڲ����������ȼ��lowlimit�Ƿ�С��uplimit��������ǣ���ô������鲿���Ѿ�������ģ����Ǿ�ֱ�ӷ��ء�
//3. ���lowlimitС��uplimit�����Ǿ͵���partition��������������л��֣�����ȡ��׼Ԫ�ص�λ��pivot��
//4. Ȼ�����ǶԻ�׼Ԫ����ߵ���������п������򣬼�����sort_score(lowlimit, pivot - 1)��
//5. ���ţ����ǶԻ�׼Ԫ���ұߵ���������п������򣬼�����sort_score(pivot + 1, uplimit);��
//6. ��������������ͱ������ˡ�
void sort_score(int lowlimit,int uplimit,int chose)
{ 	
	if (lowlimit<uplimit) {
        int pivot = score_partition(lowlimit,uplimit,chose);
        sort_score(lowlimit, pivot - 1,chose);
        sort_score(pivot + 1, uplimit,chose);
    }
}
//����������������lowlimit��uplimit�����Ƿֱ���Ҫ���л��ֵ����鲿�ֵ���ʼ�ͽ���������
//�ں����ڲ�����������ѡ��һ����׼Ԫ�أ���������ѡ��������鲿�ֵ����һ��Ԫ��data[uplimit]��
//Ȼ�����Ǵ���һ������i���������ʼ��Ϊlowlimit - 1�������������׷�����һ��С�ڻ�׼��Ԫ�ص�λ�á�
//���ţ����ǿ�ʼһ��ѭ������lowlimit��uplimit - 1����ÿ�ε����У������ǰԪ��С�ڻ�׼Ԫ�أ����Ǿͽ�i��1��Ȼ�󽻻�data[i]��data[j];
//ѭ�����������ǽ���׼Ԫ�طŵ���ȷ��λ�ã���data[i + 1]��data[uplimit]��λ�ý�������������׼Ԫ����ߵ�����Ԫ�ض�С�������ұߵ�����Ԫ�ض���������
//��󣬺������ػ�׼Ԫ�ص�λ��i + 1��
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
// �ܵ÷ָ����������򣬹����ܵ÷�>������÷�>�͹���÷֡�
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
// �͹���÷ָ����������򣬹��򣺿͹���÷�>�ܵ÷�>������÷֡� 
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
// ������÷ָ����������򣬹���������÷�>�ܵ÷�>�͹���÷֡�
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

