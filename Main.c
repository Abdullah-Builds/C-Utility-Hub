#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <unistd.h>
#include <stdbool.h>

// MEHROZ'S GLOBAL DEFINITION
#define BUFFER_SIZE 256

// ABDULLAH'S GLOBAL DEFINITION
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define BRIGHT_RED "\033[1;31m"
#define BRIGHT_GREEN "\033[1;32m"
#define BRIGHT_YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define BG_GREEN "\033[0;42m"
#define BG_DEFAULT "\033[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_RESET "\x1b[0m"

// HASSAN'S GLOBAL VARIABLES
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] =
    {
        " ",
        "\n\n\nJanuary",
        "\n\n\nFebruary",
        "\n\n\nMarch",
        "\n\n\nApril",
        "\n\n\nMay",
        "\n\n\nJune",
        "\n\n\nJuly",
        "\n\n\nAugust",
        "\n\n\nSeptember",
        "\n\n\nOctober",
        "\n\n\nNovember",
        "\n\n\nDecember"};

// ABDULLAH
void game()
{

    printf(BRIGHT_RED "GAMES  ---> MEMORY GAME -> FUN GAMES\n" RESET);
    printf("                               | \n");
    printf("                               V \n");
    printf(BRIGHT_RED "\t\t  ---> GUESS THE NUMBER \n " RESET);
    printf("\t\t  ---> MATCHSTICK GAME \n  ");
    printf("\t\t  ---> TIC TAC TOE\n ");
    printf("\033[H\033[J");

    printf("   /\\_/\\   \n");
    printf("  ( o o )  \n");
    printf("   (   )   \n");
    printf("   `---'   \n");

    int ch;
    printf("BEFORE STARTING MEMORY GAME READ INSTRUCTIONS\n");
    printf("IT COMPRISES OF THREE ROUNDS.IN EVERY ROUND YOU HAVE 5 SECONDS TO REWRITE THE DISPLAYED STRING\n");
    printf(RED "\tIN CASE THE ENTERED STRING DOES NOT MATCH ,THE WHOLE PROGRAM WILL EXIT\n" RESET);
    printf(BLACK "PRESS 1 FOR MEMORY TEST : \nPRESS 2 FOR FUN GAMES :" RESET);
    scanf("%d", &ch);

    switch (ch)
    {

    case 1:

        srand(time(NULL));
        char arr[6];
        char arr1[7];
        char arr2[9];
        char user[6];
        char user1[7];
        char user2[9];
        int i, j, k;

        printf("ROUND # 1\n");
        for (i = 0; i < 6; i++)
        {
            arr[i] = (char)(rand() % 26 + 'a');
        }

        arr[6] = '\0';
        puts(arr);

        sleep(5);
        printf("\033[H\033[J");
        printf("Screen cleared!\n");

        printf("   /\\_/\\   \n");
        printf("  ( o o )  \n");
        printf("   ==_==   \n");
        printf("    /_\\    \n");

        printf("\nENTER : ");
        getchar();
        fgets(user, sizeof(user), stdin);
        sleep(5);
        int result = strcmp(user, arr);

        if (result == 0)
        {
            printf("\nYou have successfully passed round # 1");
        }

        else
        {
            printf("\nOpps...! You loss...");
            exit(0);
        }

        printf("THE NEXT ROUND IS ABOUT TO START IN 3 SECONDS...!");
        sleep(3);
        printf("\nROUND # 2\n");

        for (j = 0; j < 7; j++)
        {
            arr1[j] = (char)rand() % 26 + 'a';
        }

        puts(arr1);
        arr[6] = '\0';

        sleep(4);
        printf("\033[H\033[J");
        printf("\nScreen cleared!\n");

        printf("   /\\_/\\   \n");
        printf("  ( o o )  \n");
        printf("   ==_==   \n");
        printf("    /_\\    \n");

        printf("\nENTER : ");
        getchar();
        fgets(user1, sizeof(user1), stdin);

        sleep(5);
        int result2 = strcmp(user1, arr1);

        if (result2 == 0)
        {
            printf("\nYou have successfully pass round # 2");
        }

        else
        {
            printf("\nNice try....!");
            exit(0);
        }

        printf("THE FINAL ROUND IS ABOUT TO START IN 5 SECONDS....!");
        sleep(5);
        printf("FINAL ROUND");

        for (k = 0; k < 9; k++)
        {
            arr2[k] = (char)(rand() % 26 + 'a');
        }

        arr2[9] = '\0';
        puts(arr2);

        sleep(3);
        printf("\033[H\033[J");
        printf("\nScreen cleared!\n");

        printf("ENTER : ");
        getchar();
        fgets(user2, 9, stdin);

        int result3 = strcmp(user2, arr2);

        if (result3 == 0)
        {

            printf("You have extraordinary intellectual power..!");

            printf("    .--.\n");
            printf("   ( . . )\n");
            printf("    |-#-|\n");
            printf("    '---'\n");
        }

        else
        {
            printf("\nunfortunately ,you failed but you are an  absolute genius");
            exit(0);
        }

        break;

    case 2:

        printf("   /\\_/\\   \n");
        printf("  ( o o )  \n");
        printf("   (   )   \n");
        printf("   `---'   \n");

        printf("\nPRESS 1 FOR GUESS THE NUMBER : ");
        printf("\nPRESS 2 MATHSTICK GAME : ");
        printf("\nPRESS 3 FOR TIC TAC TOE: ");
        int gamess;
        scanf("%d", &gamess);

        if (gamess == 1)
        {
            int count = 5, chance;

            printf(BRIGHT_RED "RULE : YOU HAVE ONLY FIVE CHANCES TO GUESS NUMBER BETWEEN 1-10" RESET);

            srand(time(NULL));
            int random = rand() % 10;

            do
            {
                printf("\nEnter your guess: ");
                scanf("%d", &chance);

                if (chance < random)
                {
                    printf("The guess number is less than the number.\n");
                }
                else if (chance > random)
                {
                    printf("The guess number is greater than the number.\n");
                }
                else if (chance == random)
                {
                    printf(YELLOW "Congratulations! You won!\n" RESET);
                    break;
                }
                else
                {
                    printf("Invalid input.\n");
                }

                count--;

                if (count == 0)
                {
                    printf(RED "\nOut of attempts. You lost. The number was: %d\n" RESET, random);
                    break;
                }

                printf(BLACK "Remaining attempts: %d\n", count, RESET);
            } while (count > 0);

            printf(RED "Game ended.\n" RESET);
        }

        else if (gamess == 2)
        {
            int choice, chances = 1, computer;
            char again;
            int i = 2, j = 1, c = 0;

            printf("\n\nIn this game there are total 21 matchsticks.");
            printf("\nWho picks the 21st matchstick will lose the game.\nThe user and computer both have  4 chances\n ");
            printf("You can pick maximum 4 matchsticks at a time");
            while (chances <= 4 || again == 'y')

            {
                printf("\n\nENTER THE NUMBER OF MATCHSTICKS YOU WANT TO CHOOSE : ");
                scanf("%d", &choice);

                if (choice >= 5)
                {
                    printf("\n****please input correctly, invalid****\n");
                    continue;
                }

                computer = 5 - choice;
                printf("COMPUTER CHOOSE THE MATCHSTICKS : %d", computer);
                c = c + computer + choice;
                printf("\nMATCHSTICK CHOOSEN : %d ", c);
                printf("\n**CHANCES USED :  %d**\n\n", chances);
                chances++;
                printf("\n");
                if (chances > 4)
                {
                    printf(BRIGHT_GREEN "\nComputer Wins\n, since last matchstick have to be choosen by the user\n******THE END****** " RESET);
                }
            }
        }

        else if (gamess == 3)
        {

            printf("RULES TO PLAY GAME : ");
            printf("INPUT NUMBER IN BETWEEN 0-2\n");

            int row1, col1, row2, col2, i, j, count = 0, count1 = 0, g = 0;
            int grid[3][3];

            for (i = 0; i < 3; i++)
            {

                for (j = 0; j < 3; j++)
                {

                    grid[i][j] = ' ';
                    printf("%d%d", i, j);

                    if (j < 2)
                    {
                        printf(" |");
                    }
                }
                printf("\n");

                if (i < 2)
                {
                    printf("--------\n");
                }
            }

            printf("\n\n");

            do
            {

                printf(BRIGHT_RED "\n PLAYER 1 TURNS  : " RESET);
                scanf("%d %d", &row1, &col1);

                if (grid[row1][col1] == ' ')
                {

                    grid[row1][col1] = 'X';
                }

                else
                {

                    printf("INVALID INPUT");
                    continue;
                }

                for (i = 0; i < 3; i++)
                {

                    for (j = 0; j < 3; j++)
                    {

                        printf(" %c ", grid[i][j]);

                        if (j < 2)
                        {
                            printf("|");
                        }

                        if (j == 0)
                        {
                            // horizontal check
                            if (grid[i][j] == 'X' && grid[i][j + 1] == 'X' && grid[i][j + 2] == 'X')
                            {

                                count1 = 1;
                            }
                            // vertical check
                            else if (grid[j][i] == 'X' && grid[j + 1][i] == 'X' && grid[j + 2][i] == 'X')
                            {

                                count1 = 1;
                            }
                        }

                        if (i == j)
                        {
                            // diagonal check
                            if (grid[i][j] == 'X' && grid[i + 1][j + 1] == 'X' && grid[i + 2][j + 2] == 'X')
                            {

                                count1 = 1;
                            }
                        }
                    }

                    printf("\n");

                    if (i < 2)
                    {

                        printf("-----------\n");
                    }
                }
                if (count1 == 1)
                {

                    printf("\n PLAYER # 1 WINS ");
                    exit(0);
                }

                printf("\n\n");

                printf(BRIGHT_RED "\n PLAYER 2 TURNS : " RESET);

                scanf("%d%d", &row2, &col2);

                if (grid[row2][col2] == ' ')
                {

                    grid[row2][col2] = 'O';
                }

                else
                {

                    printf("INVALID INPUT");
                    continue;
                }

                printf("\n\n");

                for (i = 0; i < 3; i++)
                {

                    for (j = 0; j < 3; j++)
                    {

                        printf("%c", grid[i][j]);

                        if (j < 2)
                        {
                            printf(" | ");
                        }

                        if (j == 0)
                        {
                            // horizontal check
                            if (grid[i][j] == 'O' && grid[i][j + 1] == 'O' && grid[i][j + 2] == 'O')
                            {

                                count = 1;
                            }
                            // vertical check
                            else if (grid[j][i] == 'O' && grid[j + 1][i] == 'O' && grid[j + 2][i] == 'O')
                            {

                                count = 1;
                            }
                        }

                        if (i == j)
                        {
                            // diagonal check
                            if (grid[i][j] == 'O' && grid[i + 1][j + 1] == 'O' && grid[i + 2][j + 2] == 'O')
                            {

                                count = 1;
                            }
                        }
                    }

                    printf("\n");

                    if (i < 2)
                    {

                        printf("-----------\n");
                    }
                }

                g++;

                if (count == 1)
                {

                    printf(BRIGHT_YELLOW "\n  PLAYER # 2 WINS " RESET);
                    exit(0);
                }

                else if (g == 4)
                {
                    printf(BRIGHT_YELLOW " DRAW " RESET);
                }

            } while (count != 1 || count1 != 1 || g != 4);
        }
    }
}
void calculator()
{
    printf("\x1b[48;5;231m");

    printf(MAGENTA "CLACULATOR -> COMPLEX -> SIMPLE -> NUCES GPA CALCULATOR -> CURRENCY CONVERTOR\n" RESET);
    printf("                 |          |                                        |\n");
    printf("                 V          V                                        V\n ");
    printf("          -> X TABLE      ADDITION                                RIYAL\n");
    printf("           ->FACTORIAL     MULTIPLICATION                          KUWATI DINAR\n");
    printf("           ->PRIME NUM     SUBTRACTION                             US DOLLAR\n");
    printf("           ->GCD           REMAINDER                               INDIAN RUPEE\n");
    printf("           ->ASCII VALUES  AVERAGE                                 YUAN\n");
    printf("                           QUOTIENT\n\n\n");

    char type;
    int type1, type2, type3, qt1, qt2, qt3, qt4;
    printf(CYAN "\nPRESS 'S' FOR SIMPLE CALCULATOR\nPRESS 'X' FOR COMPLEX CALCULATOR\n" RESET);
    printf(CYAN "PRESS C FOR CURRENCY CONVERTER\n" RESET);
    printf(CYAN "PRESS N TO CALULATE CGPA ;FAST NUCES" RESET);
    printf("\nENTER TYPE OF YOUR CALCULATOR : ");
    scanf(" %c", &type);
    printf("\033[H\033[J");
    printf(ANSI_BOLD "\nScreen cleared!\n" ANSI_RESET);

    printf("\n\n");
    if (type == 's' || type == 'S')
    {
        printf(BLUE "PRESS 1 FOR ADDITION\nPRESS 2 FOR MULTIPLICATION\nPRESS 3 FOR SUBTRACTION\n" RESET);
        printf(BLUE "PRESS 4 TO FIND REMAINDER\nPRESS 5 TO FIND AVERAGE\nPRESS 6 TO FIND QUOTIENT" RESET);
        printf("\nWHICH TYPE OF FUNCTION YOU WANT :");
        scanf("%d", &type1);
        printf("\n\n");
        printf("\033[H\033[J");
        printf(ANSI_BOLD "\nScreen cleared!\n" ANSI_RESET);

        if (type1 == 1)
        {

            printf("\nHOW MANY NUMBERS SUM YOU WANT? : ");
            scanf("%d", &qt1);
            float arr1[qt1], sum = 0.00;
            int i;
            printf("\nENTER NUMBERS : ");
            for (i = 0; i < qt1; i++)
            {
                scanf("%d", &arr1[i]);
                sum += arr1[i];
            }
            printf("\nSUM : %0.2f", sum);
        }

        else if (type1 == 2)
        {

            printf("\nHOW MANY NUMBERS YOU WANT TO MULTIPLY? : ");
            scanf("%d", &qt2);
            float arr2[qt2], multi = 1.00;
            int j;
            printf("\nENTER NUMBERS");
            for (j = 0; j < qt2; j++)
            {
                scanf("%f", &arr2[j]);
                multi = multi * arr2[j];
            }
            printf("\nMULTIPLICATION OF NUMBERS : %0.2f", multi);
        }

        else if (type1 == 3)
        {

            printf("\nHOW MANY NUMBERS YOU WANT TO SUBTRACT? : ");
            scanf("%d", &qt3);
            float arr3[qt3];
            float subtract = 0.0;
            int k;
            printf("\nENTER NUMBERS : ");
            for (k = 0; k < qt3; k++)
            {
                scanf("%f", &arr3[k]);
                subtract = arr3[k] - subtract;
            }
            printf("\nNUMBERS AFTER SUBTRACTION : %0.2f", subtract);
        }

        else if (type1 == 4)
        {

            float n1, n2;
            printf("ENTER TWO NUMBERS : ");
            scanf("%f%f", &n1, &n2);
            printf("\nREMAINDER : %0.2f", fmod(n1, n2));
        }

        else if (type1 == 5)
        {

            printf("\nHOW MANY NUMBERS AVERAGE YOU WANT? : ");
            scanf("%d", &qt4);
            float arr4[qt4], sum1 = 0;
            int l;
            printf("ENTER NUMBERS : ");
            for (l = 0; l < qt4; l++)
            {
                scanf("%f", &arr4[l]);
                sum1 += arr4[l];
            }
            printf("AVERAGE : %0.2f", sum1 / qt4);
        }

        else if (type1 == 6)
        {

            float n4, n5;
            printf("ENTER TWO NUMBERS : ");
            scanf("%f%f", &n4, &n5);
            printf("QUOTIENT : %0.2f", n4 / n5);
        }

        else
        {

            printf("invalid");
        }
    }

    else if (type == 'x' || type == 'X')
    {

        printf("PRESS 1 FOR MULTIPLICATION TABLE \nPRESS 2 TO FIND FACTORIAL\n");
        printf("PRESS 3 TO FIND PRIME NUMBERS\nPRESS 4 TO FIND GCD\nPRESS 5 TO FIND ASCII VALUES ");
        printf("\nWHICH TYPE OF FUNCTION YOU WANT : ");
        scanf("%d", &type1);
        printf("\033[H\033[J");
        printf("\n\n");

        if (type1 == 1)
        {

            int i, num;
            printf("WHICH NUMBERS MULTIPLICATION TABLE YOU WANT : ");
            scanf("%d", &num);
            for (i = 1; i < 11; i++)
            {
                printf("\n%d*%d=%d", num, i, num * i);
            }
        }

        else if (type1 == 2)
        {

            int num, i, fact = 1;
            printf("\nWHICH NUMBER OF WHICH YOU HAVE TO FIND FACTORIAL : ");
            scanf("%d", &num);
            for (i = num; i < 0; i--)
            {
                fact = fact * i;
            }
            printf("\nFACTORIAL OF %d : %d", num, fact);
        }

        else if (type1 == 3)
        {

            int range, i;
            printf("\nENTER RANGE TO FIND PRIME NUMBERS");
            scanf("%d", &range);
            printf("\nPRIME NUMBERS FROM RANGE 1 TO %d", range);
            for (i = 1; i <= range; i++)
            {
                if (i % 2 != 0 && i % 3 != 0)
                {
                    printf("%d\n", i);
                }
            }
        }

        else if (type1 == 4)
        {

            int num1, num2, p = 0;
            printf("\nENTER NUMBERS TO FIND GCD : ");
            scanf("%d%d", &num1, &num2);
            if (num1 < num2)
            {
                printf("\ninvalid");
            }
            else if (num1 % num2 == 0)
            {
                printf("\nGCD : %d", num2);
            }
            else
            {
                for (int i = num1; i >= 2; i--)
                {
                    if (num1 % i == 0 && num2 % i == 0)
                    {
                        printf("%d", i);
                        break;
                    }
                }
            }
        }

        else if (type1 == 5)
        {

            char ch;
            printf("\nENTER CHARACTER OF WHICH YOU HAVE TO FIND ASCII VALUES : ");
            scanf(" %c", &ch);
            printf("ASCII VALUES of %c : %d ", ch, ch);
        }

        else
        {

            printf("invalid");
        }
    }

    else if (type == 'C' || type == 'c')
    {

        float rupee, convert;
        printf("IT ONLY CONVERTS FROM PAKISTANI RUPEE TO THE FOLLOWING CURRENCIES\n");
        printf("1-RIYAL\n2-KUWATI DENNAR\n3-US DOLLAR\n4-INDIAN RUPEE\n5-YUAN");
        printf("\n\nENTER RUPEES : ");
        scanf("%f", &rupee);
        printf("\nPRESS 1 FOR RIYAL\nPRESS 2 FOR KUWATI DINAR\nPRESS 3 FOR US DOLLAR\n");
        printf("PRESS 4 FOR INDIAN RUPEE\nPRESS 5 FOR YUAN");
        printf("\n\nIN WHICH COUNTRYS CURRENCY YOU WANT TO CONVERT : ");
        scanf("%f", &convert);
        printf("\n");
        if (convert == 1)
        {

            printf("%0.2f PAKISTANI RUPEES IN RIYAL ARE :  %0.2f", rupee, rupee / 73.81);
        }

        else if (convert == 2)
        {
            printf("%0.2f PAKISTANI RUPEES IN KUWATI DINAR ARE : %0.2f", rupee, rupee / 905.75);
        }

        else if (convert == 3)
        {
            printf("%0.2f PAKISTANI RUPEES US DOLLAR ARE : %0.2f", rupee, rupee / 278.88);
        }

        else if (convert == 4)
        {
            printf("%0.2f PAKISTANI RUPEES IN  INDIAN RUPPEE ARE : %0.2f", rupee, rupee / 3.37);
        }

        else if (convert == 5)
        {
            printf("%0.2f PAKISTANI RUPEES IN YUAN ARE :  %0.2f", rupee, rupee / 38.62);
        }
        else
        {
            printf("invalid");
        }
    }

    else if (type == 'N' || type == 'n')
    {

        printf(RED "Absolute grades:\n" RESET);
        printf("marks<50-- F -- 0 points\n");
        printf("50 ------- D -----  1     Points\n");
        printf("54 ------- D+ ------1.33  points\n");
        printf("58 ------- C- ------1.66  points\n");
        printf("62 ------- C -------2.0   points\n");
        printf("66 ------- C+ ----- 2.33  points\n");
        printf("70 ------- B- ----- 2.66  points\n");
        printf("74 ------- B -----  3.0   points\n");
        printf("78 ------  B+ ----- 3.33 points\n");
        printf("82 ------- A- ----- 3.66  points\n");
        printf("86 ------- A -----  4.0   points\n");
        printf("90+ ------ A+ ----- 4.0   points\n\n\n");

        int subj = 0, crdhrs, i = 0, j = 0, k = 0, l = 0, sum = 0, sum1 = 0;
        printf("ENTER NUMBER OF COURSES : ");
        scanf("%d", &subj);
        printf("ENTER TOTAL CREDIT HOURS : ");
        scanf("%d", &crdhrs);
        char arr[subj][50];
        int arr1[subj];
        float arr2[subj];
        float gpa1[subj];

        do
        {

            printf("ENTER NAME OF COURSE # %d : ", i + 1);
            getchar();
            fgets(arr[i], 50, stdin);
            printf("ENTER CREDIT HOUR OF THIS COURSE : ");
            scanf("%d", &arr1[j]);
            printf("ENTER GPA OF THE COURSE : ");
            scanf("%f", &arr2[k]);
            sum1 = sum1 + arr1[j];

            gpa1[l] = arr1[j] * arr2[k];
            i++;
            j++;
            k++;
            l++;
            printf("\n");

        } while (i != subj);

        for (i = 0; i < subj; i++)
        {
            sum = sum + gpa1[i];
        }

        float gpa;
        if (crdhrs == sum1)
        {
            printf("YOUR GPA IS %f\n", gpa = (float)sum / crdhrs);
        }

        else
        {

            printf("INVALID");
        }

        if (gpa > 3.0)
        {

            printf("  .---.\n");
            printf(" / o o \\\n");
            printf("|   ^   |\n");
            printf("|  '-'  |\n");
            printf(" \\___/ \n");
        }

        else if (gpa > 3.5)
        {

            printf("   *****   \n");
            printf("  *     *  \n");
            printf(" *  O O  * \n");
            printf("*    ^    *\n");
            printf(" *  \\_/  * \n");
            printf("  *     *  \n");
            printf("   *****   \n");
        }

        else if (gpa > 2.5)
        {

            printf("   .---.\n");
            printf("  | o o |\n");
            printf("  |  ^  |\n");
            printf("  | \\_/ |\n");
            printf("   '---'\n");
        }

        else
        {

            printf("   .------.\n");
            printf("  /  ~ ~   \\\n");
            printf(" /   -   -   \\\n");
            printf("|  |  O  |  |\n");
            printf(" \\   -----   /\n");
            printf("  \\         /\n");
            printf("   `-------`\n");
        }
    }
}
void password()
{
    printf("\033[H\033[J");
    FILE *fptr;
    fptr = fopen("password..txt", "r");
    int result;

    char password[10], check[10];
    fscanf(fptr, "%s", password);
    do
    {

        printf(GREEN "\nENTER PASSWORD : " RESET);
        gets(check);

        result = strcmp(check, password);

        if (result != 0)
        {

            printf(BRIGHT_RED "\n\tPASSWORDS DO NOT MATCH\t\n\n" RESET);
        }

    } while (result != 0);

    fclose(fptr);
}

