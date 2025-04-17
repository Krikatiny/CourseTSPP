//
// Created by zahar on 16.04.2025.
//

#ifndef ARITHMETICS_H
#define ARITHMETICS_H

#define TRUE 1
#define FALSE 0


void clearArr(char* arr);
void getInputInArr(char* arr);
void clearSpaces(char* arr);
void copyArr(char* arr1, char* arr2);
int getOperationPos(char* arr, int position);
int searchNumberRight(char* arr, char* outArr, int position);
int standardOperator(char* arr, char* outArr, int position);
int getOperator(char* arr, char* outArr, int position);
void searchNumberLeft(char* arr, char* outArr, int position);
int calibratePos(char* arr, int position);
int getLength(char* arr);

#endif //ARITHMETICS_H
