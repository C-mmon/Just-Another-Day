class Solution {
public:
    int tribonacci(int n) {
            int a =0,b=1,c=1, sum=0;
        if(n==0)
        {
            return a;
        }
        else if(n == 1)
        {
            return b;
        }
        else if(n ==  2)
        {
            return c;
        }

        sum = a+b+c;
        while(n-3>0)
        {
            
            a=b;
            b=c;
            c = sum;
            sum = a+b+c;
            n--;
        }
        return sum;
    }
};