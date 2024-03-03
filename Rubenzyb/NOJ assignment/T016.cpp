#include<stdio.h>
int main(){
	int a=0,b=0,c=0,d=0,x=0,y=0,z=0,i=0;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	x=a*d+b*c;
	y=b*d;
	(x>y)?(z=y):(z=x);
	for(i=z;i>=1;i--)
	{
		if(x%i==0&&y%i==0)
		{
			x=x/i;
			y=y/i;
			printf("(%d/%d)+(%d/%d)=%d/%d\n",a,b,c,d,x,y);
			break;
		}
	}
	x=a*d-b*c;
	y=b*d;
	if((x>=y)||(-x>=y))z=y;
	else if(x>0)z=x;
	else z=-x;
	for(i=z;i>=1;i--)
	{
		if(x%i==0&&y%i==0)
		{
			x=x/i;
			y=y/i;
			printf("(%d/%d)-(%d/%d)=%d/%d\n",a,b,c,d,x,y);
			break;
		}
	}
	x=a*c;
	y=b*d;
	(x>y)?(z=y):(z=x);
	for(i=z;i>=1;i--)
	{
		if(x%i==0&&y%i==0)
		{
			x=x/i;
			y=y/i;
			printf("(%d/%d)*(%d/%d)=%d/%d\n",a,b,c,d,x,y);
			break;
		}
	}
	x=a*d;
	y=b*c;
	(x>y)?(z=y):(z=x);
	for(i=z;i>=1;i--)
	{
		if(x%i==0&&y%i==0)
		{
			x=x/i;
			y=y/i;
			printf("(%d/%d)/(%d/%d)=%d/%d\n",a,b,c,d,x,y);
			break;
		}
	}
	return 0;
}