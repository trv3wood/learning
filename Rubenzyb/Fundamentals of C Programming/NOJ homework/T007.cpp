#include<stdio.h>
int main(){
	int a=0,m=0,n=0,i=0;
	scanf("%d %d",&m,&n);
	a=m;
	for(i=0;a>0;i++)
	{
		a=a/10;
	}
	if(i<n)
	for(a=0;a<(n-i);a++)
	{
		printf("0");
	}
	printf("%d",m);
	return 0;
}