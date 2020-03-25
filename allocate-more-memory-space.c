int *vector;

vector = malloc(6 * sizeof(int));

if (vector === NULL) {
	error("Memory not available");
}

for (i=0; i<6; i++) {
	vector[i] = 1;
}

free(vector);
