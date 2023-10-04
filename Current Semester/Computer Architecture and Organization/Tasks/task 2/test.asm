# Function: int rand_r(unsigned int *seed)
# Arguments:
# $a0 - Address of the seed (pointer to unsigned int)
# Return value:
# $v0 - The random number

.text

.globl rand_r
rand_r:
                                        # Load the seed from the address in $a0
    lw      $t0,    0($a0)              # $t0 = *seed

# Perform the first part of the algorithm
    li      $t1,    1103515245          # Load the constant multiplier
    multu   $t0,    $t1                 # Multiply seed by constant
    mflo    $t0                         # Get the lower 32 bits of the result
    addi    $t0,    $t0,        12345   # Add 12345 to $t0

# Calculate the result of the first part
    divu    $t0,    $t0,        65536   # Divide $t0 by 65536, quotient in $t0
    li      $t2,    2048                # Load the constant 2048
    andi    $t0,    $t0,        0xFFFF  # Mask to get the lower 16 bits
    remu    $t0,    $t0,        $t2     # Calculate remainder, result in $t0

# Perform the second part of the algorithm
    li      $t1,    1103515245          # Load the constant multiplier again
    multu   $t0,    $t1                 # Multiply seed by constant
    mflo    $t0                         # Get the lower 32 bits of the result
    addi    $t0,    $t0,        12345   # Add 12345 to $t0

# Calculate the result of the second part
    divu    $t0,    $t0,        65536   # Divide $t0 by 65536, quotient in $t0
    li      $t2,    1024                # Load the constant 1024
    andi    $t0,    $t0,        0xFFFF  # Mask to get the lower 16 bits
    sll     $t0,    $t0,        10      # Left-shift by 10

# XOR the results of the first and second parts
    xor     $v0,    $t0,        $t2

# Print the result
    li      $v0,    1                   # Load the print integer system call code
    move    $a0,    $v0                 # Copy the result to $a0 for printing
    syscall                             # Perform the system call

# Update the seed with the new value
    sw      $t0,    0($a0)              # *seed = $t0

    jr      $ra                         # Return