/*  My Queue implementation  */

#include "queue.h"
#include <assert.h>

struct s_queue {
    int e;
    int pos;
    MyQueue* in_front;
};

/*  INITIALIZE QUEUE OBJECT  */
MyQueue* q_newQueue(void){
    MyQueue* q = malloc(sizeof(*q));
    q->e = 0;
    q->pos = -1;
    q->in_front = NULL;
    return q;
}

/*  ENQUEUE elem  */
MyQueue* q_enqueue(MyQueue* q, int elem){
    if (q->pos == -1){
        q->e = elem;
        q->pos = 0;
        q->in_front = NULL;
        return q;
    }
    MyQueue* q_long = malloc(sizeof(*q_long));
    q_long->e = elem;
    q_long->pos = q->pos+1;
    q_long->in_front = q;
    return q_long;
}

/*  DEQUEUE  */
void q_dequeue(MyQueue* q){
    if (q->pos == -1){
        fprintf(stdout, "\nNOTHING TO DEQUEUE.\n");
        return;
    }
    while (q->pos > 1){
        q->pos = q->pos-1;
        q = q->in_front;
    }
    if (q->in_front){
        free(q->in_front);
        q->in_front = NULL;
    } else {
        q->pos = -1;
    }
}

/*  RETURNS THE FIRST ELEMENT IN THE QUEUE  */
int q_front(MyQueue* q){
    if (q->pos == -1){
        fprintf(stdout, "\nQUEUE IS EMPTY.\n");
        return 0;
    }
    while (q->in_front)
        q = q->in_front;
    return q->e;
}

/*  RETURNS SIZE OF QUEUE  */
int q_size(MyQueue* q){
    return q->pos+1;
}

/*  RETURNS 1 IF QUEUE IS EMPTY, 0 otherwise  */
int q_isEmpty(MyQueue* q){
    return q->pos == -1;
}

/*  FREE ALL SPACE USED BY QUEUE  */
void q_free(MyQueue* q){
    while (q->in_front){
        MyQueue* killme = q;
        q = q->in_front;
        free(killme);
    }
    free(q);
}

/*  PRINT QUEUE TO stdout  */
void q_print(MyQueue* q){
    fprintf(stdout, "last-> ");
    while (q && q->pos != -1){
        fprintf(stdout, "%d ", q->e);
        q = q->in_front;
    }
    fprintf(stdout, "<- first\n");
    fflush(stdout);
}