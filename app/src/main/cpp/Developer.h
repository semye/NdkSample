//
// Created by yesheng on 2018/3/26.
//

#ifndef CBASE_DEVELOPER_H
#define CBASE_DEVELOPER_H

#include <string>
#include "Developer.h"



void test();

using namespace std;

#define SEMYE "SEMYE"
#define fucks "SB"
#define PI 3.14
#define BUF_SIZE 1024
const string yesheng = "yesheng";


class Developer {
public:
    Developer();


public:
    int name;

    void writeCode();

    string hello();

    int getAge();

    string getName();

    double length{};
    double breadth{};
    double height{};

    string getPlayer();


private:
    int age;

    // 对外隐藏的数据
    int total();

protected:
    int sex;

};


#endif
