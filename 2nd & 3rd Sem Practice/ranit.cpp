#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int data;
    struct node *next, *prev;
} node;
node *create()
{
    printf("%c Enter the size of the Linked List : ", 254);
    int size;
    scanf("%d", &size);
    node *store = NULL, *head = NULL;
    while (size--)
    {
        printf("Enter the data : ");
        int data;
        scanf("%d", &data);
        node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (!store)
        {
            head = newnode;
            store = newnode;
        }
        else
        {
            store->next = newnode;
            newnode->prev = store;
            store = newnode;
        }
    }
    return head;
}
// display
void display(node *head)
{
    printf("\n \e[4mHEAD\e[0m %c%c ", 45, 16);
    node *temp = head;
    while (temp)
    {
        if (temp->next)
            printf("\e[1m%d\e[0m %c%c%c%c ", temp->data, 45, 16, 17, 45);
        else
            printf("\e[1m%d\e[0m %c%c", temp->data, 45, 16);
        temp = temp->next;
    }
    printf(" \e[4mNULL\e[0m\n"); //\e[4m is a escape sequence to bold and \e[0m for set defalut
}
// size
int size(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        ++count;
    }
    return count;
}
// insertions
node *insert_begin(node *head, int value)
{
    node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return head;
}
node *insert_end(node *head, int value)
{
    node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}
