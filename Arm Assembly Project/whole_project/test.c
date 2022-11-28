__asm void thema1(int num, char *i_str, char *f_str, int AEM)
{
	PUSH{r4, r5}
	
	ADD r0, r0, r3
	LSL r0, r0, #31
	
loop
	LDRB r3, [r1]
	
	CMP r3, #32
	BEQ space
	
	CMP r3, #47
	BLS exit
	
	CMP r3, #57
	BLS num
	
	CMP r3, #64
	BLS exit
	
	CMP r3, #90
	BLS ABC
	BHI exit
	
ABC
	ADD r3, r3, #32
	B exit
	
space 
	CMP r0, #0
	ADDEQ r1, r1, #1
	BEQ loop
	STRBNE r3, [r2]
	ADDNE r2, r2, #1
	B exit
num
	CMP r0, #0
	MOVEQ r3, "0"
	MOVNE r3, "9"
	
exit
	STRB r3, [r2]
	ADD r1, r1, #1
	ADD r2, r2, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5}
	BX lr
}


int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "VsAB ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	//char date[] = "12-10-20";		// initialize hash
	//char AEM[] = "9743";
	int AEM = 9743;
	int num = 1;
	char str[100];
	thema1(num, string, str, AEM);
	printf("String = %s\n", str);
}
/*__asm void thema1_jun_2021(char *dateofbirth, char *i_str, char *f_str)
{
	PUSH{r4, r5, r6}
	LDRB r4, [r0, #1]
	CMP r4, #45
	
	LDRBNE r5, [r0, #0]
	SUBNE r5, #48
	MOVNE r6, #10
	MULNE r5, r5, r6
	ADDNE r4, r4, r5
	SUB r4, #48
	
loop
	LDRB r3, [r1]
	
	CMP r3, #47
	BLS exit
	
	CMP r3, #57
	BLS num
	
	CMP r3, #64
	BLS exit
	
	CMP r3, #90
	BLS ABC
	
	CMP r3, #96
	BLS exit
	
	CMP r3, #122
	BLS abc
	BHI exit
abc
	CMP r4, #45
	LDRBEQ r3, [r0, #2]
	STRBEQ r3, [r2]
  ADDEQ r2, r2, #1
	LDRBEQ r3, [r0, #3]
	LDRBNE r3, [r0, #3]
	STRBNE r3, [r2]
	LDRBNE r3, [r0, #4]
  ADD r2, r2, #1
	B exit

ABC
  CMP r4, #45
	LDRBEQ r3, [r0, #5]
	STRBEQ r3, [r2]
  ADDEQ r2, r2, #1
	LDRBEQ r3, [r0, #6]
	LDRBNE r3, [r0, #6]
	STRBNE r3, [r2]
	LDRBNE r3, [r0, #7]
  ADD r2, r2, #1
	B exit
num
	ADD r3, r4
	SUB r3, #48
	
	CMP r3, #9
	ADDLS r3, #48
	BLS exit
	
	CMP r3, #19
	MOVLS r5, "1"
	STRBLS r5, [r2]
	ADDLS r2, r2, #1
	ADDLS r3, r3,  #38
	BLS exit
	
	CMP r3, #29
	MOVLS r5, "2"
	STRBLS r5, [r2]
	ADDLS r2, r2, #1
	ADDLS r3, r3,  #28
	BLS exit
	
	CMP r3, #39
	MOVLS r5, "3"
	STRBLS r5, [r2]
	ADDLS r2, r2, #1
	ADDLS r3, r3,  #18
	BLS exit
	
	CMP r3, #49
	MOVLS r5, "4"
	STRBLS r5, [r2]
	ADDLS r2, r2, #1
	ADDLS r3, r3, #8
	
exit 
	STRB r3, [r2]
	ADD r2, r2, #1
	ADD r1, r1, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5, r6}
	BX lr
}

	int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "VsAB ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	char date[] = "12-10-20";		// initialize hash
	char AEM[] = "9743";
	char str[100];
	thema1_jun_2021(date, string, str);
	printf("String = %s\n", str);
}*/
/*__asm void themaA_feb_2021(char *AEM, char *i_str, char *f_str)
{
	PUSH{r4, r5}
	
	MOV r4, #0
	MOV r5, #0
	
loop
	LDRB r3, [r1, r4]
	
	CMP r3, #32
	BEQ space
	//BLS exit
	
	CMP r3, #47
	BLS exit
	
	CMP r3, #57
	BLS num
	
	CMP r3, #96
	BLS exit
	
	CMP r3, #122
	BLS abc
	BHI exit
	
num
	LDRB r6, [r0, #0]
	ADD r3, r3, r6
	SUB r3, r3, #96
	CMP r3, #9
	MOVHI r6, "1"
	STRBHI r6, [r2, r5]
	ADDHI r5, r5, #1
	SUBHI r3, r3, #10
	ADD r3, r3, #48
	B exit

abc
	LDRB r3, [r0, #3]
	B exit
	
space
	MOV r3, "T"
	STRB r3, [r2, r5]
	ADD r5, r5, #1
	MOV r3, "A"
	STRB r3, [r2, r5]
	ADD r5, r5, #1
	MOV r3, "B"

exit
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop 
	POP{r4, r5, r6}
	BX lr
}
	


 int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "VsAB ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	char AEM[] = "9743";		// initialize hash
	char str[100];
	themaA_feb_2021(AEM, string, str);
	printf("String = %s\n", str);
}
*/
/*__asm void themaA_feb_2021(char *AEM, char *i_str, char *f_str){
	PUSH{r4, r5, r6}
	MOV r4, #0
	MOV r5, #0
	
loop
	LDRB r3, [r1, r4]
	
	CMP r3, #32 
	BEQ space
	
	CMP r3, #47 
	BLS exit
	
	CMP r3, #57
	BLS num
	
	CMP r3, #96
	BLS exit
	
	CMP r3, #122
	BLS abc
	BHI exit
	
space
	MOV r3, "T"
	STRB r3, [r2, r5]
	ADD r5, r5, #1
	MOV r3, "A"
	STRB r3, [r2, r5]
	ADD r5, r5, #1
	MOV r3, "B"
  B exit
	
num
	LDRB r6, [r0]
  ADD r3, r3, r6
	SUB r3, r3, #96
	CMP r3, #9
	ADDLS r3, #48
	
	MOVHI r6, "1"
	STRBHI r6, [r2, r5]
	ADDHI r5, r5, #1
	//SUBHI r3, r3, #10   //(-10 + 48 = 38)
	ADDHI r3, r3, 38
	B exit
abc
	LDRB r3, [r0, #3]
	
exit 
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5, r6}
	BX lr
}
 int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "VsAB ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	char AEM[] = "9743";		// initialize hash
	char str[100];
	themaA_feb_2021(AEM, string, str);
	printf("String = %s\n", str);
}*/
/*__asm void themaA_Jun_2021(char *date_of_birth, char *i_str, char *f_str)
{
	PUSH{r4, r5, r6}
	LDRB r6, [r0, #1]
	
	MOV r4, #0
	MOV r5, #0
	
loop
	LDRB r3, [r1, r4]
	
	CMP r3, #47
	BLS exit
	
	CMP r3, #57
	BLS num
	
	CMP r3, #64
	BLS exit
	
	CMP r3, #90
	BLS ABC
	
	CMP r3, #122
	BHI exit
	BLS abc
	
ABC
	CMP r6, #47
	LDRBEQ r3, [r0, #5]
	STRBEQ r3, [r2, r5]
	ADDEQ r5, r5, #1
	LDRBEQ r3, [r0, #6]
	
	LDRBNE r3, [r0, #6]
	STRBNE r3, [r2, r5]
	ADDNE r5, r5, #1
	LDRBNE r3, [r0, #7]
	B exit 
abc
	CMP r6, #47
	LDRBEQ r3, [r0, #2]
	STRBEQ r3, [r2, r5]
	ADDEQ r5, r5, #1
	LDRBEQ r3, [r0, #3]
	
	LDRBNE r3, [r0, #3]
	STRBNE r3, [r2, r5]
	ADDNE r5, r5, #1
	LDRBNE r3, [r0, #4]
	B exit
num 
 CMP r6, #47
	LDRBEQ r3, [r0, #0]
	
	LDRBNE r3, [r0, #0]
	STRBNE r3, [r2, r5]
	ADDNE r5, r5, #1
	LDRBNE r3, [r0, #1]
exit 
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5, r6}
	BX lr
}
 int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "VsAB ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	char date[] = "25/12/01";		// initialize hash
	char str[100];
	themaA_Jun_2021(date, string, str);
	printf("String = %s\n", str);
}
*/
/*__asm void thema4_FEB_2022(char *date, char *i_str, char *f_str)
{
	PUSH{r4, r5, r6}
	MOV r4, #0
	MOV r5, #0
	MOV r6, #0
  LDRB r6, [r0, #4]
	LSL r6, r6, #31

loop
	LDRB r3, [r1, r4]
	
	CMP r3, #47
  BLS exit
  
  CMP r3, #57
  BLS num

  CMP r3, #64
  BLS exit

  CMP r3, #90
	BLS ABC
	
	CMP r3, #172
	BHI exit
	
	CMP r3, #96
	BHI abc
	BLT exit
	
abc
	CMP r6, #0
	ADDEQ r4, r4, #1 /////////////!!!!!!!!
	BEQ loop
	BNE exit
	
ABC
	CMP r6, #0
	ADDNE r4, r4, #1 /////////////!!!!!!!!
	BNE loop
	BEQ exit

num
	CMP r6, #0
	LDRBEQ r3, [r0, #0]
	STRBEQ r3, [r2, r5]
	ADDEQ r5, r5, #1
	LDRBEQ r3, [r0, #1]
	
	LDRBNE r3, [r0, #6]
	STRBNE r3, [r2, r5]
	ADDNE r5, r5, #1
	LDRBNE r3, [r0, #7]
	STRBNE r3, [r2, r5]
	ADDNE r5, r5, #1
	LDRBNE r3, [r0, #8]
	STRBNE r3, [r2, r5]
	ADDNE r5, r5, #1
	LDRBNE r3, [r0, #9]

exit 
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5, r6}
	BX lr
}
 int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "VsAB ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	char date[] = "10/02/2022";		// initialize hash
	char str[100];
	thema4_FEB_2022(date, string, str);
	printf("String = %s\n", str);
}
*/
/*
//Thema A Sep 2021
__asm void themaA_sep_2021(char *AEM, char *i_str, char *f_str)
{
	PUSH{r4, r5}
	MOV r7, #0
	
	LDRB r4, [r0]
	LDRB r6, [r0, #1]
	ADD r4, r4, r6
	LDRB r6, [r0, #2]
	ADD r4, r4, r6
  LDRB r6, [r0, #3]
	ADD r6, r4, r6
	SUB r6, r6, #192
	
 	MOV r4, #0
	MOV r5, #0
	
loop 
	LDRB r3, [r1, r4]
	
	CMP r3, #64
	BLS conv
	
	CMP r3, #90
	BLS exit
	
	CMP r3, #96
	BLS conv
	
	CMP r3, #122
	BHI conv
	BLS exit

conv
	CMP r3, #0 ///////////////////
	BEQ exit /////////////////////
	
  CMP r6, #9
	MOVLS r3, r6
	ADDLS r3, r3, #48
	BLS exit
T1	
	CMP r6, #19
	MOVLS r3, "1"
	STRBLS r3, [r2, r5]
	ADDLS r5, r5, #1
	SUBLS r7, r6, #10
	MOVLS r3, r7
	ADDLS r3, r3, #48
	BLS exit
	
	CMP r6, #29
	MOVLS r3, "2"
	STRBLS r3, [r2, r5]
	ADDLS r5, r5, #1
	SUBLS r7, r6, #20
	MOVLS r3, r7
	ADDLS r3, r3, #48
	BLS exit
	
	CMP r6, #39
	MOVLS r3, "3"
	STRBLS r3, [r2, r5]
	ADDLS r5, r5, #1
	SUBLS r7, r6, #30
	MOVLS r3, r7
	ADDLS r3, r3, #48
	BLS exit

exit
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5}
	BX lr	
}

int main(void){
  char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
  //char string[] = "sA as! ";	// a string to test
	char AEM[5] = "9999";		// initialize hash
	char str[100];
	themaA_sep_2021(AEM, string, str);
	printf("String = %s\n", str);
}
*/
/*
__asm void themaA_sept_2020(int AEM, char *i_str, char *f_str)
{
	PUSH{r4, r5, r6}
	MOV r6, #9000
	MOV r4, #0
	MOV r5, #0
loop_1
	CMP r0, r6
	BHI loop_2
	
	LDRB r3, [r1, r4]
	
	CMP r3, #31
	BLS exit
	
	CMP r3, #32
	BEQ space
	
	CMP r3, #47
	BLS exit
	
	CMP r3, #57
	BLS num
	
	CMP r3, #96
	BLS exit
	
	CMP r3, #122
	BLS abc
	BHI exit
	
abc
	MOV r3, "9"
	B exit

space
	ADD r4, r4, #1
	B loop_1

num 
	SUB r3, r3, #9
	CMP r3, "0"
	MOVLS r3, "0"
	B exit

loop_2
	LDRB r3, [r1, r4]
	
	CMP r3, #31
	BLS exit
	
	CMP r3, #32
	BEQ space_2
	
	CMP r3, #47
	BLS exit
	
	CMP r3, #57
	BLS num_2
	
	CMP r3, #90
	BHI exit
	
	CMP r3, #64
	BHI ABC
	
ABC
	MOV r3, "0"
	B exit

space_2
	STRB r3, [r2, r5]
	ADD r5, r5, #1
	B exit
	
num_2
	ADD r3, r3, "9"
	CMP r3, "9"
	MOVHI r3, "9"

exit
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop_1
	POP{r4, r5, r6}
	BX lr
}
int main(void){
  //char string[] = "abcdefgh ijkl";
  //char string[] = "sA as! ";	// a string to test
	char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
	int AEM = 9743;		// initialize hash
	char str[100];
	themaA_sept_2020(AEM, string, str);
	printf("String = %s\n", str);
}
*/

