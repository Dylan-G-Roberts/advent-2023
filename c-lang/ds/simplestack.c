#include <stdio.h>

#define MAX_STACK 10

typedef struct stack
{
    int index;
    char stack[MAX_STACK];
} stack;

char pop_stack(stack *s)
{
   if (s->index < 0) {
       return '\0';
   }

    return s->stack[s->index--];
}

void put_stack(stack *s, char c)
{
    if (s->index >= MAX_STACK - 1)
        printf("Error: stack is full\n");
    else
        s->stack[++s->index] = c;
}

struct stack make_stack()
{
    struct stack tmp;
    tmp.index = 0;

    return tmp;
}

int main() {
    struct stack s = make_stack();

    put_stack(&s, ')');
    put_stack(&s, '(');

    int balanced = 0;
    char c;
    while ((c = pop_stack(&s)) != '\0') {
        if (c == '(')
            balanced++;
        if (c == ')')
            balanced--;
    }

    if (balanced == 0)
        printf("balanced\n");
    else
        printf("no way bucko\n");

    return 0;
}