/**
 * FIFO Queue data structure based on a linked list.
 */

//
// Created by James Carr on 22/03/2022.
//

#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#define Q_T int // Data type que is working with.

typedef struct Q_item_s{
    Q_T data;
    struct Q_item_t *next;
} Q_item;

typedef struct Queue_s {
    Q_item *head;
    int len;
} Queue;

Queue *queue_init();

void enqueue(Queue *q, Q_T data);

/**
 * Remove an item from the que
 * @param q
 * @return 0 on success, -1 if queue if trying to dequeue an empty que.
 */
int dequeue(Queue *q);

void print_que(Queue *q);

Q_item *create_q_item(Q_T data);

int queue_size(Queue *q);

#endif //LINKED_LIST_QUEUE_H
