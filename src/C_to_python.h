/*
 * C_to_python.h
 *
 *  Created on: 01 oct. 2018
 *      Author: loixou
 */

#ifndef C_TO_PYTHON_H_
#define C_TO_PYTHON_H_
#include <stdio.h>
#include <stdlib.h>



typedef struct READ_DATA{

	int nb_elements;
	int exists_nb_elements;

	int** matrix;
	int* n_el_in_matrix;
	int n;
	int exists_matrix;

}READ_DATA;


void welcome();
void print_text(char* text);

int add(int a, int b);
double sum(int n, double *tab);
void square_array(int n, double* ina, double* outa);

void init_tab(int n, int** tab);
int** init_matrix(int n, int* m);
void free_tab(int* tab);
void free_matrix(int n, int* n_el, int** matrix);

READ_DATA* init_data(int el);
void free_data(READ_DATA* input_data);

#endif /* C_TO_PYTHON_H_ */