/*__asm void themaA_June_2020(int num, char *i_str, char *f_str, int AEM)
{
	PUSH{r4, r5}
	MOV r4, #0
	MOV r5, #0

	ADD r0, r0, r3
	LSL r0, r0, #31
	
loop 
	LDRB r3, [r1, r4]
	
	CMP r3, #90
	BHI exit
	
	CMP r3, #31
	BLS exit
	
	CMP r3, #32
	BEQ space
	
	CMP r3, #47
	BLS exit
	CMP r3, #57
	BLS num
	
	CMP r3, #64
	BLS exit
	
  ADD r3, r3, #32
	B exit
	
space 
	CMP r0, #0 //if is 0, number is even
	ADDEQ r4, r4, #1
  BEQ loop
	BNE space_odd

space_odd
	STRB r3, [r2, r5]
	ADD r5, r5, #1
	B exit
	
num
  CMP r0, #0 //if is 0, number is even
	MOVEQ r3, "0"
	MOVNE r3, "9"
  
exit
	STRB r3, [r2, r5]
	ADD r4, r4, #1
	ADD r5, r5, #1
	CMP r3, #0
	BNE loop
	POP{r4, r5}
	BX lr	
}

int main(void){
  char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefgh ijklmnopqrstuvwxyz!@#$%^&**)( ";
  //char string[] = "sA as! ";	// a string to test
	int AEM = 9743;		// initialize hash
	int num = 1;
	char str[100];
	themaA_June_2020(num, string, str, AEM);
	printf("String = %s\n", str);
}
*/
