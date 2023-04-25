#include <stdio.h>
#include <math.h>

// Function to compute r
double compute_r(double x_sum, double y_sum, double xy_sum, double x_squared_sum, int n) {
    double m = ((n * xy_sum) - (x_sum * y_sum)) / ((n * x_squared_sum) - pow(x_sum, 2));
    return m;
}

// Function to compute k
double compute_k(double x_sum, double y_sum, double xy_sum, double x_squared_sum, int n) {
    double m = compute_r(x_sum, y_sum, xy_sum, x_squared_sum, n);
    double a = exp((y_sum - (m * x_sum)) / n);
    return a;
}

// Function to compute the time needed for detoxication
double compute_detox_time(double k, double r, double safe_threshold) {
    double time = (log(safe_threshold / k)) / r;
    return time;
}

int main() {
    // Print welcome message
    printf("Welcome to Toxic Waste Calculator\n");

    // Prompt user to enter samples
    double c, t = 0.0;
    int n = 0;
    double x_sum = 0.0, y_sum = 0.0, xy_sum = 0.0, x_squared_sum = 0.0;

    while (1) {
        printf("Please enter the concentration at time %.0f min: ", t);
        scanf("%lf", &c);
        if (c == -1) {
            break;
        }
        x_sum += t;
        y_sum += log(c);
        xy_sum += t * log(c);
        x_squared_sum += pow(t, 2);
        t += 1.0;
        n += 1;
    }

    // Prompt user for safe concentration threshold
    double safe_threshold;
    printf("Please enter the safe concentration threshold for discharge.\n");
    scanf("%lf", &safe_threshold);

    // Compute k and r
    double k = compute_k(x_sum, y_sum, xy_sum, x_squared_sum, n);
    double r = compute_r(x_sum, y_sum, xy_sum, x_squared_sum, n);

    // Compute detox time and print result
    double detox_time = compute_detox_time(k, r, safe_threshold);
    printf("The r value of the curve: %.4f\n", r);
    printf("The k value of the curve: %.4f\n", k);
    printf("Time needed to reach threshold for discharge: %.4f mins\n", detox_time);

    printf("Thank you for using Toxic Waste Calculator.\n");

    return 0;
}
