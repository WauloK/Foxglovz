; draw spriteno at location
; c function format: fox_asm_spriteat(*location, spriteno)
  
XDEF _fox_asm_spriteat
_fox_asm_spriteat:
                LD HL,2
                ADD HL,SP               ; skip over return address on stack
                LD A,(HL)               ; A = spriteno
                LD C,A                  ; C = spriteno  **
                INC HL
                INC HL
                LD E,(HL)
                INC HL
                LD D,(HL)               ; DE = fox_asm_spriteat screen location
                PUSH DE
                LD A,(spriteheader+1)
                LD (HEIGHT_COUNTER),A                 
                LD HL,spritedata
                LD A,0h
                CP C
                JR Z,displaysprite      ; if spriteno = 0, just display it
                LD A,(spriteheader+2)  ; Sprite data amount per sprite                
                LD E,A 
sprite_mult:                
                ADD HL,BC
                DEC E
                JR NZ,sprite_mult       ; HL = start of spriteno spritedata 
displaysprite:
                POP BC                  ; BC = fox_asm_spriteat screen location
iterate_height:
                LD A,(spriteheader)     ; sprite width
                LD D,A                  ; D = sprite width
iterate_width:
                LD A,(HL)
                LD (BC),A
                INC HL
                INC BC
                DEC D
                JR NZ,iterate_width     ; Display all sprite data in X dimension
                PUSH HL                 ; Save HL (sprite data position) cos only HL can be used in 16bit adding
                LD HL,0000h
                ADD HL,BC               ; Put screen location into HL
                LD DE,0020h             
                ADD HL,DE               ; Add one screen line down
                LD A,(spriteheader)     ; Sprite width
                LD D,A                  ; D = sprite width
subtract_width:
                DEC HL                  ; Move HL=BC to start of new line
                DEC D
                JR NZ,subtract_width    
                PUSH HL                 ; Save screen location
                POP BC                  ; Restore fox_spriteat screen location
                POP HL                  ; Restore sprite data position
                LD A,(HEIGHT_COUNTER)   ; Sprite height counter
                DEC A 
                LD (HEIGHT_COUNTER),A
                JR NZ,iterate_height
RET

HEIGHT_COUNTER: defb $00
include "sprites.asm"
