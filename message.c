#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void list_files();
void change_permissions();
void move_file();
void create_file();
void delete_file();
void create_directory();
void delete_directory();
void create_symbolic_link();

int main() {
    char option;
    do {
        // Display the GUI menu
        printf("+---------------------------------------------------+\n");
        printf("|                 File Manager                      |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. List Files/Directories                         |\n");
        printf("| 2. Change Permissions of Files                    |\n");
        printf("| 3. Make Files/Directories                         |\n");
        printf("| 4. Delete Files/Directories                       |\n");
        printf("| 5. Create Symbolic Link                           |\n");
        printf("| Q. Quit                                           |\n");
        printf("+---------------------------------------------------+\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);
        option = toupper(option);

        // Process user's choice
        switch (option) {
            case '1':
                list_files();
                break;
            case '2':
                change_permissions();
                break;
            case '3': {
                int choice;
                printf("Type (1) -> create a Directory, (2) -> create a File:  ");
                scanf("%d", &choice);
                if (choice == 1) {
                    create_directory();
                } else if (choice == 2) {
                    create_file();
                } else {
                    printf("Invalid option.\n");
                }
                break;
            }
            case '4': {
                int choice;
                printf("Type (1) -> delete a Directory, (2) -> delete a File:  ");
                scanf("%d", &choice);
                if (choice == 1) {
                    delete_directory();
                } else if (choice == 2) {
                    delete_file();
                } else {
                    printf("Invalid option.\n");
                }
                break;
            }
            case '5':
            	int link_type;
                printf("Type (1) -> Create a Soft Link, (2) -> Create a Hard Link:  ");
                scanf("%d",&link_type);
                create_symbolic_link(link_type);
                break;
            case 'Q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 'Q');

    return 0;
}

void list_files() {
    char path[100];
    printf("Enter the path of file/directory: ");
    scanf("%s", path);
    
    char command[200];
    sprintf(command, "ls -la %s", path);
    system(command);

}

void change_permissions() {
    char file_path[100];
    printf("Enter the file path: ");
    scanf("%s", file_path);
    
    char permissions[50];
    printf("Enter the permission command: ");
    scanf("%s", permissions);
    
    char command[200];
    sprintf(command, "chmod %s %s", permissions, file_path);
    system(command);
}

void create_file() {
    char file_path[100];
    printf("Enter the /path/to/the/file to create: ");
    scanf("%s", file_path);
    
    char command[200];
    sprintf(command, "touch %s", file_path);
    system(command);
}

void delete_file() {
    char file_path[100];
    printf("Enter the /path/to/the/file to delete: ");
    scanf("%s", file_path);
    
    char command[200];
    sprintf(command, "rm %s", file_path);
    system(command);
}

void create_directory() {
    char directory_path[100];
    printf("Enter the /path/to/the/folder to create: ");
    scanf("%s", directory_path);
    
    char command[200];
    sprintf(command, "mkdir %s", directory_path);
    system(command);
}

void delete_directory() {
    char directory_path[100];
    printf("Enter the /path/to/the/folder to delete: ");
    scanf("%s", directory_path);
    
    char command[200];
    sprintf(command, "rm -r %s", directory_path);
    system(command);
}

void create_symbolic_link(int link_type) {
    char source_path[100];
    printf("Enter the Source File: ");
    scanf("%s", source_path);
    
    char link_path[100];
    printf("Enter the Destination File: ");
    scanf("%s", link_path);
	char command[200];
    if(link_type == 1){
	sprintf(command, "ln -s %s %s", source_path, link_path);
	system(command);
    }else if(link_type == 2){
    	sprintf(command, "ln %s %s", source_path, link_path);
	system(command);
    }
}
