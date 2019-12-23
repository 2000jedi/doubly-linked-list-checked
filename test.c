#include <stdio_checked.h>
#include <stdlib_checked.h>

#include "linkedlist.h"
#include "print.h"

#pragma CHECKED_SCOPE ON

struct Integer{
    int c;
    struct list l;
};

ptr<struct Integer> int1, int2, int3;

int main(int argc, nt_array_ptr<char> argv checked[] : count(argc)) {
    int1 = malloc<struct Integer>(sizeof(struct Integer));
    fputs("Addr of int1: ", stdout);
    print_int((int) int1);
    putchar('\n');
    int1->c = 1;

    int2 = malloc<struct Integer>(sizeof(struct Integer));
    fputs("Addr of int2: ", stdout);
    print_int((int) int2);
    putchar('\n');
    int2->c = 2;

    int3 = malloc<struct Integer>(sizeof(struct Integer));
    fputs("Addr of int3: ", stdout);
    print_int((int) int3);
    putchar('\n');
    int3->c = 3;

    list_new(int1, struct Integer, l);
    list_insert(int1, int2, struct Integer, l);
    list_insert(int2, int3, struct Integer, l);

    fputs("Testing Iterator\n", stdout);
    int sum = 0;
    ptr<struct Integer> iter = 0;
    list_iter(iter, &(int1->l), struct Integer, l, {
        sum += iter->c;
    })
    fputs("Sum of Integers: ", stdout);
    print_int(sum);
    
    fputs("Addr of ptr int1->l.next: ", stdout);
    print_int((int) int1->l.next);
    putchar('\n');
    fputs("Address of list_get for int1->l.next: ", stdout);
    print_int((int) list_get(int1->l.next, struct Integer, l));
    putchar('\n');

    fputs("Integer in int1->l.next: ", stdout);
    print_int(list_get(int1->l.next, struct Integer, l)->c);
    putchar('\n');
    fputs("List Size: ", stdout);
    print_int(list_size(int1, struct Integer, l));
    putchar('\n');

    fputs("Remove int1->l.next\n", stdout);
    list_remove(int1->l.next, struct Integer, l);

    fputs("Integer in int1->l.next: ", stdout);
    print_int(list_get(int1->l.next, struct Integer, l)->c);
    putchar('\n');
    fputs("List Size: ", stdout);
    print_int(list_size(int1, struct Integer, l));
    putchar('\n');
    fputs("Remove int1->l\n", stdout);
    list_remove(&int1->l, struct Integer, l);

    fputs("List Size: ", stdout);
    print_int(list_size(int3, struct Integer, l));
    putchar('\n');
    fputs("Remove int3->l\n", stdout);
    list_remove(&int3->l, struct Integer, l);
    return 0;
}
