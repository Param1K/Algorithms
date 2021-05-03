/* LIFO */
///////////////////////////////////

#include<stdio.h>
#define STACK_MAX_LEN 10 
typedef struct stack {
    int top;
    int key[STACK_MAX_LEN];
} STACK;

int stackEmpty (STACK *s)
{
    if(s->top <= 0) {
        printf("stack empty\n");
        return 1;
    }
    return 0;
}

int stackFull (STACK *s)
{
    if(s->top >= STACK_MAX_LEN) {
        printf("stack full\n");
        return 1;
    }
    return 0;
}

int push (STACK *s, int key)
{
    if (!stackFull(s)) {
        printf("Adding key %d at TOP %d\n", key, s->top);
        s->key[s->top++] = key;
        return 0;
    }
    return -1;
}

int pop (STACK *s, int *key) 
{
    if (!stackEmpty(s)) {
        *key = s->key[--s->top];
        printf("Stack key %d retrieved frop TOP %d\n", s->key[s->top], s->top);
        return 0;
    }
    return -1;
}

void stackInit (STACK *s) 
{
    s->top = 0;
}

void main () 
{
    int     i = 0;
    int     key = 0;
    STACK   coinSelf;

    stackInit(&coinSelf);
    while(i <= STACK_MAX_LEN) {
        push(&coinSelf, i);
        i++;
    }
    while(i >= 0) {
        pop(&coinSelf, &key);
        i--;
    }
}
