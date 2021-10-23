#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int list_calc() {
    struct node *ptr = NULL, md = NULL, temp, tr;
    int i, s = 0;
    for (i=1; i<8; i+=2){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = i;
        temp->link = ptr;
        ptr = temp;
    }
    while (ptr){
        tr = md;
        md = ptr;
        ptr = ptr->link;
        md->link = tr;
    }
    for (;md;md=md->link)
        s-= md->data;
    return(s);
    
}
