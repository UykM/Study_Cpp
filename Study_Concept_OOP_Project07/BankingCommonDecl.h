#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int Name_Lens = 20;             // 입력할 이름의 최대 길이 

// 프로그램 사용자의 선택 메뉴
enum { Make = 1, DEPOSIT, WITHDRAW, INFORM, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };
