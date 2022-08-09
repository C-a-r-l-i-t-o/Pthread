#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N_ITENS 30
int buffer [N_ITENS];

int inicio = 0, final = 0;

void* produtor(){
    int i;

    for (i =0; i< N_ITENS; i++){
    printf("produtor, item= %d\n", i);
    final= (final + 1);
    buffer[final = i];
    sleep (random() %1); // dorme por um tempo aleatorio e permite que o outro execute
 
 }
    return NULL;
}

void* consumidor(){
    int i;

    for (i =0; i< N_ITENS; i++){
    printf("consumidor, item= %d\n", i);
    inicio = inicio +1;
    buffer[inicio] = i;
    sleep (random() %3); // dorme por um tempo aleatorio e permite que o outro execute

 }
    return NULL;
}



int main(){
    int i;

    pthread_t thr_produtor, thr_consumidor; // define duas thread


for(i =0; i< N_ITENS; i++)

        buffer[i] = -1; /*se o consumidor consumir o valor de -1 siginifica que o
 consumidor está na frente do produto e consumiu um valor que ainda não foi produzido*/ 

    pthread_create (&thr_produtor, NULL, produtor, NULL);
    pthread_create (&thr_consumidor, NULL , consumidor, NULL);

    pthread_join (thr_produtor, NULL);
    pthread_join (thr_consumidor, NULL);

}
