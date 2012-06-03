#include <iostream>

using namespace std;

/*
*  结构体内存对齐
*  0. 为了提高内存读取速度,变量间不是紧密挨着的,之间有为了对齐而补全的缝隙
*  1. 变量依次存入地址的偏移量(相对于结构体首址)为自身长度整数倍
*  2. 结构体长度必然是最长变量的整数倍
*/
struct st {
	char c;
	short a;
	long b;
	char c1;

} ;

int main (){
	/* 1 byte*/
	bool v_bool;
	/* 1 byte*/
	char v_char;
	/* 2 byte*/
	short v_short;
    /* 4/8 byte (gcc), 与机器字长,编译器有关 */
	int v_int ;
    /* 8 byte */
	long v_long;
    /* 4 byte */
	float v_float;
    /* 8 byte */
	double v_double;
    /* 16 byte */
	long double v_longdouble;
	
	cout <<"bool:"       << sizeof(v_bool)<< endl;
	cout <<"char:"       << sizeof(v_char)<< endl;
	cout <<"short:"      << sizeof(v_short)<< endl;
	cout <<"int:"        << sizeof(v_int)<< endl;
	cout <<"long:"       << sizeof(v_long)<< endl;
	cout <<"float:"      << sizeof(v_float)<< endl;
	cout <<"double:"     << sizeof(v_double)<< endl;
	cout <<"long double:"<< sizeof(v_longdouble)<< endl;
	cout << "STRUCT:"    <<sizeof(st)<< endl;

}
