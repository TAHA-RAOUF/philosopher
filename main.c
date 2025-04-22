



#include <pthread.h>
#include <stdio.h>


void* foo(void* arg) {
    printf("%s", (char*)arg);
    return NULL;
}

int meals = 0;

pthread_mutex_t mutex;

// hena test diyal mutex 
void *routine()
{
    for(int i = 0;i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        meals++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
	pthread_mutex_init(&mutex,NULL);

    int i = 0;
    // while(i < 2)
    // {
    //     pthread_join(tread,NULL);
    //     pthread_create(&tread,NULL,routine,NULL);
    //     i++;
    // }



    if(pthread_create(&thread1, NULL,routine,NULL) != 0)
            return (0);
    if(pthread_create(&thread2, NULL,routine,NULL) != 0)
            return (0);
    
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    pthread_mutex_destroy(&mutex);
    printf("%d",meals);
        
    // pthread_create(&thread2, NULL, foo,
    //     (void*)"Thread2 is running.");
    
    // pthread_join(thread1,NULL);
    // pthread_join(thread2,NULL);

    return 0;
}
