.text

.globl main


main:
    li      $t1,    0
    li      $t9,    6

read:
    beq     $t9,    0,      end

    addi    $t9,    $t9,    -1

    li      $v0,    5
    syscall 
    move    $t0,    $v0

    blt     $t0,    0,      read

    addi    $t2,    $t1,    1

    move    $t1,    $t2

    j       read

end:
    li      $v0,    1
    move    $a0,    $t1
    syscall 

    li      $v0,    4
    la      $a0,    ans
    syscall 

    li      $v0,    10
    syscall 


.data
ans: .asciiz " valores positivos"