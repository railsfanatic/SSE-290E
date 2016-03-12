/*	HOMEWORK 3
	File:	common.h
	Module:	Common functions for Homework 3
	by Tom Grushka
	Mar. 11, 2016
*/

#ifndef COMMON_H_
#define COMMON_H_

#define ARRAY_SIZE 10

char *getString(int length, const char *prompt);
int getInteger(const char *prompt);
char *strrev(char *str);

void reverseArray(int size, int *a);
void   fillRandom(int size, int *a, int min, int max);
void   inputArray(int size, int *a);
void   printArray(int size, int *a);
int    findLowest(int size, int *a);
void    mergeSort(int size, int *a);
/*
void splitMerge(int *a, int iBegin, int iEnd, int *b);
void topDownMerge(int *a, int iBegin, int iMiddle, int iEnd, int *b);
void copyArray(int *b, int iBegin, int iEnd, int *a);
*/

#endif // COMMON_H_
