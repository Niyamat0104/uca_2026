#include <stdlib.h>
#include <stdio.h>

long long evenSumBrute( long long n )
{
    long long a = 1;
    long long b = 1;
    long long sum = 0;
    
    for (long long i = 1; i <= n; i++)
    {
        if (i == a)
        {
            if (i % 2 == 0)
            {
                sum = sum + i;
            }

            long long c = a + b;
            a = b;
            b = c;
        }
    }

    return sum;

}

long long evenSumOpt( long long n ) 
{
    
    long long a = 2;
    long long b = 8;
    long long sum = 0;
    
    while(a <= n) {
       
        sum += a;
        
        long long c = 4 * a + b;
        a = b;
        b = c;

    }
    return sum;


}

int main(){
    long long n;
    scanf("%lld" , &n);
    printf("The sum of Even numbers in fibonnaci series upto %lld (using O(n)) is %lld\n",n,evenSumBrute(n));
    printf("The sum of Even numbers in fibonnaci series upto %lld (using O(log n)) is %lld\n",n,evenSumOpt(n));


     
}}
