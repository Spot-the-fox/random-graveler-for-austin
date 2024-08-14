/*///////////////////////////////////////////
 The graveler's problem
	Start of project: 14.08.2024 17:56
	Author: Alexander Iakovenko

///////////////////////////////////////////*/

#include <stdio.h>  // Input/output library, for displaying text.
#include <stdlib.h> // Randomness function and seeding.


int main(){  //Main function
	char r0 = 0;   // The number of times the number 0 has been rolled over 231 tries
	char br0 = 0;  // The highest number pulled this way.
	int rand_value;

for(int j = 0; j<1000000000; j++){ // 1 billion rolls of 231d4
	srand(j); //setting seed each roll.
	r0=0;
	for(int i = 0; i<14; i++){ //rolling 224 out of 231 dice.
		/*
			We need to check whether a 1/4 probabily is rolled, all we need is 2 bits:
			00, 01, 10 and 11 are 4 options. And we can choose one.
			Since rand() returns random 32 bits of information, it means that each rand() generates 16 throws for us, each is 2 bits.
			But 231 is not divisible by 16, so the remaining 7 numbers are calculated later.

			We detect if the rolled number is a 00, as it's the easiest to detect. Perform an AND on the 2 bits, and you'll isolate them.
			Now, if it's 00, that means that the whole 32 bits is 0. Which is boolean false. So, we say: NOT, and it being false becomes true.
			Any other number 01, 10, 11 turns from true to false.
		*/
		rand_value = rand();
		if(!(rand_value&0x00000003))r0++;
		if(!(rand_value&0x0000000c))r0++;
		if(!(rand_value&0x00000030))r0++;
		if(!(rand_value&0x000000c0))r0++;
		if(!(rand_value&0x00000300))r0++;
		if(!(rand_value&0x00000c00))r0++;
		if(!(rand_value&0x00003000))r0++;
		if(!(rand_value&0x0000c000))r0++;
		if(!(rand_value&0x00030000))r0++;
		if(!(rand_value&0x000c0000))r0++;
		if(!(rand_value&0x00300000))r0++;
		if(!(rand_value&0x00c00000))r0++;
		if(!(rand_value&0x03000000))r0++;
		if(!(rand_value&0x0c000000))r0++;
		if(!(rand_value&0x30000000))r0++;
		if(!(rand_value&0xc0000000))r0++;
	}
	rand_value = rand();

	if(!(rand_value&0x00000003))r0++; //remaining 7 rolls.
	if(!(rand_value&0x0000000c))r0++;
	if(!(rand_value&0x00000030))r0++;
	if(!(rand_value&0x000000c0))r0++;
	if(!(rand_value&0x00000300))r0++;
	if(!(rand_value&0x00000c00))r0++;
	if(!(rand_value&0x00003000))r0++;
	

	br0 = (r0>br0)?r0:br0; //Records the maximum
	}

	printf("Best roll:%d", br0); //output
	}




