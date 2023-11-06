/*  My Stack implementation  */

#include "stack.h"
#include <assert.h>

struct s_stack {
    int e;
    int pos;
    MyStack* below;
};

/*  INITIALIZE STACK OBJECT  */
MyStack* s_newStack(void){
    MyStack* s = malloc(sizeof(*s));
    s->e = 0;
    s->pos = -1;
    s->below = NULL;
    return s;
}

/*  PUSH elem TO TOP  */
MyStack* s_push(MyStack* s, int elem){
    if (s->pos == -1){
        s->e = elem;
        s->pos = 0;
        s->below = NULL;
        return s;
    }
    MyStack* s_long = malloc(sizeof(*s_long));
    s_long->e = elem;
    s_long->pos = s->pos+1;
    s_long->below = s;
    return s_long;
}

/*  POP FRONT  */
void s_pop(MyStack* s){
    if (s->pos == -1){
        fprintf(stdout, "\nNOTHING TO POP.\n");
        return;
    }
    if (s->below){
        MyStack* freeme = s->below;
        s->e = s->below->e;
        s->pos = s->below->pos;
        s->below = s->below->below;
        free(freeme);
    } else {
        s->pos = -1;
    }
}

/*  RETURNS THE TOP  */
int s_top(MyStack* s){
    if (s->pos == -1){
        fprintf(stdout, "\nNOTHING ON TOP.\n");
        return 0;
    }
    return s->e;
}

/*  RETURNS SIZE OF STACK  */
int s_size(MyStack* s){
    return s->pos+1;
}

/*  RETURNS 1 IF STACK IS EMPTY, 0 otherwise  */
int s_isEmpty(MyStack* s){
    return s->pos == -1;
}

/*  FREE ALL SPACE USED BY STACK  */
void s_free(MyStack* s){
    while (s->below){
        MyStack* killme = s;
        s = s->below;
        free(killme);
    }
    free(s);
}

/*  PRINT STACK TO stdout  */
void s_print(MyStack* s){
    fprintf(stdout, "TOP --> ");
    while (s && s->pos != -1){
        fprintf(stdout, "%d ", s->e);
        s = s->below;
    }
    fprintf(stdout, " <- BOTTOM\n");
    fflush(stdout);
}