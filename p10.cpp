#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
char playfairMatrix[SIZE][SIZE] = 
{
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};
void findPosition(char letter, int *row, int *col) 
{
    int i, j;
    if (letter == 'J') letter = 'I'; 
    for (i = 0; i < SIZE; i++) 
	{
        for (j = 0; j < SIZE; j++) 
		{
            if (playfairMatrix[i][j] == letter) 
			{
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void preprocessMessage(char message[], char processed[]) 
{
    int i, j = 0;
    for (i = 0; message[i] != '\0'; i++) 
	{
        if (isalpha(message[i])) 
		{
            processed[j++] = toupper(message[i]);
        }
    }
    processed[j] = '\0';
    char result[200];
    int k = 0;
    for (i = 0; i < j; i += 2) 
	{
        result[k++] = processed[i];
        if (i + 1 < j && processed[i] == processed[i + 1]) 
		{
            result[k++] = 'X';
            i--; 
        } 
		else if (i + 1 < j) 
		{
            result[k++] = processed[i + 1];
        } 
		else 
		{
            result[k++] = 'X'; 
        }
    }
    result[k] = '\0';
    strcpy(processed, result);
}
void encryptPlayfair(char message[], char encrypted[]) 
{
    int i, row1, col1, row2, col2;
    for (i = 0; message[i] != '\0'; i += 2) 
	{
        findPosition(message[i], &row1, &col1);
        findPosition(message[i + 1], &row2, &col2);

        if (row1 == row2) 
		{
            encrypted[i] = playfairMatrix[row1][(col1 + 1) % SIZE];
            encrypted[i + 1] = playfairMatrix[row2][(col2 + 1) % SIZE];
        } 
		else if (col1 == col2) 
		{
            encrypted[i] = playfairMatrix[(row1 + 1) % SIZE][col1];
            encrypted[i + 1] = playfairMatrix[(row2 + 1) % SIZE][col2];
        } 
		else 
		{
           
            encrypted[i] = playfairMatrix[row1][col2];
            encrypted[i + 1] = playfairMatrix[row2][col1];
        }
    }
    encrypted[i] = '\0';
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char processedMessage[200], encryptedMessage[200];

    preprocessMessage(message, processedMessage);
    encryptPlayfair(processedMessage, encryptedMessage);

    printf("Original message: %s\n", message);
    printf("Processed message: %s\n", processedMessage);
    printf("Encrypted message: %s\n", encryptedMessage);

    return 0;
}