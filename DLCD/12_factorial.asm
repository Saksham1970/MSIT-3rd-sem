;Store the number whose factorial to be found in 2000H
XRA A           ;Clear A
LXI H, 2000H    ;The number whose factorial to be found stored at 2000H
MOV B, M        ;B is taken as register which keeps the count of iterations
MOV D, B        ;D is taken as register which keeps the sum 
DCR B            
MOV C, B        ;The next number is stored in C

LOOP: ADD D     ;Multiplies B and D by summation
DCR B
JNZ LOOP
                ;A has B*D
MOV D, A        ;Stores the sum in D
XRA A           ;Clear A
DCR C           ;Decreasing to the next number in factorial
MOV B, C        
JNZ LOOP
                ;D has the factorial 
INX H           ;Point to 2001H
MOV M, D        ;Store the value at 2001H
HLT             ;Stops the program