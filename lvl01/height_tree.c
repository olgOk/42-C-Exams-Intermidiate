/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:10:27 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 11:47:47 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : height_tree
Expected files   : height_tree.c
Allowed functions: 
--------------------------------------------------------------------------------

Implement a function to calculate the height of an n-ary tree.

Your should use the following node structure in your code for the n-ary tree:

	struct s_node {
		int           value;
		struct s_node **nodes;
	};

In this struct nodes is a null-terminated array.

Note that the height of a tree is the number of EDGES on the longest path from
the root node to a leaf. A tree with a single node will have a height of 0.

An empty tree should have height -1;

The function must be declared as follows:

	int height_tree(struct s_node *root);

EXAMPLE:

The Input Tree :

	   94
           / \
          /   \
         34   52
        / \	\
       /   \	 \
      1    99	 11
		 /
		/
	       13
Output : 3 */

struct      s_node {
	int     value;
	struct  s_node **nodes;
};

int height_tree(struct s_node *root)
{
    int max;
    int h;
    int i;

    max = 0;
    h = 0;
    if(!root)
        return (-1);
    for (i = 0; root->nodes[i]; i++)
        if ((max = (height_tree(root->nodes[i] + 1)) > h))
            h = max;
    return (h);
}