#include <stdlib.h>
#include <printf.h>

typedef struct list
{
    item_type item;
    struct list next;
} list;

list *search_list(list *l, item_type x)
{
    if (l == NULL) return NULL;

    if (l->item == x)
        return l;
    else
        return search_list(l->next);
}

void insert_list(list **l, item_type x)
{
    list *p;

    p = malloc( sizeof(list) );

    p->item = x;
    p->next = *l;

    *l = p;
}

list *predecessor_list(list *l, item_type x)
{
    if ((l == NULL) || (l->next == NULL)) {
        printf("Error: predecessor sought on null list.\n");
        return(NULL);
    }

    if ((l->next)->item == x)
        return(l);
    else
        return ( predecessor_list(l->next, x) );
}

list *delete_list(list **l, item_type x)
{
    list *p;            /* item pointer */
    list *pred;
    list *search_list(), *predecessor_list();

    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
        if (pred == NULL)
            *l = p->next;
        else
                pred->next = p->next;
        free(p);
    }
}