#include <stdio.h>

struct Resource
{
    int personnel;
    int vehicles;
    int fuel;
    int food;
    int medical;
};

int main()
{
    struct Resource r;
    int risk = 0;

    printf("====================================\n");
    printf(" DEFENCE RESOURCE INTELLIGENCE SYSTEM\n");
    printf("====================================\n");

    printf("\nEnter Personnel: ");
    scanf("%d", &r.personnel);

    printf("Enter Vehicles: ");
    scanf("%d", &r.vehicles);

    printf("Enter Fuel (%%): ");
    scanf("%d", &r.fuel);

    printf("Enter Food (%%): ");
    scanf("%d", &r.food);

    printf("Enter Medical (%%): ");
    scanf("%d", &r.medical);

    /* Fuel Risk */
    if (r.fuel < 30)
        risk += 30;
    else if (r.fuel < 60)
        risk += 15;

    /* Food Risk */
    if (r.food < 30)
        risk += 25;
    else if (r.food < 60)
        risk += 10;

    /* Medical Risk */
    if (r.medical < 30)
        risk += 30;
    else if (r.medical < 60)
        risk += 15;

    /* Vehicle Risk */
    if (r.vehicles < 5)
        risk += 10;
    else if (r.vehicles < 10)
        risk += 5;

    printf("\n========== RESOURCE STATUS ==========\n");

    printf("Personnel : %d\n", r.personnel);
    printf("Vehicles  : %d\n", r.vehicles);
    printf("Fuel      : %d%%\n", r.fuel);
    printf("Food      : %d%%\n", r.food);
    printf("Medical   : %d%%\n", r.medical);

    printf("\n========== RISK ANALYSIS ==========\n");

    printf("Risk Score: %d\n", risk);

    if (risk >= 60)
    {
        printf("Risk Level: HIGH\n");
        printf("Status: Immediate attention required.\n");
    }
    else if (risk >= 30)
    {
        printf("Risk Level: MODERATE\n");
        printf("Status: Resources need monitoring.\n");
    }
    else
    {
        printf("Risk Level: LOW\n");
        printf("Status: Resources are stable.\n");
    }

    printf("\n========== PRIORITY ==========\n");

    if (r.medical < 30)
        printf("Medical resources need priority.\n");
    else if (r.fuel < 30)
        printf("Fuel resources need priority.\n");
    else if (r.food < 30)
        printf("Food resources need priority.\n");
    else if (r.vehicles < 5)
        printf("Vehicles need priority.\n");
    else
        printf("All resources are at acceptable levels.\n");

    printf("\nAnalysis completed.\n");

    return 0;
}