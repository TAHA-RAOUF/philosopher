/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:16:19 by moraouf           #+#    #+#             */
/*   Updated: 2025/05/18 18:49:24 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


#include <stddef.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>


#define MAX_PHILOS 200



typedef struct s_data	t_data;
typedef struct s_philo
{
	pthread_t			thread;
	int					id_philo;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		*left_fork;
	int					meals_eaten;
	time_t				last_meal;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					num_phi_eat;
	time_t				start_time;
	time_t				death_time;
	pthread_mutex_t		print;
	t_philo				*philos;
}						t_data;

int						ft_atoi(const char *str);
int                     ft_parssing(char **av, int ac);
void					free_philo(t_philo *philo, int num);
void					init_data(int ac, char **av, t_data *data);
size_t					get_current_time(void);

#endif
