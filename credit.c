#include <stdio.h>
#include <cs50.h>

int getLenght(long long num);
int checkValidSum(long long num, int lenght);

int pickDigit(long long num, int lenght, int digit);

int main(void)
{
    long long creditNumber;
    int lenght;
    int valid;

    creditNumber=get_long_long("Your Credit Card number:");
    lenght=getLenght(creditNumber);

    valid=checkValidSum(creditNumber, lenght);

    if(valid==1)
    {
        switch(lenght)
        {
            case 15:
                if(pickDigit(creditNumber, lenght, 15)==3)
                {
                    if(pickDigit(creditNumber, lenght, 14)==4 || pickDigit(creditNumber, lenght, 14)==7)
                        printf("AMEX\n");
                    else
                        printf("INVALID\n");
                }
                else
                    printf("INVALID\n");
                break;

            case 13:
                if(pickDigit(creditNumber, lenght, 13)==4)
                    printf("VISA\n");
                else
                    printf("INVALID\n");
                break;

            case 16:
                if(pickDigit(creditNumber, lenght, 16)==4)
                    printf("VISA\n");
                else if(pickDigit(creditNumber, lenght, 16)==5)
                {
                    if(pickDigit(creditNumber, lenght, 15)==1 ||
                       pickDigit(creditNumber, lenght, 15)==2 ||
                       pickDigit(creditNumber, lenght, 15)==3 ||
                       pickDigit(creditNumber, lenght, 15)==4 ||
                       pickDigit(creditNumber, lenght, 15)==5)
                        printf("MASTERCARD\n");
                    else
                        printf("INVALID\n");
                }
                else
                    printf("INVALID\n");
                break;

            default:
                printf("INVALID\n");
                break;
        }
    }
    else
        printf("INVALID\n");
}

int getLenght(long long num)
{
    int i;

    for(i=0; num>=1; i++)
    {
        num /= 10;
    }

    return i;
}

int checkValidSum(long long num, int lenght)
{
    long long temp, sum;

    for(int i=1; i<=lenght; i++)
    {
        if (i%2==0)
        {
            temp=pickDigit(num, lenght, i);
            temp=temp*2;

            if(temp>9)
            {
                sum=sum+(temp%10);
                sum=sum+(temp/10);
            }
            else
                sum += temp;
        }
        else
        {
            temp=pickDigit(num, lenght, i);

            sum += temp;
        }

    }

    if(sum%10==0)
    {
        return 1;
    }
    else
        return 0;
}

int pickDigit(long long num, int lenght, int digit)
{
    long long pw10=1;
    long long ris;

    while(digit>1)
    {
        pw10 *= 10;
        digit--;
    }

    ris=num/pw10;
    ris=ris%10;

    return ris;
}