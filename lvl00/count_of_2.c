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