#include <iostream>

void ArrayInit(int array[], int size);
void ArrayPrint(int array[], int size);

int ArrayMinValue(int array[], int size);
int ArrayMinIndex(int array[], int size);

void ArrayReverse(int array[], int size);

void ArrayShiftLeft(int array[], int size, int steps);

void ArraySortSelect(int array[], int size);
void ArraySortBubble(int array[], int size);
void ArraySortShacker(int array[], int size);
void ArraySortInsert(int array[], int size);

int main()
{
    srand(time(nullptr));

    const int size{ 10 };
    int array[size]{};

    ArrayInit(array, size);
    ArrayPrint(array, size);

    //ArrayReverse(array, size);
    //ArrayShiftLeft(array, size, 3);
    //ArraySortSelect(array, size);
    //ArraySortBubble(array, size);
    //ArraySortShacker(array, size);
    ArraySortInsert(array, size);

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

void ArrayShiftLeft(int array[], int size, int steps)
{
    //steps = steps % size;
    steps %= size;

    int temp;

    for (int s{}; s < steps; s++)
    {
        temp = array[0];
        for (int i{}; i < size - 1; i++)
            array[i] = array[i + 1];
        array[size - 1] = temp;
    }
    
}

void ArraySortSelect(int array[], int size)
{
    for (int left{}; left < size - 1; left++)
    {
        int indexMin{ left };
        for (int i{ left + 1 }; i < size; i++)
            if (array[indexMin] > array[i])
                indexMin = i;
        int temp = array[left];
        array[left] = array[indexMin];
        array[indexMin] = temp;
    }
}

void ArraySortBubble(int array[], int size)
{
    int temp;
    bool isSort;
    for (int i{}; i < size - 1; i++)
    {
        isSort = true;
        for(int j{ size - 1 }; j > i; j--)
            if (array[j] < array[j - 1])
            {
                isSort = false;
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        if (isSort) break;
    }
}

void ArraySortShacker(int array[], int size)
{
    int top{};
    int bottom{ size - 1 };
    int temp;
    bool isSort;

    while (top < bottom)
    {
        isSort = true;
        for(int i{ bottom }; i > top; i--)
            if (array[i] < array[i - 1])
            {
                isSort = false;
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        if (isSort) break;
        top++;

        isSort = true;
        for(int i{ top }; i < bottom; i++)
            if (array[i] > array[i + 1])
            {
                isSort = false;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        if (isSort) break;
        bottom--;
    }
}

void ArraySortInsert(int array[], int size)
{
    int temp;
    int j;
    for (int i{ 1 }; i < size; i++)
    {
        temp = array[i];
        for (j = i; j > 0; j--)
        {
            if (array[j - 1] > temp)
                array[j] = array[j - 1];
            else
                break;
        }
        array[j] = temp;
    }

}
