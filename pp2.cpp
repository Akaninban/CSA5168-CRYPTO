#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(char plaintext[],char key[])
{
	char ciphertext[100];
	int i=0;
	while(plaintext[i]!='\0')
	{
		char ch=plaintext[i];
		if (isupper(ch))
		
		{
			ciphertext[i]=key[ch-'A'];
		}
		else if(islower(ch))
		{
			ciphertext[i]=tolower(key[ch-'a']);
		}
		else
	    {
		    ciphertext[i]=ch;
	    }
	i++;
		
		
	}
	ciphertext[i]='\0';
	printf("encrypted message: %s\n",ciphertext);
}
int main()
{
	char plaintext[100];
	char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
	printf("enter the message to encrypt: ");
	fgets(plaintext,sizeof(plaintext),stdin);
	plaintext[strcspn(plaintext, "\n")] = '\0';
	encrypt(plaintext,key);
	return 0;
}