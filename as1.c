#include<stdio.h>
#include<string.h>

#define MAX_BLOCKS 100

char disk[MAX_BLOCKS][20];

void create_file(char filename[], int start_block, int length) {
    int i;
    for (i = start_block; i < start_block + length; i++) {
        strcpy(disk[i], filename);
    }
}

void delete_file(char filename[]) {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(disk[i], filename) == 0) {
            strcpy(disk[i], "Free");
        }
    }
}

void display_disk_contents() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: %s\n", i, disk[i]);
    }
}

int main() {
    int num_blocks, option, start_block, length;
    char filename[20];
    
    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &num_blocks);
    
    int i;
    for (i = 0; i < num_blocks; i++) {
        strcpy(disk[i], "Free");
    }
    
    do {
        printf("\nMenu:\n1. Create a file\n2. Delete a file\n3. Display the contents of the disk\n4. Exit the program\nEnter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                printf("Enter the starting block: ");
                scanf("%d", &start_block);
                printf("Enter the length: ");
                scanf("%d", &length);
                create_file(filename, start_block, length);
                break;
                
            case 2:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                delete_file(filename);
                break;
                
            case 3:
                printf("\nDisk contents:\n");
                display_disk_contents();
                break;
                
            case 4:
                printf("\nExiting program...\n");
                break;
                
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}
