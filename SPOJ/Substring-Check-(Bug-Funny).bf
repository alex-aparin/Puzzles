[
   Current program checks whether pattern (5 length) is substring for
   given string (16 length). Check is performed on given 24 statements

   Program memory organization:
   Header : OutCounter 24 | \n 10 | \r 13 | Answer 0 | RawAnswer 0
   InnerCycle Out data : 1 | DiffCounts 0 | LhsOp 0 | RhsOp 0 | Temp
   InnerCycle In data : Counter 5 | str (16 symbs)| pattern (5 symbs)
]

; Header initialization
+            ; OutCounter
>            ; Jmp to \n
+++++++++    ; Code of new line
>            ; Jmp to \r
++++++++++++ ; Code of carret return
>            ; Jmp to Answer
>            ; Jmp to RawAnswer
<<<<         ; Jmp to OutCounter
; Program running
[
    -        ; Decrease OutCounter
    >>>>>    ; Jmp to InnerCycle out data
    ; Clear InnerCycle Out data
    [-]+     ; Create constant 1
    >        ; Jmp to DiffCounts
    [-]      ; Mov DiffCounts 0
    >        ; Jmp to LhsOp
    [-]      ; Mov LhsOp 0
    >        ; Jmp to RhsOp
    [-]      ; Mov RhsOp 0
    >        ; Jmp Temp
    [-]      ; Mov Temp 0
    >        ; Jmp to InnerCycle In data
    ; Init InnerCycle In data
    
]