#include <stdio.h>
#include <stdlib.h>

//Kyle Fleming
//93089
//Frida 1 pm
//Lab 05
// Program that takes an input file and performs various functions to generate sales reports
//collaborators - None

#define M 12  // making a constant for # of months

// names for output
const char *months[M] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// monthly sales func
void printMonthlySales(double sales[]) {
    for (int i = 0; i < M; i++) {
        // print month with report
        printf("%-10s\t$%.2f\n", months[i], sales[i]);
    }
}

// sales summary func
void printSalesSummary(double sales[]) {
    double min = sales[0], max = sales[0], total = 0.0;  // Initialize min, max, and total
    int minmonth = 0, maxmonth = 0;  // keep track of min and max
    
    // looping through each mnonth
    for (int i = 0; i < M; i++) {
        total += sales[i];  // for average
        if (sales[i] < min) {
            min = sales[i];  // Update min
            minmonth = i;  // store min month
        }
        if (sales[i] > max) {
            max = sales[i];  // Update max
            maxmonth = i;  // store max month
        }
    }
    
    // average sales
    double avg = total / M;
    // min, avg, max with month
    printf("Minimum sales: $%.2f (%s)\n", min, months[minmonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxmonth]);
    printf("Average sales: $%.2f\n", avg);
}

// moving report func
void printMovingAvg(double sales[]) {
    // Loop through each possible six-month period (7 periods total)
    for (int i = 0; i <= M - 6; i++) {
        double total = 0.0;
        // Calculate the total of sales for the current six-month period
        for (int j = i; j < i + 6; j++) {
            total += sales[j];
        }
        // Calculate the average sales for the current six-month period
        double avg = total / 6;
        // Print the range of months and the moving average
        printf("%s-%s\t$%.2f\n", months[i], months[i + 5], avg);
    }
}

// high to low func
void printSalesSorted(double sales[]) {
    // arrays for storages
    double sorted[M];
    int indices[M];
    
    // copy into sorting arrays
    for (int i = 0; i < M; i++) {
        sorted[i] = sales[i];
        indices[i] = i;
    }
    
    // bubble sort to descending
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - i - 1; j++) {
            if (sorted[j] < sorted[j + 1]) {
                // swap to sort in descending order
                double temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
                
                // swap to maintain month-to-sales mapping
                int tempIdx = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tempIdx;
            }
        }
    }
    
    // print sorted sales
    printf("Month\t\tSales\n");
    for (int i = 0; i < M; i++) {
        // Print each month's name and corresponding sorted sales figure
        printf("%-10s\t$%.2f\n", months[indices[i]], sorted[i]);
    }
}


int main() {
    // sale data array
    double sales[M];
    
    // read from input
    FILE *f = fopen("sales_input.txt", "r");
    if (f == NULL) {
        // file not found error handling
        printf("Error: Unable to open file.\n");
        return 1;
    }
    
    // storing info into the array
    for (int i = 0; i < M; i++) {
        fscanf(f, "%lf", &sales[i]);  // read as a double
    }
    
    fclose(f);  // close file

    // generating reports
    printf("Monthly Sales Report for 2024\n");
    printf("Month\t\tSales\n");
    printMonthlySales(sales);  // print monthly sales

    printf("\nSales summary report:\n");
    printSalesSummary(sales);  // print sales summary

    printf("\nSix-Month moving average report:\n");
    printMovingAvg(sales);  // print six month moving average

    printf("\nSales report (highest to lowest):\n");
    printSalesSorted(sales);  // print sales in descending

    return 0;
}