// HASSAN
void websites()
{
    char myweb[256];
    char page[256];
    char url[256] ="start www.";
    int exit = 0;

    do
    {
        getchar();
        printf(CYAN "\nEnter the Website name: " RESET);
        gets(myweb);

        strcat(url, myweb);
        strcat(url, ".com");
        printf("\n");

        char choice;
        printf(CYAN "Want to open any specific page on " RESET);
        printf(WHITE "%s" RESET);
        printf(BRIGHT_GREEN " (Press Y for yes & N for no) : " RESET);

        scanf(" %c", &choice);
        getchar();

        switch (choice)
        {
        case 'y':
        case 'Y':

            printf("\nEnter a specific page you want to open on %s : ", myweb);
            fgets(page, 256, stdin);
            strcat(url, "/");
            strcat(url, page);
            printf(GREEN "Opening website..." RESET);
            sleep(2);
            system(url);
            break;

        case 'n':
        case 'N':
            printf(GREEN "Opening website..." RESET);
            sleep(2);
            system(url);
            break;

        default:
            printf(RED "Wrong Selection! Opening website without any specific page." RESET);
            printf(GREEN "Opening website..." RESET);
            sleep(2);
            system(url);
            break;
        }

        memset(url, 0, strlen(url));
        memset(myweb, 0, strlen(myweb));
        memset(page, 0, strlen(page));

        printf(CYAN "\n\nWant to open other website ? " RESET);
        printf(GREEN "(Press any key to continue). " RESET);
        printf(RED "Else Press 1 to exit! \n" RESET);
        scanf("%d", &exit);
        getchar();

    } while (exit != 1);
}

