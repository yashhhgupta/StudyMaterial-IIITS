CODE SEGMENT
     ASSUME CS: CODE

START:  MOV AX,2000H
        MOV DS,AX
        MOV [500H],0AFH
        MOV AL,[500H]
        MOV BH,0FH
        SUB AL,BH

STOP:   HLT