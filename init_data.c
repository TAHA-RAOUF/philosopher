/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:12:03 by moraouf           #+#    #+#             */
/*   Updated: 2025/04/23 16:12:53 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//INIT DIYAL DATA OF PHILO
t_philo **init_philo(t_data *data)
{
    t_philo **philo;
    int i;

    philo = malloc(sizeof(t_philo*) * data->num_philo);
    if (!philo)
    {
        return NULL; // FREE HERE;
        free_philo(philo,data->num_philo);    
    }
    i = 0;
    while(i < data->num_philo)
    {
        philo[i] = malloc(sizeof(t_philo));
        if(!philo[i])
            return NULL;
        philo[i]->id_philo = i;
        philo[i]->last_meal = 0;
        i++;
    }
    return (philo);
}

// INIT DATA INTIAL OF ALL PHILOS
void init_data(int ac,char **av,t_data *data)
{
    data->num_philo = ft_atoi(av[1]);
    data->time_die = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);
    if(ac == 6)
        data->num_phi_eat = ft_atoi(av[5]);
    else
        data->num_phi_eat = -1 ;

    data->philos = init_philo(data);
}



