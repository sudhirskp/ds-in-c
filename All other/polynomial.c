#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;

};
void main()
{
    struct node *head=NULL;
    head=malloc(sizeof(struct node));
    struct node *temp=head;
    temp->coeff=4;
    temp->expo=3;
    if(head==NULL)
    {
        head=temp;
        struct node *secnode;
        secnode->coeff=3;
        secnode->expo=2;
        head->next=secnode;
        secnode->next=NULL;

        struct node *third;
        third->coeff=1;
        third->expo=0;
        secnode->next=third;
        third->next=NULL;
        printf("%u\n",secnode->coeff);
        printf("%u\n",secnode->expo);
        printf("%u\n",third->coeff);
        printf("%u\n",third->expo);

        
    }
    printf("%u\n",temp->coeff);
    printf("%u\n",temp->expo);
    printf("%u\n",head->next);

}
