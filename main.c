/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: --- LOGIN 1: ---
 * AUTHOR 2: --- LOGIN 2: ---
 * GROUP: -
 * DATE: - / - / -
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

//NEW

void newUser(char *username, char *category, tListU* L){
    //it creates the item it'll add, initializing everything
    tItemU item;
    strcpy(item.userName, username);
    if (strcmp(category, "basic") == 0) {
        item.userCategory = basic;
    } else {
        item.userCategory = pro;
    }
    item.totalPlayTime = 0;
    createEmptyListS(&item.songList);
    //once everything is initialized it checks if the list is empty
    if (isEmptyListU(*L)){
        //if it is it just tries inserts the item and prints if it worked or not
        bool userInserted;
        userInserted = insertItemU(item, L);
        if (userInserted) {
            printf("* New: user %s category %s\n", username, category);
        } else {
            printf("+ Error: New not possible\n");
        }
    } else {
        //if the list isn't empty it searches if there's already an item with the same username
        if (findItemU(item.userName, *L) == NULLU){
            //if there's not, it tries inserts the item and prints if it worked or not
            bool userInserted;
            userInserted = insertItemU(item, L);
            if (userInserted) {
                printf("* New: user %s category %s\n", username, category);
            } else {
                printf("+ Error: New not possible\n");
            }
        } else {
            //if there's already an item with the same username it doesn't insert it
            printf("+ Error: New not possible\n");
        }
    }

}

//UPGRADE

void upgradeUser(char *user, tListU* L){

}

//DELETE

void deleteUser(char *user, tListU* L){
    //it checks if the list is empty
    if (isEmptyListU(*L)){
        //if it is there's no user to delete
        printf("+ Error: Delete not possible\n");
    } else {
        //if it's not it searches for the user
        tPosU pos;
        pos = findItemU(user, *L);
        if (pos == NULLU) {
            //if it doesn't find it then there's no user to delete
            printf("+ Error: Delete not possible\n");
        } else {
            //if it finds it, it creates an item to access its username, category and playtime
            tItemU item;
            item = getItemU(pos, *L);
            //it creates a string for the category, so it can be printed
            char category[6];
            if (pos->data.userCategory == basic) {
                strcpy(category,"basic");
            } else {
                strcpy(category,"pro");
            }
            //it checks if the song list is empty
            if (isEmptyListS(pos->data.songList)) {
                deleteAtPositionU(pos, L);
                printf("* Delete: user %s category %s totalplaytime %d\n", item.userName, category, item.totalPlayTime);
            } else {
                while (!isEmptyListS(pos->data.songList)) {
                    deleteAtPositionS(firstS(pos->data.songList), &pos->data.songList);
                }
                deleteAtPositionU(pos, L);
                printf("* Delete: user %s category %s totalplaytime %d\n", item.userName, category, item.totalPlayTime);
            }
        }
    }
}

//ADD

void addSong(char *user, char *songName, tListU* L){
    //it checks if the list is empty
    if (isEmptyListU(*L)) {
        //if it is it can't add the song to the user cause there's no user
        printf("+ Error: Add not possible\n");
    } else {
        //if the list is not empty it searches for the item to add the song to
        tPosU pos = findItemU(user, *L);
        if (pos == NULLU){
            //if there's no item to add the song to it prints the error
            printf("+ Error: Add not possible\n");
        } else {
            //if the item exists it gets it, so it can add the song
            tItemU item = getItemU(pos, *L);
            //it initializes the song to add
            tItemS song;
            strcpy(song.songTitle, songName);
            song.playTime = 0;
            //once the song is initialized it checks if the song list is empty
            if (isEmptyListS(item.songList)) {
                //if it is it just tries inserts the item and prints if it worked or not
                bool songInserted = insertItemS(song, NULLS, &item.songList);
                if (songInserted) {
                    updateItemU(item, pos, L);
                    printf("* Add: user %s adds song %s\n", user, songName);
                } else {
                    printf("+ Error: Add not possible\n");
                }
            } else {
                //if the list isn't empty it searches if there's already a song with the same name
                if (findItemS(songName, item.songList) == NULLS) {
                    //if there's not, it tries inserts the item and prints if it worked or not
                    bool songInserted = insertItemS(song, NULLS, &item.songList);
                    if (songInserted) {
                        updateItemU(item, pos, L);
                        printf("* Add: user %s adds song %s\n", user, songName);
                    } else {

                        printf("+ Error: Add not possible\n");
                    }
                } else {
                    //if there's already a song with the same name it doesn't insert it
                    printf("+ Error: Add not possible\n");
                }
            }
        }
    }
}

