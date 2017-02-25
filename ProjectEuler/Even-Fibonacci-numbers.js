function fib_even_sum()
{
    let sum = 0;
    let a1 = 1;
    let a2 = 1;
    let ev = 0;
    do
    {
        sum += (ev == 2) ? a1 : 0;
        a2 += a1;
        a1 = a2 - a1;
        ev = (ev + 1) % 3
    }
    while (a1 <= 4000000);
    return sum;
}
