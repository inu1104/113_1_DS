int climbStairs(int n)
{
    static int f[50] = {0};
    f[0] = 1;
    f[1] = 1;
    if (f[n] > 0)
        return f[n];

    f[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return f[n];
}