//STATS

//function for printing each user individually
void printUserStats(tItemU item){
    tPosS q;
    tItemS song;
    //it creates a string for the category, so it can be printed
    char category[6];
    if (item.userCategory == basic) {
        strcpy(category,"basic");
    } else {
        strcpy(category,"pro");
    }
    printf("User %s category %s totalplaytime %d\n", item.userName, category, item.totalPlayTime);

    if (isEmptyListS(item.songList)) {
        //if the list is empty the user doesn't have any song
        printf("No songs\n");
    } else {
        //if the list isn't empty it iterates through the song list printing the information for each song
        q = firstS(item.songList);
        while (q!=NULLS){
            song = getItemS(q,item.songList);
            printf("Song %s playtime %d\n", song.songTitle, song.playTime);
            q = nextS(q, item.songList);
        }
    }
    printf("\n");
}

//function for printing the summary stats
void printTotalStats(int basicUsers, int basicTotalTimeplay, int proUsers, int proTotalTimeplay){
    float basicAveragePlaytime, proAveragePlaytime;
    //to avoid math errors dividing by 0, whenever there are 0 users the average is automatically set to 0
    if (basicUsers != 0) {
        basicAveragePlaytime = (float) basicTotalTimeplay / (float) basicUsers;
    } else {
        basicAveragePlaytime = 0;
    }
    if (proUsers != 0) {
        proAveragePlaytime = (float) proTotalTimeplay / (float) proUsers;
    } else {
        proAveragePlaytime = 0;
    }
    //when all things are calculated it prints the summary stats
    printf("Category  Users  TimePlay  Average\n");
    printf("Basic     %5d %9d %8.2f\n", basicUsers, basicTotalTimeplay, basicAveragePlaytime);
    printf("Pro       %5d %9d %8.2f\n", proUsers, proTotalTimeplay, proAveragePlaytime);
}

//base function for showing stats
void showStats(tListU* L){
    //if the list is empty there is nothing to show
    if (isEmptyListU(*L)){
        printf("+ Error: Stats not possible\n");
    } else {
        //it initializes the iterator p and the counters
        tPosU p;
        p = firstU(*L);
        tItemU item;
        int basicUsers = 0, proUsers = 0, basicTotalTimeplay = 0, proTotalTimeplay = 0;
        //while the iterator doesn't reach the end
        while (p!=NULLU){
            //in each iteration it gets the item and prints it stats
            item = getItemU(p,*L);
            printUserStats(item);
            //it adds the item to the counters
            if(item.userCategory==basic){
                basicUsers++;
                basicTotalTimeplay += item.totalPlayTime;
            } else {
                proUsers++;
                proTotalTimeplay += item.totalPlayTime;
            }
            //then it advances to the next position
            p = nextU(p, *L);
        }
        //when it reaches the end it prints the summary stats
        printTotalStats(basicUsers, basicTotalTimeplay, proUsers, proTotalTimeplay);
    }
}

//END OF IMPLEMENTED FUNCTIONS

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListU* L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            newUser(param1, param2, L);
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            deleteUser(param1, L);
            break;
        case 'A':
            printf("********************\n");
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            addSong(param1, param2, L);
            break;
        case 'U':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            upgradeUser(param1, L);
            break;
        case 'P':
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c:\n", commandNumber, command);
            showStats(L);
            break;
        case 'R':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        tListU L;
        createEmptyListU(&L);

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}
