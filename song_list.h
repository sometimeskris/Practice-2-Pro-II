/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: --- LOGIN 1: ---
 * AUTHOR 2: --- LOGIN 2: ---
 * GROUP: -
 * DATE: - / - / -
 */

#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "types.h"

/* Write your code here... */

#define NULLS (-1)
#define MAX 25

typedef int tPosS;

typedef tSong tItemS;

typedef struct tListS{
    tPosS lastPos;
    tItemS data[MAX];
}tListS;

//FUNCTIONS

//generators

void createEmptyListS(tListS* L);
//GOAL: Create an empty list
//INPUT: The name of the list you want to create
//POSTCONDITION: The list is initialized and empty

bool insertItemS(tItemS item, tPosS pos, tListS* L);
//GOAL: Insert an item into a position of the list
//If the position is LNULL, the element is added at the end of the list, if its any other valid position it will
//be placed right before the element currently holding that position.
//INPUT: The item to add and the position and list it will be added in.
//OUTPUT: True if the item could be inserted and false if not
//PRECONDITION: The given position is either a valid position or LNULL.
//POSTCONDITION: The positions of the elements in the positions following the one we inserted may have changed.

//modifiers

void updateItemS(tItemS item, tPosS pos, tListS* L);
//GOAL: Modify the content of the item in the indicated position
//INPUT: The new item and the position and list where it will be included.
//PRECONDITION: The given position is a valid position of the list
//POSTCONDITION: The order of the elements has not been changed

//destructors

void deleteAtPositionS(tPosS pos, tListS* L);
//GOAL: Deletes the item in the given position from the list
//INPUT: The position and list of the item we want to delete
//PRECONDITION: The given position is a valid position of the list
//POSTCONDITION: The positions of the elements in the positions following the one we deleted may have changed.

//observers

bool isEmptyListS(tListS L);
//GOAL: Check whether a list is empty or not.
//INPUTS: The list we want to check.
//OUTPUT: A boolean. True if it is empty and false if it's not.

tPosS firstS(tListS L);
//GOAL: Obtain the position of the first element of the list.
//INPUTS: The list we want to get the position from.
//OUTPUT: The position of the first element of the list.
//PRECONDIITON: The list is not empty.

tPosS lastS(tListS L);
//GOAL: Obtain the position of the first element of the list.
//INPUTS: The list we want to get the position from.
//OUTPUT: The position of the first element of the list.
//PRECONDIITON: The list is not empty.

tPosS nextS(tPosS pos, tListS L);
//GOAL: Obtain the position of the element following the one selected.
//INPUTS: The position of the element selected from which the position of the following one is obtained and the list that element belongs to.
//OUTPUT: The position of the element following the one we selected.
//PRECONDIITON: The inputted position is a valid position in the list.

tPosS previousS(tPosS pos, tListS L);
//GOAL: Obtain the position of the element preceding the one selected.
//INPUTS: The position of the element selected from which the position of the preceding one is obtained and the list that element belongs to.
//OUTPUT: The position of the element preceding the one we selected.
//PRECONDIITON: The inputted position is a valid position in the list.

tItemS getItemS(tPosS pos, tListS L);
//GOAL: Obtain the content of the element with the position selected.
//INPUTS: The position of the element we want to get the contents from and the list it belongs to.
//OUTPUT: The content of the element at the position we selected.
//PRECONDIITON: The inputted position is a valid position in the list.

tPosS findItemS(tUserName user, tListS L);
//GOAL: Obtain the position of the first element in the list whose username is the same as the one selected.
//INPUTS: The username that is going to be checked for matches at every position of the lists and the list we are going to check.
//OUTPUT: The position of the first element of the list whose username matches the one we selected.

#endif
