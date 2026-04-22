#include <stdio.h>


int is_same(int x, int y);


int main()

{

    int j=0, k=0;

    int x=0;

    int n = 0;

    int a=0, b=0, c=0;

    int ge,shi,bai;

    scanf("%d",&n);

    for(j=1; j<=9; j++)

    {

        for(k=1; k<=9; k++)

        {

            if(j==n || k==j || n==k)

                continue;

            a = n*100 + j*10 + k;

            for(x=200; x<1000; x++)

            {

                ge = x%10;

                shi = (x/10)%10;

                bai = x/100;

                if(ge==n || ge==j || ge==k)

                    continue;

                if(shi==n || shi==j || shi==k)

                    continue;

                if(bai==n || bai==j || bai==k)

                    continue;

                if(bai==ge || bai==shi || shi==ge)

                    continue;


                if(x == a*2)

                    b = x;

                if(x == a*3)

                    c = x;

            }

            if(b==a*2 && c==a*3)

            {

                if(!is_same(b,c))

                {

                    printf("%d,%d,%d\n",a,b,c);
                }
                
                    
                   

                

            }

        }

    }


    return 0;

}


int is_same(int x, int y)

{

    int x_bai,x_shi,x_ge;

    int y_bai,y_shi,y_ge;

    x_ge = x%10;

    x_shi = (x/10)%10;

    x_bai = x/100;

    y_ge = y%10;

    y_shi = (y/10)%10;

    y_bai = y/100;


    if(x_ge==y_ge || x_ge==y_shi || x_ge==y_bai)

    {

        return 1;

    }

    if(x_shi==y_ge || x_shi==y_shi || x_shi==y_bai)

    {

        return 1;

    }

    if(x_bai==y_ge || x_bai==y_shi || x_bai==y_bai)

    {

        return 1;

    }

    if(x_ge==0 || x_shi==0 || y_shi==0 || y_ge==0)

    {

        return 1;

    }


    return 0;

}

