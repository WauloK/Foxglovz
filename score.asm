XDEF _drawscore
_drawscore:

         LD    HL,2
         ADD   HL,SP                ; skip over return address on stack
         LD    A,(HL)               ; A = spriteno
         LD    C,A                  ; C = spriteno  **
         INC   HL
         INC   HL
         LD    E,(HL)
         INC   HL
         LD    D,(HL)               ; DE = screen location
         LD    A,C                  ; BC = 5*C
         ADD   A,A
         ADD   A,A
         ADD   A,C
         LD    C,A
         LD    B,0
         LD    HL,numbers
         ADD   HL,BC
         LD    C,5
 
 .SHOWIT
         LDI
         RET PO
         LD A,31
         ADD A,E
         LD E,A
         JP NC, SHOWIT
         INC D
         JP SHOWIT

numbers:
defb $15, $11, $11, $11, $15       ; 0
defb $14, $04, $04, $04, $15       ; 1
defb $15, $01, $04, $10, $15       ; 2
defb $15, $01, $05, $01, $15       ; 3
defb $11, $11, $15, $01, $01       ; 4
defb $15, $10, $15, $01, $15       ; 5
defb $15, $10, $15, $11, $15       ; 6
defb $15, $01, $01, $01, $01       ; 7
defb $15, $11, $04, $11, $15       ; 8
defb $15, $11, $15, $01, $15       ; 9
