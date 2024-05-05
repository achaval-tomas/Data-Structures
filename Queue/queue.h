/*  My Queue Specification  */

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stdio.h>
#include <stdlib.h>

typedef struct s_queue MyQueue;

/*  INITIALIZE QUEUE OBJECT  */
MyQueue* q_newQueue(void);

/*  ENQUEUE elem  */
MyQueue* q_enqueue(MyQueue* q, int elem);

/*  DEQUEUE  */
void q_dequeue(MyQueue* q);

/*  RETURNS THE FIRST ELEMENT IN THE QUEUE  */
int q_front(MyQueue* q);

/*  RETURNS SIZE OF QUEUE  */
int q_size(MyQueue* q);

/*  RETURNS 1 IF QUEUE IS EMPTY, 0 otherwise  */
int q_isEmpty(MyQueue* q);

/*  FREE ALL SPACE USED BY QUEUE  */
void q_free(MyQueue* q);

/*  PRINT QUEUE TO stdout  */
void q_print(MyQueue* q);

#endif /* QUEUE_HEADER */