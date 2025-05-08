void _start(){
        __asm__("mov $60,%eax\n"
                "mov $99,%edi\n"

                "syscall");
}
