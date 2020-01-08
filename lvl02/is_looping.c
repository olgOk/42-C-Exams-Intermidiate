/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:55:33 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 17:55:47 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : is_looping
Expected files   : is_looping.c
Allowed functions:
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

Given the first node of a linked list as parameter, create a function which
returns 1 if the linked list is looping, otherwise 0.

The linked list uses the following structure:

struct s_node {
	int value;
	struct s_node *next;
};

The function must be declared as follows:

int	is_looping(struct s_node *node);


Considerations:

- Be careful: the naive solution won't work on our largest input, you have to
find a solution with better complexity than O(N^2) time (where N is the
number of nodes).
- The values of each node does not matter.

Example 1:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         v
          |         6
           \        |
            \______/

In this case, it should return 1 (at the node 3 begins the loop).

Example 2:

12 -> 150 -> 30 -> 50 -> 345 -> 120
       ^                         |
       |                         v
       |                        200
        \                      /
         \____________________/

In this case, it should return 1 (the loop begins at node 150).

Example 3:

12 -> 150 -> 30 -> 50 -> 345 -> 120

In this case, it should return 0 (no loop begins).

Example 4:

12 -> 19 -> 14
            ^ \
            | |
            \/

In this case, it should return 1 (the loop begins at node 14).

The list may not be modified.*/

struct               s_node
{
       int           value;
	struct s_node *next;
};


int	              is_looping(struct s_node *node)
{
       struct s_node *slow_move = node;
       struct s_node *fast_move = node;

       while(slow_move && fast_move && fast_move->next)
       {
              slow_move = slow_move->next;
              fast_move = fast_move->next->next;
              if (slow_move == fast_move)
                     return (1);
       }
       return (0);
}
