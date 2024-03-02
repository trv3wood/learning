#include <stdio.h>
int main()
{
	char s[10]={'\0'};
	int i,ret=0,yes=1;
	scanf("%s",&s);
	for(i=0; i<10; i++) {
		if(s[i]==51||s[i]==52) {
			yes=0;
			goto end;
		}
		if(s[i]=='\0') break;
	}
	ret=i-1;
	if(ret%2!=0) {
		for(i=0; i<=ret/2; i++) {
			if(s[ret-i]==s[i]) {
				if(s[ret-i]==48||s[ret-i]==49||s[ret-i]==56||s[ret-i]==50||s[ret-i]==53) continue;
				else {
					yes=0;
					break;
				}
			} else if((s[ret-i]==54&&s[i]==57)||(s[ret-i]==57&&s[i]==54)) continue;
			else {
				yes=0;
				break;
			}
		}
	} else {
		if(s[ret/2]==48||s[ret/2]==49||s[ret/2]==56||s[ret/2]==50||s[ret/2]==53) {
			for(i=0; i<=ret/2-1; i++) {
				if(s[ret-i]==s[i]) {
					if(s[ret-i]==48||s[ret-i]==49||s[ret-i]==56||s[ret-i]==50||s[ret-i]==53) continue;
					else {
						yes=0;
						break;
					}
				} else if((s[ret-i]==54&&s[i]==57)||(s[ret-i]==57&&s[i]==54)) continue;

				else {
					yes=0;
					break;
				}
			}
		} else yes=0;

	}
end :
	if(yes==1)printf("Yes");
	else printf("No");
	return 0;
}