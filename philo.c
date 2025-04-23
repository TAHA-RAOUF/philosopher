/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:15:50 by moraouf           #+#    #+#             */
/*   Updated: 2025/04/23 16:12:48 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



//LOGIQUE OF PHILO PRO 
void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    printf("The thread id : %d\n", philo->id_philo);
    printf("The thread is eating\n");
    printf("The thread is thinking\n");
    printf("The thread is sleeping\n");

    return NULL;
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
        pthread_create(&data->philos[i]->thread, NULL, routine, data->philos[i]);
        i++;
    }
}



int main(int ac,char **av)
{
    t_data *data;
    
    if(!check_data(av,ac))
        return 1;
    data = malloc(sizeof(t_data));
    init_data(ac,av,data);
    create_philo(data);
    join_philo(data);
    free_philo(data->philos,data->num_philo);   // FREE of all Falasifa 
    free(data);
}