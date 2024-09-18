#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define TOP_N 10
const float english_frequencies[ALPHABET_SIZE] = 
{
    0.127, 0.090, 0.081, 0.075, 0.069, 0.067, 0.063, 0.061, 
    0.059, 0.055, 0.043, 0.040, 0.038, 0.036, 0.034, 0.032, 
    0.030, 0.028, 0.025, 0.022, 0.020, 0.018, 0.016, 0.014, 
    0.012, 0.010
};

void calculate_frequencies(char *ciphertext, int *letter_count, int *total_letters) 
{
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) 
	{
        char c = toupper(ciphertext[i]);
        if (isalpha(c)) 
		{
            letter_count[c - 'A']++;
            (*total_letters)++;
        }
    }
}
void decrypt(char *ciphertext, int shift, char *plaintext) 
{
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) 
	{
        char c = toupper(ciphertext[i]);
        if (isalpha(c)) 
		{
            plaintext[i] = ((c - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + 'A';
        } else {
            plaintext[i] = c;
        }
    }
    plaintext[i] = '\0';
}
float score_plaintext(int *letter_count, int total_letters) 
{
    float score = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) 
	{
        float observed_freq = (float)letter_count[i] / total_letters;
        score += observed_freq * english_frequencies[i];
    }
    return score;
}
void sort_top_results(float scores[], int shifts[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (scores[j] < scores[j + 1]) 
			{
                float temp_score = scores[j];
                int temp_shift = shifts[j];
                scores[j] = scores[j + 1];
                shifts[j] = shifts[j + 1];
                scores[j + 1] = temp_score;
                shifts[j + 1] = temp_shift;
            }
        }
    }
}

int main() 
{
    char ciphertext[1000], plaintext[1000];
    int letter_count[ALPHABET_SIZE], total_letters = 0;
    int top_shifts[ALPHABET_SIZE];
    float top_scores[ALPHABET_SIZE];
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; 
    memset(letter_count, 0, sizeof(letter_count));
    calculate_frequencies(ciphertext, letter_count, &total_letters);
    for (int shift = 0; shift < ALPHABET_SIZE; shift++) 
	{
        int shifted_letter_count[ALPHABET_SIZE] = {0};
      
        decrypt(ciphertext, shift, plaintext);
        for (int i = 0; i < strlen(plaintext); i++) 
		{
            if (isalpha(plaintext[i])) 
			{
                shifted_letter_count[toupper(plaintext[i]) - 'A']++;
            }
        }
        float score = score_plaintext(shifted_letter_count, total_letters);

        top_scores[shift] = score;
        top_shifts[shift] = shift;
    }
    sort_top_results(top_scores, top_shifts, ALPHABET_SIZE);

    printf("\nTop %d possible plaintexts:\n", TOP_N);
    for (int i = 0; i < TOP_N; i++) 
	{
        decrypt(ciphertext, top_shifts[i], plaintext);
        printf("Shift: %d, Score: %.4f\n", top_shifts[i], top_scores[i]);
        printf("Plaintext: %s\n", plaintext);
        printf("\n");
    }

    return 0;
}