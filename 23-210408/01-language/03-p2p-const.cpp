int main() {
    int x[10]{};
    const int cx[10]{};

    int *px = &x[0];
    const int *pcx = &cx[0];

    {
        int **ppx = &px;
        const int **ppcx = &pcx;
    }
    // https://isocpp.org/wiki/faq/const-correctness#constptrptr-conversion
    {
        // int **ppx = &pcx;
        /* Пример:
        **px = 10;  // изменили константный массив
        */
    }
    {
        // const int **ppcx = &px;
        /* Пример:
        *ppcx = &cx[0];
        // px == &cx[0];
        *px = 10;
        */
    }
    {
        const int *const *pcpcx = &px;
    }
}
