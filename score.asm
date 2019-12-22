XDEF _drawscore
_drawscore:

         LD    HL,2
         ADD   HL,SP               ; skip over return address on stack
         LD    A,(HL)               ; A = spriteno
         LD    C,A                  ; C = spriteno  **
         INC   HL
         INC   HL
         LD    E,(HL)
         INC   HL
         LD    D,(HL)               ; DE = screen location
         PUSH  DE
         POP   HL   
			LD		A,5
			LD		(counter),A
         LD    A,C
			CP    $00
			LD		DE,numbers
			JR		Z,showit
countit: INC   DE
			INC   DE
			INC   DE
			INC   DE
			INC   DE
			DEC   A   
			JR	   NZ,countit
showit:
			LD	   A,(DE)
			INC	DE
			LD 	(HL),A
			LD	   BC,32			 ; A line's length
			ADD	HL,BC
			LD	   A,(counter)
			DEC	A
			LD	   (counter),A
			JR	   NZ,showit
			RET

counter: defb 0x00

numbers:

   ; 0
   defb $3f, $33, $33, $33, $3f

   ; 1
      defb $3c, $0c, $0c, $0c, $3f

   ; 2
      defb $3f, $03, $0c, $30, $3f

   ; 3
      defb $3f, $03, $0f, $03, $3f
 
   ; 4
      defb $33, $33, $3f, $03, $03

   ; 5
      defb $3f, $30, $0c, $03, $3f

   ; 6
      defb $3f, $30, $3f, $33, $3f

   ; 7
      defb $3f, $03, $03, $03, $03

   ; 8
      defb $3f, $33, $0c, $33, $3f

   ; 9
      defb $3f, $33, $3f, $03, $3f
