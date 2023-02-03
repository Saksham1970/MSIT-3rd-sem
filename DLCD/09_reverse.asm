;This program stores the numbers from 8001 at 9000 in reverse
LXI D, 9000H    ;Destination at 9000H
LXI H, 8000H    ;Count number is stored at 8000
MVI B, 00H      ;Clearing B
MOV C, M        ;Storing count in C register
DAD B          	;Adding rp BC in HL

LOOP: MOV A, M  ;Move number at HL to A
STAX D          ;Store value of A in memory of DE
INX D          	;Increament DE
DCX H           ;Decrement HL
DCR C           ;Decrement C
JNZ LOOP        ;Loop back if C is not 0

HLT             ;Stop