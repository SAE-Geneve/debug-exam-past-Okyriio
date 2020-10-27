#include <iostream>


void swaps(int* a, int* b)
{
    //This function swaps the values contained in the two pointers
	int c = *a ;
     a = b;
	 b = &c;
 
}

void print_values(int* a, int* b)
{
    //This function shows the values and their pointer
    std::cout << "The value of a is: "<< *a << " and is contained in address: "<<a<<"\n";
    std::cout << "The value of b is: "<< *b << " and is contained in address: "<<b<<"\n";
}


int main(const char* argv, int argc)
{
	int a = 4;
    int b = 3;


    swaps( &a, &b);

    print_values(&a,&b);

    //Windows specific
    system("pause");
    return 0;
}
