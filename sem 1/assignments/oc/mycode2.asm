CODE SEGMENT
    ASSUME CS: CODE
START:
      MOV AL,20H       ;initializing AL with 20H
      MOV [500H],11H   ;initilaizing memory space [500h] with 11H
      ADD AL, [500H]   ;adding value of AL with value of [500H]
     
STOP: HLT