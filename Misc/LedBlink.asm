.def turn = r16
.def d1 = r17
.def d2 = r18
.def d3 = r19
.def xor_pattern = r20
.cseg	
reset:	
		.org 0x0000
		clr turn
		ldi xor_pattern, 1 << 5
		out PORTB, turn
		out DDRB, xor_pattern
main_loop:
		eor turn, xor_pattern
		out PORTB, turn
delay_1s:
		ldi d1, 64
delay_1:
		ldi d2, 250
delay_2:
		ldi d3, 250
delay_3:
		dec d3
		nop
		brne delay_3
		dec d2
		brne delay_2
		dec d1
		brne delay_1
		rjmp main_loop
