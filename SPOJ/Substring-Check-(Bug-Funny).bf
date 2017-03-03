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
    >        ; Jmp to Counter
    ; Init InnerCycle In data
    +++++    ; Mov Counter 5
    >        ; Jmp to str
    ,>,>,>,>,>,>,>,>,>,>,>,>,>,>,>, ; Read str (16 length)
    >                ; Jmp to pattern
    ,[-]             ; Read and clear delimiter
    ,>,>,>,>,        ; Read pattern (5 length)
    <<<<<<<<<<<<<<<< ; Jmp to Counter
   ; Counting substring "including"
   [
       -             ; Decrease counter
       ; Mov str(0) to left operand
       >             ; Jmp to str(0)
       [
          -          ; Decrease value
          <<<<       ; Jmp to LeftOp
          +          ; Increase LeftOp
          >>>>       ; Jmp to str
       ]
       <                              ; Jmp to counter
       ; Mov pattern(0) to right operand and temp
       >>>>>>>>>>>>>>>>               ; Jmp to pattern(0)
       [
          -                           ; Decrease value
          <<<<<<<<<<<<<<<<  <<<       ; Jmp to RightOp
          +                           ; Increase RightOp
          >                           ; Jmp to Temp
          +                           ; Increase Temp
          <                           ; Jmp to RightOp
          >>>>>>>>>>>>>>>>  >>>       ; Jmp to pattern(0)
       ]
       <<<<<<<<<<<<<<<<               ; Jmp to counter
       ; Mov temp to pattern(0)
       <                              ; Jmp to Temp
       [
            -                         ; Decrease value
            >                         ; Jmp to counter
            >>>>>>>>>>>>>>>>          ; Jmp to pattern(0)
            +                         ; Increase value
            <<<<<<<<<<<<<<<<          ; Jmp to counter
            <                         ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       <<<                            ; Jmp to LeftOp
       ;    Perform eq test and add res to HitCounter
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       >>>                            ; Jmp to Counter
       ; Shift string to left by one sym
       >                              ; Jmp to str
       >[-<+>]>[-<+>]>[-<+>]>[-<+>]>[-<+>]
       >[-<+>]>[-<+>]>[-<+>]>[-<+>]>[-<+>]
       >[-<+>]>[-<+>]>[-<+>]>[-<+>]>[-<+>]>[-<+>]
       <<<<<<<<<<<<<<<<               ; Jmp to str
       <                              ; Jmp to Counter
   ]
]
