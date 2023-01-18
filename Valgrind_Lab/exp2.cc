int main() {
    char *x = new char[10];
    x[9] = 'a';
    delete []x;
    return 0;
}
