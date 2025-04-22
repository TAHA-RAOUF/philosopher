/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:16:19 by moraouf           #+#    #+#             */
/*   Updated: 2025/04/22 14:11:14 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H


    
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>






typedef struct  s_philo
{
    pthread_t thread;
    int id_philo;
    time_t last_meal;
    pthread_mutex_t *mutex_left;
    pthread_mutex_t *mutex_right;
    
}   t_philo;


typedef struct s_data
{
    int num_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_phi_eat;
    void *content;
    t_philo **philos;
}        t_data;






int	ft_atoi(const char *str);
int check_data(char **av,int ac );


#endif