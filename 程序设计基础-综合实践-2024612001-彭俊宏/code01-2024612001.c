#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100 // ����¼�����

typedef struct {
    int year;
    int month;
    int day;
    char description[100];
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

// �ж��Ƿ�Ϊ����
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ��ȡĳ�µ�����
int get_days_in_month(int year, int month) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_in_month[month - 1];
}


//����ÿ���µĵ�һ�������ڼ�����ӡ���µ����� 
int getFirstDayOfWeek(int year, int month) {
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    int c = year / 100;
    int y = year % 100;
    int d = 1; // ��һ��
    int w = (d + 2*month + 3*(month+1)/5 + y + y/4 - y/100 + y/400 + 1) % 7;
    return w;
}

 //��ӡĳ���ĳ�µ�����
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
    printf("     %d��%d��\n", year, month);
    printf("�� һ �� �� �� �� ��\n");

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


// ����¼�
void add_event() {
    if (event_count >= MAX_EVENTS) {
        printf("�¼��б��������޷���Ӹ����¼���\n");
        return;
    }
    Event e;
    printf("�������¼�����ݣ�");
    scanf("%d", &e.year);
    printf("�������¼����·ݣ�");
    scanf("%d", &e.month);
    printf("�������¼������ڣ�");
    scanf("%d", &e.day);
    printf("�������¼�������");
    getchar(); // ���������
    fgets(e.description, 100, stdin);
    e.description[strcspn(e.description, "\n")] = '\0'; // �Ƴ����з�

    events[event_count++] = e;
    printf("�¼�����ӳɹ���\n");
}

// ��ѯ�¼�
void query_event() {
    int year, month, day;
    printf("�������ѯ����ݣ�");
    scanf("%d", &year);
    printf("�������ѯ���·ݣ�");
    scanf("%d", &month);
    printf("�������ѯ�����ڣ�");
    scanf("%d", &day);

    int found = 0;
    for (int i = 0; i < event_count; i++) {
        if (events[i].year == year && events[i].month == month && events[i].day == day) {
            printf("�¼���%s\n", events[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("δ�ҵ��κ��¼���\n");
    }
}

// ���˵�
void menu() {
    int choice;
    while (1) {
        printf("\n===== ������ =====\n");
        printf("1. ��ʾ����\n");
        printf("2. ����¼�\n");
        printf("3. ��ѯ�¼�\n");
        printf("4. �˳�\n");
        printf("���������ѡ��");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int year, month;
                printf("��������ݣ�");
                scanf("%d", &year);
                printf("�������·ݣ�");
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
                printf("�ټ���\n");
                exit(0);
            default:
                printf("��Чѡ�����������롣\n");
        }
    }
}

int main() {
    menu();
    return     0;
}
