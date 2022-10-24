/* Implementação de uma tabela de dispersão usando endereçamento aberto,
 * especificamente a sondagem linear. O registro nulo é o 0. */
#include <stdio.h>

// Função de dispersão.
size_t hash(size_t ht_length, unsigned int key) {
	return key % ht_length;
}

// Inserir registro na tabela.
int insert(unsigned int ht[], size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	if (ht[i] == 0) {
		ht[i] = key;
	} else if (ht[i] != key) {
		size_t j = (i + 1) % ht_length;
		while (j != i && ht[j] != 0) {
			j = (j + 1) % ht_length;
		}
		i = (j == i) ? -1 : j;
	}
	return i;
}

// Remover registro da tabela.
int rm(unsigned int ht[], size_t ht_length, unsigned int key) {
	if (key == 0) return -1; // Registro vazio.
							 //
	int i = (int) hash(ht_length, key);
	if (ht[i] == key) {
		ht[i] = 0;
	} else {
		i = -1;
	}
	return i;
}

// Imprimir tabela.
void printHt(unsigned int ht[], size_t ht_length) {
	for (size_t i = 0; i < ht_length; i++) {
		printf("%u ", ht[i]);
	}
	printf("\b");
}

int main() {
	size_t ht_length = 11;
	unsigned int ht[ht_length];

	// a) Inserção dos registros 4, 17, 13, 35, 25, 11, 2, 10, 32.
	unsigned int test[] = { 4, 17, 13, 35, 25, 11, 2, 10, 32 };
	size_t length_test = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < length_test; i++) {
		insert(ht, ht_length, test[i]);
	}
	printHt(ht, ht_length);
	printf("\n");
	
	// // b) Remoção dos registros 25 e 11.
	// rm(ht, ht_length, 25);
	// rm(ht, ht_length, 11);
	// 
	// // c) Inserção dos registros 40 e 3.
	// insert(ht, ht_length, 40); insert(ht, ht_length, 3);

	return 0;
}
