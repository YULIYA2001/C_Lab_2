#include <stdio.h>
#include <conio.h>
#include <locale.h>

void decision(int weight, int distance);
void order_details(int weight, int distance);

void my_2_1_6(void)
{
    int weight = 0, distance = 0;
    char choose;

    setlocale (LC_CTYPE, "Russian");
    printf("\t\t\t\t\t\tTask 1: \"EUROTRANS GROUP\"\n\n");
    printf("1 - ���� ���� (�� 50 �� 300)\n2 - ���� ���������� (�� ����� 4000)\n3 - ������� ������������ ������\n");
    printf("4 - ��������� ������\n5 - ������ � ����� ���������\n6 - �����\n");
    do
    {
        printf("\n�������� ����� ����: ");
        choose = _getche();
        printf("\n");
        switch (choose)
        {
            case '1':
            {
                /* ���� ����� � �������� ����� (����� ���� ��� �������� ��������) */
                printf("������� ��� ����� (�����): ");
                while (scanf("%d", &weight) != 1)
                {
                    scanf("%*[^\n]");
                    printf("������������ ����. ������� ��� ���: ");
                }
                break;
            }
            case '2':
            {
                /* ���� ����� � �������� ����� (����� ���� ��� �������� ��������) */
                printf("������� ���������� ��������� (��): ");
                while (scanf("%d", &distance) != 1)
                {
                    scanf("%*[^\n]");
                    printf("������������ ����. ������� ��� ���: ");
                }
                break;
            }
            case '3':
            {
                decision(weight, distance);
                break;
            }
            case '4':
            {
                order_details(weight, distance);
                break;
            }
            case '5':
            {
                printf("������ 1.0.0\t�����: ��������� �. �.\n");
                break;
            }
            case '6':
            {
                printf("�� ����� �� ���������\n");
                break;
            }
            default: printf("�������� ����� ����\n");
        }
    } while (choose != '6');
}

/* ������� � �������� ������ */
void decision(int weight, int distance)
{
    if ((weight <= 0) || (distance <= 0))
        printf("�������� �������� ������. ������� ������\n");
    else
    {
        if ((weight < 50) || (weight > 300) || (distance > 4000))
            printf("��� ����� �������� \n");
        else
            printf("��� ����� ������ \n");
    }
}

/* ����� ���������� ������ ��� ��� �������� */
void order_details(int weight, int distance)
{
    int cars;
    float order_cost, insurance;

    if ((weight <= 0) || (distance <= 0))
        printf("�������� �������� ������. ������� ������\n");
    else
    {
        if ((weight < 50) || (weight > 300) || (distance > 4000))
            printf ("��� ����� ��������\n");
        else
        {
            if ((weight % 20) == 0)
                cars = weight / 20;
            else
                cars = (weight / 20) + 1;
            insurance = distance * 2 * cars * 0.05;
            order_cost = (distance * 2 * cars) + insurance;
            printf("���������� ����� - %d\n", cars);
            printf("��������� ��������� - %.2f $\n", insurance);
            printf("����� ��������� ������ - %.2f $\n", order_cost);
        }
    }
}
