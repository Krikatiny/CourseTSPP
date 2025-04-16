//
// Created by zahar on 16.04.2025.
//


#include <stdio.h>
#include "arithmetics.h"

//Clearing array
void clearArr(char* arr)
{
    for (int i = 0; arr[i]; i++)
    {
        arr[i] = ' ';
    }
    arr[1] = '\0';
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
                return;
            }
        }
    }
}

int identifyOperator(char* arr, char* outArr, int position)
{
    clearArr(outArr);
    if (arr[position] == 's' && arr[position + 1] == 'i' && arr[position + 2] == 'n')
    {
        outArr[0] = 's';
        outArr[1] = 'i';
        outArr[2] = 'n';
        return 0;
    }
    else
    {
        outArr[0] = arr[position];
        return 1;
    }
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
                return;
            }
        }
    }
}

int getOperationPos(char* arr, int position)
{
    for (int i = position; arr[i]; i++)
    {
        switch (arr[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;
        default:
            {
                return i;
            }
        }
    }
};

int getLength(char* arr)
{
    int i;
    for (i = 0; arr[i]; i++)
    {
        if (arr[i] == ' ')
        {
            return i;
        }
    }
    return i;
}
