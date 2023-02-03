LXI H, 2500H	;Count number is stored at 2500
MOV C, M        ;Storing count in C register
XRA A           ;Clearing A
LOOP:INX H      ;Pointing to next number
CMP M           ;Comparing it to A
JNC SMALLER     ;If Smaller than A ie carry is 0, skip to label
MOV A,M         ;If larger store number to A
SMALLER: DCR C  ;Decrease count
JNZ LOOP        ;If count 0 break loop

STA 2450H       ;Store the largest value at 2450H
HLT             ;Stop