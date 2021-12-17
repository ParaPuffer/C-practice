#include <cs50.h>
#include <stdio.h>

int check_sum(void);
long get_card(void);
long card = 0; // assigns global value for card number so it can be accessed from either function.

int main(void) //main func that prints a result based on card type/check_sum
{

    int valid = 0;
    int final = 0;
    long c = 0;
    do //I'm sure there was another way to do this but it works I guess. prints results based on card number
    {
        final = check_sum(); // calls check_sum which calls get_card. After card number is validated, passes check 1 or 0 to final
        c = card; // assigns card number to c which is used in the do while loop
        if (c < 4000000000000)
        {
            printf("INVALID\n");
            valid = 1;
        }
        else if ((c > 3999999999999) && (c < 5000000000000))
        {
            if (final == 1)
            {
                printf("VISA\n");
                valid = 1;
            }
            else
            {
                printf("INVALID\n");
                valid = 1;
            }
        }
        else if ((c > 3999999999999999) && (c < 5000000000000000))
        {
            if (final == 1)
            {
                printf("VISA\n");
                valid = 1;
            }
            else
            {
                printf("INVALID\n");
                valid = 1;
            }
        }
        else if ((c > 5099999999999999) && (c < 5600000000000000))
        {
            if (final == 1)
            {
                printf("MASTERCARD\n");
                valid = 1;
            }
            else
            {
                printf("INVALID\n");
                valid = 1;
            }
        }
        else if ((c > 339999999999999) && (c < 350000000000000))
        {
            if (final == 1)
            {
                printf("AMEX\n");
                valid = 1;
            }
            else
            {
                printf("INVALID\n");
                valid = 1;
            }
        }
        else if ((c > 369999999999999) && (c < 380000000000000))
        {
            if (final == 1)
            {
                printf("AMEX\n");
                valid = 1;
            }
            else
            {
                printf("INVALID\n");
                valid = 1;
            }
        }
        else
        {
            printf("INVALID\n");
            valid = 1;
        }
    }
    while (valid == 0);
}

int check_sum(void) //function that returns a result based on Luhn's Alg
{
    long x = get_card(); // takes number from user and then assigns it to x which is used for the checksum % 10 = 0
    long set1 = 0;
    long set2 = 0;
    long y = 0;
    long d = 0; //variable used incase of y value greater than 5 which would cause Luhn's algo to be incorrect
    long f = 0; //sets y back to the digit before loop
    long z = 0;
    int check = 0;
    for (long i = 0; i < 16; i++)
    {
        // loop iterates card number, takes %, adds it to a set, subtracts % from original then / 10 for 2 sets with their own formulas. repeats til 16 digits.
        y = x % 10;
        set1 = y + set1; //digits that arent muliplied
        z = (x - y) / 10;
        x = z;
        y = x % 10;
        if (y < 5) //digits that are multiplied and under 5 dont need to be seperated
        {
            set2 = (y * 2) + set2;
        }
        else if (y > 4) //products of digits that are > 5 need to be added separately to fit the alg
        {
            d = (y * 2) % 10;
            set2 = d + set2;
            f = ((y * 2) - d) % 10 + 1;
            set2 = f + set2;
        }
        z = (x - y) / 10;
        x = z;
    }
    if ((set1 + set2) % 10 == 0)
    {
        check = 1;
    }
    else
    {
        check = 0;
    }
    return check;
}

long get_card(void) //makes sure input is long and non-negative because my loop game isn't the best
{
    //long card = 0; // assigning the variable here causes issues with bounded extent(I think?) since I need to use the card number in not just the function tha calls this one, but the function that calls that one.
    do
    {
        card = get_long("Number: ");
    }
    while (card < 1);
    return card;
}