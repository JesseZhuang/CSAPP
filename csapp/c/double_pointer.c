#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int value;
    node *next;
};

node *create_list()
{
    int test_values[] = {1, 2, 3, 4, 5};
    node *new_node, *head = NULL;
    int i;

    for (i = 0; i < 5; i++)
    {
        new_node = malloc(sizeof(struct node));
        assert(new_node);
        new_node->value = test_values[i];
        new_node->next = head;
        head = new_node;
    }

    return head;
}

void print_list(const node *head)
{
    for (; head; head = head->next)
        printf("%d ", head->value);
    printf("\n");
}

void destroy_list(node **head)
{
    node *next;

    while (*head)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}

void remove_from_list(int val, node *head)
{
    node *del, **p = &head;

    while (*p && (**p).value != val) // (**p).value == (*p)->value
    {
        int v = (*p)->value;
        printf("temp v address: %p, value: %d\n", &v, v);
        printf("node value: %d, value's address: %p\n", (**p).value, &((**p).value));
        printf("node next pointer's address: %p\n", (**p).next);
        printf("double pointer p address: %p\n", p);
        printf("*p address: %p\n", *p);
        p = &(*p)->next; // alternatively: p = &(**p).next

        // temp v address: 0x7ff7b81615cc, value: 5
        // node value: 5, value's address: 0x7f8e37705a20, address of the int value in node(value 5)
        // node next pointer's address: 0x7f8e37705a10, same as the address of node(value 4)
        // double pointer p address: 0x7ff7b81615e0, points to head, this one varies more often
        // *p address: 0x7f8e37705a20, address of node(value 5), same as the address of the int in there

        // temp v address: 0x7ff7b81615cc, value: 4
        // node value: 4, value's address: 0x7f8e37705a10, address of the int value in node(value 4)
        // node next pointer's address: 0x7f8e37705a00, address of node(value 3)
        // double pointer p address: 0x7f8e37705a28, now points to the next pointer in node(value 5)
        // *p address: 0x7f8e37705a10, address of node(value 4), same as the address of the int in there

        // node address decrement by 16: 0x7f8e37705a20 -> 0x7f8e37705a10
    }

    printf("before deleting\n");
    printf("double pointer p address: %p\n", p); // 0x7f8e37705a18
    printf("*p address: %p\n", *p);              // 0x7f8e37705a00

    if (p)
    { // non-empty list and value was found
        del = *p;
        *p = del->next;
        del->next = NULL; // avoid loitering
        free(del);
    }

    printf("after deleting\n");
    printf("double pointer p address: %p\n", p); // 0x7f8e37705a18, no change
    printf("*p address: %p\n", *p);              // 0x7f8e377059f0, smaller by 16
}

int main(int argc, char **argv)
{
    node *head;

    head = create_list();
    print_list(head); // 5 4 3 2 1

    remove_from_list(3, head);
    print_list(head); // 5 4 2 1

    destroy_list(&head);
    assert(head == NULL);

    return EXIT_SUCCESS;
}
