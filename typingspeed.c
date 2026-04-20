#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char text[] = "C programming is powerful and efficient";
    char input[100];
    
    printf("Typing Speed Test\n");
    printf("------------------\n");
    printf("Type the following sentence:\n\n");
    printf("%s\n\n", text);

    time_t start, end;
    double time_taken;

    start = time(NULL);

    printf("Start typing:\n");
    getchar(); // to clear buffer
    fgets(input, sizeof(input), stdin);

    end = time(NULL);

    time_taken = difftime(end, start);

    // Remove newline from input
    input[strcspn(input, "\n")] = '\0';

    int correct = 0;
    int total = strlen(text);

    for(int i = 0; i < total; i++) {
        if(input[i] == text[i]) {
            correct++;
        }
    }

    double accuracy = ((double)correct / total) * 100;
    double wpm = ((double)strlen(input) / 5) / (time_taken / 60);

    printf("\nTime: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f WPM\n", wpm);

    return 0;
}