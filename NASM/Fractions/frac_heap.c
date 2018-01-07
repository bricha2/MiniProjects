/* Name: Brianna Richardson
 * 
 * This is the definition for the frac_heap class.
 *
 */

#include "frac_heap.h"
#include <stdlib.h>
#include <stdio.h>

/* Global Variables */
union fraction_block_u {
  union fraction_block_u *next;
  fraction frac;
};

typedef union fraction_block_u fraction_block;


static fraction_block *free_list;

/*
 * init_heap():
 * must be called once by the program using your
 * functions before calls to any other functions are made. This
 * allows you to set up any housekeeping needed for your memory
 * allocator. For example, this is when you can initialize
 * your free block list.
 */
void init_heap(void) {

  free_list = NULL;

}


/*
 * new_frac():
 * must return a pointer to fractions.
 * It should be an item taken from the list of free blocks.
 * (Don't forget to remove it from the list of free blocks!)
 * If the free list is empty, you need to get more using malloc()
 * (Number of blocks to malloc each time is specified in the project
 * description)
 */
fraction *new_frac(void) {

  if (free_list == NULL) {
    fraction_block *ptr;
    fraction *ret;
    ptr = (fraction_block*) malloc(sizeof(fraction_block)*5);

    /* Never mind this based on Piazza
    if (ptr = NULL) {
      printf("You've run out of memory!");
      break;
      } */

    /* print out that malloc was called */
    printf("\ncalled malloc(%d):returned %p\n\n", sizeof(fraction)*5, ptr);

    /* Create the return pointer */
    ret = &ptr[0].frac;

    /* Loop through the rest of values and link them together */
    free_list = &ptr[1];
    ptr[1].next = &ptr[2];
    ptr[2].next = &ptr[3];
    ptr[3].next = &ptr[4];
    ptr[4].next = NULL;

    return ret;

  } else {
    /* otherwise remove top value and send it */
    fraction_block *fbp;
    fbp = free_list;
    free_list = free_list->next;
    return (&fbp->frac);
  }
}

/*
 * del_frac():
 * takes a pointer to a fraction and adds that item to the free block list.
 * The programmer using your functions promises to never use that item again,
 * unless the item is given to her/him by a subsequent call to new_frac().
 */
void del_frac(fraction *frac) {
  fraction_block *replace;
  
  replace = (fraction_block *) frac;
  replace->next = free_list;
  free_list = replace;

}
/*
 * dump_heap():
 * For debugging/diagnostic purposes.
 * It should print out the entire contents of the free list,
 * printing out the address for each item.
 */
void dump_heap(void) {
  printf("**** Begin Heap Dump ****\n");
  printf("\n");

  fraction_block *current;
  if (free_list == NULL) {
    printf("Free list is empty.\n");
    printf("\n**** End Heap Dump ****\n");

    return;
  }
  current = free_list;
  while (current != NULL) {
    printf("  %p \n", current);
    current = current->next;
  }

  printf("\n");
  printf("**** End Heap Dump ****\n");
}

