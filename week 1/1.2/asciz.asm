    .global print_asciz
print_asciz:
    push {R5, lr}
    mov R5, R0
loop:
    ldrb R0, [R5]
    ADD R0, R0, #0
    BEQ done
    bl uart_put_char
    ADD R5, R5, #1
    b loop
done:
    pop {R5, PC}
