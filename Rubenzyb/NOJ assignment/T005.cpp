#include<stdio.h>
int main(){
	int a=0,b=0,x=0,y=0,i=0,k=1,n=1,m=0;
	scanf("%d",&a);
	x=a;

	m=a;
	while(m>=8){m=m/8;n++;}
	int e[n];

	for(i=0;a>=8;i++){
	b=a%8;
	a=a/8;
	switch(b)
	   {case 0:e[i]=0;break;
		case 1:e[i]=1;break;
	    case 2:e[i]=2;break;
	    case 3:e[i]=3;break;
	    case 4:e[i]=4;break;
	    case 5:e[i]=5;break;
	    case 6:e[i]=6;break;
	    case 7:e[i]=7;break;}
	}
	switch(a)
	   {case 0:e[i]=0;break;
	    case 1:e[i]=1;break;
	    case 2:e[i]=2;break;
	    case 3:e[i]=3;break;
	    case 4:e[i]=4;break;
	    case 5:e[i]=5;break;
	    case 6:e[i]=6;break;
	    case 7:e[i]=7;break;}

	m=x;
	while(m>=16){m=m/16;k++;}
	char d[k];

	for(i=0;x>=16;i++){
	y=x%16;
	x=x/16;
	switch(y)
	   {case 0:d[i]='0';break;
		case 1:d[i]='1';break;
	    case 2:d[i]='2';break;
	    case 3:d[i]='3';break;
	    case 4:d[i]='4';break;
	    case 5:d[i]='5';break;
	    case 6:d[i]='6';break;
	    case 7:d[i]='7';break;
	    case 8:d[i]='8';break;
	    case 9:d[i]='9';break;
	    case 10:d[i]='A';break;
		case 11:d[i]='B';break;
		case 12:d[i]='C';break;
		case 13:d[i]='D';break;
		case 14:d[i]='E';break;
		case 15:d[i]='F';break;}
	}
	switch(x)
	   {case 0:d[i]='0';break;
	    case 1:d[i]='1';break;
	    case 2:d[i]='2';break;
	    case 3:d[i]='3';break;
	    case 4:d[i]='4';break;
	    case 5:d[i]='5';break;
	    case 6:d[i]='6';break;
	    case 7:d[i]='7';break;
	    case 8:d[i]='8';break;
	    case 9:d[i]='9';break;
	    case 10:d[i]='A';break;
		case 11:d[i]='B';break;
		case 12:d[i]='C';break;
		case 13:d[i]='D';break;
		case 14:d[i]='E';break;
		case 15:d[i]='F';break;}

    for(i=k-1;i>=0;i--){putchar(d[i]);}
    printf(",");
    for(i=n-1;i>=0;i--){printf("%d",e[i]);}
	return 0;
}