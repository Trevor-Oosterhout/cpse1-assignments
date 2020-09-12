    .global uppercase_lowercase
uppercase_lowercase:
    push {lr}
    cmp r0, #91
    blt lower_test
    b upper_test
lower_test:
    cmp r0, #64
    bgt lower_case
    b upper_test
lower_case:
    add r0, r0, #32
    b done
upper_test:
    cmp r0, #123
    blt upper_test2
    b done
upper_test2:
    cmp r0, #96
    bgt upper_case
    b done
upper_case:
    sub r0, r0, #32
    b done
done:
    pop {pc}
