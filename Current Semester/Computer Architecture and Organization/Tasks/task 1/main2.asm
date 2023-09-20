# victor jorge carvalho chaves

.text

.globl	main
main:
    li      $v0,    5
    syscall 
    move    $t0,    $v0

    li      $v0,    5
    syscall 
    move    $t1,    $v0

    li      $v0,    5
    syscall 
    move    $t2,    $v0

compab:
    bge     $t0,    $t1,    compac
    bge     $t1,    $t0,    compbc

compac:
    bge     $t0,    $t2,    biggera
    bge     $t2,    $t0,    biggerc

compbc:
    bge     $t1,    $t2,    biggerb
    bge     $t2,    $t1,    biggerc

biggera:
    move    $t3,    $t0
    j       final

biggerb:
    move    $t3,    $t1
    j       final

biggerc:
    move    $t3,    $t2
    j       final

final:
    li      $v0,    4
    la      $a0,    maior
    syscall 


    li      $v0,    1
    move    $a0,    $t3
    syscall 

    li      $v0,    10
    syscall 

.data
maior: .asciiz "Maior: "
