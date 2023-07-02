#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include<iostream>
#include<cstring>

#pragma warning(disable: 4996)

using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum {LEVEL_A = 7,LEVEL_B = 4, LEVEL_C = 2 };

enum {NORMAL = 1, CREDIT = 2};

#endif // !BANKING_COMMON_DECL_H__
