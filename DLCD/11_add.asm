LXI H,2501H	;Put the value of first number into H-L register pair
MOV A,M		;Move value from 2501H to A
INX H		;Increment the H-L register pair
ADD M		;Add value at 2501H (A) and 2502H (M)
STA 2503H	;Store A at 2503 address
HLT		;Stop the execution