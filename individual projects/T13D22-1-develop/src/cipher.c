#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256
#define MAX_TXT_LENGTH 20000

void readAndPrintFile(const char* filePath);
void appendToFile(const char* filePath, const char* text);
void caesar_encrypt(char* message, int shift);
void encrypt_file(const char* file_path, int shift);
void encrypt_files_in_directory(const char* directory_path, int shift);

int main() {
    int choice = 0;
    char filePath[MAX_PATH_LENGTH];
    char text[MAX_TXT_LENGTH];
    bool fileExists = false;

    while (choice != -1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%s", filePath);
                FILE* existingFile = fopen(filePath, "r");
                if (existingFile == NULL) {
                    printf("n/a\n");
                    break;
                }
                fclose(existingFile);
                fileExists = true;
                readAndPrintFile(filePath);
                printf("\n");
                break;
            case 2:
                scanf(" %[^\n]s", text);
                if (!fileExists) {
                    printf("n/a\n");
                    break;
                }
                appendToFile(filePath, text);
                readAndPrintFile(filePath);
                break;
            case 3: {
                char directory_path[100];
                int shift;
                fgets(directory_path, sizeof(directory_path), stdin);
                scanf("%d", &shift);
                directory_path[strcspn(directory_path, "\n")] = '\0';
                encrypt_files_in_directory(directory_path, shift);
                break;
            }
            case -1:
                break;
            default:
                printf("n/a\n");
                break;
        }
    }

    return 0;
}

void readAndPrintFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("n/a");
        return;
    }

    char buffer[MAX_PATH_LENGTH];
    bool isEmpty = true;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        isEmpty = false;
    }

    if (isEmpty) {
        printf("n/a");
    }

    fclose(file);
}

void appendToFile(const char* filePath, const char* text) {
    FILE* file = fopen(filePath, "a");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    fprintf(file, "%s\n", text);

    fclose(file);
}

void caesar_encrypt(char* message, int shift) {
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + shift) % 26;
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + shift) % 26;
        }
        i++;
    }
}

void encrypt_file(const char* file_path, int shift) {
    FILE* file = fopen(file_path, "r+");
    if (file == NULL) {
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        caesar_encrypt(buffer, shift);

        fseek(file, -strlen(buffer) - 1, SEEK_CUR);
        fprintf(file, "%s\n", buffer);
        fflush(file);
    }

    fclose(file);
}

void encrypt_files_in_directory(const char* directory_path, int shift) {
    char command[100];
    snprintf(command, sizeof(command), "ls %s", directory_path);

    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("n/a");
        return;
    }

    char file_name[100];
    while (fgets(file_name, sizeof(file_name), pipe)) {
        file_name[strcspn(file_name, "\n")] = '\0';

        char file_path[200];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, file_name);

        char* format = strchr(file_path, '.');
        if (format != NULL) {
            if (strcmp(format, ".h") == 0) {
                FILE* file = fopen(file_path, "w");
                if (file != NULL) {
                    fclose(file);
                }
            } else if (strcmp(format, ".c") == 0) {
                encrypt_file(file_path, shift);
            }
        }
    }
    pclose(pipe);
}