node *insert_after(node *head, int value, int target)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    node *temp = head;
    while (temp && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n\e[1m\e[7m %c %d is not present. \e[0m\e[0m\n", 254, target);
        return head;
    }
    node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = temp->next;
    if (temp->next)
        temp->next->prev = newnode;
    newnode->prev = temp;
    temp->next = newnode;
    return head;
}
node *insert_before(node *head, int value, int target)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    node *temp = head;
    while (temp && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n\e[1m\e[7m %c %d is not present. \e[0m\e[0m\n", 254, target);
        return head;
    }
    node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (temp == head)
    {
        newnode->next = temp;
        newnode->prev = NULL;
        temp->prev = newnode;
        return newnode;
    }
    newnode->next = temp;
    newnode->prev = temp->prev->next;
    temp->prev->next = newnode;
    temp->prev = newnode;
    return head;
}
node *insert_pos(node *head, int value, int pos)
{
    if (pos <= 0 || pos > size(head) + 1)
    {
        printf("\n\e[1m\e[7m %c Invalid Position. \e[0m\e[0m\n", 254);
        return head;
    }
    if (pos == 1)
    {
        head = insert_begin(head, value);
        return head;
    }
    if (pos == size(head) + 1)
    {
        head = insert_end(head, value);
        return head;
    }
    node *temp = head;
    while (--pos && temp)
        temp = temp->next;
    node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev = newnode;
    return head;
}
// search
int search_pos(node *head, int value)
{
    if (head == NULL)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return -1;
    }
    if (head->data == value)
        return 1;
    int pos = 1;
    node *temp = head;
    while (temp && temp->data != value)
    {
        temp = temp->next;
        pos++;
    }
    return temp ? pos : -1;
}
node *search_node(node *head, int value)
{
    if (head == NULL)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return NULL;
    }
    node *temp = head;
    while (temp && temp->data != value)
        temp = temp->next;
    return temp;
}
// deletions
node *delete_begin(node *head)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return head;
}
node *delete_end(node *head)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    if (head->next == NULL)
        return delete_begin(head);
    node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}
node *delete_after(node *head, int target)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    if (!head->next)
    {
        printf("\n\e[1m\e[7m %c Deletion not possible. \e[0m\e[0m\n", 254);
        return head;
    }
    node *temp = head;
    while (temp && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n\e[1m\e[7m %c %d is not found. \e[0m\e[0m\n", 254, target);
        return head;
    }
    temp = temp->next;
    if (!temp)
    {
        printf("\n\e[1m\e[7m %c %d is the last element. So impossible to delete. \e[0m\e[0m\n", 254, target);
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    free(temp);
    return head;
}
node *delete_before(node *head, int target)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    if (head->data == target)
    {
        printf("\n\e[1m\e[7m %c Deletion not possible. \e[0m\e[0m\n", 254);
        return head;
    }
    node *temp = head;
    while (temp && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n\e[1m\e[7m %c %d is not found. \e[0m\e[0m\n", 254, target);
        return head;
    }
    temp = temp->prev;
    if (temp == head)
    {
        return delete_begin(head);
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    free(temp);
    return head;
}
node *delete_node(node *head, int target)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    node *temp = head;
    while (temp && temp->data != target)
        temp = temp->next;
    if (!temp)
    {
        printf("\n\e[1m\e[7m %c %d is not found. \e[0m\e[0m\n", 254, target);
        return head;
    }
    if (temp == head)
        return delete_begin(head);
    if (temp->next == NULL)
        return delete_end(head);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    free(temp);
    return head;
}
node *delete_pos(node *head, int pos)
{
    if (!head)
    {
        printf("\n\e[1m\e[7m %c Linked List is empty. \e[0m\e[0m\n", 254);
        return head;
    }
    if (pos <= 0 || pos > size(head))
    {
        printf("\n\e[1m\e[7m %c Invalid position. \e[0m\e[0m\n", 254);
        return head;
    }
    if (pos == 1)
        return delete_begin(head);
    if (pos == size(head))
        return delete_end(head);
    node *temp = head;
    while (--pos && temp)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    free(temp);
    return head;
}
// reverse

node *reverse(node *head)
{
    if (head == NULL)
        return head;
    node *temp1 = head, *temp2 = NULL;
    while (temp1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        node *s = temp2->prev;
        temp2->prev = temp2->next;
        temp2->next = s;
    }
    head = temp2;
    return head;
}
void searching_list(node *head)
{
    system("cls");
    printf("\nYour current Doubly Linked List is :\n");
    display(head);
    printf("\n");
    printf("%c ENTER 1 : Search for a node's Posiiton \n", 249);
    printf("%c ENTER 2 : Search for a node if that is Present or not \n", 249);
    printf("\nEnter a valid Number : ");
    int take;
    scanf("%d", &take);
    while (take <= 0 || take > 2)
        scanf("%d", &take);
    switch (take)
    {
    case 1:
        printf("Enter value : ");
        int value;
        scanf("%d", &value);
        int idx = search_pos(head, value);
        if (idx == -1)
        {
            printf("\n%c %d is not Present.\n", 254, value);
        }
        else
        {
            printf("\n\e[1m\e[7m %c %d is present at position %d . \e[0m\e[0m\n", 254, value, idx);
        }
        break;
    case 2:
        printf("Enter a value : ");
        scanf("%d", &value);
        node *p = search_node(head, value);
        if (p == NULL)
        {
            printf("\n\e[1m\e[7m %c %d is not found. \e[0m\e[0m\n", 254, value);
        }
        else
        {
            printf("\n\e[1m\e[7m %c %d is found at adress %u \e[0m\e[0m\n", 254, value, p);
        }
        break;
    }
}
int main()
{
    system("cls");
    node *head = create();
    int loop = 1;
    while (loop)
    {
        system("cls");
        printf("\nYour current Doubly Linked List is :\n");
        display(head);
        printf("\n");
        printf("%c ENTER 1 : All types of insertion\n", 249);
        printf("%c ENTER 2 : All types of deletion\n", 249);
        printf("%c ENTER 3 : All types of searching\n", 249);
        printf("%c ENTER 4 : Reverse\n", 249);
        printf("%c ENTER 5 : Count\n", 249);
        printf("%c ENTER 6 : EXIT\n", 249);
        int value;
        printf("\nEnter a valid Number : ");
        scanf("%d", &value);
        while (value <= 0 || value > 6)
            scanf("%d", &value);
        switch (value)
        {
        case 1: // Insertions
            system("cls");
            printf("\nYour current Doubly Linked List is :\n");
            display(head);
            printf("\n");
            printf("%c ENTER 1 : Insert At Begining\n", 249);
            printf("%c ENTER 2 : Insert At End\n", 249);
            printf("%c ENTER 3 : Insert After Given Value\n", 249);
            printf("%c ENTER 4 : Insert Before Given Value\n", 249);
            printf("%c ENTER 5 : Insert At Position\n", 249);
            printf("\nEnter a valid Number : ");
            int take;
            scanf("%d", &take);
            while (take <= 0 || take > 5)
                scanf("%d", &take);
            printf("Enter the value you want to insert : ");
            int val;
            scanf("%d", &val);
            switch (take)
            {
            case 1:
                head = insert_begin(head, val);
                continue;
            case 2:
                head = insert_end(head, val);
                continue;
            case 3:
                printf("Enter the Target value you want to insert after : ");
                int target;
                scanf("%d", &target);
                head = insert_after(head, val, target);
                break;
            case 4:
                printf("Enter the Target value you want to insert Before : ");
                scanf("%d", &target);
                head = insert_before(head, val, target);
                break;
            case 5:
                printf("Enter the position you want to insert : ");
                int idx;
                scanf("%d", &idx);
                head = insert_pos(head, val, idx);
                break;
            }
            break;
        case 2: // deletion content
            system("cls");
            printf("\nYour current Doubly Linked List is :\n");
            display(head);
            printf("\n");
            printf("%c ENTER 1 : Delete First Node\n", 249);
            printf("%c ENTER 2 : Delete Last Node\n", 249);
            printf("%c ENTER 3 : Delete After a Node\n", 249);
            printf("%c ENTER 4 : Delete Before a Node\n", 249);
            printf("%c ENTER 5 : Delete a Node\n", 249);
            printf("%c ENTER 6 : Delete at position\n", 249);
            printf("\nEnter a valid Number : ");
            scanf("%d", &take);
            while (take <= 0 || take > 6)
                scanf("%d", &take);
            switch (take)
            {
            case 1:
                head = delete_begin(head);
                break;
            case 2:
                head = delete_end(head);
                break;
            case 3:
                printf("Enter the Target : ");
                int val;
                scanf("%d", &val);
                head = delete_after(head, val);
                break;
            case 4:
                printf("Enter the Target : ");
                scanf("%d", &val);
                head = delete_before(head, val);
                break;
            case 5:
                printf("Enter the Target : ");
                scanf("%d", &val);
                head = delete_node(head, val);
                break;
            case 6:
                printf("Enter position : ");
                int idx;
                scanf("%d", &idx);
                head = delete_pos(head, idx);
                break;
            }
            break;
        case 3:
            searching_list(head);
            break;
        case 4:
            head = reverse(head);
            continue;
        case 5:
            printf("\n\e[1m\e[7m %c Size of Your Current Linked list is : %d \e[0m\e[0m\n", 254, size(head));
            break;
        case 6:
            loop = 0;
            continue;
        }
        printf("\nPress any key to continue \n");
        getch();
    }
    return 0;
}