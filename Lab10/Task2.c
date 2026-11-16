#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

int main() {
    struct Movie movies[50];
    int count = 0;
    int choice, i, found;
    char searchGenre[30];

    while (1) {
        printf("\n1. Add New Movie\n2. Display All Movies\n3. Search by Genre\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Title (single word or use_underscores): ");
            scanf("%s", movies[count].title);

            printf("Enter Genre: ");
            scanf("%s", movies[count].genre);

            printf("Enter Director (single word): ");
            scanf("%s", movies[count].director);

            printf("Enter Release Year: ");
            scanf("%d", &movies[count].releaseYear);

            printf("Enter Rating (out of 10): ");
            scanf("%f", &movies[count].rating);

            count++;
            printf("Movie added successfully!\n");

        } else if (choice == 2) {
            if (count == 0) {
                printf("\nNo movies in the list yet.\n");
            } else {
                printf("\n--- All Movies ---\n");
                for (i = 0; i < count; i++) {
                    printf("%d. %s (%d) | Genre: %s | Director: %s | Rating: %.1f/10\n",
                           i + 1, movies[i].title, movies[i].releaseYear,
                           movies[i].genre, movies[i].director, movies[i].rating);
                }
            }

        } else if (choice == 3) {
            printf("Enter Genre to search: ");
            scanf("%s", searchGenre);
            found = 0;

            printf("\n--- Search Results ---\n");
            for (i = 0; i < count; i++) {
                if (strcmp(movies[i].genre, searchGenre) == 0) {
                    printf("- %s (%d) | Director: %s | Rating: %.1f/10\n",
                           movies[i].title, movies[i].releaseYear,
                           movies[i].director, movies[i].rating);
                    found = 1;
                }
            }
            if (!found) {
                printf("No movies found in the '%s' genre.\n", searchGenre);
            }

        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}