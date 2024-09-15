// A Hospital management system.....


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct patient
{
    int id;
    char patientName[105];
    int patientAge;
    char patientDisease[25];
    char patientGender[15];
    char patientContact[25];
    char patientAddress[55];
    char date[15];
} p;

struct doctor
{
    int id;
    char doctorName[105];
    char doctorAddress[105];
    char specialize[105];
    char date[15];
} d;

FILE *hos, *fp, *ft;

void admitPatient();
void patientList();
void dischargePatient();
void addDoctor();
void doctorList();
void getchoice();

int main()
{
    int choice;
    do
    {
        printf("**<< Welcome to Hospital Management System >>**\n\n\n");
        printf("1. Admit patient\n");
        printf("2. Patient List\n");
        printf("3. Discharge Patient\n");
        printf("4. Add Doctor\n");
        printf("5. Doctor List\n");
        printf("0. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            admitPatient();
            break;
        case 2:
            patientList();
            break;
        case 3:
            dischargePatient();
            break;
        case 4:
            addDoctor();
            break;
        case 5:
            doctorList();
            break;
        default:
            printf("<< Invalid Choice >>\n");
            printf("\n\n<< Press Any Key To Continue....");
            getchoice();
        }
    } while (choice != 0);

    return 0;
}

void admitPatient()
{
    char myDate[105];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(p.date, myDate);
    hos = fopen("patient.txt", "ab");
    if (hos == NULL)
    {
        printf("Error Opening The File!");
        exit(0);
    }
    printf("Enter Patient Id: \n");
    scanf("%d", &p.id);

    printf("Enter Patient Name: \n");
    fflush(stdin);
    gets(p.patientName);

    printf("Enter Patient Address: \n");
    fflush(stdin);
    gets(p.patientAddress);

    printf("Enter Patient Disease: \n");
    fflush(stdin);
    gets(p.patientDisease);

    printf("Enter Patient Age: \n");
    fflush(stdin);
    scanf("%d", &p.patientAge);

    printf("Enter Patient Gender: \n");
    fflush(stdin);
    gets(p.patientGender);

    printf("Enter Patient Contact Number: \n");
    fflush(stdin);
    gets(p.patientContact);

    printf("\n<< Patient Added Successfully >>\n\n\n");

    fwrite(&p, sizeof(p), 1, hos);
    fclose(hos);
}

void patientList()
{
    printf("<== Patient List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %-10s %-10s %-25s %s\n", "Id", "Patient Name", "Address", "Disease", "Age", "Gender", "Contact", "Date");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    fp = fopen("patient.txt", "rb");
    if (fp == NULL)
    {
        printf("Error Opening The File!");
        exit(0);
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-20s %-10d %-10s %-25s %s\n", p.id, p.patientName, p.patientAddress, p.patientDisease, p.patientAge, p.patientGender, p.patientContact, p.date);
    }

    fclose(fp);
}

void dischargePatient()
{
    int id, f = 0;
    printf("<<== Discharge patient ==>>\n");
    printf("Enter Patient Id: \n");
    scanf("%d", &id);

    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    if (fp == NULL || ft == NULL)
    {
        printf("Error Opening The File!");
        exit(0);
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (p.id == id)
        {
            f = 1;
        }
        else
        {
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (f == 1)
    {
        remove("patient.txt");
        rename("temp.txt", "patient.txt");
        printf("\n\nPatient Discharged Successfully.\n\n");
    }
    else
    {
        remove("temp.txt");
        printf("\n\nRecord Not Found.\n\n");
    }
}

void addDoctor()
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    printf("<<== Add Doctor ==>>\n");
    fp = fopen("doctor.txt", "ab");
    if (fp == NULL)
    {
        printf("Error Opening The File!\n");
        exit(0);
    }

    printf("Enter Doctor Id: \n");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: \n");
    fflush(stdin);
    gets(d.doctorName);

    printf("Enter Doctor Address: \n");
    fflush(stdin);
    gets(d.doctorAddress);

    printf("Doctor Specialize in: \n");
    fflush(stdin);
    gets(d.specialize);

    printf("\n<< Doctor Added Successfully >>\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}

void doctorList()
{
    printf("<<== Doctor List ==>>\n\n");
    printf("%-10s %-30s %-30s %-30s %s\n", "Id", "Name", "Address", "Specialize", "Date");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("doctor.txt", "rb");
    if (fp == NULL)
    {
        printf("Error Opening The File!");
        exit(0);
    }

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.doctorName, d.doctorAddress, d.specialize, d.date);
    }

    fclose(fp);
}

void getchoice()
{
    getchar();
}
