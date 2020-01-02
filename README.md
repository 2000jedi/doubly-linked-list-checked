# Doubly Linked List Checked
Reimplementing 2000jedi/doubly-linked-list with Checked-C

**Note**: Be sure to change the CC variable (to identify the clang version) to the checked c version of clang!

## Research Result

It turns out that due to checked c does not support pointer arithmetics, it is hard to implement this piece without any adjustment. Mainly, a pointer and a `size_t` variable are added to store the lower and upper bound of the element.

The general result is a 100\% memory overhead of the linked list head structure, which makes it unsuitable and unwise for implementation. Perhaps it is better to use generics to compile a doubly linked list separately with different structures for C instead of this workaround with macros.

### Overhead

Implementing a doubly linked list with checked c possesses an overhead of one pointer and a `size_t` variable per list element. This overhead stores the pointer and the bounds for the element that is linked. But since the original structure only contains two pointers, this would be nearly a **100\%** space (memory) overhead!
