#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SILLAS 5
sem_t cliente;
sem_t barberos;
sem_t mutex;
int espera=0;

void *barbero()
{
    printf("entra barbero\n");
    int e=0;
    for(e=0;e<=20;e++)
    {
        sem_wait(&cliente);
        sem_wait(&mutex);
        espera=espera-1;
        sem_post(&barberos);
        sem_post(&mutex);
        sleep(1);
        printf("cortar pelo.....\n");
    }
}

void *clientes()
{
    printf("entra cliente\n");
    sem_wait(&mutex);
    if(espera<SILLAS)
    {
        espera=espera+1;
        sem_post(&cliente);
        sem_post(&mutex);
        sem_wait(&barberos);
        sleep(1);
        printf("preparado para recibir corte\n");
    }
    else
    {
        sem_wait(&mutex);
    }
}

int main()
{
    pthread_t cliente1;
    pthread_t cliente2;
    pthread_t cliente3;
    pthread_t barbero1;
    sem_init(&cliente,0,0);
    sem_init(&barberos,0,0);
    sem_init(&mutex,0,1);
    pthread_create(&barbero1,NULL,barbero,NULL);
    pthread_create(&cliente1,NULL,clientes,NULL);
    pthread_create(&cliente2,NULL,clientes,NULL);
    pthread_create(&cliente3,NULL,clientes,NULL);
    pthread_join(barbero1,NULL);
    pthread_join(cliente1,NULL);
    pthread_join(cliente2,NULL);
    pthread_join(cliente3,NULL);
    sem_destroy(&cliente);
    sem_destroy(&barberos);
    sem_destroy(&mutex);
}

