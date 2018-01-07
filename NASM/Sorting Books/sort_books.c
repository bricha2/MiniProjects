/* Brianna Richardson
 * This is the main file which intakes books and compares them
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book.h"

/*
 * Declarations for functions that are defined in other files
 */

extern int bookcmp(const struct book*, const struct book*);

/*
 * sort_books(): receives an array of struct book's, of length
 * numBooks.  Sorts the array in-place (i.e., actually modifies
 * the elements of the array).
 *
 * This is almost exactly what was given in the pseudocode in
 * the project spec--need to replace STUBS with real code
 */
typedef int (* func_ptr) (const void *, const void *);
void sort_books(struct book books[], int numBooks) {
  qsort(books, 31, sizeof(struct book), (func_ptr) &bookcmp);

}
