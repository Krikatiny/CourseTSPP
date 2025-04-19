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
void copyArr(char* fromArr, char* toArr)
{
    for (int i = 0; fromArr[i]; i++)
    {
        toArr[i] = fromArr[i];
    }
}

//return pos of last digit
int searchNumberRight(char* arr, char* outArr, int position)
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
            arr[i] = ' ';
            length++;
            break;
        default:
            {
                length = i;
                return length;
            }
        }
    }
}

int standardOperator(char* arr, int position)
{
    if (arr[position] == 's' && arr[position + 1] == 'i' && arr[position + 2] == 'n')
    {
        return 0;
    }
    if (arr[position] == 'c' && arr[position + 1] == 'o' && arr[position + 2] == 's')
    {
        return 0;
    }
    if (arr[position] == 't' && arr[position + 1] == 'a' && arr[position + 2] == 'n')
    {
        return 0;
    }
    if (arr[position] == 'c' && arr[position + 1] == 't' && arr[position + 2] == 'a' && arr[position + 3] == 'n')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int getOperator(char* arr, char* outArr, int position)
{
    clearArr(outArr);
    if (arr[position] == 's' && arr[position + 1] == 'i' && arr[position + 2] == 'n')
    {
        outArr[0] = 's';
        outArr[1] = 'i';
        outArr[2] = 'n';
        arr[position] = ' ';
        arr[position + 1] = ' ';
        arr[position + 2] = ' ';
    }

    if (arr[position] == 'c' && arr[position + 1] == 'o' && arr[position + 2] == 's')
    {
        outArr[0] = 'c';
        outArr[1] = 'o';
        outArr[2] = 's';
        arr[position] = ' ';
        arr[position + 1] = ' ';
        arr[position + 2] = ' ';
    }
    if (arr[position] == 't' && arr[position + 1] == 'a' && arr[position + 2] == 'n')
    {
        outArr[0] = 't';
        outArr[1] = 'a';
        outArr[2] = 'n';
        arr[position] = ' ';
        arr[position + 1] = ' ';
        arr[position + 2] = ' ';
    }
    if (arr[position] == 'c' && arr[position + 1] == 't' && arr[position + 2] == 'a' && arr[position + 3] == 'n')
    {
        outArr[0] = 'c';
        outArr[1] = 't';
        outArr[2] = 'a';
        outArr[3] = 'n';
        outArr[4] = '\0';
        arr[position] = ' ';
        arr[position + 1] = ' ';
        arr[position + 2] = ' ';
        arr[position + 3] = ' ';
    }
    switch (arr[position])
    {
    case '*':
    case '/':
    case '%':
    case '+':
    case '-':
    case '^':
        {
            outArr[0] = arr[position];
            arr[position] = ' ';
            break;
        };
    default:
        return -1;
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
            arr[i] = ' ';
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
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == 's' || arr[i] == 'c' || arr[i]
            == 't')
        {
            return i;
        }
    }
    return -1;
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

int calibratePos(char* arr, int position)
{
    if (arr[position] == 's' && arr[position + 1] == 'i' && arr[position + 2] == 'n')
    {
        return position + 2;
    }
    if (arr[position] == 'c' && arr[position + 1] == 't' && arr[position + 2] == 'a' && arr[position + 3] == 'n')
    {
        return position + 3;
    }
    if (arr[position] == 'c' && arr[position + 1] == 'o' && arr[position + 2] == 's')
    {
        return position + 2;
    }

    if (arr[position] == 't' && arr[position + 1] == 'a' && arr[position + 2] == 'n')
    {
        return position + 2;
    }


    return position;
}

void getNumber(char* arr, char* outArr, int position)
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
            outArr[position] = arr[i];
            break;
        default:
            {
                return;
            }
        }
    }
}

int getLengthWithoutSpaces(char* arr)
{
    int length = 0;
    for (int i = 0; arr[i]; i++)
    {
        if (arr[i] != ' ')
        {
            length++;
        }
    }
    return length;
}
