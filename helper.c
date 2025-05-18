/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:28:44 by moraouf           #+#    #+#             */
/*   Updated: 2025/05/18 20:13:41 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int is_num(int ac,char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = ft_atoi(av[i]);
        if(j <= 0)
            return 0;
        while(av[i][j])
        {
            if(!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

size_t get_current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        write(2, "error at the gettimeofday", 22);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
