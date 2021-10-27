#include <stdio.h>
#include <stdlib.h>

	int a1, b1;
	int a2, b2;
    int a3, b3;

void input1()
{
	printf("[1] a|b: ");
	scanf("%d %d", &a1, &b1);
}

void input2()
{
	printf("[2] a|b: ");
	scanf("%d %d", &a2, &b2);
}

void print()
{
	printf("[1]: %d | %d\n", a1, b1);
	printf("[2]: %d | %d\n", a2, b2);
}

void add()
{
	a3 = a1 * b2 + a2 * b1;
	b3 = b1 * b2;
	printf("amount: %d | %d\n", a3, b3);
}

void subtract()
{
    a3 = a1 * b2 - a2 * b1;
	b3 = b1 * b2;
	printf("subtraction: %d | %d\n", a3, b3);
}

void division()
{
    a3 = a1 * b2;
	b3 = b1 * a2;
	printf("division: %d | %d\n", a3, b3);
}

void multiplication()
{
    a3 = a1 * a2;
    b3 = b1 * b2;

	printf("multiplication: %d | %d\n", a3, b3);
}

void translationDecimal()
{
	float c = (float) a3 / b3;
	printf("Decimal: %.2f\n", c);
}


int main()
{
int choice = -1;
do
 {
	printf("\n");
	printf("0 - exit\n");
	printf("1 - input 1\n");
	printf("2 - input 2\n");
	printf("3 - printf\n");
	printf("4 - add\n");
	printf("5 - subtract\n");
    printf("6 - devision\n");
    printf("7 - multiplication\n");
    printf("8 - translationDecimal\n");

	printf("\n");

	printf("choice: ");
	int choice;
	scanf("%d", &choice);


	switch(choice)
	{
	    case 0: return 0; break;
		case 1: input1(); break;
		case 2: input2(); break;
		case 3: print(); break;
		case 4: add(); break;
		case 5: subtract(); break;
        case 6: division();break;
        case 7: multiplication();break;
        case 8: translationDecimal();break;
	}
    printf("\n");
	printf("press");
    printf("\n");
 }
 while(choice != 0);



	return 0;
}
