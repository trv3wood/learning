//������ʹ��ð�������㷨���������ȼ�˳�򣬽�ǰһλͬѧ�ĵ÷����һλͬѧ�ĵ÷ֽ��бȽϡ�
//������ߵ÷ָ��������߽�����λ���ٽ���һλͬѧ�ĵ÷ּ������ٺ�һλͬѧ�ĵ÷ֱȽϣ�ֱ��ĩβ��
//�ظ������Ĳ������ɴΣ�ֱ��ĳ�α�������ʱû�����ݵ�λ�÷�������������ʾ�����Ѱ��Ӵ�С��˳�����к��ˡ�
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
void sort_tlscore(int);
void sort_objscore(int);
void sort_sbjscore(int);
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
		sort_tlscore(limit);
		break;
	case 2:
		sort_objscore(limit);
		break;
	case 3:
		sort_sbjscore(limit);
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
// �ܵ÷ָ����������򣬹����ܵ÷�>������÷�>�͹���÷�
void sort_tlscore(int limit)
{
//��������һ����ʾ���鳤�ȵĲ�����
//������ʼһ���ⲿѭ����������ĵ�һ��Ԫ�ؿ�ʼ������Ϊ0����ֱ�������ڶ���Ԫ�أ�����Ϊlimit-2�������ѭ�����ڿ�����Ҫ����Ĳ��֡�
//����ÿ����ǰԪ�أ����ǿ�ʼһ���ڲ�ѭ�����ӵ�ǰԪ�ؿ�ʼ��ֱ��δ���򲿷ֵ����һ��Ԫ�ء����ѭ�����ڱȽϺͽ���Ԫ�ء�
//���ڲ�ѭ���У������ǰԪ�أ�data[j]��С����һ��Ԫ�أ�data[j+1]�������Ǿͽ������ǡ�������ͨ������һ����ʱ����agency����ɵġ�
//�����ظ�������̣�ֱ���������鶼������   
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
// �͹���÷ָ����������򣬹��򣺿͹���÷�>�ܵ÷�>������÷�
void sort_objscore(int limit)
{
//��������һ����ʾ���鳤�ȵĲ�����
//������ʼһ���ⲿѭ����������ĵ�һ��Ԫ�ؿ�ʼ������Ϊ0����ֱ�������ڶ���Ԫ�أ�����Ϊlimit-2�������ѭ�����ڿ�����Ҫ����Ĳ��֡�
//����ÿ����ǰԪ�أ����ǿ�ʼһ���ڲ�ѭ�����ӵ�ǰԪ�ؿ�ʼ��ֱ��δ���򲿷ֵ����һ��Ԫ�ء����ѭ�����ڱȽϺͽ���Ԫ�ء�
//���ڲ�ѭ���У������ǰԪ�أ�data[j]��С����һ��Ԫ�أ�data[j+1]�������Ǿͽ������ǡ�������ͨ������һ����ʱ����agency����ɵġ�
//�����ظ�������̣�ֱ���������鶼������   
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
// ������÷ָ����������򣬹���������÷�>�ܵ÷�>�͹���÷�
void sort_sbjscore(int limit)
{
//��������һ����ʾ���鳤�ȵĲ�����
//������ʼһ���ⲿѭ����������ĵ�һ��Ԫ�ؿ�ʼ������Ϊ0����ֱ�������ڶ���Ԫ�أ�����Ϊlimit-2�������ѭ�����ڿ�����Ҫ����Ĳ��֡�
//����ÿ����ǰԪ�أ����ǿ�ʼһ���ڲ�ѭ�����ӵ�ǰԪ�ؿ�ʼ��ֱ��δ���򲿷ֵ����һ��Ԫ�ء����ѭ�����ڱȽϺͽ���Ԫ�ء�
//���ڲ�ѭ���У������ǰԪ�أ�data[j]��С����һ��Ԫ�أ�data[j+1]�������Ǿͽ������ǡ�������ͨ������һ����ʱ����agency����ɵġ�
//�����ظ�������̣�ֱ���������鶼������   
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
