/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:16:19 by moraouf           #+#    #+#             */
/*   Updated: 2025/05/18 14:53:08 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H


    
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <string.h>
#include <time.h>
# include <sys/time.h>




typedef struct s_data   t_data; 
typedef struct  s_philo
{
    pthread_t thread;
    int id_philo;
    pthread_mutex_t right_fork;
    pthread_mutex_t *left_fork;
    int     meals_eaten;
    time_t last_meal;
    t_data *data;
}   t_philo;


typedef struct s_data
{
    int num_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_phi_eat;
    pthread_mutex_t print;
    t_philo *philos;
}        t_data;




int	ft_atoi(const char *str);
int check_data(char **av,int ac );
void free_philo(t_philo *philo, int num);
void init_data(int ac,char **av,t_data *data);
size_t get_current_time(void);

#endif
