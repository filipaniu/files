#include <stdio.h>
#include <stdlib.h>

void writeToFile() {
    FILE *fptr = fopen("text.txt", "w");
    fprintf(fptr, "%s\n", "Hello world");
    fputs("plik otwarty pomyslnie\0", fptr);
    fclose(fptr);
}

char *readFromFile(char *filename) {
    FILE *fptr = fopen(filename, "a+");
    fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr) + 1;
    char *result = malloc(size * sizeof(char));
    fseek(fptr, 0, SEEK_SET);
    fread(result, sizeof(char), size, fptr);
    result[size - 1] = '\0';
    fclose(fptr);
    return result;
}

int main() {
//    writeToFile();
    char *string = readFromFile("text.txt");
    puts(string);
}
