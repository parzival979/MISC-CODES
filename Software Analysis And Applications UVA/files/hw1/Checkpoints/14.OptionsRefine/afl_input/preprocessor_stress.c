#ifdef SOME_UNDEF_SYMBOL
# error "This should not appear"
#endif

#define FOO(x,y) (x)*(y)
#pragma pack(push, 1)
struct P { char c; int i; };
#pragma pack(pop)

#define STR(s) #s
#define CAT(a,b) a ## b

#if 1
int main(void) {
    int result = FOO(3,4);
    const char *str = STR(HelloWorld);
    int xCAT(Num, ber) = 10;
    return result + xNumber;
}
#else
# error "We should not get here"
#endif