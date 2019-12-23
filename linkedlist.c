#include <stdlib_checked.h>
#include <stdio_checked.h>
#include <stdchecked.h>

#include "linkedlist.h"
#include "print.h"

#pragma CHECKED_SCOPE ON

void __debug_print(ptr<struct list> p) {
    /**
     * __debug_print - print the address / next value / prev value 
     *                 of all pointers in the linked list
     * 
     * p: the list head, can be an arbitrary element in the list
     */
    ptr<struct list> q = p;
    do {
        fputs("{\n", stdout);
        fputs("\tCurr Address: ", stdout);
        print_int((int) q);
        putchar('\n');
        fputs("\tNext Address: ", stdout);
        print_int((int) q->next);
        putchar('\n');
        fputs("\tPrev Address: ", stdout);
        print_int((int) q->prev);
        putchar('\n');
        fputs("}\n", stdout);
        q = q->next;
    } while (q != p);
}

void __internal_new_list(ptr<struct list> head, array_ptr<void> data : byte_count(length), size_t length) {
    /**
     * __internal_new_list - initialize a doubly linked list within a structure
     * 
     * head: the first element in the doubly linked list
     */
    head->prev = head;
    head->next = head;

    head->data_addr = data;
    head->length = length;
    return;
}

void __internal_insert_list_after(ptr<struct list> curr, ptr<struct list> insertion, array_ptr<void> data : byte_count(length), size_t length) {
    /**
     * __internal_insert_list_after - insert an element after the destiny element
     * 
     * curr     : the list location to be inserted after
     * insertion: the element to insert into the list
     */
    curr->next->prev = insertion;
    insertion->next = curr->next;
    curr->next = insertion;
    insertion->prev = curr;

    insertion->data_addr = data;
    insertion->length = length;
    return;
}

void __internal_remove_list(ptr<struct list> curr, long offset) {
    /**
     * __internal_remove_list - remove an element from the list
     * 
     * curr  : the element to be removed
     * offset: the offset of doubly linked list within the struct
     */
    if (curr->next != curr) { 
        // trim the list only if there exist element
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    // free current pointer
    free <void>(curr->data_addr);
    return;
}

int __internal_list_size(ptr<struct list> head) {
    /**
     * __internal_list_size - fetch the size of the list
     * 
     * head  : an arbitrary list element
     * return: the size of the doubly linked list
     */
    int size = 1;
    ptr<struct list> p = head->next;

    while (p != head) {
        p = p->next;
        size++;
    }

    return size;
}
