#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char website[256];
    char page[256];
    char url[256] = "start www.";
    int exit=0;

    do
    {
        printf("\nEnter the Website name: ");
        gets(website);

        strcat(url, website);
        strcat(url, ".com");
        printf("\n");

        char choice;
        printf("Want to open any specific page on this website (Press Y for yes & N for no) : ");
        scanf("%c", &choice);
        getchar();

        switch (choice)
        {
        case 'y':
        case 'Y':

            printf("\nEnter a specific page you want to open on %s : ", website);
            gets(page);
            strcat(url, "/");
            strcat(url, page);
            system(url);
            break;

        case 'n':
        case 'N':
            system(url);
            break;

        default:
            printf("Wrong Selection! Opening website without any specific page.");
            system(url);
            break;
        }

        printf("\n\nWant to exit (Press -1). Else press any key to continue.\n");
        scanf("%d", &exit);
        getchar();

    } while (exit!=-1);
}
