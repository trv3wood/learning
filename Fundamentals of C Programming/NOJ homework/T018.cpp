#include<stdio.h>
int main(){
	int a=0,b=0,c=0,d=0,n=0,i=0;
	scanf("%d",&n);

	for(a=0;a<=9;a++){
		for(b=0;b<=9;b++){
			for(c=0;c<=9;c++){
				for(d=0;d<=9;d++){
				if(a+b+c+d==n) i++;
				}
			}
		}
	}
	printf("%d",i);
	return 0;
}