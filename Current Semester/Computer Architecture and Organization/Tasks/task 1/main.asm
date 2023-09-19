# Simple input/output in MIIPS assembly
# From: http://labs.cs.upt.ro/labs/so2/html/resources/nachos-doc/mipsf.html

# Start .text segment (program code)
.text

.globl	main
main:
    lw      $t5,    divisor
                                        # Get input A from user and save
    li      $v0,    5                   # read_int syscall code = 5
    syscall 
    move    $t0,    $v0                 # syscall results returned in $v0

# Get input B from user and save
    li      $v0,    5                   # read_int syscall code = 5
    syscall 
    move    $t1,    $v0                 # syscall results returned in $v0

# Get input C from user and save
    li      $v0,    5                   # read_int syscall code = 5
    syscall 
    move    $t6,    $v0                 # syscall results returned in $v0


# Calcule a diferença
    sub     $t2,    $t0,        $t1     # $t2 = $t0 - $t1

# Verifique se a diferença é negativa
    bltz    $t2,    negative            # Se for negativa, vá para o rótulo 'negative'

# Se a diferença for positiva ou zero, copie-a para o resultado
    move    $t3,    $t2                 # $t3 = $t2
    j       math

negative:
                                        # Se a diferença for negativa, inverta o sinal
    neg     $t3,    $t2                 # $t3 = -$t2

math:
                                        # Math!
    add     $t0,    $t0,        $t1
    add     $t0,    $t0,        $t3

    div     $t0,    $t5                 # {lo, hi} = A / B
    mflo    $t4

# -----------------------

# Calcule a diferença
    sub     $t7,    $t6,        $t4     # $t2 = $t0 - $t1

# Verifique se a diferença é negativa
    bltz    $t7,    negative2           # Se for negativa, vá para o rótulo 'negative'

# Se a diferença for positiva ou zero, copie-a para o resultado
    move    $t8,    $t7                 # $t3 = $t2
    j       math2

negative2:
                                        # Se a diferença for negativa, inverta o sinal
    neg     $t8,    $t7                 # $t3 = -$t2

math2:
                                        # Math!
    add     $t6,    $t6,        $t4
    add     $t6,    $t6,        $t8

    div     $t6,    $t5                 # {lo, hi} = A / B
    mflo    $t9


# Print sum
    li      $v0,    1                   # print_int syscall code = 1
    move    $a0,    $t9                 # int to print must be loaded into $a0
    syscall 

# Print \n
    li      $v0,    4                   # print_string syscall code = 4
    la      $a0,    newline
    syscall 

    li      $v0,    10                  # exit
    syscall 

# Start .data segment (data!)
.data
newline:   .asciiz	"\n"
divisor:    .word  2                    # Second number (denominator)
