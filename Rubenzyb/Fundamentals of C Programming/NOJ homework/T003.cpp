#include<stdio.h>
int main(){
	int d=0;
	scanf("%d",&d);
	switch(d){
	case 1: printf("%d,-128,127",sizeof(char));break;
	case 2: printf("%d,0,255",sizeof(unsigned char));break;
	case 3: printf("%d,-32768,32767",sizeof(short));break;
	case 4: printf("%d,0,65535",sizeof(unsigned short));break;
	case 5: printf("%d,-2147483648,2147483647",sizeof(int));break;
	case 6: printf("%d,0,4294967295",sizeof(unsigned int));break;
	case 7: printf("%d,-2147483648,2147483647",sizeof(long));break;
	case 8: printf("%d,0,4294967295",sizeof(unsigned long));break;
	case 9: printf("%d,-9223372036854775808,9223372036854775807",sizeof(long long));break;
	case 10: printf("%d,0,18446744073709551615",sizeof(unsigned long long));break;
	}
 	return 0;
}