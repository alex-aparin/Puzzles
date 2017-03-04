[
   Current program checks whether pattern (5 length) is substring for
   given string (10 length). Check is performed on given 24 statements

   Program memory organization:
   Header : OutCounter 24 | \n 10 | \r 13 | Answer 0 | RawAnswer 0
   InnerCycle Out data : 1 | DiffCounts 0 | LhsOp 0 | RhsOp 0 | Temp
   InnerCycle In data : Counter 5 | str (16 symbs)| pattern (5 symbs)
]

; Header initialization
++++++++++++++++++++++++            ; OutCounter 24
>            ; Jmp to \n
++++++++++    ; Code of new line
>            ; Jmp to \r
+++++++++++++ ; Code of carret return
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
    ; Read str (10 length)
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,>             ; Read delimiter
    ; Read pattern (5 length)
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------>
    ,------------------------------------------------
    <<<<<<<<<<<<<<<< ; Jmp to Counter
   ; Counting substring "including"
   [
       -             ; Decrease counter
;====================================================================
;      COMPARISON OF (0) LETTER
       ; Mov str(0) to left operand
       >             ; Jmp to str(0)
       [
          -          ; Decrease value
          <<<<       ; Jmp to LeftOp
          +          ; Increase LeftOp
          >>         ; Jmp to Temp
          +          ; Increase Temp
          <<         ; Jmp to LeftOp
          >>>>       ; Jmp to str
       ]
       <                              ; Jmp to counter
       ; Mov temp to str(0)
       <                              ; Jmp to Temp
       [
          -                           ; Decrease Temp
          >>                          ; Jmp to str(0)
          +                           ; Increase str(0)
          <<                          ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       ; Mov pattern(0) to right operand and temp
       >>>>>>>>>>>>               ; Jmp to pattern(0)
       [
          -                           ; Decrease value
          <<<<<<<<<<<<                ; Jmp to RightOp
          +                           ; Increase RightOp
          >                           ; Jmp to Temp
          +                           ; Increase Temp
          <                           ; Jmp to RightOp
          >>>>>>>>>>>>                ; Jmp to pattern(0)
       ]
       <<<<<<<<<<<<                   ; Jmp to counter
       ; Mov temp to pattern(0)
       <                              ; Jmp to Temp
       [
            -                         ; Decrease value
            >                         ; Jmp to counter
            >>>>>>>>>>                ; Jmp to pattern(0)
            +                         ; Increase value
            <<<<<<<<<<                ; Jmp to counter
            <                         ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       <<<                            ; Jmp to LeftOp
       ;    Perform eq test and add res to HitCounter
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       >>>                            ; Jmp to Counter
;====================================================================
;      COMPARISON OF (1) LETTER
       ; Mov str(1) to left operand
       >>             ; Jmp to str(1)
       [
          -          ; Decrease value
          <<<<<       ; Jmp to LeftOp
          +          ; Increase LeftOp
          >>         ; Jmp to Temp
          +          ; Increase Temp
          <<         ; Jmp to LeftOp
          >>>>>       ; Jmp to str(1)
       ]
       <<                              ; Jmp to counter
       ; Mov temp to str(1)
       <                              ; Jmp to Temp
       [
          -                           ; Decrease Temp
          >>>                          ; Jmp to str(1)
          +                           ; Increase str(1)
          <<<                          ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       ; Mov pattern(1) to right operand and temp
       >>>>>>>>>>>>>               ; Jmp to pattern(1)
       [
          -                           ; Decrease value
          <<<<<<<<<<<<<<<                ; Jmp to RightOp
          +                           ; Increase RightOp
          >                           ; Jmp to Temp
          +                           ; Increase Temp
          <                           ; Jmp to RightOp
          >>>>>>>>>>>>>>>                ; Jmp to pattern(1)
       ]
       <<<<<<<<<<<<<                   ; Jmp to counter
       ; Mov temp to pattern(0)
       <                              ; Jmp to Temp
       [
            -                         ; Decrease value
            >                         ; Jmp to counter
            >>>>>>>>>>>>>                ; Jmp to pattern(1)
            +                         ; Increase value
            <<<<<<<<<<<<<                ; Jmp to counter
            <                         ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       <<<                            ; Jmp to LeftOp
       ;    Perform eq test and add res to HitCounter
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       >>>                            ; Jmp to Counter
;====================================================================
;      COMPARISON OF (2) LETTER
       ; Mov str(2) to left operand
       >>>             ; Jmp to str(2)
       [
          -          ; Decrease value
          <<<<<<       ; Jmp to LeftOp
          +          ; Increase LeftOp
          >>         ; Jmp to Temp
          +          ; Increase Temp
          <<         ; Jmp to LeftOp
          >>>>>>       ; Jmp to str(2)
       ]
       <<<                              ; Jmp to counter
       ; Mov temp to str(2)
       <                              ; Jmp to Temp
       [
          -                           ; Decrease Temp
          >>>>                          ; Jmp to str(2)
          +                           ; Increase str(2)
          <<<<                          ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       ; Mov pattern(2) to right operand and temp
       >>>>>>>>>>>>>>               ; Jmp to pattern(2)
       [
          -                           ; Decrease value
          <<<<<<<<<<<<<<<<                ; Jmp to RightOp
          +                           ; Increase RightOp
          >                           ; Jmp to Temp
          +                           ; Increase Temp
          <                           ; Jmp to RightOp
          >>>>>>>>>>>>>>>>                ; Jmp to pattern(2)
       ]
       <<<<<<<<<<<<<<                   ; Jmp to counter
       ; Mov temp to pattern(2)
       <                              ; Jmp to Temp
       [
            -                         ; Decrease value
            >                         ; Jmp to counter
            >>>>>>>>>>>>>>                ; Jmp to pattern(2)
            +                         ; Increase value
            <<<<<<<<<<<<<<                ; Jmp to counter
            <                         ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       <<<                            ; Jmp to LeftOp
       ;    Perform eq test and add res to HitCounter
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       >>>                            ; Jmp to Counter
;====================================================================
;      COMPARISON OF (3) LETTER
       ; Mov str(3) to left operand
       >>>>             ; Jmp to str(3)
       [
          -          ; Decrease value
          <<<<<<<       ; Jmp to LeftOp
          +          ; Increase LeftOp
          >>         ; Jmp to Temp
          +          ; Increase Temp
          <<         ; Jmp to LeftOp
          >>>>>>>       ; Jmp to str
       ]
       <<<<                              ; Jmp to counter
       ; Mov temp to str(3)
       <                              ; Jmp to Temp
       [
          -                           ; Decrease Temp
          >>>>>                          ; Jmp to str(3)
          +                           ; Increase str(3)
          <<<<<                          ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       ; Mov pattern(3) to right operand and temp
       >>>>>>>>>>>>>>>               ; Jmp to pattern(3)
       [
          -                           ; Decrease value
          <<<<<<<<<<<<<<<<<                ; Jmp to RightOp
          +                           ; Increase RightOp
          >                           ; Jmp to Temp
          +                           ; Increase Temp
          <                           ; Jmp to RightOp
          >>>>>>>>>>>>>>>>>                ; Jmp to pattern(3)
       ]
       <<<<<<<<<<<<<<<                   ; Jmp to counter
       ; Mov temp to pattern(3)
       <                              ; Jmp to Temp
       [
            -                         ; Decrease value
            >                         ; Jmp to counter
            >>>>>>>>>>>>>>>                ; Jmp to pattern(3)
            +                         ; Increase value
            <<<<<<<<<<<<<<<                ; Jmp to counter
            <                         ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       <<<                            ; Jmp to LeftOp
       ;    Perform eq test and add res to HitCounter
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       >>>                            ; Jmp to Counter
;====================================================================
;      COMPARISON OF (4) LETTER
       ; Mov str(4) to left operand
       >>>>>             ; Jmp to str(4)
       [
          -          ; Decrease value
          <<<<<<<<       ; Jmp to LeftOp
          +          ; Increase LeftOp
          >>         ; Jmp to Temp
          +          ; Increase Temp
          <<         ; Jmp to LeftOp
          >>>>>>>>       ; Jmp to str
       ]
       <<<<<                              ; Jmp to counter
       ; Mov temp to str(4)
       <                              ; Jmp to Temp
       [
          -                           ; Decrease Temp
          >>>>>>                          ; Jmp to str(4)
          +                           ; Increase str(4)
          <<<<<<                          ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       ; Mov pattern(4) to right operand and temp
       >>>>>>>>>>>>>>>>               ; Jmp to pattern(4)
       [
          -                           ; Decrease value
          <<<<<<<<<<<<<<<<<<                ; Jmp to RightOp
          +                           ; Increase RightOp
          >                           ; Jmp to Temp
          +                           ; Increase Temp
          <                           ; Jmp to RightOp
          >>>>>>>>>>>>>>>>>>                ; Jmp to pattern(4)
       ]
       <<<<<<<<<<<<<<<<                   ; Jmp to counter
       ; Mov temp to pattern(4)
       <                              ; Jmp to Temp
       [
            -                         ; Decrease value
            >                         ; Jmp to counter
            >>>>>>>>>>>>>>>>                ; Jmp to pattern(4)
            +                         ; Increase value
            <<<<<<<<<<<<<<<<                ; Jmp to counter
            <                         ; Jmp to Temp
       ]
       >                              ; Jmp to Counter
       <<<                            ; Jmp to LeftOp
       ;    Perform eq test and add res to HitCounter
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       >>>                            ; Jmp to Counter
;====================================================================
       ; Shift string to left by one sym
       >                              ; Jmp to str
       [-]                            ; Clear First Letter
       >[-<+>]>[-<+>]>[-<+>]>[-<+>]>[-<+>]
       >[-<+>]>[-<+>]>[-<+>]>[-<+>]
       <<<<<<<<<                      ; Jmp to str
       <                              ; Jmp to Counter
       ; Mov RawAnswer ~HitCounter
       <<<<<                          ; Jmp to constant
       ;    Perform eq test and add res to RawAnswer
       [-<+>>[-<<->>]<][-<+>]>[-<<+>>]<
       +                              ; Set constant 1
       >>>>>                          ; Jmp to Counter
   ]
   ; Convert RawAnswer to Answer
   <<<<<<                             ; Jmp to RawAnswer
   [
       -                              ; Decrease RawAnswer
       <                              ; Jmp to Answer
       +                              ; Increase Answer
       >                              ; Jmp to RawAnswer
       [-]                            ; Clear RawAnswer
   ]
   <                                  ; Jmp to Answer
   ++++++++++++++++++++
   ++++++++++++++++++++
   ++++++++                           ; Convert Answer to Ascii Num
   .                                  ; Print Answer
   <.                                 ; Jmp to \r and print it
   <.                                 ; Jmp to \n and print it
   <                                ; Jmp to OutCounter
]