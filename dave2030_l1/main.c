/*
 -------------------------------------
 File:    main.c
 Project: dave2030_l1
 file description
 -------------------------------------
 Author:  Shyam Dave
 ID:      180332030
 Email:   dave2030@mylaurier.ca
 Version  2020-01-06
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL); // turns standard output buffering off
	int number = 0;
	printf("Enter a number: ");
	scanf("%d", &number);
	printf("The number you entered is %d\n", number);
	return (0);
}
