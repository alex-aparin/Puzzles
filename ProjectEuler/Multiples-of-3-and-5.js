function sum_mults3_5()
{
    let sum = 0;
    for (let i = 3; i < 1000; ++i)
        sum += (i % 3 == 0 || i % 5 == 0) ? i : 0; 
    return sum;
}
