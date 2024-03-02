#include<stdio.h>
#include<math.h>
int main()
{
	double chill,T,v;
	int chill1;
	scanf("%lf %lf",&v,&T);
	chill=13.12+0.6215*T-11.37*pow(v,0.16)+0.3965*T*pow(v,0.16);
	if( ((int)(10*chill))%10<5 )chill1=(int)chill;
	else chill1=(int)chill+1;
	printf("%d",chill1);
	return 0;
}