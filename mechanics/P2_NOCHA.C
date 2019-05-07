#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(){
	char s[30],i,j=0,word=0,cha=0;
	printf("Enter a string: ");
	gets(s);
	printf("Characters including white spaces: %d\n",strlen(s));
	for(i=0;i<strlen(s);i++){
		if(s[i]!=' '){
			cha++;
			j++;
		}
		else{
			if(j!=0){
				word++;
				j=0;
			}}}
	printf("Characters without white spaces: %d\n",cha);
	if(j!=0)
		word++;
	printf("word= %d",word);
	getch();
}
