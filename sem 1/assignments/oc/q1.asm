DATA SEGMENT
    A DB 04H
    B DB 02H
    C DB 06H
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE DS:DATA

START:  MOV AX,DATA

        MOV DS,AX

        MOV AX,0000H

        MOV AL,A

        MOV BL,B

        XOR AL,BL

        MOV BL,C

        AND AL,BL

        MOV BL,A

        OR AL,BL

        MOV [500H],AL

STOP:   NOP
    CODE ENDS
    END START