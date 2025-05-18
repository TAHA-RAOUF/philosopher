/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:15:50 by moraouf           #+#    #+#             */
/*   Updated: 2025/05/18 18:58:01 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	print_msg(char * str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%s\n", str);
	pthread_mutex_unlock(&philo->data->print);
}

//LOGIQUE OF PHILO PRO 
void *routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    printf("the thread id is :%d\n",philo->id_philo);
    //print_msg("The thread id : %d\n", philo);
    print_msg("The thread %d is eating\n", philo);
    print_msg("The thread %d is thinking\n", philo);
    print_msg("The thread %d is sleeping\n", philo);
    return NULL;
}


// THE JOIN FUN
void join_philo(t_data *data)
{
    int i = 0;

    while(i < data->num_philo)
    {
        pthread_join(data->philos[i].thread, NULL);
        i++;
    }
}
// CREATE EACH PHILO

void create_philo(t_data *data)
{
    int i = 0;
    while(i < data->num_philo)
    {
        pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]);
        i++;
    }
}




int main(int ac,char **av)
{
    t_data data;
    
    if(ft_parssing(av,ac) == 1)
        return (1);
    memset(&data,'0',sizeof(t_data));
    //data = malloc(sizeof(t_data)); // replace with bzero HERE
    init_data(ac, av, &data);
    create_philo(&data);
    join_philo(&data);
    //free_philo(data.philos,data.num_philo);   // FREE of all Falasifa 
    free(data.philos);
}
