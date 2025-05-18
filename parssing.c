/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:42:06 by moraouf           #+#    #+#             */
/*   Updated: 2025/05/18 20:10:47 by moraouf          ###   ########.fr       */
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
	if(str[i] == '+')
        i++;
    // while(str[i] == 0)
    //     i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result < INT_MIN || result > INT_MAX)
			return -1;
		i++;
	}
    if ((str[i] && (str[i] < '0' || str[i] > '9')) || 
		(!str[i] && !result))
		return (-2);
	return (result * sign);
}

int    ft_parssing(char **av, int ac )
{
    int i;
    int num;
    
    if(ac != 5 && ac != 6)
        return(printf("Invalid Argument Number!\n"),1);
    i = 1;
    while(i < ac)
    {
        num = ft_atoi(av[i]);
        if(num == -1)
            return(printf("Error\nOverflow"),1);
        else if(num == -2)
            return(printf("Eroor\n No digits"),1);
        if((num == 0 || num > MAX_PHILOS) && i == 1)
            return(printf("Eroor\n Number of Philos incorrect"),1);
        i++;
    }
    return(0);
}
    