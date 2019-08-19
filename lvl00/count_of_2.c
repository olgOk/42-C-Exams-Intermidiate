/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:01:12 by vokrut            #+#    #+#             */
/*   Updated: 2019/06/23 12:18:14 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : count_of_2
Expected files   : count_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Implement a function which counts, for a given integer n, the number of 2s
that appear in all the numbers between 0 and n (inclusive).

Your function must be declared as follows:

int    count_of_2(int n);

If n <= 1, the function returns 0;

Examples:

input  = 25
output =  9

because there are 9 2s in (2, 12, 20, 21, 22, 23, 24 and 25)

Note:

the number 22 counts as 2 because it has two 2s, number 202 count as 2, number 22022 count as 4 etc...*/

int     count_of_2(int n)
{
    int k;
    int count;

    if (n <= 1)
        return (0);
    count = 0;
    k = 2;
    while (k <= n)
    {
        if (k / 10 == 2)
            count++;
        if (k % 10 == 2)
            count++;
        k++;
    }
    return (count);
}


/*remove later*/
#include <stdio.h>
int main(void)
{
    printf("%d\n", count_of_2(25)); //9
    printf("%d\n", count_of_2(1)); //0
    printf("%d\n", count_of_2(5)); //1
    printf("%d\n", count_of_2(30)); //13
    return (0);
}    
