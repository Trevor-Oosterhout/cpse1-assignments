str:    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"
        .global application
application:
    push {lr}
    ldr r0, =str
    BL print_asciz
    POP {pc}
