#include<stdio.h>
#include<math.h>
# define PI 3.14159265358979323846
double hav(double);
int main()
{
	double q1,p1,q2,p2,sum;
	scanf("%lf %lf\n%lf %lf",&q1,&p1,&q2,&p2);
	sum=hav(q2*PI/180-q1*PI/180)+cos(q1*PI/180)*cos(q2*PI/180)*hav(p2*PI/180-p1*PI/180);
	printf("%.4lfkm",6371*acos(1-2*sum));
	return 0;
}
double hav(double a)
{
	return (1-cos(a))/2;
} 