int inputYear(void)
{
    int year;

    printf(CYAN "Please enter a year (example: 1999) : " RESET);
    scanf("%d", &year);
    return year;
}
int inputMonth(void)
{
    int month;

    do
    {
        printf(CYAN "\nPlease enter a month (example: 12) : " RESET);
        scanf("%d", &month);

    } while (month < 1 || month > 13);
    return month;
}
int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1.) / 4.0;
    d2 = (year - 1.) / 100.;
    d3 = (year - 1.) / 400.;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}
int determinedaycodeMonth(int year, int month)
{
    int daycode;
    int d1, d2, d3;

    if (month < 3)
    {
        month += 12;
        year--;
    }

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (2 + 2 * month + 3 * (month + 1) / 5 + year + d1 - d2 + d3) % 7;

    return daycode;
}
int determineleapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        days_in_month[2] = 29;
        return 1;
    }
    else
    {
        days_in_month[2] = 28;
        return 0;
    }
}
void printCalendar(int year, int daycode)
{
    int month, day;
    for (month = 1; month <= 12; month++)
    {
        printf(BRIGHT_GREEN "%s" RESET, months[month]);
        printf(BRIGHT_YELLOW "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" RESET);

        // Correct the position for the first date
        for (day = 1; day <= 1 + daycode * 5; day++)
        {
            printf(" ");
        }

        // Print all the dates for one month
        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%2d", day);

            // Is day before Sat? Else start next line Sun.
            if ((day + daycode) % 7 > 0)
                printf("   ");
            else
                printf("\n ");
        }
        // Set position for next month
        daycode = (daycode + days_in_month[month]) % 7;
    }
}
void printCalendarMonth(int year, int month, int daycode)
{
    int day;

    printf(BRIGHT_GREEN "%s" RESET, months[month]);
    printf(BRIGHT_YELLOW "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" RESET);

    // Correct the position for the first date
    for (day = 1; day <= 1 + daycode * 5; day++)
    {
        printf(" ");
    }

    // Print all the dates for one month
    for (day = 1; day <= days_in_month[month]; day++)
    {
        printf("%2d", day);

        // Is day before Sat? Else start next line Sun.
        if ((day + daycode) % 7 > 0)
            printf("   ");
        else
            printf("\n ");
    }
    // Set position for next month
    daycode = (daycode + days_in_month[month]) % 7;
}
int calendar()
{
    int year, month, daycode, leapyear, choice;

    do
    {
        printf("\033[H\033[J");

        printf(CYAN "\nPrint a whole year calendar or only a single month : \n" RESET);
        printf(GREEN "For whole year, Press 1.\n" RESET);
        printf(GREEN "For just a month of a year, Press 2.\n\n--> " RESET);
        scanf("%d", &choice);

        printf("\033[H\033[J");

        switch (choice)
        {
        case 1:
            year = inputYear();
            daycode = determinedaycode(year);
            determineleapyear(year);
            printCalendar(year, daycode);
            printf("\n");
            break;

        case 2:
            year = inputYear();
            month = inputMonth();
            daycode = determinedaycodeMonth(year, month);
            determineleapyear(year);
            printCalendarMonth(year, month, daycode);
            printf("\n");
            break;

        default:
            printf(RED "\n\nInvalid choice! Try Again.\n" RESET);
            sleep(1);
        }
    } while (choice < 1 || choice > 2);
}

