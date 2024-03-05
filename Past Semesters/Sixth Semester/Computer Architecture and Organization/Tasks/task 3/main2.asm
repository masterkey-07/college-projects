.text

.globl	main
main:
    li      $v0,            5
    syscall 
    move    $t0,            $v0

    blt     $t0,            1,              finalnaovalido
    bgt     $t0,            30,             finalnaovalido

    li      $t1,            0

    addi    $t1,            $t1,            1

    li      $v0,            5
    syscall 
    move    $t2,            $v0


    blt     $t2,            1,              continuarexecucao2
    bgt     $t2,            50,             continuarexecucao2

    j       loop

continuarexecucao2:
    li      $v0,            1
    move    $a0,            $t2
    syscall 

    li      $v0,            4
    la      $a0,            velinvalida
    syscall 


    addi    $t1,            $t1,            1

    li      $v0,            5
    syscall 
    move    $t2,            $v0

    beq     $t0,            $t1,            exit

    blt     $t2,            1,              continuarexecucao2
    bgt     $t2,            50,             continuarexecucao2

    j       loop

loop:
    li      $v0,            5
    syscall 
    move    $t3,            $v0

    blt     $t3,            1,              continuarexecucao3
    bgt     $t3,            50,             continuarexecucao3
    bge     $t3,            $t2,            t3maior

contiuarloop:
    addi    $t1,            $t1,            1
    beq     $t0,            $t1,            exit
    j       loop

continuarexecucao3:
    li      $v0,            1
    move    $a0,            $t3
    syscall 

    li      $v0,            4
    la      $a0,            velinvalida
    syscall 

    li      $v0,            5
    syscall 
    move    $t3,            $v0

    addi    $t1,            $t1,            1

    beq     $t0,            $t1,            exit
    blt     $t3,            1,              continuarexecucao3
    bgt     $t3,            50,             continuarexecucao3
    j       loop
t3maior:
    move    $t2,            $t3
    j       contiuarloop


exit:
    blt     $t2,            10,             nivel1
    bge     $t2,            20,             nivel3
    j       nivel2

nivel1:
    li      $v0,            4
    la      $a0,            nivelvel1
    syscall 
    j       exit2
nivel2:
    li      $v0,            4
    la      $a0,            nivelvel2
    syscall 
    j       exit2
nivel3:
    li      $v0,            4
    la      $a0,            nivelvel3
    syscall 
    j       exit2


finalnaovalido:
    li      $v0,            1
    move    $a0,            $t0
    syscall 

    li      $v0,            4
    la      $a0,            Lerrado
    syscall 
    j       exit2

exit2:
    li      $v0,            10
    syscall 

.data
velinvalida:	.asciiz	": velocidade invalida\n"
nivelvel1:	.asciiz	"Maior nivel: velocidade 1"
nivelvel2:	.asciiz	"Maior nivel: velocidade 2"
nivelvel3:	.asciiz	"Maior nivel: velocidade 3"
Lerrado:     .asciiz ": valor invalido."