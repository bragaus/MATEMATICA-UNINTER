/* ============================================================
 *  TEOREMA DE BRAGA  (A = anarquismo, US = sobre nos)
 *  Tabuada espelho mod 10: o infinito volta pro 0 depois do 10.
 *  O 10 nao existe -> e o 0,1 ao contrario. Loop infinito de 10.
 *
 *  SEM libs   -> freestanding, syscalls Linux diretos (asm)
 *  SEM aritmetica -> nada de + - * / % ; so bitwise ^ & | << >>
 *                    (soma feita por full-adder; mult por shift-and-add)
 *  x86-64 Linux apenas.
 *  build: gcc -nostdlib -ffreestanding -no-pie -fno-stack-protector \
 *             -o braga teorema_braga.c
 * ============================================================ */

/* ---- syscall write(fd, buf, len) ---- */
static long sys_write(long fd, const char *buf, long len) {
    long ret;
    __asm__ volatile("syscall"
        : "=a"(ret)
        : "a"(1), "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory");
    return ret;
}

/* ---- syscall exit(code) ---- */
static void sys_exit(long code) {
    __asm__ volatile("syscall" : : "a"(60), "D"(code));
    __builtin_unreachable();
}

/* ---- soma SEM '+' : full-adder (XOR = soma, AND<<1 = carry) ---- */
static int add(int a, int b) {
    while (b) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

/* ---- negacao (complemento de dois) e subtracao, SEM '-' ---- */
static int neg(int a)         { return add(~a, 1); }
static int sub(int a, int b)  { return add(a, neg(b)); }

/* ---- mod 10 = TEOREMA DE BRAGA: tudo volta pro anel 0..9 ---- */
static int mod10(int x) {
    while (x >= 10)            /* comparacao nao e aritmetica */
        x = sub(x, 10);
    return x;
}

/* ---- mult SEM '*' : shift-and-add, resultado no anel ---- */
static int mul10(int a, int b) {
    int res = 0;
    while (b) {
        if (b & 1) res = add(res, a);
        a = a << 1;            /* a*2 */
        b = b >> 1;            /* b/2 */
    }
    return mod10(res);
}

/* ---- saida ---- */
static void putc_(char c)      { sys_write(1, &c, 1); }
static void putdigit(int d)    { putc_((char)add(d, '0')); }  /* '0'+d sem + */

void _start(void) {
    int n = 1;
    while (n <= 10) {                 /* 10 -> mod10 -> 0 : "nao existe" */
        int i = 1;
        while (i <= 10) {
            putdigit(mul10(n, i));
            putc_(' ');
            i = add(i, 1);
        }
        putc_('\n');
        n = add(n, 1);
    }
    sys_exit(0);
}
