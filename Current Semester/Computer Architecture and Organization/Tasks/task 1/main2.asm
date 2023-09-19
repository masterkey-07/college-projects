# Simple input/output in MIIPS assembly
# From: http://labs.cs.upt.ro/labs/so2/html/resources/nachos-doc/mipsf.html

# Start .text segment (program code)
.text

.globl	main
main:
                                            # Get input A from user and save
    li      $v0,    5                       # read_int syscall code = 5
    syscall 
    move    $t0,    $v0                     # syscall results returned in $v0


# Get input B from user and save
    li      $v0,    5                       # read_int syscall code = 5
    syscall 
    move    $t1,    $v0                     # syscall results returned in $v0


# Get input C from user and save
    li      $v0,    5                       # read_int syscall code = 5
    syscall 
    move    $t2,    $v0                     # syscall results returned in $v0

compab:
    bge     $t0,    $t1,        compac
    bge     $t1,    $t0,        compbc

compac:
    bge     $t0,    $t2,        biggera
    bge     $t2,    $t0,        biggerc

compbc:
    bge     $t1,    $t2,        biggerb
    bge     $t2,    $t1,        biggerc

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
                                            # Print sum
    li      $v0,    1                       # print_int syscall code = 1
    move    $a0,    $t3                     # int to print must be loaded into $a0
    syscall 


# Print \n
    li      $v0,    4                       # print_string syscall code = 4
    la      $a0,    newline
    syscall 

    li      $v0,    10                      # exit
    syscall 

# Start .data segment (data!)
.data
newline:   .asciiz	"\n"
