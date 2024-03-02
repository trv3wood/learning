#include<stdio.h>
int main(){
	double x=0,y=0;
	int n=0,i=0;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		if(i+1<10)x=i+0.1*(i+1);
		else x=i+0.01*(i+1);

		if(i+1<10||(i+1)%10==0)printf("%.1f",x);
		else printf("%.2f",x);

		if(i<=n-1) printf("+");
		else printf("=");

		y=y+x;

	}

	printf("%.2f",y);
	return 0;
}