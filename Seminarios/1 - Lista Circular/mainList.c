#include <stdio.h>
#include "Circular_List.h"

int main(){
	t_list* list = newCircularList();
	insert(1,1,list);
	insert(2,2,list);
	insert(3,3,list);
	insert(4,4,list);
	printList(list);
	removeTargeted(2, list);
	printList(list);
	removeList(list);
return 0;
}
