/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:28:44 by moraouf           #+#    #+#             */
/*   Updated: 2025/04/23 16:10:06 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	ft_atoi(const char *str)
{
	unsigned int	i;

	int(result), sign;
	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i
			+ 1] <= '9'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result < INT_MIN || result > INT_MAX)
			return 1;
		i++;
	}
	return (result * sign);
}

int is_num(int ac,char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = 0;
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

int check_data(char **av,int ac )
{
    if(ac != 5 && ac != 6)
    {
        printf("Invalid Arg");
        return(0);
    }
    if(!is_num(ac,av))
    {
        printf("Incorrect arg");
        return(0);
    }
    return 1;
}
void free_philo(t_philo **philo, int num)
{
    int i;

    i = 0;
    while(i <num)
    {
        free(philo[i]);
        i++;
    }
    free(philo);
}