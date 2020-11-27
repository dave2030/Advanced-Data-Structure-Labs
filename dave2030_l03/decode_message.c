/*
 -------------------------------------
 File:    decode_message.c
 Project: dave2030_l03
 file description
 -------------------------------------
 Author:  Shyam Dave
 ID:      180332030
 Email:   dave2030@mylaurier.ca
 Version  2020-01-25
 -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//===================== GLOBAL MACRO DEFINITIONS ==========================================================

#define  cNUL     '\0'          // NULL character
#define  sNUL     "\0"          // NULL String
#define  cBlank   ' '           // Blank character
#define  sBlank   " "           // Blank String
#define  cUScore  '_'           // Underscore character
#define  sUScore  "_"           // Underscore string.

// Define machine-independent TRUE and FALSE values
#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)
// ======================== Statement Function Definitions.
#define  F_MIN(v1,v2) (((v1) <  (v2))? (v1):(v2))        // Return the less    of v1 and v2
#define  F_MAX(v1,v2) (((v1) >  (v2))? (v1):(v2))        // Return the greater of v1 and v2
#define ZF_MIN(v1,v2) (F_MAX(0, (F_MIN((v1),(v2)))))     // Like F_MIN, but lower bounds the result at ZERO
#define ZF(v)         (F_MAX(0, (v)))                    // Lower bounds the value "v" at ZERO.
#define  F_NOT(v)     (((v) == TRUE)? FALSE:TRUE)        // Logical Negation.
#define  F_ABS(v)     (((v) >= 0   )? (v):(-(v)))        // Absolute value

//====================== GLOBAL CONSTANTS ==================================================================
#define MAX_NUM_ROWS     5           // Max. number of rows.
#define MAX_NUM_COLS     6           // Max. number of columns.
#define MAX_KEY_PAIRS   12           // Max. number of [row, col] key pairs.

int main(int argc, char *argv[]) {
//==============================
	setbuf(stdout, NULL);
	// Turns standard output buffering off
	// "scrambled" - 2D Character Array storing adhoc characters.
	char scrambled[MAX_NUM_ROWS][MAX_NUM_COLS] = { { "zevk83" }, { "Ju96Tp" }, {
			"b2o7If" }, { "lx0D4U" }, { "p_Q_cR" } };
	// "Key" - 2D Integer Array storing the message key pairs [row, col].
	//         Note: The range of the row, col pair values stored in the "key"
	//               array is as shown below:
	//               [row, col] ==> [1...5, 1...6], not [0...4, 0...5]!!!
	int key[MAX_KEY_PAIRS][2] = { { 3, 5 }, { 5, 2 }, { 4, 1 }, { 3, 3 },
			{ 1, 3 }, { 1, 2 }, { 5, 4 }, { 5, 5 }, { 2, 6 }, { 3, 2 },
			{ 2, 4 }, { 4, 5 } };
	int i, row, col;
	int *kp = &key[0][0];
	char temp[] = { cNUL, cNUL };
	char message[MAX_KEY_PAIRS] = sNUL;
	for (i = 0; i < 24; i += 2) {
		row = *(kp + i);
		col = *(kp + i + 1);
		if (scrambled[row - 1][col - 1] == cUScore)
			temp[0] = cBlank;
		else
			temp[0] = scrambled[row - 1][col - 1];
		strcat(message, temp);
	}
	printf(message);
}
