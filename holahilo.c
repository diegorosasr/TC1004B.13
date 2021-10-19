#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

int saldo;

void * printHola(void *arg){
    char *p = (char *)arg;
    printf("Hola desde hilo %s\n",p);
    pthread_exit(NULL);
}

void * suma100(void *arg){
    int lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    char *s = "Soy un hilo";
    saldo = 0;
    for(int i=0; i < NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,suma100,NULL);
    }

    printf("Saldo final es %d\n",saldo);
    pthread_exit(NULL);
}