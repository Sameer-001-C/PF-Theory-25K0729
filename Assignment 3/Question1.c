#include <stdio.h>

//We are assuming here that the interest is charged AFTER the first payment has been paid, to the REMAINING loan amount, as stated in the question:
//"The loan decreases each year AFTER paying a fixed installment, and interest is applied annually to the REMAINING loan."


float calculateRepayment(float loan, float interestRate, int years, float installmentAmount, int initialYears, float extraPayment, float total){ //returns amount
	if(loan <= 0 || years == 0){
		return total;
	}
	if(loan < installmentAmount + extraPayment){ //for eg, loan is 200 and payment given is 300, so ofcourse only 200 needs to be paid
		total += loan; //so now, only add this 200 into the total instead of the 300 to the total
	}
	loan -= (installmentAmount + extraPayment); //payment of the installments and extra amount should decrease the remaining amount to be paid (loan)
	if(loan < 0){
		loan = 0; 
	}
	else{
		total += (installmentAmount + extraPayment); //if even after payment, we still have some loan to be paid, then add the payment made currectly to the total
	}
	
	loan = loan*(1 + interestRate); //apply interest on the remaining amount
	printf("Year %d: Remaining loan = %.2f\n", initialYears - years + 1, loan); //print the remaining loan for that year, after the payment for that year has been made
	
	//call function for the remaining loan, with n-1 years, same installmentAmount, same initialYears, and same extraPayment, and updated total
	return calculateRepayment(loan, interestRate, years - 1, installmentAmount, initialYears, extraPayment, total);
}

int main(){
	float loan = 100000, interestRate = 5.0/100;
	int years = 3;
	float total = 0;
	/*
	printf("Please enter total amount of loan: ");
	scanf("%f", &loan);
	printf("Please enter total years for the repayment of the loan: ");
	scanf("%d", &years);
	printf("Please enter annual interest rate: ");
	scanf("%f", &interestRate);
	*/
	float extraPayment = 0;
	char choice;
	printf("Do you want to add an extra yearly payment? (y/n): ");
	scanf(" %c", &choice);
	if(choice == 'y'){
		printf("Enter annual extra amount: ");
		scanf("%f", &extraPayment);
	}
	float installmentAmount = 36720.86; //hardcoding it for the currect scenario as the calculation uses power/indices
	total = calculateRepayment(loan, interestRate, years, installmentAmount, years, extraPayment, total);
	printf("Total Amount to be paid: %.2f", total);
	
}

//Note:

/*since the initial loan was 100000, paying the installment plus the 1000 extra payment would mean we would be left with 62279.14,
at which interest would be applied, which would now become 65393.09, which is the remaining loan for the first year as well as the output for first year. now, for the
second year, the installemnt, plus the extra 1000, would be paid, leaving the loan to be 27672.237, at which interest would be 
applied, which would now become 29,055.85, which would be the output for year 2. now, for the third year, the installment amount
to be paid plus the extra 1000 is greater than the loan remaining, so, only the remaining loan would now need to be paid, and
hence, 29055.85 would be paid, leaving the remaining loan to be zero, at which, no interest would be applied, so the output 
would be the remaining loan, which is equal to 0 for the third year. this way, all the loan has been paid back.

For the total amount to be paid, the amount paid each year is added. the amount paid each year is equal to yearlyInstallemnt + extraAmount.
By default, the extra amount is zero to be paid, unless specified by the user. The total is updated and passed to the function call inside
the function, until we reach a point where the loan to be paid is less than the actual amount that the customer has been paying yearly so,
now, only the remaining amount needs to be paid, therefore, the total is instead updated and increamented by this remaiing amount. The total
is then returned at the end, when the loan is fully paid (loan = 0).
*/
