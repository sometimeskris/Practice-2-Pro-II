/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: KRIS SANTISO SAMPEDRO LOGIN 1: kris.santiso@udc.es
 * AUTHOR 2: Diego Arturo Contreras Gonzalez LOGIN 2: diego.contreras@udc.es
 * GROUP: 6.1
 * DATE: 12 / 04 / 24
 */

#ifndef USER_LIST_H
#define USER_LIST_H

#include "types.h"
#include "song_list.h"

/* Write your code here... */

#define NULLU NULL

typedef struct tNode* tPosU;

typedef struct tItemU{
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
}tItemU;

struct tNode{
    tItemU data;
    tPosU next;
};

typedef tPosU tListU;

//FUNCTIONS

//generators

bool createNodeU(tPosU* pos);
//FUNCTION FOR AUTOMATING THE PROCESS OF CREATING A NODE

void createEmptyListU(tListU* L);
//GOAL: Create an empty list
//INPUT: The name of the list you want to create
//POSTCONDITION: The list is initialized and empty

bool insertItemU(tItemU item, tListU* L);

//modifiers

void updateItemU(tItemU item, tPosU pos, tListU* L);
//GOAL: Modify the content of the item in the indicated position
//INPUT: The new item and the position and list where it will be included.
//PRECONDITION: The given position is a valid position of the list
//POSTCONDITION: The order of the elements has not been changed

//destructors

void deleteAtPositionU(tPosU pos, tListU* L);

//observers

bool isEmptyListU(tListU L);
//GOAL: Check whether a list is empty or not.
//INPUTS: The list we want to check.
//OUTPUT: A boolean. True if it is empty and false if it's not.

tPosU firstU(tListU L);
//GOAL: Obtain the position of the first element of the list.
//INPUTS: The list we want to get the position from.
//OUTPUT: The position of the first element of the list.
//PRECONDIITON: The list is not empty.

tPosU lastU(tListU L);
//GOAL: Obtain the position of the first element of the list.
//INPUTS: The list we want to get the position from.
//OUTPUT: The position of the first element of the list.
//PRECONDIITON: The list is not empty.

tPosU nextU(tPosU pos, tListU L);
//GOAL: Obtain the position of the element following the one selected.
//INPUTS: The position of the element selected from which the position of the following one is obtained and the list that element belongs to.
//OUTPUT: The position of the element following the one we selected.
//PRECONDIITON: The inputted position is a valid position in the list.

tPosU previousU(tPosU pos, tListU L);
//GOAL: Obtain the position of the element preceding the one selected.
//INPUTS: The position of the element selected from which the position of the preceding one is obtained and the list that element belongs to.
//OUTPUT: The position of the element preceding the one we selected.
//PRECONDIITON: The inputted position is a valid position in the list.

tItemU getItemU(tPosU pos, tListU L);
//GOAL: Obtain the content of the element with the position selected.
//INPUTS: The position of the element we want to get the contents from and the list it belongs to.
//OUTPUT: The content of the element at the position we selected.
//PRECONDIITON: The inputted position is a valid position in the list.

tPosU findItemU (tUserName user, tListU L);
//GOAL: Obtain the position of the first element in the list whose username is the same as the one selected.
//INPUTS: The username that is going to be checked for matches at every position of the lists and the list we are going to check.
//OUTPUT: The position of the first element of the list whose username matches the one we selected.

#endif
