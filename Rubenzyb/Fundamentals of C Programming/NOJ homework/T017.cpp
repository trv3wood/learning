#include<stdio.h>
int main(){
	int a=0,b=0,c=0,i=0;
	scanf("%d",&a);
	c=a;
	for(i=0;a>0;i++)
	{
		while(a>=1)
		{
			b=b+a%10;
			a=a/10;
		}
		a=c-b;
		c=a;
		b=0;
	}
	printf("%d",i);
	return 0;
}