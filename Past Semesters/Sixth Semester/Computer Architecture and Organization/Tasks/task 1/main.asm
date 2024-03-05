# victor jorge carvalho chaves

.text

.globl	main
main:
    lw      $t5,    divisor
    li      $v0,    5
    syscall 

    move    $t0,    $v0
    li      $v0,    5
    syscall 

    move    $t1,    $v0
    li      $v0,    5
    syscall 

    move    $t6,    $v0

    sub     $t2,    $t0,        $t1

    bltz    $t2,    negative

    move    $t3,    $t2
    j       math

negative:
    neg     $t3,    $t2

math:
    add     $t0,    $t0,        $t1
    add     $t0,    $t0,        $t3
    div     $t0,    $t5
    mflo    $t4

    sub     $t7,    $t6,        $t4

    bltz    $t7,    negative2

    move    $t8,    $t7
    j       math2

negative2:
    neg     $t8,    $t7

math2:
    add     $t6,    $t6,        $t4
    add     $t6,    $t6,        $t8
    div     $t6,    $t5
    mflo    $t9

    li      $v0,    4
    la      $a0,    maior
    syscall 

    li      $v0,    1
    move    $a0,    $t9
    syscall 

    li      $v0,    10
    syscall 

.data
divisor:    .word  2
maior: .asciiz "Maior: "