// MEHROZ
void Emo(const char *userResponse, const char *array[], int size, bool *emotionalState, char *emotion)
{

    for (int i = 0; i < size; i++)
    {
        if (strstr(userResponse, array[i]) != NULL)
        {
            *emotionalState = true;
            strcpy(emotion, array[i]);
            break;
        }
    }
};
int chatBot()
{

    // Greeting and space
    printf(" \n");
    printf(CYAN "Hi, Im FASTBOT, how are you feeling?\n" RESET);
    getchar();

    char firstResponse[BUFFER_SIZE];
    printf(" \n");
    fgets(firstResponse, sizeof(firstResponse), stdin);

    // GET EMOTION

    const char *pronouns[22] = {"I like", "I did", "I went to", "I went", "I went on a", "I went to the", "I ate", "I ate at",
                                "i went to", "i went", "i like", "i did", "i went on a", "i went to the", "i ate", "i ate at", "i had", "I had", "I passed", "i passed", "I didnt", "I did not"};

    const char *positiveResponses[10] = {"Happy", "happy", "Good", "good", "Alright", "alright", "aight", "Aight", "Fine", "fine"};

    const char *extraPositiveResponses[6] = {"Great", "great", "Amazing", "amazing", "Wonderful", "wonderful"};

    // Negative responses

    const char *negativeResponses[6] = {"Sad", "sad", "Bad", "bad", "Unhappy", "unhappy"};

    const char *extraNegativeResponses[2] = {"Horrible", "horrible"};

    const char *no[] = {"No", "Nope", "Nah", "N", "n", "no", "nope", "nah"};

    // Emotion bools and emotion variable, along with number of Substrings
    bool positive = false;
    bool extraPositive = false;
    bool negative = false;
    bool extraNegative = false;

    int numSubstrs = sizeof(pronouns) / sizeof(pronouns[0]);

    char emotion[50];

    Emo(firstResponse, positiveResponses, 10, &positive, emotion);
    Emo(firstResponse, extraPositiveResponses, 6, &extraPositive, emotion);
    Emo(firstResponse, negativeResponses, 6, &negative, emotion);
    Emo(firstResponse, extraNegativeResponses, 2, &extraNegative, emotion);

    // If user input is equal to happy, continue, else go down
    if (positive || extraPositive)
    {

        if (positive)
        {
            // Regular level emotion if regularly happy
            printf(" \n");
            printf(GREEN "Why are you feeling %s?\n" RESET, emotion);
            printf(" \n");
        }
        else if (extraPositive)
        {
            // Extra emotion if extra happy
            printf(" \n");
            printf(BRIGHT_GREEN "Thats great! Why are you feeling %s?!\n" RESET, emotion);
            printf(" \n");
        }

        char secondResponse[BUFFER_SIZE];
        do
        {
            fgets(secondResponse, sizeof(secondResponse), stdin); // Sets buffer
            secondResponse[strcspn(secondResponse, "\n")] = '\0';
        } while (strcmp(secondResponse, "") == 0);

        // Loop to remove any of the pronouns from the previous response
        for (int i = 0; i < numSubstrs; i++)
        {
            long len = strlen(pronouns[i]);
            char *p = strstr(secondResponse, pronouns[i]);
            while (p != NULL)
            {
                memmove(p, p + len, strlen(p + len) + 1);
                p = strstr(secondResponse, pronouns[i]);
            }
        }

        // Start is the leftover space added by the previous for loop
        char *start = secondResponse;
        while (*start == ' ')
        {
            start++; // Skip leading spaces
        }

        // Continuning conversation
        printf(" \n");
        printf("I see, its good that%s, makes you happy\n", secondResponse);
        sleep(2);
        // Continuing conversation with one last question
        printf("Is there anything else?\n");
        printf("\n");

        // Creating input variable and possible parameters
        char thirdResponse[BUFFER_SIZE];

        // Getting third response.
        do
        {
            fgets(thirdResponse, sizeof(thirdResponse), stdin);
            thirdResponse[strcspn(thirdResponse, "\n")] = '\0';
        } while (strcmp(thirdResponse, "") == 0);

        // Checking to see if response is in the no array.
        for (int i = 0; i < sizeof(no) / sizeof(no[0]); i++)
        {
            if (strcmp(thirdResponse, no[i]) == 0)
            {
                printf("\n");
                printf(YELLOW "Ok, well thanks for talking, goodbye!\n" RESET);
                sleep(2);
                return 0;
            }
        }

        // Ending regarldess of user input
        printf("\n");
        printf(YELLOW "Thats nice, well I have to go, but I hope we can talk again!\n" RESET);
        sleep(2);

        return 0;
    }
    else if (negative || extraNegative)
    {

        if (negative)
        {
            // Regular level emotion if just sad
            printf(" \n");
            printf(RED "Whats wrong, why are you feeling %s?\n" RESET, emotion);
            printf(" \n");
        }
        else if (extraNegative)
        {
            // Extra emotion if user emotion is worse
            printf(" \n");
            printf(BRIGHT_RED "Im sorry! Whats going on, why are you feeling %s?\n" RESET, emotion);
            printf(" \n");
        }

        char secondResponse[BUFFER_SIZE];
        do
        {
            fgets(secondResponse, sizeof(secondResponse), stdin);
            secondResponse[strcspn(secondResponse, "\n")] = '\0';
        } while (strcmp(secondResponse, "") == 0);

        for (int i = 0; i < numSubstrs; i++)
        {
            long len = strlen(pronouns[i]);
            char *p = strstr(secondResponse, pronouns[i]);
            while (p != NULL)
            {
                memmove(p, p + len, strlen(p + len) + 1);
                p = strstr(secondResponse, pronouns[i]);
            }
        }

        char *start = secondResponse;
        while (*start == ' ')
        {
            start++;
        }

        printf(" \n");
        printf(YELLOW "Im sorry, that%s is making you feel %s\n" RESET, secondResponse, emotion);
        // Delay
        sleep(2);
        printf(GREEN "Is their anything else?\n" RESET);
        printf("\n");

        char thirdResponse[BUFFER_SIZE];
        do
        {
            fgets(thirdResponse, sizeof(thirdResponse), stdin);
        } while (strcmp(thirdResponse, "") == 0);

        for (int i = 0; i < sizeof(no) / sizeof(no[0]); i++)
        {
            if (strstr(thirdResponse, no[i]) != NULL)
            {
                printf("\n");
                printf(YELLOW "Ok, im sorry that you feel that way. I hope we can talk again when you feel better." RESET);
                printf(" \n");
                sleep(2);
                return 0;
            }
        }

        printf("\n");
        printf(YELLOW "Well thats unfortunate, but I have to go. I hope we can talk again when you feel better.\n" RESET);
        sleep(2);

        // End
        return 0;
    }
    else
    {
        printf("\n");
        printf(YELLOW "I dont know how to respond to that, Ill have to talk to you later.\n" RESET);
        printf("\n");
        sleep(2);
        return 1;
    }
    return 0;
}

