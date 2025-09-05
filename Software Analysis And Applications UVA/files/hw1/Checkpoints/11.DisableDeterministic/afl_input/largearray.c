int arr[10000];
int main() {
    arr[9999] = 42;
    return arr[9999];
}