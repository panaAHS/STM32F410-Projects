#include <stdio.h>
#include <stdint.h>

const uint8_t array[] = {10, 42, 12, 21, 7, 5, 67, 48, 69, 2, 36, 3, 19, 1, 14, 51, 71, 8, 26, 54, 75, 15, 6, 59, 13, 25};

__asm int hash_calculate(const char *string, const uint8_t *array, int *hash)
{

	    PUSH	  {r4, r5}  //Push r4, r5 and lr to stack
		MOV 	  r4, #0 //Temporary hash = 0

start
		LDRB 		r3, [r0]     // Load byte into r3 from memory pointed to by r0

		/*	First we check if r3 is not one of the symbols that we are searching for.
				We will not consider all of the possible cases just yet.	*/

		CMP 		r3, #48     // Compare r3 with '0' - '0' in ASCII -> 48
		BLS 		next        // If r3 is lower or equal to 48, go to next

		CMP 		r3, #90    // Compare r3 with 'Z' - Z in ASCII -> 90
		BHI 		next       // If r3 is higher than 90, go to next

	  /* 	In case it is a number, we have to substract its value from hash.
				To do so, we first add the number 48 (ASCII -> '0') to hash and then substract the value of r3 from hash (r4).
				Only execute the next 2 calculations after CMP if r3=<57.	*/

		CMP			r3, #57   // Compare r3 with '9', '9' in ASCII -> 57
		ADDLS 	r4, #48  // If r3 is lower or equal to 57, add the number 48 to r4
		SUBLS 	r4, r3   // If r3 is lower or equal to 57, substract the number r3 from r4
		BLS 		next     // If r3 is lower or equal to 57, go to next

		// Now we check for the case in which r3 is NOT a capital letter

	    CMP 		r3, #64 // Compare r3, with '@' (the char before 'A') - '@' in ASCII -> 64
		BLS 		next    // If r3 is lower or same than 64, go to next


		/*	Last case: r3 is a capital letter.
				Now we use the array to add to hash.	*/

		SUB 	 r5, r3, #65  // Substract 65 from r3, 65 is 'A' in ASCII
		LDRB 	 r5, [r1, r5]  // Load byte to r5, from memory address r1+r5,
		ADD 	 r4, r5 // Add r5 = array[r3-#65] to hash (r4)



next
		ADD 	r0, r0, #1 // Go to the next byte of the string
		CMP 	r3, #0   // Was r3 zero ?
	  BNE 	start    // If r3 !zero,  go to start
		MOV 	r0, r4   // If r3 was zero, move (r0=hash)
		STR 	r4, [r2] // Store hash (r4) to address [r2]
		POP 	{r4, r5}  // Pop r4, r5 and pc from stack
		BX		lr		// Return from routine

}
int main(void){
	//const char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz!@#$%^&**)(";
    const char string[] = "sAr,PE2! ";	// a string to test
	int hash = 0;		// initialize hash
	//int hash1;

	// call assembly function
	hash_calculate(string, array, &hash);
    //hash1 = hash_calculate(string, array, &hash);

	// Print string to see and hash to check on debug
	printf("String = %s\n", string);
	printf("Hash = %d\n", hash);
	//printf("Hash = %d", hash1);

	///////////////////////////////////////////////////////////////////////////////////////////////
	//	Another way to check on debug, with a string array!
	///////////////////////////////////////////////////////////////////////////////////////////////
	/*printf("\n\n\n");		// Just for the output to look more presentable

	char a[8][10] = {"5", "A", "A5", "h", "h4A", "!", "25ATx0kB", "Test!"};		// initialize a string array with all the strings we want to check

	// check each element of the array a, just like above
	for(int i=0; i<8; i++){

		hash_calculate(a[i], array, &hash);
		printf("String = %s\n", a[i]);
		printf("Hash = %d\n\n", hash);

	}*/
	return 0;
}





