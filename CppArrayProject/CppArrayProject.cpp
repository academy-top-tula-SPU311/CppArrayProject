#include <iostream>

void ArrayInit(int array[], int size);
void ArrayPrint(int array[], int size);

int ArrayMinValue(int array[], int size);
int ArrayMinIndex(int array[], int size);

void ArrayReverse(int array[], int size);



int main()
{
    srand(time(nullptr));

    const int size{ 10 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    ArrayReverse(array, size);

    ArrayPrint(array, size);

    //std::cout << "Min = " << ArrayMinValue(array, size) << "\n";


    /*int a, b, c;
    std::cin >> a >> b >> c;

    int min{ a };

    if (min > b)
        min = b;
    if (min > c)
        min = c;
  
    std::cout << a << " " 
              << b << " " 
              << c << " " 
              << min << "\n";*/

}

void ArrayInit(int array[], int size)
{
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int array[], int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int ArrayMinValue(int array[], int size)
{
    int minValue{ array[0] };
    for (int i{ 1 }; i < size; i++)
        if (minValue > array[i])
            minValue = array[i];
    return minValue;
}

int ArrayMinIndex(int array[], int size)
{
    int minIndex{ 0 };
    for (int i{ 1 }; i < size; i++)
        if (array[minIndex] > array[i])
            minIndex = i;

    return minIndex;
}

void ArrayReverse(int array[], int size)
{
    int temp;
    for (int i{}; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}
