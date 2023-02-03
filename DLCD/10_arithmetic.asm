MVI A,32H	;Move 32H in the accumulator
MVI B,15H	;Move 15H in register B
ADD B		;Add B to A
STA 2000H	;Store A to 2000H location
HLT		;Stop execution