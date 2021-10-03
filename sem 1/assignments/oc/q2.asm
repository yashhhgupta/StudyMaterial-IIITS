DATA SEGMENT
    X DW 0007H
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE DS:DATA

START:  MOV AX,DATA

        MOV DS,AX

        MOV AX,X

        MOV BL,02H

        DIV BL

        CMP AH,00H

        JNZ ODD;jump if not zero

        MOV [500H],00H

        JZ STOP;jump if zero

ODD:    MOV BX,0500H

        MOV [BX],01H

STOP:   NOP

    CODE ENDS
    END START