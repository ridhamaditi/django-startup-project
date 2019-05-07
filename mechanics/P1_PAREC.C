#include<stdio.h>
#include<conio.h>
#include<string.h>
char st[30],top=-1;
void push(char ch){
	st[++top] = ch;}
char pop(){
	top--;
	return st[top+1];}
void main(){
	char s[30],ch;
	int i=0,k = 1;
	clrscr();
	printf("Enter String: ");
	gets(s);
	for(i = 0;i<strlen(s);i++){
		if(s[i] == '{')
			push('{');
		else if(s[i] == '[')
			push('[');
		else if(s[i] == '(')
			push('(');
		if(s[i] == '}'){
			ch = pop();
			if(ch != '{')
				k = 0;}
		else if(s[i] == ']'){
			ch = pop();
			if(ch != '[')
				k = 0;}
		else if(s[i] == ')'){
			ch = pop();
			if(ch != '(')
				k = 0;
}
}
	if(top != -1)
		k = 0;
	if(k == 0){
		printf("not balanced.");
}
	else{
		printf("Balanced.");
}
	getch();
}
