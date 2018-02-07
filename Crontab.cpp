// Crontab.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int monarray[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

struct cron
{
	string minutes;
	string hours;
	string dayofmonth;
	string month;
	string dayofweek;
	string command;
};

bool isrunyear(int year) {
	return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

vector<string> splitStringAndbuildVector(string s,int tag)//0为其它，1为月，2为dayofweek
{
	vector<string> ret;

	if (s == "*") {
		if (tag == 1) {
			for (int i = 1; i <= 12; i++) {
				
			}
		}
	}
}

int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;
	cron *crontab = new cron[n];
	int i, j, k, m, n;
	
	string startyear = s.substr(0, 4), startmonth = s.substr(4, 2),
		startday = s.substr(6, 2), starthour = s.substr(8, 2), startmin = s.substr(10, 2);
	string endyear = s.substr(0, 4), endmonth = s.substr(4, 2),
		endday = s.substr(6, 2), endhour = s.substr(8, 2), endmin = s.substr(10, 2);
	int syear = atoi(startyear.c_str), eyear = atoi(endyear.c_str);
	int smon = atoi(startmonth.c_str), emon = atoi(endmonth.c_str);
	int sday = atoi(startday.c_str), eday = atoi(endday.c_str);
	int shour = atoi(starthour.c_str), ehour = atoi(endhour.c_str);
	int smin = atoi(startmin.c_str), emin = atoi(endmin.c_str);

	for (i = 0; i < n; i++) {
		string minutes, hours, dofmon, month, dofwek, command;
		vector<string> vmts, vhur, vdfm, vmth, vdfw;
		cin >> minutes >> hours >> dofmon >> month >> dofwek >> command;
		if (minutes == "*") minutes = "0-59";
		vmts = splitStringAndbuildVector(minutes, 0);//应该执行的分钟 
		if (hours == "*") hours = "0-23";
		vhur = splitStringAndbuildVector(hours, 0); //应该执行的小时
		if (dofmon == "*") dofmon = "1-31";
		vdfm = splitStringAndbuildVector(dofmon, 0);//应该执行的日期
		if (month == "*") month = "1-12";
		vmth = splitStringAndbuildVector(month, 1);//应该执行的月份 
		if (dofwek == "*") dofwek = "0-6";
		vdfw = splitStringAndbuildVector(dofwek, 2);//应该周几执行


	}
	

	for (i = syear; i <= eyear; i++) {
		if (isrunyear(i)) monarray[2] = 29;
		else monarray[2] = 28;

	}
    return 0;
}

