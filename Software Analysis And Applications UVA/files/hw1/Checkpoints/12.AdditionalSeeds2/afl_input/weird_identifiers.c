int $myvar = 10;
int _weird = 20;

int main(void) {
    extern int $myvar;
    extern int _weird;
    return $myvar + _weird;
}