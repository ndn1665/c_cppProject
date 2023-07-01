#ifndef BANKING_COMMON_DECL_H__
#define BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
using std::cin;

const int NAME_LEN = 20;

//프로그램 사용자의 선택메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};
//계좌의 종류
enum {NORMAL = 1,HIGH_CREDIT = 2};

#endif // !BANKING_COMMON_DECL_H__
