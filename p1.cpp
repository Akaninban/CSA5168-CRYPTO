#include<stdio.h>
#include<ctype.h>
void encrypt(char text[],int k)
{
	char ch;
	int i=0;
	while(text[i]!='\0')
	{
		ch=text[i];
		if(isupper(ch))
		{
			ch=(ch-'A'+k)%26+'A';
		}
		else if(islower(ch))
		{
			ch=(ch-'a'+k)%26+'a';
		}
		text[i]=ch;
		i++;		
	}
}
int main()
{
	char text[100];
	int k;
	printf("enter the message to encrypt: ");
	fgets(text,sizeof(text),stdin);
	printf("enter shift value(1-25): ");
	scanf("%d",&k);
	encrypt(text,k);
	printf("encrypted message: %s\n",text);
	return 0;
}