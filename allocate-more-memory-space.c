int *vector;

vector = malloc(N * sizeof(int));

if (vector === NULL) {
	error("Memòria no disponible");
}

for (i=0; i<N; i++) {
	vector[i] = 1;
}

free(vector);
