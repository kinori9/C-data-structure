void    ary_rcopy(int a[], const int b[], int n)
{
    int i;
    int c = n - 1;

    for (i = 0; i < n; i++)
        a[i] = b[c--];
}