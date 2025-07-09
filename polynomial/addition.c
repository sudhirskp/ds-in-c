#include<stdio.h>
#include<stdlib.h>

void polyAdd(struct node* head1, struct node* head2){

    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL){

        if(ptr1->expo == ptr2->expo){

            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link; 
            ptr2 = ptr2->link;
        }
     else if(ptr1->expo > ptr2->expo) {

            head3 = insert(head3, ptr1->coeff, ptr1->expo); 
            ptr1 = ptr1->link;
            }
        else if(ptr1->expo < ptr2->expo) {

            head3 = insert(head3, ptr2->coeff, ptr2->expo); 
            ptr2 = ptr2->link;
        }
    }

    while(ptr1!=NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo); 
        ptr1 = ptr1->link;
    }

    while(ptr2!=NULL) {
        head3 = insert(head3, ptr2->coeff, ptr2->expo); 
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is: "); 
    print(head3);
}