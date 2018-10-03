/*
 ============================================================================
 Name        : C_to_python.c
 Author      : loixou
 Version     :
 Copyright   : Your copyright notice
 Description : Fake C file to use in Python
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "C_to_python.h"

void welcome(){
	printf("C --> Would you like a cup of tea?\n");
}

void print_text(char* text){
	printf("C --> %s\n", text);
}

int add(int a, int b){
	return a + b;
}

double sum(int n, double *tab){
	double sum = 0;
	for (int i = 0; i < n; i++){
		sum += tab[i];
	}
	printf("C --> Sum = %lf\n", sum);
	return sum;
}

void square_array(int n, double* ina, double* outa){
	for (int i = 0; i < n; i++){
		outa[i] = ina[i]*ina[i];
	}
}

void init_tab(int n, int** tab){
	printf("C --> Allocating memory for tab\n");
	int* temp_list = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n;i++){
		temp_list[i] = 0;
	}
	*tab = temp_list;
}

int** init_matrix(int n, int* m){
	printf("C --> Allocating memory for matrix\n");
	int** matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n;i++){
		matrix[i] = (int*)malloc(sizeof(int)*m[i]);
		for (int j = 0; j < m[i]; j++){
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void free_tab(int* tab){
	printf("C --> Freeing a table previously allocated\n");
	free(tab);
}

void free_matrix(int n, int* n_el, int** matrix){
	printf("C --> Freeing a matrix previously allocated\n");
	for (int i = 0; i < n; i++){
		free(matrix[i]);
	}
	free(matrix);
}

READ_DATA* init_data(int el){
	READ_DATA* input_data;
	input_data=(READ_DATA*)malloc(sizeof(READ_DATA));

	input_data->nb_elements = el;
	input_data->exists_nb_elements = 1;

	input_data->n = 0;
	input_data->n_el_in_matrix = NULL;
	input_data->matrix = NULL;
	input_data->exists_matrix = 0;

	return input_data;
}

 void free_data(READ_DATA* input_data){
	 if(input_data->exists_matrix){
		 free_matrix(input_data->n, input_data->n_el_in_matrix, input_data->matrix);
	 }

	 free(input_data);
 }