void finance()
{

    int income, bills, expense;
    char name[100], ans;

    getchar();

    printf(CYAN "\nENTER NAME : " RESET);
    gets(name);

    printf(BRIGHT_RED "\nDO YOU OWN ANYTHING ON INTEREST(Y or N)  : " RESET);
    scanf(" %c", &ans);

    printf(MAGENTA "\nENTER YOUR INCOME : " RESET);
    scanf("%d", &income);

    printf(BLUE "\nENTER SUM OF ALL BILLS : " RESET);
    scanf("%d", &bills);

    printf(BRIGHT_YELLOW "\nENTER EXPENSE OF A MONTH : " RESET);
    scanf("%d", &expense);

    int sum = 0;

    sum = bills + expense;

    if (ans == 'y' || ans == 'Y')
    {

        printf(BRIGHT_GREEN "\n\n\nUSURY ONCE IN CONTROL WILL WRECK THE NATION\n" RESET);
        printf(WHITE "BY WILLIAM LION MACKENZIE KING\n" RESET);
        printf("SO NEXT TIME ,DONOT TAKE ANYTHING ON INTEREST\n\n\n");
    }

    if (sum >= 0)
    {

        printf(RED "\nSAVINGS : %d ", sum, RESET);
    }

    else if (sum < 0)
    {

        printf(RED "\nSAVINGS : NO SAVINGS" RESET);
    }

    if (sum < income)
    {

        printf(WHITE "\nYOU ARE ON GOOD TRACK..%s!", name, RESET);
    }
    else if (sum > income)
    {

        printf(WHITE "\nYOU ARE ON A WRONG TRACK..%s!", name, RESET);
    }

    else
    {

        printf(WHITE "\nYOU ARE ON A WRONG TRACK...%s", name, RESET);
    }
}

