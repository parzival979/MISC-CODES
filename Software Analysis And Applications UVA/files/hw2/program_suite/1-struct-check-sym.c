#include <stdio.h>
#include <klee/klee.h>

typedef struct {
    int age;
    int score;
} Person;

int main() {
    Person p;
    klee_make_symbolic(&p, sizeof(p), "p");
    
    klee_assume(p.age >= 0);
    klee_assume(p.age <= 100);
    klee_assume(p.score >= 0);
    klee_assume(p.score <= 100);

    if(p.age >= 18 && p.score > 50)
        printf("Eligible\n");
    else
        printf("Not eligible\n");
    
    return 0;
}