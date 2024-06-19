/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: --- LOGIN 1: ---
 * AUTHOR 2: --- LOGIN 2: ---
 * GROUP: -
 * DATE: - / - / -
 */

#include "user_list.h"
#include "song_list.h"
#include <stdlib.h>
#include <string.h>

/* Write your code here... */

//Generators

bool createNodeU(tPosU* p){
    *p = malloc(sizeof(struct tNode));
    return *p != NULLU;
}

//function for creating a new empty list
void createEmptyListU(tListU *L){
    //initializes a list by making it point to LNULL
    *L = NULLU;
}

//function for inserting an item into a list
bool insertItemU(tItemU item, tListU* L) {
    tPosU p, q;
    q = *L;
    //if the node creating fails it returns false and stops the insertion
    if (!createNodeU(&p)){
        return false;
    }
    //if the list is empty it inserts it in the first position
    if (*L == NULLU) {
        p->data = item;
        p->next = NULLU;
        *L = p;
    //if the element to insert is greater than the first it also inserts it in the first position
    }else if (strcmp(q->data.userName, item.userName) > 0){
        p->data = item;
        p->next = *L;
        *L = p;
    } else {
        //if q is not the last element in the list we perform a loop that checks element by element if the username of the
        //element we want to insert is greater than the username in the position following q
        if (q->next != NULLU) {
            while (strcmp(q->next->data.userName, item.userName) <= 0) {
                q = q->next;
                //every loop we check if q is the last element in the list
                if (q->next == NULLU){
                    //if it is we add the item at the end
                    p->data = item;
                    p->next = NULLU;
                    q->next = p;
                    return true;
                }
            }
        }
        p->data = item;
        p->next = q->next;
        q->next = p;
    }
    return true;
}

//Modifiers

//function for changing the value of an item of a list given its position
void updateItemU(tItemU item, tPosU pos, tListU* L){
    //it makes the given positions data point to the new data
    pos->data = item;
}

//Destructors

//function for deleting an item of a list given its position
void deleteAtPositionU(tPosU pos, tListU* L) {
    tListU p;
    p = *L;
    //in the case of deleting the first element of the list
    if (pos == *L) {
        p = *L;
        *L = p->next;
    }else if (pos->next == NULLU){ //if the position we want to delete is the last position of the list
        while (p->next != pos) { //loop to go through the list until p is the element preceding pos
            p = p->next;
        }
        p->next = NULLU;
    } else { //in the case of wanting to delete an element in the middle (every other case)
        while (p->next != pos) { //same loop as in the case when pos is the last position
            p = p->next;
        }
        p->next = pos->next;
    }
    //we free pos so that it doesn't take unnecessary space
    free(pos);
}

//Observers

//function for checking if the list is empty
bool isEmptyListU(tListU L){
    //initialized lists are empty when they point to null
    return (L == NULLU);
}

//function that returns the first position of a given list
tPosU firstU(tListU L){
    //the first position is the position L points to
    return (L);
}

//function that returns the last position of a given list
tPosU lastU(tListU L){
    tListU p=L;
    //it searches for the last position by iterating until the positions next is null and returns it
    while (p->next != NULLU) {
        p = p->next;
    }
    return p;
}

//function that returns the next position of a given position
tPosU nextU(tPosU pos, tListU L){
    //it returns the next position, if its the last it returns LNULL by definition
    return pos->next;
}

//function that returns the previous position of a given position
tPosU previousU(tPosU pos, tListU L){
    tListU p=L;
    if (pos == L){
        //if the position is the first one then it doest have a previous position
        return NULLU;
    }else {
        //it searches for the previous position by iterating until p next is equal to the given position
        while (p->next != pos) {
            p = p->next;
        }
        return p;
    }
}

//function that returns the data of a list in a given position
tItemU getItemU(tPosU pos, tListU L){
    //the data is always stored in the data pointer
    return pos->data;
}

//function that returns the first position of a given item
tPosU findItemU(tUserName user, tListU L){
    tListU p = L;
    //it iterates while the username stored in data is allocated before to the given user
    while (strcmp(p->data.userName, user) < 0) {
        //if it reaches null then it didnt find it and returns null
        if (p->next == NULLU){
            return NULLU;
        }
        p = p->next;
    }
    //if it passes the supposed position of the given user
    if (strcmp(p->data.userName, user) == 0) {
        //if both usernames are the same it means it found the item and returns the position
        return p;
    } else {
        //if the usernames arent the same it passed the position where the item should be and cause the list is ordered there is not such item
        return NULLU;
    }
}
