
#result = (unsigned int)  % 2048;
#next *= 1103515245;
#next += 12345;
#result <<= 10;
#result ^= (unsigned int) (next / 65536) % 1024;
#next *= 1103515245;
#next += 12345;
#result <<= 10;
#result ^= (unsigned int) (next / 65536) % 1024;
.text

.globl main
main:
    lw      $t0,    bigA #next = 1103515245
    lw      $t1,    bigB
    lw      $t2,    bigC
    lw      $t3,    bigD
    lw      $t4,    bigE
    lw      $t5,    ten 
    lw      $t7,    bigA

    add     $t0,    $t0,    $t1 #next += 12345;

    divu     $t0,    $t2 # next / 65536

    mflo    $t6 # helper = next / 65536

    divu     $t6,    $t3 # helper % 2048

    mfhi    $t9 # result = helper % 2048

    multu     $t0,    $t7   #next * 1103515245;

    add     $t0,    $t0,    $t1 #next += 12345;

    sll $t9, $t9, 10 # result ^= 

    xor $t9, $t9, $t1

    # mflo    $t6 # helper = next / 65536

    # div     $t6,    $t3 # helper % 2048



    li      $v0,    1
    move    $a0,    $t9
    syscall 

    li      $v0,    10
    syscall 


.data

bigA: .word 1103515245
bigB: .word 12345
bigC: .word 65536
bigD: .word 2048
bigE: .word 1024
ten: .word 10


