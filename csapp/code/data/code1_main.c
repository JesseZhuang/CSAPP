int sum(int x, int y);
// declaration needed
// error: implicit declaration of function 'sum' is invalid in C99 [-Werror,-Wimplicit-function-declaration]

int main() {
    return sum(1, 3);
}
