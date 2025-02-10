#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100 // 最大事件数量

typedef struct {
    int year;
    int month;
    int day;
    char description[100];
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

// 判断是否为闰年
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某月的天数
int get_days_in_month(int year, int month) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_in_month[month - 1];
}


//计算每个月的第一天是星期几，打印该月的日历 
int getFirstDayOfWeek(int year, int month) {
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    int c = year / 100;
    int y = year % 100;
    int d = 1; // 第一天
    int w = (d + 2*month + 3*(month+1)/5 + y + y/4 - y/100 + y/400 + 1) % 7;
    return w;
}

 //打印某年的某月的日历
void print_calendar(int year, int month) {
    int days = get_days_in_month(year, month);
     int start_day =0;
    if (month == 2 && is_leap_year(year)) {
        start_day = getFirstDayOfWeek(year,month)+1;
    }
    else
	{
		start_day = getFirstDayOfWeek(year,month);
	}
    printf("     %d年%d月\n", year, month);
    printf("日 一 二 三 四 五 六\n");

    for (int i = 0; i < start_day; i++) {
        printf("   ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((start_day + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}


// 添加事件
void add_event() {
    if (event_count >= MAX_EVENTS) {
        printf("事件列表已满，无法添加更多事件。\n");
        return;
    }
    Event e;
    printf("请输入事件的年份：");
    scanf("%d", &e.year);
    printf("请输入事件的月份：");
    scanf("%d", &e.month);
    printf("请输入事件的日期：");
    scanf("%d", &e.day);
    printf("请输入事件描述：");
    getchar(); // 清除缓冲区
    fgets(e.description, 100, stdin);
    e.description[strcspn(e.description, "\n")] = '\0'; // 移除换行符

    events[event_count++] = e;
    printf("事件已添加成功！\n");
}

// 查询事件
void query_event() {
    int year, month, day;
    printf("请输入查询的年份：");
    scanf("%d", &year);
    printf("请输入查询的月份：");
    scanf("%d", &month);
    printf("请输入查询的日期：");
    scanf("%d", &day);

    int found = 0;
    for (int i = 0; i < event_count; i++) {
        if (events[i].year == year && events[i].month == month && events[i].day == day) {
            printf("事件：%s\n", events[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("未找到任何事件。\n");
    }
}

// 主菜单
void menu() {
    int choice;
    while (1) {
        printf("\n===== 万年历 =====\n");
        printf("1. 显示日历\n");
        printf("2. 添加事件\n");
        printf("3. 查询事件\n");
        printf("4. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int year, month;
                printf("请输入年份：");
                scanf("%d", &year);
                printf("请输入月份：");
                scanf("%d", &month);
                print_calendar(year, month);
                break;
            }
            case 2:
                add_event();
                break;
            case 3:
                query_event();
                break;
            case 4:
                printf("再见！\n");
                exit(0);
            default:
                printf("无效选择，请重新输入。\n");
        }
    }
}

int main() {
    menu();
    return     0;
}
