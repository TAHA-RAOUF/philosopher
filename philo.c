/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:15:50 by moraouf           #+#    #+#             */
/*   Updated: 2025/04/22 14:38:23 by moraouf          ###   ########.fr       */
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
        return NULL; // FREE HERE;
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
void init_data(int ac, char **av,t_data *data)
{
    data->num_philo = ft_atoi(av[1]);
    data->time_die = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);   
}
//LOGIQUE OF PHILO PRO 
void *routine()
{
    printf("the thread is created\n");
    return 0;
}


// THE JOIN FUN
void join_philo(t_data *data)
{
    int i = 0;

    while(i < data->num_philo)
    {
        pthread_join(data->philos[i]->thread,NULL);
        i++;
    }
}
// CREATE EACH PHILO
void create_philo(t_data *data)
{
    int i = 0;
    while(i < data->num_philo)
    {
        pthread_create(&data->philos[i]->thread,NULL,routine,data);
        i++;
    }
}


int main(int ac,char **av)
{
    t_data *data;
    
    check_data(av,ac);
    data = malloc(sizeof(t_data));
    init_data(ac,av,data);
    create_philo(data);
    join_philo(data);
}