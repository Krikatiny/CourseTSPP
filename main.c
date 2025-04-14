#include <stdio.h>
#include <string.h>

void clearArr(char* arr);
void getInputInArr(char* arr);
void clearSpaces(char* arr);
void copyArr(char* arr1, char* arr2);
int getOperationPos(char* arr, int position);
void searchNumberRight(char* arr, char* outArr, int position);
void searchOperator(char* arr, char* outArr, int position);
void searchNumberLeft(char* arr, char* outArr, int position);
int getLength(char* arr);

int main()
{
    char input[100] = " ";
    char numberRight[100] = " ";
    char numberLeft[100] = " ";
    char operation[100] = " ";
    char refactoredInput[100] = " ";
    int length = 0;
    int pos = 0;
    clearArr(input);
    clearArr(numberRight);
    clearArr(operation);
    clearArr(numberLeft);
    clearArr(refactoredInput);

    getInputInArr(input);
    clearSpaces(input);
    copyArr(input, refactoredInput);
    getLength(refactoredInput);

    pos = getOperationPos(refactoredInput, pos);
    searchNumberRight(refactoredInput, numberRight, pos);
    searchOperator(refactoredInput, operation, pos);
    searchNumberLeft(refactoredInput, numberLeft, pos);

    printf("%s\n", numberRight);
    printf("%s\n", operation);
    printf("%s", numberLeft);

    return 0;
}

//Clearing array
void clearArr(char* arr)
{
    for (int i = 0; arr[i]; i++)
    {
        arr[i] = ' ';
    }
}

//Get input into array and return length of array
void getInputInArr(char* arr)
{
    char c;
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        arr[i] = c;
    }
}

//Clearing spaces in arr
void clearSpaces(char* arr)
{
    int position = 0;
    for (int i = 0; arr[i]; i++)
    {
        switch (arr[i])
        {
        case ' ':
            break;
        case '\n':
            break;
        default:
            {
                arr[position] = arr[i];
                position++;
            }
        }
    }
    for (int i = position; arr[i]; i++)
    {
        arr[i] = ' ';
    }
}

//Copy arr1 into arr2
void copyArr(char* arr1, char* arr2)
{
    for (int i = 0; arr1[i]; i++)
    {
        arr2[i] = arr1[i];
    }
}

void searchNumberRight(char* arr, char* outArr, int position)
{
    char number[100];
    clearArr(number);
    int length = 0;
    for (int i = position + 1; arr[i]; i++)
    {
        switch (arr[i])
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            outArr[length] = arr[i];
            length++;
            break;
        default:
            {
            }
        }
    }
}

void searchOperator(char* arr, char* outArr, int position)
{
    //TODO Here I should to change this 0 for sin, cos, tan etc.

    outArr[0] = arr[position];
}

void searchNumberLeft(char* arr, char* outArr, int position)
{
    char number[100];
    clearArr(number);
    int length = 0;
    for (int i = position - 1; i >= 0; i--)
    {
        switch (arr[i])
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            outArr[length] = arr[i];
            length++;
            break;
        default:
            {
            }
        }
    }
}

int getOperationPos(char* arr, int position)
{
    for (int i = position; arr[i]; i++)
    {
        //TODO Define what to do with operators like sin, cos, log
        switch (arr[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            position = i;
            return position;
        default:
            {
            }
        }
    }
};

int getLength(char* arr)
{
    int i;
    for (i = 0; arr[i]; i++)
    {
    }
    return i;
}
