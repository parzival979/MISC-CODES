#ifdef __GNUC__
__attribute__((section(".my_custom_section")))
#endif
int global_var = 42;

static void __attribute__((section(".init_array"))) init_func(void) {}

int main(void) {
    return global_var;
}