/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: KRIS SANTISO SAMPEDRO LOGIN 1: kris.santiso@udc.es
 * AUTHOR 2: Diego Arturo Contreras Gonzalez LOGIN 2: diego.contreras@udc.es
 * GROUP: 6.1
 * DATE: 12 / 04 / 24
 */

#include "song_list.h"
#include "string.h"

/* Write your code here... */

//Generators

//function for creating a new empty list
void createEmptyListS (tListS* L) {
    //initializes a list by giving a value to its last position
    L->lastPos=NULLS;
}

//function for inserting an item into a list
bool insertItemS (tItemS item, tPosS pos, tListS* L) {
    //if the list is full it cant add more elements, so it returns false
    if (L->lastPos == (MAX-1)) {
        return false;
    //if the given position is null it adds the given item to the last position
    } else if (pos == NULLS) {
        L->lastPos = L->lastPos+1;
        L->data[L->lastPos] = item;
        return true;
    //if the given position is any other valid position it adds the item there and "moves the other items to the right"
    } else {
        int i;
        L->lastPos = L->lastPos + 1;
        for (i = L->lastPos; i > pos; i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[pos] = item;
        return true;
    }
}


//Modifiers

//function for changing the value of an item of a list given its position
void updateItemS (tItemS item, tPosS pos, tListS* L) {
    //changes the value of the data in the given position with the given item
    L->data[pos] = item;
}


//Destructors

//function for deleting an item of a list given its position
void deleteAtPositionS (tPosS pos, tListS* L) {
    int i;
    //deletes the item in the given position and "moves the other items to the left"
    for (i = pos; i < L->lastPos; i++) {
        L->data[i] = L->data[i+1];
    }
    L->lastPos = L->lastPos-1;
}


//Observers

//function for checking if the list is empty
bool isEmptyListS (tListS L) {
    //initialized lists are empty when their last position is null
    return (L.lastPos == NULLS);
}

//function that returns the first position of a given list
tPosS firstS (tListS L) {
    //if the list is not empty its first position is always 0
    return 0;
}

//function that returns the last position of a given list
tPosS lastS (tListS L) {
    //we always store the last position of a list into the lastPos variable
    return L.lastPos;
}

//function that returns the next position of a given position
tPosS nextS (tPosS pos, tListS L) {
    //if the given position is the last position it doesn't have a next position
    if (pos == L.lastPos) {
        return NULLS;
    //if its any other position it returns the next one
    } else {
        return pos+1;
    }
}

//function that returns the previous position of a given position
tPosS previousS (tPosS pos, tListS L) {
    //if the given position is the first position it doesn't have a previous position
    if (pos == 0) {
        return NULLS;
        //if its any other position it returns the previous one
    } else {
        return pos-1;
    }
}

//function that returns the data of a list in a given position
tItemS getItemS (tPosS pos, tListS L) {
    //it returns the data of the list in the given position
    return L.data[pos];
}

//function that returns the first position of a given itemç
tPosS findItemS (tSongTitle title, tListS L) {
    int i;
    //it searches through the list until a username coincides with the given one
    for (i=0;i<=L.lastPos;i++) {
        if (strcmp(title, L.data[i].songTitle)==0){
            return i;
        }
    }
    return NULLS;
}