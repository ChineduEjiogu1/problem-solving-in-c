/*
  2.   * Computes and prints a water bill given an unpaid balance and previous and
  3.   * current meter readings. Bill includes a demand charge of $35.00, a use
  4.   * charge of $1.10 per thousand gallons, and a surcharge of $2.00 if there is
  5.   * an unpaid balance.
  6.   */

#include <stdio.h>

#define DEMAND_CHG 35.00  /* basic water demand charge                     */
#define PER_1000_CHG 1.10 /* charge per thousand gallons used              */
#define LATE_CHG 2.00     /* surcharge assessed on unpaid balance          */

/* Function prototypes                                                       */
void instruct_water(void);
double comp_use_charge(int previous, int current);
double comp_late_charge(double unpaid);
void display_bill(double late_charge, double bill, double unpaid);

int main(void)
{
    int previous;  /* input - meter reading from previous quarter
27.                                 in thousands of gallons                    */
    int current;   /* input - meter reading from current quarter */
    double unpaid; /* input - unpaid balance of previous bill    */
    double bill;   /* output - water bill                        */
    int used;      /* thousands of gallons used this quarter     */

    double use_charge;  /* charge for actual water use                */
    double late_charge; /* charge for nonpayment of part of previous
34.                                 balance                                    */

    /* Display user instructions.                                     */
    instruct_water();

    /* Get data: unpaid balance, previous and current meter
40.             readings.                                                      */

    printf("Enter unpaid balance> $");
    scanf("%lf", &unpaid);
    printf("Enter previous meter reading> ");
    scanf("%d", &previous);
    printf("Enter current meter reading> ");
    scanf("%d", &current);
    /* Compute use charge.                                            */
    use_charge = comp_use_charge(previous, current);
    /* Determine applicable late charge                               */
    late_charge = comp_late_charge(unpaid);
    /* Figure bill.                                                   */
    bill = DEMAND_CHG + use_charge + unpaid + late_charge;
    /* Print bill.                                                    */
    display_bill(late_charge, bill, unpaid);
    return (0);
}
/*
   64.   * Displays user instructions
   65.   */
void instruct_water(void)
{
    printf("This program figures a water bill ");
    printf("based on the demand charge\n");
    printf("($%.2f) and a $%.2f per 1000 ", DEMAND_CHG, PER_1000_CHG);
    printf("gallons use charge.\n\n");
    printf("A $%.2f surcharge is added to ", LATE_CHG);
    printf("accounts with an unpaid balance.\n");

    printf("\nEnter unpaid balance, previous ");
    printf("and current meter readings\n");
    printf("on separate lines after the prompts.\n");
    printf("Press <return> or <enter> after ");
    printf("typing each number.\n\n");
}

/*
83.   * Computes use charge
84.   * Pre: previous and current are defined.
85.   */
double comp_use_charge(int previous, int current)
{
    int used;          /* gallons of water used (in thousands)             */
    double use_charge; /* charge for actual water use                      */
    used = current - previous;
    use_charge = used * PER_1000_CHG;
    return (use_charge);
}
/*
  99.   * Computes late charge.
 100.   * Pre : unpaid is defined.
 101.   */
double comp_late_charge(double unpaid)
{
    double late_charge; /* charge for nonpayment of part of previous balance  */
    if (unpaid > 0)
        late_charge = LATE_CHG; /* Assess late charge on unpaid balance.    */
    else
        late_charge = 0.0;
    return (late_charge);
}

/*
116.   * Displays late charge if any and bill.
117.   * Pre : late_charge, bill, and unpaid are defined.
118.   */
void display_bill(double late_charge, double bill, double unpaid)

{
    if (late_charge > 0.0)
    {
        printf("\nBill includes $%.2f late charge", late_charge);
        printf(" on unpaid balance of $%.2f\n", unpaid);
    }
    printf("\nTotal due = $%.2f\n", bill);
}