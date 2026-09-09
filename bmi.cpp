#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const double KG_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;

    double weightPounds, heightInches;

    //Prompt for input
    std::cout << "Enter weight in pounds: ";
    std::cin >> weightPounds;

    std::cout << "Enter height in inches: ";
    std::cin >> heightInches;

    //Convert to metric
    double weightKg = weightPounds * KG_PER_POUND;
    double heightMeters = heightInches * METERS_PER_INCH;

    //Calculate BMI
    double bmi = weightKg / (heightMeters * heightMeters);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "BMI is " << bmi << std::endl;

    //Determine category
    if (bmi < 18.5) {
        std::cout << "Underweight" << std::endl;
    } else if (bmi <= 24.9) {
        std::cout << "Normal" << std::endl;
    } else if (bmi <= 29.9) {
        std::cout << "Overweight" << std::endl;
    } else {
        std::cout << "Obese" << std::endl;
    }

    return 0;
}
