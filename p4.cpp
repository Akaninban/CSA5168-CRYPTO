#include<stdio.h>
#include<string.h>
#include<ctype.h>

void vigenereEncrypt(char plaintext[],char key[],char ciphertext[]){
    int keyLength=strlen(key);
    int textLength=strlen(plaintext);
    int i,j=0;

    for(i=0;i<textLength;i++){
        char ptChar=plaintext[i];
        char keyChar=key[j%keyLength];
        
        if(isalpha(ptChar)){
            char base=isupper(ptChar)?'A':'a';
            char encryptedChar=((toupper(ptChar)-'A')+(toupper(keyChar)-'A'))%26+'A';
            ciphertext[i]=isupper(ptChar)?encryptedChar:tolower(encryptedChar);
            j++;
        }else{
            ciphertext[i]=ptChar;
        }
    }
    ciphertext[textLength]='\0';
}

int main(){
    char plaintext[100],key[100],ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext,sizeof(plaintext),stdin);
    plaintext[strcspn(plaintext,"\n")]='\0';

    printf("Enter the key: ");
    fgets(key,sizeof(key),stdin);
    key[strcspn(key,"\n")]='\0';

    vigenereEncrypt(plaintext,key,ciphertext);

    printf("Encrypted message: %s\n",ciphertext);

    return 0;
}
