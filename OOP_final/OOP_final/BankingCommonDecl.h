#ifndef BANKING_COMMON_DECL_H__
#define BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
using std::cin;

const int NAME_LEN = 20;

//���α׷� ������� ���ø޴�
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//�ſ���
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};
//������ ����
enum {NORMAL = 1,HIGH_CREDIT = 2};

#endif // !BANKING_COMMON_DECL_H__
