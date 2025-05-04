#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int number;
} Task;

int main(int argc, char *argv[]) {


    if (argc == 1) {
        printf("Usage: <command>\n");
        exit(EXIT_FAILURE);
    }


    FILE *file = fopen("tasks.txt", "a+");
    
    if (!file) {
        perror("Can't open the file");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "list") == 0) {
        listTasks(file);
    } else if(strcmp(argv[1], "add") == 0) {

        if (argc == 2) {
            printf("Usage: add <taskName>\n");
        } else {
            addTask(file, argv[2]);
        }

    } else if (strcmp(argv[1], "done") == 0) {
        if (argc == 2) {
            printf("Usage: done <taskNumber>\n");
        } else {
            doneTask(file, argv[2]);
        } 
    } else if (strcmp(argv[1], "delete") == 0) {

        if (argc == 2) {
            printf("Usage: delete <taskNumber>"); 
        } else {
            deleteTask(file, argv[2]);
        }
        
    }


    if (!file) {
        printf("tasks.txt closed successfully\n");
    } else {
        printf("Can't close tasks.txt file\n");
    }



    return 0;
}