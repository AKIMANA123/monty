,                Read first digit (ASCII)
>+++++++[<------>-]  Subtract 48 to get actual number
,                Read second digit (ASCII)
>+++++++[<------>-]  Subtract 48 to get actual number
<                Move to first number
[                Loop
  >+             Add 1 to second number
  <-             Subtract 1 from first number
]                End loop
>                Move to result
+++++++[<+++++++>-]  Add 48 to convert to ASCII
<.               Print result
