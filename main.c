#include "list.c"
#include "list.h"
#include <stdio.h>
#include <string.h>


int main(){
	LIST * List1 = ListCreate();
	printf("List count: %d\n", ListCount(List1));
	printf("Empty Cases:");
	printf("First = 0, empty list %d\n", data(ListFirst(List1)));
	printf("Prev = 0, empty list %d\n", data(ListPrev(List1)));
	printf("Next = 0, empty list %d\n", data(ListNext(List1)));
	printf("Last = 0, empty list %d\n", data(ListLast(List1)));
	printf("Curr = 0, empty list %d\n", data(ListCurr(List1)));
	printf("return 0, nothing removed (empty list) %d\n", ListRemove(List1));
	ListFree(List1, itemFree);
	ListPrint(List1);
	ListConcat(List1, List1);
	ListPrint(List1);
	printf("Searched item (0 returned if does not match): %d\n", ListSearch(List1, comparator, (void *) 5));
	printf("Trim = 0, no tail (list empty) %d\n", ListTrim(List1));
	printf("_________Empty Case Finished____________________\n\n");

	printf("Cases when only 1 element in the array: ");
	printf("Return 0 if added, -1 if not %d\n", ListAdd(List1, (void *) 1));
	printf("Current list1: ");
	ListPrint(List1); //Should Print 1
	ListCount(List1); //Should Print 1
	printf("First: %d\n", data(ListFirst(List1))); //should be 1
	printf("Last: %d\n", data(ListLast(List1))); //should be 1
	printf("Next: %d\n", data(ListNext(List1))); //should be 0
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 0
	printf("Current: %d\n", data(ListCurr(List1))); //should be 1
	printf("Removed Item: %d\n", ListRemove(List1)); //should be 1
	printf("Current list1: ");
	ListPrint(List1); //Should return empty list
	ListInsert(List1, (void *) 2);
	printf("Current list1: ");
	ListPrint(List1); //Should be 2
	printf("Removed Item: %d\n", ListRemove(List1)); //should be 2
	printf("Current list1: ");
	ListPrint(List1); //should be empty list
	ListAppend(List1, (void *) 3);
	printf("Current list1: ");
	ListPrint(List1); //should be 3
	printf("Removed Item: %d\n", ListRemove(List1)); //should be 3
	printf("Current list1: ");
	ListPrint(List1); //should be empty list
	ListPrepend(List1, (void *) 4);
	printf("Current list1: ");
	ListPrint(List1); //should be 4
	printf("Removed Item: %d\n", ListRemove(List1)); //should be 4
	printf("Current list1: ");
	ListPrint(List1); //should be empty list
	ListPrepend(List1, (void *) 5);
	printf("Current list: ");
	ListPrint(List1); //should be 5
	printf("Searched for 5, returned: %d\n", ListSearch(List1, comparator, (void *) 5)); //should be 5
	printf("Searched for 5, (return 0 if not found): %d\n", ListSearch(List1, comparator, (void *) 4)); //should be 0
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 5
	printf("Current list1: ");
	ListPrint(List1); //should be empty list
	ListPrepend(List1, (void *) 6);
	printf("Current list1: ");
	ListPrint(List1); //should be 5
	ListFree(List1, itemFree); //Should remove a list
	printf("Current list1: ");
	ListPrint(List1); //Should be empty
	printf("____________Only 1 element Case Ended______________\n\n");

	printf("Cases when multiple nodes are added: \n");
	ListPrepend(List1, (void *) 1);
	ListPrepend(List1, (void *) 2);
	ListPrepend(List1, (void *) 3);
	printf("Current list1: ");
	ListPrint(List1); //should be 3 2 1
	printf("First: %d\n", data(ListFirst(List1))); //should be 3
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 0
	printf("Next: %d\n", data(ListNext(List1))); //should be 2 
	printf("Next: %d\n", data(ListNext(List1))); //should be 1
	printf("Next: %d\n", data(ListNext(List1))); //should be 0 (NULL)
	printf("Current: %d\n", data(ListCurr(List1))); //should be 1
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 2
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 3
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 0 (NULL)
	printf("Last: %d\n", data(ListLast(List1))); //should be 1
	printf("Next: %d\n", data(ListNext(List1))); //should be 0
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 2
	printf("First: %d\n", data(ListFirst(List1))); //should be 3
	printf("Removed item: %d\n", ListRemove(List1)); //should be 3
	printf("Removed item: %d\n", ListRemove(List1)); //should be 2
	printf("Removed item: %d\n", ListRemove(List1)); //should be 1
	printf("Removed item: %d\n", ListRemove(List1)); //should be 0

	ListAppend(List1, (void *) 1);
	ListAppend(List1, (void *) 2);
	ListAppend(List1, (void *) 3);
	printf("List count: %d\n", ListCount(List1));
	printf("Current list1: ");
	ListPrint(List1); //should be 1 2 3
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 2
	printf("Removed item: %d\n", ListRemove(List1)); //should be 2
	printf("Current: %d\n", data(ListCurr(List1))); //should be 1
	printf("Last: %d\n", data(ListLast(List1))); //should be 1
	printf("Removed item: %d\n", ListRemove(List1)); //should be 3
	printf("Removed item: %d\n", ListRemove(List1)); //should be 1
	printf("Removed item: %d\n", ListRemove(List1)); //should be 0

	ListAdd(List1, (void *) 1);
	ListAdd(List1, (void *) 2);
	ListAdd(List1, (void *) 3);
	printf("Current list1: ");
	ListPrint(List1); //should be 1 2 3
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 3
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 2
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 1
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 0

	ListInsert(List1, (void *) 1);
	ListInsert(List1, (void *) 2);
	ListInsert(List1, (void *) 3);
	printf("Current list1: ");
	ListPrint(List1); //should be 3 2 1
	printf("Search for 3, return: %d\n", ListSearch(List1, comparator, (void *) 3)); //should be 3
	printf("Search for 5, return: %d\n", ListSearch(List1, comparator, (void *) 5)); //should be 0
	ListFree(List1, itemFree);
	printf("Current list1: ");
	ListPrint(List1);	
	printf("_______Multiple nodes Case Finished_____________\n\n");

	printf("Multiple nodes and multiple lists are added: \n");
	ListPrepend(List1, (void *) 1);
	printf("Current list1: ");
    ListPrint(List1); //should be 1
	ListPrepend(List1, (void *) 2);
	printf("Current list1: ");
    ListPrint(List1); //should be 2 1
	ListAppend(List1, (void *) 3);
	printf("Current list1: ");
    ListPrint(List1); //should be 2 1 3
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 1
	ListAdd(List1, (void *) 4);
	printf("Current list1: ");
    ListPrint(List1); //should be 2 1 4 3
	ListInsert(List1, (void *) 5);
	printf("Current list1: ");
    ListPrint(List1); //should be 2 1 5 4 3
	printf("Current: %d\n", data(ListCurr(List1))); //should be 5
	printf("Prev: %d\n", data(ListPrev(List1))); //should be 1
	printf("Searched for 1, returned: %d\n", ListSearch(List1, comparator, (void *) 1)); //should be 1
	printf("Searched for 5, returned: %d\n", ListSearch(List1, comparator, (void *) 5)); //should be 5
	printf("Searched for 2, returned: %d\n", ListSearch(List1, comparator, (void *) 2)); //should be 0
	
	LIST * List2 = ListCreate();
	ListAppend(List2, (void *) 5);
	printf("Current list2: ");
    ListPrint(List2); //should be 5
	ListInsert(List2, (void *) 4);
	printf("Current list2: ");
    ListPrint(List2); //should be 4 5
	ListAdd(List2, (void *) 3);
	printf("Current list2: ");
    ListPrint(List2); //should be 4 3 5
	printf("First: %d\n", data(ListFirst(List2))); //should be 4
	printf("Next: %d\n", data(ListNext(List2))); //should be 3
	printf("Next: %d\n", data(ListNext(List2))); //should be 5
	ListPrepend(List2, (void *) 2);
	printf("Current list2: ");
	ListPrint(List2); //should be 2 4 3 5
	ListAdd(List2, (void *) 1);
	printf("Current list2: ");
	ListPrint(List2); //should be 2 1 4 3 5 
	printf("Searched for 1, returned: %d\n", ListSearch(List2, comparator, (void *) 1)); //should be 1
	printf("Searched for 2, returned: %d\n", ListSearch(List2, comparator, (void *) 2)); //should be 2	

	ListConcat(List1, List2);
	printf("Current list1: "); 
	ListPrint(List1); //should be 2 1 5 4 3 2 1 4 3 5 
	printf("Current list2: ");
	ListPrint(List2); //should be empty list

	ListConcat(List1, List2);
	printf("Current list1: ");
	ListPrint(List1); //should be 2 1 5 4 3 2 1 4 3 5
	ListConcat(List2, List1);
	printf("Current list2: ");
	ListPrint(List2); //should be 2 1 5 4 3 2 1 4 3 5
	ListPrint(List1); //should be empty

	ListFree(List2, itemFree);
	ListPrint(List2); //should be empty
	ListConcat(List1, List2);
	ListPrint(List1); //should be empty

	LIST * List3 = ListCreate();
	ListPrepend(List3, (void *) 1); // 1
	ListAppend(List3, (void *) 2); // 1 2
	ListInsert(List3, (void *) 3); // 1 3 2
	ListAdd(List3, (void *) 4); // 1 3 4 2
	ListAdd(List3, (void *) 5); // 1 3 4 5 2
	printf("First: %d\n", data(ListFirst(List1))); //should be 1
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 2
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 5
	printf("Last: %d\n", data(ListLast(List1))); //should be 4
	printf("Trimed Item: %d\n", ListTrim(List1)); //should be 4
	printf("Removed item: %d\n", ListRemove(List1)); //should be 3
	ListInsert(List3, (void *) 6); // 6 1
	ListAdd(List3, (void *) 7); // 6 7 1
	ListPrepend(List3, (void *) 8); // 8 6 7 1
	printf("Current list3: ");
	ListPrint(List3); //should print 8 6 7 1

    ListAppend(List2, (void *) 70);
	printf("Current list2: ");
    ListPrint(List2); //should be 70
	ListInsert(List2, (void *) 80);
	printf("Current list2: ");
    ListPrint(List2); //should be 80 70
	ListAdd(List2, (void *) 90);
	printf("Current list2: ");
    ListPrint(List2); //should be 80 90 70

    ListConcat(List3, List2);
	printf("Current list3: ");
	ListPrint(List1); //should be 8 6 7 1 80 90 70
	ListConcat(List2, List1);
	printf("Current list2: ");
	ListPrint(List2); //should be 8 6 7 1 80 90 70
	ListFree(List1, itemFree);
	ListPrint(List1); //should be empty
	ListFree(List2, itemFree);
	ListPrint(List2); //should be empty
	ListFree(List3, itemFree);
	ListPrint(List3); //should be empty
	printf("________Multiple Cases Finished___________\n\n");


}

