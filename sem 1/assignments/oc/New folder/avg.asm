CODE SEGMENT

    ASSUME CS: CODE DS: DATA

START: 
       MOV AX,2000H     ;Initializing Data Register
       MOV DS,AX
       MOV [500H],0AFH  ;Storing 0AFH value at 500H offset memory location
       MOV AL,[500H]    ;Copying contents of 500H memory location using Direct Addressing mode 
       MOV AH, 00H      ;Setting AH value as 00H
       MOV DH,00H       ;Setting DH value as 00H
       MOV [504H],0FH   ;Storing 0AFH value at 504H offset memory location 
       MOV BX, 0504H    ;Setting BL value as 0FH
       MOV DL,[BX]      ;Indirect addressing 
       ADD AX,DX        ;Adding AX and BX to AX
       MOV CL, 02H      ;MOV 02H value to CL for dividing by 2
       DIV CL           ;Divide AX by CL
       MOV [501H],AX    ;Move AX to memory location [501H]

STOP:  HLT