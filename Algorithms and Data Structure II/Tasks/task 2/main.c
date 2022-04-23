#include <stdio.h>
#include <stdlib.h>

int getBookByTicket(int tickets, int ticketPrice)
{
    int books, leftover;

    if (tickets < ticketPrice)
        return 0;
    else
    {
        books = tickets / ticketPrice;
        leftover = tickets % ticketPrice;

        return books + getBookByTicket(books + leftover, ticketPrice);
    }
}

int bookTest()
{
    int money, bookPrice, ticketPrice, books;

    scanf("%d", &money);
    scanf("%d", &bookPrice);
    scanf("%d", &ticketPrice);

    books = money / bookPrice;

    return books + getBookByTicket(books, ticketPrice);
}

int main(int argc, char const *argv[])
{
    int repetions, i;

    scanf("%d", &repetions);

    for (i = 0; i < repetions; i++)
        printf("%d\n", bookTest());

    return 0;
}