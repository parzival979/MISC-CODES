#define RECURSIVE_MACRO(x) RECURSIVE_MACRO(x)

int main() {
    return RECURSIVE_MACRO(10);
}