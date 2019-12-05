#include <stdio.h>

void copy_string(char from[], char to[])
{
	int i = 0;
	while(from[i]!='\0')
	{
		to[i]=from[i];
		i++;
	}
	to[i]='\0';
	return;
}
void copy_string1(char* from, char* to)
{
	for(;*from != '\0';from++,to++)
	{
		*to=*from;
	}
	*to='\0';
	return;
}

int main()
{
	char a[]="jason";
	char b[]="welcome to newcapec";
	printf("copy before:\n");
	printf("a=%s\n",a);
	printf("b=%s\n",b);
	printf("\n");
	copy_string1(a,b);
	printf("copy after:\n");
	printf("a=%s\n",a);
	printf("b=%s\n",b);
	getchar();
}