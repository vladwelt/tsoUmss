#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5;

#define PENSANDO 0
#define HAMBRE 1
#define COMIENDO 2

int estado[5];

sem_t mutex;
sem_t s[5];

void *filosofo(int i);
void *filosofo1(int i);
void tomar_tenedor(int i);
void dejar_tenedor(int i);
void probar(int i);

int izq(int i)
{
    return ((i+5-1)%5);
}

int der(int i)
{
    return ((i+1)%5);
}

void *filosofo(int i)
{
    printf("Desperto filosofo %i",i);
    int e=0;
    for(e=0;e<=10;e++)
    {
        printf("pensando %i ....\n",i);
        tomar_tenedor(i);
        fflush(stdout);
        sleep(1);
        printf("comiendo %i ....\n",i);
        fflush(stdout);
        sleep(1);
        dejar_tenedor(i);
    }
}

void *filosofin(int i)
{
    printf("Desperto filosofo %i",i);
    int e=0;
    for(e=0;e<=10;e++)
    {
        printf("pensando %i ....\n",i);
        tomar_tenedor(i);
        fflush(stdout);
        sleep(1);
        printf("comiendo %i ....\n",i);
        fflush(stdout);
        sleep(1);
        dejar_tenedor(i);
    }
}

void tomar_tenedor(int i)
{
    sem_wait(&mutex);
    estado[i]=HAMBRE;
    probar(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
}

void dejar_tenedor(int i)
{
    sem_wait(&mutex);
    estado[i]=PENSANDO;
    probar(izq(i));
    probar(der(i));
    sem_post(&mutex);
}

void probar(int i)
{
    if(estado[i]==HAMBRE && estado[izq(i)] != COMIENDO && estado[der(i)] != COMIENDO)
    {
        estado[i]=COMIENDO;
        sem_post(&s[i]);
    }
}

int main()
{
    pthread_t filosofo0;
    pthread_t filosofo1;
    pthread_t filosofo2;
    pthread_t filosofo3;
    pthread_t filosofo4;
    sem_init(&mutex,0,1);
    sem_init(&s[0],0,0);
    sem_init(&s[1],0,0);
    sem_init(&s[2],0,0);
    sem_init(&s[3],0,0);
    sem_init(&s[4],0,0);
    printf("Iniciando hilos.......\n");
    pthread_create(&filosofo0,NULL,filosofo(0),NULL);
    printf("Iniciando hilo 0\n");
    pthread_create(&filosofo1,NULL,filosofin(1),NULL);
    printf("Iniciando hilo 1\n");
    pthread_create(&filosofo2,NULL,filosofo(2),NULL);
    printf("Iniciando hilo 2\n");
    pthread_create(&filosofo3,NULL,filosofo(3),NULL);
    printf("Iniciando hilo 3\n");
    pthread_create(&filosofo4,NULL,filosofo(4),NULL);
    printf("Iniciando hilo 4\n");
    pthread_join(filosofo0,NULL);
    pthread_join(filosofo1,NULL);
    pthread_join(filosofo2,NULL);
    pthread_join(filosofo3,NULL);
    pthread_join(filosofo4,NULL);
    sem_destroy(&mutex);
    sem_destroy(&s[0]);
    sem_destroy(&s[1]);
    sem_destroy(&s[2]);
    sem_destroy(&s[3]);
    sem_destroy(&s[4]);
}
