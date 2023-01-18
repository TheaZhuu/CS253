void dispose(long double *p) {
    delete[] p;
}

int main() {
    long double *a = new long double [10];
    a+=3;
    dispose(a);
    return 0;
}
