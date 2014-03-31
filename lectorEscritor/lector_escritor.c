#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
sem_t db;
int rc=0;

void *leer();
void *escribir();


void *leer()
{
    int i=0;
    for(i=0;i<10;i++)
    {
        sem_wait(&mutex);
        rc=rc+1;
        if (rc==1)
        {
            sem_post(&db);
        }
        sem_post(&mutex);
        printf("leendo...\n");
        fflush(stdout);
        sleep(1);
        sem_wait(&mutex);
        rc=rc-1;
        if(rc==0)
        {
            sem_post(&db);
        }
        sem_post(&mutex);
        printf("Datos Leidos\n");
        fflush(stdout);
    }
}

void *escribir()
{
    int i=0;
    for(i=0;i<10;i++)
    {
        printf("inventando datos\n");
        fflush(stdout);
        sem_wait(&db);
        printf("escribiendo....\n");
        fflush(stdout);
        sleep(1);
        sem_post(&db);
    }
}

int main()
{
    pthread_t escritor;
    pthread_t lector;
    sem_init(&mutex,0,1);
    sem_init(&db,0,1);
    pthread_create(&escritor,NULL,escribir,NULL);
    pthread_create(&lector,NULL,leer,NULL);
    pthread_join(escritor,NULL);
    pthread_join(lector,NULL);
    sem_destroy(&mutex);
    sem_destroy(&db);
}
