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

void *filosofo_cero()
{
    int i=0;
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

void *filosofo_uno()
{
    int i=1;
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

void *filosofo_dos()
{
    int i=2;
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

void *filosofo_tres()
{
    int i=3;
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

void *filosofo_cuatro()
{
    int i=4;
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
    pthread_t filo0;
    pthread_t filo1;
    pthread_t filo2;
    pthread_t filo3;
    pthread_t filo4;
    sem_init(&mutex,0,1);
    sem_init(&s[0],0,0);
    sem_init(&s[1],0,0);
    sem_init(&s[2],0,0);
    sem_init(&s[3],0,0);
    sem_init(&s[4],0,0);
    //printf("Iniciando hilos.......\n");
    pthread_create(&filo0,NULL,filosofo_cero,NULL);
    //printf("Iniciando hilo 0\n");
    pthread_create(&filo1,NULL,filosofo_uno,NULL);
    //printf("Iniciando hilo 1\n");
    pthread_create(&filo2,NULL,filosofo_dos,NULL);
    //printf("Iniciando hilo 2\n");
    pthread_create(&filo3,NULL,filosofo_tres,NULL);
    //printf("Iniciando hilo 3\n");
    pthread_create(&filo4,NULL,filosofo_cuatro,NULL);
    //printf("Iniciando hilo 4\n");
    pthread_join(filo0,NULL);
    pthread_join(filo1,NULL);
    pthread_join(filo2,NULL);
    pthread_join(filo3,NULL);
    pthread_join(filo4,NULL);
    sem_destroy(&mutex);
    sem_destroy(&s[0]);
    sem_destroy(&s[1]);
    sem_destroy(&s[2]);
    sem_destroy(&s[3]);
    sem_destroy(&s[4]);
}
