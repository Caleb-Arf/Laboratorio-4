#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int entero;
	struct nodo* next;
};

void insertar_inicio(int dato, struct nodo** head) {
	struct nodo* nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->entero = dato;
	nuevo->next = *head;
	*head = nuevo;
}

void insertar_final(int dato, struct nodo** head) {
	struct nodo* nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->entero = dato;
	nuevo->next = NULL;
	if (*head == NULL) {
		*head = nuevo;
	} else {
		struct nodo* actual = *head;
		while (actual->next != NULL) {
			actual = actual->next;
		}
		actual->next = nuevo;
	}
}

void imprimir_lista(struct nodo* head) {
	struct nodo* actual = head;
	while (actual != NULL) {
		printf("%d -> ", actual->entero);
		actual = actual->next;
	}
	printf("NULL\n");
}

void borrar_nodo(int valor, struct nodo** head) {
	struct nodo* actual = *head;
	struct nodo* anterior = NULL;

	while (actual != NULL && actual->entero != valor) {
		anterior = actual;
		actual = actual->next;

		if (actual == NULL) {
			return;
		}

		if (anterior == NULL) {
			*head = actual->next;
		}	 
		else {
		anterior->next = actual->next;
		}
	}
	free(actual);
}

void liberar_memoria(struct nodo* head) {
	struct nodo* actual = head;
	struct nodo* next;

	while (actual != NULL) {
		next = actual->next;
		free(actual);
		actual = next;
	}
}

void buscar_nodo(struct nodo* head, int valor) {
	struct nodo* actual = head;
	while (actual != NULL && actual->entero != valor) {
		actual = actual->next;
	}
	if (actual != NULL) {
		printf("Valor %d se encuentra en la lista\n", valor);
	} else {
		printf("El valor %d no se encuentra en la lista.\n", valor);
	}
}

void obtener_elemento(struct nodo* head, int posicion) {
	struct nodo* actual = head;
	int valor_actual = 0;
	while (actual != NULL && valor_actual < posicion) {
		if (valor == valor_actual) {
			printf("El elemento en la posición %d es %d.\n", posicion, actual->entero);
			return;
		} 
		actual = actual->next;
		valor_actual++;
	}
	printf("No hay posición %d en la lista.\n", posicion);
}

int main() {
	struct nodo* inicio = NULL;
	insertar_inicio(25, &inicio);
	imprimir_lista(inicio);
	insertar_final(12, &inicio);
	imprimir_lista(inicio);
	borrar_nodo(12, &inicio);
	imprimir_lista(inicio);
	insertar_final(35, &inicio);
	insertar_final(34, &inicio);
	buscar_nodo(inicio, 34);
	imprimir_lista(inicio);
	obtener_elemento(inicio, 2);
	imprimir_lista(inicio);
	liberar_memoria(inicio);
	return 0;
}

