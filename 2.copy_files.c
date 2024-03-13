#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter source filename: ");
    scanf("%s", filename);

    if ((fptr1 = fopen(filename, "r")) == NULL) {
        printf("Cannot open source file %s\n", filename);
        exit(1);
    }

    printf("Enter destination filename: ");
    scanf("%s", filename);

    if ((fptr2 = fopen(filename, "w")) == NULL) {
        printf("Cannot open destination file %s\n", filename);
        exit(1);
    }

    while ((c = fgetc(fptr1)) != EOF)
        fputc(c, fptr2);

    printf("Contents from %s copied to %s\n", filename, filename);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

