//
// Created by James Carr on 22/03/2022.
//

#include <stdlib.h>
#include <printf.h>
#include "queue.h"

Queue *queue_init() {
    Queue *q = malloc(sizeof(Queue));
    q->len = 0;
    q->head = NULL;
    return q;
}

void enqueue(Queue *q, Q_T data) {
    Q_item **p = &q->head;
    Q_item *item = create_q_item(data);
    item->data = data;
    while (*p) {
        p = &(*p)->next;
    }
    *p = item;
    q->len++;
}

int dequeue(Queue *q) {
    if (!queue_size(q)) return -1;  // Error: No items in que.

    Q_item *cur = q->head, *prev;
    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }
    printf("Popping item [ %d ]\n", cur->data);
    free(cur);
    prev->next = NULL;
    q->len--;
}

void print_que(Queue *q) {
    // Queue has items.
    if (q->len) {
        Q_item *p = q->head;
        while (p) {
            printf("%d%s", p->data, p->next ? " -> " : "\n");
            p = p->next;
        }
    } else {
        // Queue has no items.
        printf("Queue Empty.\n");
    }
}

Q_item *create_q_item(Q_T data) {
    Q_item *item = malloc(sizeof(Q_item));
    item->data = data;
    item->next = NULL;
    return item;
}

int queue_size(Queue *q) {
    return q->len;
}
