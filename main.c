#include <stdio.h>
#include <string.h>

// STEP 2: Define structure
struct Student {
    int id;
    char name[50],
    description[50],
    priorityVal[30] ;   
    
    int age , priority;
};

// STEP 3: Database
struct Student db[200];
int count = 0;

// CREATE
void createProject() {
    printf("Enter Project ID (unique) : ");
    scanf("%d", &db[count].id);
    getchar();  // Consume leftover newline from previous input

    printf("Enter Project Name: ");
    fgets(db[count].name, sizeof(db[count].name), stdin);
    db[count].name[strcspn(db[count].name, "\n")] = 0; // Remove newline

    printf("Enter Description: ");
    fgets(db[count].description, sizeof(db[count].description), stdin);
    db[count].description[strcspn(db[count].description, "\n")] = 0; // Remove newline

    printf("Enter Project's Priority (1-Low, 2-Medium, 3-High): ");
    scanf("%d", &db[count].priority);

    count++;

    printf("Project added successfully!\n");
}


// READ
void readStudents() {
    if (count == 0) {
        printf("\n====================================\n");
        printf("        No projects found.\n");
        printf("====================================\n");
        return;
    }

    printf("====================================\n");
    printf("           ALL PROJECTS\n");
    printf("====================================\n");

    for (int i = 0; i < count; i++) {

        // printf("Project No %d:", i+1);

        printf("\n%d)\tProject ID   : %d\n", i + 1, db[i].id);
        printf("\tProject Name: %s\n", db[i].name);
        printf("\tDescription: %s\n", db[i].description);
        if(db[i].priority == 1){
        printf("\tProject's Priority: Low");
        }
        else if(db[i].priority == 2){
        printf("\tProject's Priority: Medium");
        }
        else{
        printf("\tProject's Priority: High");
        }
		 printf("\n====================================\n");

        // printf("Project's Priority: %d\n", db[i].priority);
    }
}

// UPDATE
void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", db[i].name);

            printf("Enter new age: ");
            scanf("%d", &db[i].age);

            printf("Record updated!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// DELETE
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                db[j] = db[j + 1];
            }
            count--;

            printf("Record deleted!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// STEP 5: MENU AND MAIN LOOP
int main() {
    int choice;

    while (1) {
    	//printf("\n====================================\n");
   		printf("\n    SIMPLE CRUD SYSTEM    \n");
    	printf("====================================\n");
        printf("1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\n");
         printf("====================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        //printf("====================================\n");

        switch (choice) {
            case 1: createProject(); break;
            case 2: readStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
