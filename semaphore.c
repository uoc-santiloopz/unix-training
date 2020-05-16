#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


sem_t sync_temps[4];
char *name[4]={"Admissió", "Compressió", "Explosió", "Escapament"};

/* Common code for the four times engine simulator */
void *temps(void *par) {
	int t = (int) par;
	while (1) {
		if (sem_wait(&sync_temps[t]) < 0 ) error();
		printf("%d %s\n", t, name[t]);
		sleep(rand() % 4); /* Retard aleatori */
		if (sem_post(&sync_temps[(t+1)%4]) < 0 ) error();
	}
}

int main() {
	int i;
	pthread_t th[4];

	/* Sincronisme Escapament -> Admissió. Inicialitzat a 1 */
	if (sem_init(&sync_temps[0], 0, 1) < 0 ) error();
	/* Sincronisme Admissió -> Compressió */
	if (sem_init(&sync_temps[1], 0, 0) < 0 ) error();
	/* Sincronisme Compressió -> Explosió */
	if (sem_init(&sync_temps[2], 0, 0) < 0 ) error();
	/* Sincronisme Explosió -> Escapament */
	if (sem_init(&sync_temps[3], 0, 0) < 0 ) error();
	
	/* Children creation */
	for (i=0; i<4; i++)
		if (pthread_create(&th[i], NULL, temps, (void*)i) < 0) error();
	
	/* Wait for children to die (I never thought I would write this) */
	for (i=0; i<4; i++)
		if (pthread_join(th[i], NULL) < 0) error();
	
	return(0);
}