#pragma once

#include <stddef.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

#define list_new(curr, structure, name) (__internal_new_list(&(curr->name), (array_ptr<void>)curr, sizeof(structure)))
#define list_get(curr, structure, name) (dynamic_bounds_cast<ptr<structure>>(curr->data_addr))
#define list_insert(curr, next, structure, name) __internal_insert_list_after(&((curr)->name), &((next)->name), (array_ptr<void>)next, sizeof(structure));
#define list_remove(curr, structure, name) __internal_remove_list(curr, offsetof(structure, name))
#define list_size(curr, structure, name) __internal_list_size(&(curr->name))
#define list_iter(iter, curr, structure, name, code) {\
    ptr<struct list> __list_iterator = curr;\
    do {\
        iter = list_get(__list_iterator, structure, name);\
        code\
        __list_iterator = __list_iterator->next;\
    } while (__list_iterator != curr);\
}

struct list {
    /**
     * struct list - the doubly linked list structure
     * 
     * The doubly linked list forms a closed ring that the 'first' and 'last' element are  
     * connected through pointers.
     * The structure has no defined first element. Every element can be used as a first el-
     * ment and can use it to iterate through the entire list.
     * Note that if there is no element in the doubly linked list, the list itself cease to
     * exist.
     * 
     * To use the list, define a struct list element in the structure that you wish to be  
     * doubly linked, then use macro functions to operate the list.
     */
    ptr<struct list> prev, next; /* the previous and next pointer in the doubly linked list */
    array_ptr<void> data_addr : byte_count(length);
    size_t length;
};

extern void __internal_new_list(ptr<struct list> head, array_ptr<void> data : byte_count(length), size_t length); 
extern void __internal_insert_list_after(ptr<struct list> curr, ptr<struct list> insertion, array_ptr<void> data : byte_count(length), size_t length);
extern void __internal_remove_list(ptr<struct list> curr, long offset);
extern int __internal_list_size(ptr<struct list> head);

// extern void __debug_print(struct list* p);
