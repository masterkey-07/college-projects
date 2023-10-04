.text

.globl	main
main:
    li      $t2,    0

    li      $v0,    5
    syscall 
    move    $t0,    $v0

    bgt     $t0,    30,         lbig


read:
    addi    $t0,    $t0,        -1

    beq     $t0,    -1,         printr

    li      $v0,    5
    syscall 
    move    $t1,    $v0

    bgt     $t1,    50,         notright
    blt     $t1,    1,          notright

    bgt     $t1,    $t2,        bigger

    j       read

bigger:
    move    $t2,    $t1

    j       read

notright:
    li      $v0,    1
    move    $a0,    $t1
    syscall 

    li      $v0,    4
    la      $a0,    toobig2
    syscall 

    j       read


lbig:
    li      $v0,    1
    move    $a0,    $t0
    syscall 

    li      $v0,    4
    la      $a0,    toobig
    syscall 

    j       end

printr:
    blt     $t2,    10,         nivel1

    bge     $t2,    20,         nivel3

    j       nivel2

nivel1:
    li      $v0,    4
    la      $a0,    level1
    syscall 

    j       end

nivel2:
    li      $v0,    4
    la      $a0,    level2
    syscall 

    j       end

nivel3:
    li      $v0,    4
    la      $a0,    level3
    syscall 

    j       end


end:
    li      $v0,    10
    syscall 



.data
toobig: .asciiz ": valor invalido."
toobig2: .asciiz ": velocidade invalida\n"
level1: .asciiz "Maior nivel: velocidade 1"
level2: .asciiz "Maior nivel: velocidade 2"
level3: .asciiz "Maior nivel: velocidade 3"