int main()
{
    password();

    int choice, end = 0;
    do
    {

        printf("\033[H\033[J");
        printf("---------------------------------------------------");
        printf("---------------------------------------------------");
        printf("---------------------------------------------------");
        printf("-------------------------------------------------\n\n");
        printf(BRIGHT_YELLOW ANSI_BOLD "\t\t\t\t\tYOUR VERY OWN PERSONAL ASSISTANT\n\n" RESET ANSI_RESET);
        printf("---------------------------------------------------");
        printf("---------------------------------------------------");
        printf("---------------------------------------------------");
        printf("-------------------------------------------------\n\n");

        // OPTIONS
        printf(BLUE "\t\t\t\t\tWhat you would like to do today?\n\n" RESET);
        printf("\t\t\t\t\t\t1) Play some games?\n\n");
        printf("\t\t\t\t\t  2) Try our advanced calculator?\n\n");
        printf("\t\t\t\t\t\t3) Open some Websites?\n\n");
        printf("\t\t\t\t\t  4) Take a look at the calendar?\n\n");
        printf("\t\t\t\t\t\t 5) Feeling lonely, talk with our Emotional Chatbot!\n\n");
        printf("\t\t\t\t\t 6) Want to manage finace? \n\n");
        printf(BRIGHT_YELLOW "\t\t\t\tDo you want to exit THE PERSONAL ASSISTANT?" RESET);
        printf(RED " Enter 0 to exit.\n" RESET);

        // INPUT
        printf(BRIGHT_GREEN "\nENTER THE CORRESPONDING NUMBER TO ACCESS THAT FEATURE! " RESET);
        printf(ANSI_BOLD "\t--> OPEN " ANSI_RESET);
        scanf("%d", &choice);
        // CHECK
        if (choice < 0 || choice > 6)
        {
            {
                printf(BRIGHT_RED "\n\t\t\t\t\t\t\t\t   OPTION SELECTED IS OUT OF SCOPE! Try Again." RESET);
                sleep(2);
            }
        }

        if (choice == 0)
        {
            printf(RED "\n\n\t\t\t\t\t\t\t\t\tClosing PERSONAL ASSISTANT!" RESET);
            sleep(1);
        }

        printf("\033[H\033[J");

        switch (choice)
        {
        case 1:
            game();
            break;

        case 2:
            calculator();
            break;

        case 3:
            websites();
            break;

        case 4:
            calendar();
            break;

        case 5:
            chatBot();
            break;

        case 6:
            finance();
            break;

        case 0:
            break;
        }

    } while (end != 0);
}

