#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <iomanip>

using namespace std;

typedef struct user_info{
    string name;
    int time[5];
    int statue;
}info;

// bool cmp_name (info a, info b) {
//     return a.name < b.name;
// }

// bool cmp_time (info a, info b) {
//     if (a.name == b.name && a.time[0] == b.time[0]) {
//         return a.time[4] < b.time[4];
//     }
//     return false;
// }

// bool cmp_month (info a, info b) {
//     if (a.name == b.name) {
//         return a.time[0] < b.time[0];
//     }
//     return false;
// }

bool cmp(info a, info b) {
    if (a.name != b.name) {
        return a.name < b.name;
    }
    else if (a.time[0] != b.time[0]) {
        return a.time[0] < b.time[0];
    }
    else if (a.time[1] != b.time[1]) {
        return a.time[1] < b.time[1];
    }
    else if (a.time[2] != b.time[2]) {
        return a.time[2] < b.time[2];
    }
    else {
        return a.time[3] < b.time[3];
    }
}

int main () {
    vector <double> toll;
    double temp;
    double dayofcharge = 0;
    for (int i = 0; i < 24; i++) {
        cin >> temp;
        temp = temp * 0.01;
        dayofcharge += temp * 60;
        toll.push_back(temp);
    }
    int n;
    cin >> n;
    vector <info> data;
    info userdata;
    string state;
    for (int i = 0; i < n; i++) {
        cin >> userdata.name;
        scanf("%d:%d:%d:%d", &userdata.time[0], &userdata.time[1], &userdata.time[2], &userdata.time[3]);
        userdata.time[4] = userdata.time[3] + userdata.time[2] * 60 + userdata.time[1] * 24 * 60;
        cin >> state;
        if (state == "on-line") {
            userdata.statue = 0;
        }
        else {
            userdata.statue = 1;
        }
        data.push_back(userdata);
    }
    sort(data.begin(), data.end(), cmp);
    // sort(data.begin(), data.end(), cmp_month);
    // sort(data.begin(), data.end(), cmp_time);
    string name_now;
    double total = 0;
    int hasfinished = 0;
    int lastflag = 0;
    int i = 0;
    double tempcharge = 0;
    for (int i = 0; i < n - 1; i++) {
        if (data[i].name == data[i + 1].name) {
            if (data[i + 1].statue == 1 && data[i].statue == 0) {
                if (hasfinished == 0) {
                    cout << data[i].name << " ";
                    printf("%02d\n", data[i].time[0]);
                    hasfinished = 1;
                }
                int tempd = data[i].time[1];
                int temph = data[i].time[2];
                int tempm = data[i].time[3];
                tempcharge = 0;
                // while (tempd < data[i + 1].time[1]) {
                //     tempcharge += dayofcharge;
                //     tempd++;
                // }
                // if (temph < data[i + 1].time[2] && tempd < data[i + 1].time[1]) {
                //     tempcharge += dayofcharge;
                // }
                while (tempd != data[i + 1].time[1] || temph != data[i + 1].time[2] || tempm != data[i + 1].time[3]) {
                    tempcharge += toll[temph];
                    tempm++;
                    if (tempm == 60) {
                        tempm = 0;
                        temph++;                  
                    }
                    if (temph == 24) {
                        tempd++;
                        temph = 0;
                    }
                }
                tempcharge = tempcharge + toll[temph] * (data[i + 1].time[3] - tempm);
                printf("%02d:%02d:%02d ", data[i].time[1], data[i].time[2], data[i].time[3]);
                printf("%02d:%02d:%02d ", data[i + 1].time[1], data[i + 1].time[2], data[i + 1].time[3]);
                cout << data[i + 1].time[4] - data[i].time[4] << " " << "$";
                printf("%.2lf\n", tempcharge);
                total += tempcharge;
                }
        }
        else {
            if (hasfinished == 1) {
                cout << "Total amount: $";
                printf("%.2lf\n", total);
            }
            total = 0;
            hasfinished = 0;
            tempcharge = 0;
        }
    }
    if (hasfinished == 1) {
        cout << "Total amount: $";
        printf("%.2lf", total);       
    }
    return 0;
}

/*
真不知道哪里错了，找了几种测试数据都没发现区别，好你妈离谱
不过有些答案把所有的比较全部写在一个函数里，可以学习一下

妈的，好像是我的算钱的方法算错了，宁愿1分钟1分钟加也不要考虑跨天直接加天数，不知道少考虑了什么情况反正就是错了
*/

// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// int toll[24];
// struct Rec{
// 	char name[25];
// 	int mon,dd,hh,mm;
// 	int isOn;
// }rec[1010];
// bool cmp(Rec a, Rec b){
// 	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name)<0;
//     else if (a.mon!=b.mon) return a.mon<b.mon;
// 	else if (a.dd!=b.dd) return a.dd<b.dd;
// 	else if (a.hh!=b.hh) return a.hh<b.hh;
// 	else return a.mm<b.mm;
// }
// int  getAmount(Rec a, Rec b, double& amount){
// 	int min=0;
// 	while (a.dd!=b.dd || a.hh!=b.hh || a.mm!=b.mm){
// 		amount+=toll[a.hh];
// 		a.mm++;
// 		min++;
// 		if (a.mm==60){
// 			a.hh++;
// 			a.mm=0;
// 		}
// 		if (a.hh==24){
// 			a.dd++;
// 			a.hh=0;
// 		}
// 	}
// 	return min;
// }
// int main(){
// 	for (int i=0; i<24; i++){
// 		scanf("%d",&toll[i]);
// 	}
// 	int n;
// 	scanf("%d",&n);
// 	for (int i=0; i<n; i++){
// 		char temp[20];
// 		scanf("%s %d:%d:%d:%d %s",rec[i].name,&rec[i].mon,&rec[i].dd,&rec[i].hh,&rec[i].mm,temp);
// 		if (strcmp(temp,"on-line")) rec[i].isOn=0;
// 		else rec[i].isOn=1;
// 	}
// 	sort(rec,rec+n,cmp);
// 	int flag=0,min=0;
// 	double amount=0,all=0;
// 	for (int i=0; i<n-1; i++){
// 		if (strcmp(rec[i].name,rec[i+1].name)==0){
// 			if (rec[i].isOn && !rec[i+1].isOn){
// 				if (!flag) {
// 					printf("%s %02d\n",rec[i].name,rec[i].mon);
// 					flag=1;
// 				}
// 				amount=0;
// 				min=getAmount(rec[i],rec[i+1],amount);
// 				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",rec[i].dd,rec[i].hh,rec[i].mm,
// 				rec[i+1].dd,rec[i+1].hh,rec[i+1].mm,min,amount/100);
// 				all+=amount/100;	
// 			}
// 		}else {
// 			if (flag){
// 				printf("Total amount: $%.2f\n",all);
// 			}
// 			flag=all=amount=min=0;
// 		}
// 	}
// 	if (flag){
// 		printf("Total amount: $%.2f",all);
// 	}
//     system("pause");
//     return 0;
// }
