

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 256 


void Emo(const char* userResponse, const char* array[], int size, bool* emotionalState, char* emotion){

    for(int i = 0; i < size; i++){
        if(strstr(userResponse, array[i]) != NULL){
                *emotionalState = true;
            strcpy(emotion, array[i]);
            break;
        }
    }

};


int main(int argc, const char * argv[]) {
    
    //Greeting and space
    printf(" \n");
    printf("Hi, Im FASTBOT, how are you feeling?\n");
    
    char firstResponse[BUFFER_SIZE];
    printf(" \n");
    fgets(firstResponse, sizeof(firstResponse), stdin);
    
//GET EMOTION
    
    const char* pronouns[22] = {"I like", "I did", "I went to", "I went", "I went on a", "I went to the", "I ate", "I ate at",
    "i went to", "i went", "i like", "i did", "i went on a", "i went to the", "i ate", "i ate at", "i had", "I had", "I passed", "i passed", "I didnt", "I did not"};
    
    const char* positiveResponses[10] = {"Happy", "happy", "Good", "good", "Alright", "alright", "aight", "Aight", "Fine", "fine"};
    
    const char* extraPositiveResponses[6] = {"Great", "great", "Amazing", "amazing", "Wonderful", "wonderful"};
    
    //Negative responses
    
    const char* negativeResponses[6] = {"Sad", "sad", "Bad", "bad", "Unhappy", "unhappy"};
    
    const char* extraNegativeResponses[2] = {"Horrible", "horrible"};
    
    const char* no[] = {"No", "Nope", "Nah", "N", "n", "no", "nope","nah"};
    
    //Emotion bools and emotion variable, along with number of Substrings
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
    
    
    
    //If user input is equal to happy, continue, else go down
    if(positive || extraPositive){
        
        if(positive){
            //Regular level emotion if regularly happy
            printf(" \n");
            printf("Why are you feeling %s?\n", emotion);
            printf(" \n");
            
        } else if (extraPositive){
            //Extra emotion if extra happy
            printf(" \n");
            printf("Thats great! Why are you feeling %s?!\n", emotion);
            printf(" \n");
        }

        
        char secondResponse[BUFFER_SIZE];
        do {
            fgets(secondResponse, sizeof(secondResponse), stdin); // Sets buffer 
            secondResponse[strcspn(secondResponse, "\n")] = '\0';
        } while (strcmp(secondResponse, "") == 0); 
        
    
        //Loop to remove any of the pronouns from the previous response
        for (int i = 0; i < numSubstrs; i++) {
            long len = strlen(pronouns[i]);  
            char *p = strstr(secondResponse, pronouns[i]); 
            while (p != NULL) {
                memmove(p, p + len, strlen(p + len) + 1); 
                p = strstr(secondResponse, pronouns[i]);
            }
        }
        
        //Start is the leftover space added by the previous for loop
        char *start = secondResponse;
        while (*start == ' ') {
            start++;  // Skip leading spaces
        }
    
        
        //Continuning conversation
        printf(" \n");
        printf("I see, its good that%s, makes you happy\n", secondResponse);
        sleep(2);
        //Continuing conversation with one last question
        printf("Is there anything else?\n");
        printf("\n");
        
       //Creating input variable and possible parameters
        char thirdResponse[BUFFER_SIZE];
        
        //Getting third response.
        do {
            fgets(thirdResponse, sizeof(thirdResponse), stdin);
            thirdResponse[strcspn(thirdResponse, "\n")] = '\0';
        } while (strcmp(thirdResponse, "") == 0);
        
        
        //Checking to see if response is in the no array.
        for(int i = 0; i < sizeof(no) / sizeof(no[0]); i++){
            if(strcmp(thirdResponse, no[i]) == 0){
                printf("\n");
                printf("Ok, well thanks for talking, goodbye!\n");
                sleep(2);
                return 0;
            }
        }
       
        //Ending regarldess of user input
        printf("\n");
        printf("Thats nice, well I have to go, but I hope we can talk again!\n");
        sleep(2);
        
        return 0;
    } else if (negative || extraNegative){
        
        if(negative){
            //Regular level emotion if just sad
            printf(" \n");
            printf("Whats wrong, why are you feeling %s?\n", emotion);
            printf(" \n");
            
        } else if (extraNegative){
            //Extra emotion if user emotion is worse
            printf(" \n");
            printf("Im sorry! Whats going on, why are you feeling %s?\n", emotion);
            printf(" \n");
        }

        char secondResponse[BUFFER_SIZE];
        do{
            fgets(secondResponse, sizeof(secondResponse), stdin); 
            secondResponse[strcspn(secondResponse, "\n")] = '\0'; 
        } while (strcmp(secondResponse, "") == 0);
    
        
        for (int i = 0; i < numSubstrs; i++) {
            long len = strlen(pronouns[i]);  
            char *p = strstr(secondResponse, pronouns[i]); 
            while (p != NULL) {
                memmove(p, p + len, strlen(p + len) + 1);
                p = strstr(secondResponse, pronouns[i]); 
            }
        }
        
        
        char *start = secondResponse;
        while (*start == ' ') {
            start++;  
        }
        
        printf(" \n");
        printf("Im sorry, that%s is making you feel %s\n", secondResponse, emotion);
        //Delay
        sleep(2);
        printf("Is their anything else?\n");
        printf("\n");
       
        char thirdResponse[BUFFER_SIZE];
        do {
            fgets(thirdResponse, sizeof(thirdResponse), stdin);
        } while(strcmp(thirdResponse, "") == 0);
        
        for(int i = 0; i < sizeof(no) / sizeof(no[0]); i++){
            if(strstr(thirdResponse, no[i]) != NULL){
                printf("\n");
                printf("Ok, im sorry that you feel that way. I hope we can talk again when you feel better.");
                printf(" \n");
                sleep(2);
                return 0;
            }
        }
        
        
        printf("\n");
        printf("Well thats unfortunate, but I have to go. I hope we can talk again when you feel better.\n");
        sleep(2);
        
        //End
        return 0;
        
    } else {
        printf("\n");
        printf("I dont know how to respond to that, Ill have to talk to you later.\n");
        printf("\n");
        sleep(2);
        return 1;
    }
    return 0;
}

