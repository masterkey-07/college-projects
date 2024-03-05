.text

.globl main


main:
    li      $t3,        0
    li      $t4,        0
    li      $t5,        0
    li      $t6,        0
    li      $t8,        2
    li      $t9,        5

read:
    beq     $t9,        0,      end

    addi    $t9,        $t9,    -1

    li      $v0,        5
    syscall 
    move    $t0,        $v0

    div     $t0,        $t8

    mfhi    $t7

    beq     $t7,        0,      sumeven

    j       sumodd

sumeven:
    addi    $t3,        $t3,    1
    j       compsign

sumodd:
    addi    $t4,        $t4,    1
    j       compsign

compsign:
    bgt     $t0,        -1,     sumpos
    j       sumneg

sumpos:
    addi    $t5,        $t5,    1
    j       read

sumneg:
    addi    $t6,        $t6,    1
    j       read

end:
    li      $v0,        1
    move    $a0,        $t3
    syscall 

    li      $v0,        4
    la      $a0,        even
    syscall 


    li      $v0,        1
    move    $a0,        $t4
    syscall 

    li      $v0,        4
    la      $a0,        odd
    syscall 


    li      $v0,        1
    move    $a0,        $t5
    syscall 

    li      $v0,        4
    la      $a0,        pos
    syscall 


    li      $v0,        1
    move    $a0,        $t6
    syscall 

    li      $v0,        4
    la      $a0,        neg2
    syscall 

    li      $v0,        10
    syscall 


.data

even: .asciiz " valor(es) par(es)\n"
odd: .asciiz " valor(es) impar(es)\n"
pos: .asciiz " valor(es) positivo(s)\n"
neg2: .asciiz " valor(es) negativo(s)"
