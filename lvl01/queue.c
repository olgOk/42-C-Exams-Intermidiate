/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:56:57 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 11:48:13 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : queue
Expected files   : queue.c
Allowed functions: malloc free
--------------------------------------------------------------------------------

Implement a queue data structure in C, using the following structures in your 
code:

	struct s_node {
		void *content;
		struct s_node *next;
	};

	struct s_queue {
		struct s_node *first;
		struct s_node *last;
	};


A queue uses FIFO (first-in fist-out) ordering:
	Items are removed from the data structure in the same order that they are added.

Implement 5 functions for the following queue operations:

	- init() : Initialize the queue.
	  The first and last pointers are set to NULL.

	- enqueue(queue, item) : Add an item to the end of the queue.

	- dequeue(queue) : Remove the first item from the queue and return it.
	  If the queue is empty, the function returns NULL.

	- peek(queue) : Return the first item of the queue.
	  If the queue is empty, the function returns NULL.

	- isEmpty(queue) : Return 1 if the queue is empty, 0 otherwise.


These functions must be declared as follows:

	struct s_queue *init(void);

	void enqueue(struct s_queue *queue, void *content);

	void *dequeue(struct s_queue *queue);

	void *peek(struct s_queue *queue);

	int isEmpty(struct s_queue *queue); */
    
#include <stdlib.h>

struct      s_node {
    void    *content;
    struct  s_node *next;
};

struct      s_queue {
    struct  s_node *first;
    struct  s_node *last;
};

struct s_queue *init(void)
{
    struct s_queue  *queue;

    queue = malloc(sizeof(struct s_queue));
    queue->first = NULL;
    queue->last = NULL;
    return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
    struct s_node *last;

    last = malloc(sizeof(struct s_node));
    last->content = content;
    last->next = NULL;
    if (!queue->first)
        queue->first = last;
    if (queue->last)
        queue->last->next = last;
    queue->last = last;
}

void *dequeue(struct s_queue *queue)
{
    void    *content;
    
    if (!queue || !queue->first)
        return (NULL);
    content = queue->first->content;
    queue->first = queue->first->next;

    return (content);
}

void *peek(struct s_queue *queue)
{
    if (!queue->first)
        return (NULL);
    return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
    if (!queue || (!queue->first && !queue->last))
        return (1);
    return (0);
    
}

/*
#include <stdio.h>
int main(void)
{
    struct s_queue  *queue = init();
    char            *content[][1] = {
      "Eins",
      "Zwei",
      "Drei",
      "Vier",
      "Funf"
    };
    for (int i = 0; i < 5; i += 1)
    {
        enqueue(queue, *content[i]);
        printf("Content : %s\n", peek(queue));
        printf("Empty   : %s\n", (isEmpty(queue) ? "yes" : "no"));
    }
    for (int i = 5; i > 0; i -= 1)
    {
        dequeue(queue);
        printf("Content : %s\n", peek(queue));
        printf("Empty   : %s\n", (isEmpty(queue) ? "yes" : "no"));
    }
    return (0);
}
*/
