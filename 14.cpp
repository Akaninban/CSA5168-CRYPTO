*#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MOD 26
void encrypt(char plaintext[], int keyStream[], char ciphertext[]) {
    int length = strlen(plaintext);
    
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
    
            int letter = tolower(plaintext[i]) - 'a';
            int key = keyStream[i];
    
            int encryptedLetter = (letter + key) % MOD;
        
            ciphertext[i] = encryptedLetter + 'a';
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[length] = '\0'; 
}
void decrypt(char ciphertext[], int keyStream[], char plaintext[]) {
    int length = strlen(ciphertext);
    
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
 
            int letter = tolower(ciphertext[i]) - 'a';
            int key = keyStream[i];
            int decryptedLetter = (letter - key + MOD) % MOD;
         
            plaintext[i] = decryptedLetter + 'a';
        } else {
            plaintext[i] = ciphertext[i]; 
        }
    }
    plaintext[length] = '\0';  
}

int main() {
    char plaintext[] = "send more money";
    int keyStream[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[100], decryptedText[100];
    
    encrypt(plaintext, keyStream, ciphertext);
    
    printf("Original plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    
    char targetPlaintext[] = "cash not needed";
    int newKeyStream[] = {2, 0, 13, 15, 11, 15, 13, 0, 14, 1, 12, 7, 14}; 
    
    decrypt(ciphertext, newKeyStream, decryptedText);
    
    printf("New key stream: ");
    for (int i = 0; i < strlen(targetPlaintext); i++) {
        printf("%d ", newKeyStream[i]);
    }
    printf("\nDecrypted to: %s\n", decryptedText);
    
    return 0;
}