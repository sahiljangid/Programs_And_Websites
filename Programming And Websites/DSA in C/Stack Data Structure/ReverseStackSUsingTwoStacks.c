#include <stdio.h>


void Tmppush1(int data);
void Tmppush2(int data);

// Original Stack

#define size 5
int Orstk[size];
int Ortop = -1;

void Orpush(int data)
{
    if (Ortop == size - 1)
    {
        printf("Original Stack is full\n");
        return;
    }
    Ortop++;
    Orstk[Ortop] = data;
    printf("%d Element inserted successfully into Original Stack\n", data);
}

void Orpop()
{
    if (Ortop == -1)
    {
        printf("Original Stack is empty\n");
        return;
    }
    int data = Orstk[Ortop];
    Tmppush1(data);
    Ortop--;
    printf("%d Element deleted successfully into Original Stack\n", data);
}


void Orprint()
{
    if (Ortop == -1)
    {
        printf("Original Stack is empty\n");
        return;
    }
    printf("Original Stack is: ");
    for (int i = 0; i <= Ortop; i++)
    {
        printf("%d ", Orstk[i]);
    }
    printf("\n");
}



// Temp Stack 1

#define size 5
int Tmpstk1[size];
int Tmptop1 = -1;

void Tmppush1(int data)
{
    if (Tmptop1 == size - 1)
    {
        printf("Temp Stack 1 is full\n");
        return;
    }
    Tmptop1++;
    Tmpstk1[Tmptop1] = data;
    printf("%d Element inserted successfully into Temp Stack 1\n", data);
}

void Tmppop1()
{
    if (Tmptop1 == -1)
    {
        printf("Temp Stack 1 is empty\n");
        return;
    }
    int data = Tmpstk1[Tmptop1];
    Tmppush2(data);
    Tmptop1--;
    printf("%d Element deleted successfully into Temp Stack 1\n", data);
}


void Tmpprint1()
{
    if (Tmptop1 == -1)
    {
        printf("Temp Stack 1 is empty\n");
        return;
    }
    printf("Temp Stack 1 is: ");
    for (int i = 0; i <= Tmptop1; i++)
    {
        printf("%d ", Tmpstk1[i]);
    }
    printf("\n");
}


// Temp Stack 2

#define size 5
int Tmpstk2[size];
int Tmptop2 = -1;

void Tmppush2(int data)
{
    if (Tmptop2 == size - 1)
    {
        printf("Temp Stack 2 is full\n");
        return;
    }
    Tmptop2++;
    Tmpstk2[Tmptop2] = data;
    printf("%d Element inserted successfully into Temp Stack 2\n", data);
}

void Tmppop2()
{
    if (Tmptop2 == -1)
    {
        printf("Temp Stack 2 is empty\n");
        return;
    }
    int data = Tmpstk2[Tmptop2];
    Orpush(data);
    Tmptop2--;
    printf("%d Element deleted successfully into Temp Stack 2\n", data);
}


void Tmpprint2()
{
    if (Tmptop2 == -1)
    {
        printf("Temp Stack 2 is empty\n");
        return;
    }
    printf("Temp Stack 2 is: ");
    for (int i = 0; i <= Tmptop2; i++)
    {
        printf("%d ", Tmpstk2[i]);
    }
    printf("\n");
}


int main()
{
    printf("Enter 5 elements:\n");
    int data;
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        Orpush(data);
    }
    Orprint();

    for (int i = 0; i < size; i++)
    {
        Orpop();
    }
    Orprint();
    Tmpprint1();

    for (int i = 0; i < size; i++)
    {
        Tmppop1();
    }
    Orprint();
    Tmpprint1();
    Tmpprint2();
    for (int i = 0; i < size; i++)
    {
        Tmppop2();
    }
    Orprint();
    Tmpprint1();
    Tmpprint2();
    


    return 0;
}