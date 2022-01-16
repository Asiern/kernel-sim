#include "process.h"

/* GLOBALS */
unsigned long last_id;
sem_t proc_queue_sem;
pthread_mutex_t queue_mtx;
machine m;
queue q;

/**
 * @brief Initialize queue
 * @param q queue pointer
 * @param size queue size
 * @return (void)
 */
void init_queue(void)
{
    q = *(queue*)malloc(sizeof(queue));
    q.count = -1;
    q.first = NULL;
    q.last = NULL;
}

/**
 * @brief Add pcb at queue end
 * @param q queue pointer
 * @param item pcb pointer
 * @return (void)
 */
void addItem(pcb* item)
{
    queue_node* curr = q.first;
    queue_node* node = (queue_node*)malloc(sizeof(queue_node));
    node->item = item;
    node->next = NULL;
    if (curr == NULL)
    {
        q.first = node;
        q.last = node;
        q.count = 1;
    }
    else
    {
        q.last->next = node;
        q.last = node;
        q.count++;
    }
}

/**
 * @brief Pop first queue item
 * @return first pcb at queue
 */
pcb* pop_queue(void)
{
    pcb* item;
    item = q.first->item;
    queue_node* old = q.first;
    q.first = q.first->next;
    q.count--;
    free(old);
    return item;
}

/**
 * @brief
 * @return
 */
int isQueueFull()
{
    if (q.count == queue_size)
        return 0;
    return 1;
}

/**
 * @brief Enqueue item and return first
 * @param item
 * @return
 */
pcb* replaceItem(pcb* item)
{
    pcb* first = q.first->item;
    q.first = q.first->next;
    queue_node* last = (queue_node*)malloc(sizeof(queue_node));
    last->next = NULL;
    last->item = item;
    q.last->next = last;
    q.last = last;
    return first;
}

void print_queue()
{
    queue_node* n = q.first;
    int id = 0;
    while (n->next != NULL)
    {
        printf("[QUEUE] Node %d, pid: %ld\n", id, n->item->pid);
        id++;
        sleep(2);
    }
}