#include <iostream>
#include <string>
#include <cmath>

// Removes comma thousands-separators from a numeric string (e.g. "4,000,000" -> "4000000")
std::string stripCommas(const std::string &input) {
    std::string result;
    for (char c : input) {
        if (c != ',') {
            result += c;
        }
    }
    return result;
}

double computeResidentTax(double income) {
    if (income <= 2820000.0) {
        return 0.0;
    } else if (income <= 4020000.0) {
        return (income - 2820000.0) * 0.10;
    } else if (income <= 4920000.0) {
        return (income - 4020000.0) * 0.20 + 120000.0;
    } else if (income <= 120000000.0) {
        return (income - 4920000.0) * 0.30 + 300000.0;
    } else {
        double baseTax = (income - 4920000.0) * 0.30 + 300000.0;
        double surcharge = (income - 120000000.0) * 0.10;
        return baseTax + surcharge;
    }
}

double computeNonResidentTax(double income) {
    if (income <= 2820000.0) {
        return income * 0.10;
    } else if (income <= 4020000.0) {
        return income * 0.10;
    } else if (income <= 4920000.0) {
        return (income - 4020000.0) * 0.20 + 402000.0;
    } else if (income <= 120000000.0) {
        return (income - 4920000.0) * 0.30 + 582000.0;
    } else {
        double baseTax = (income - 4920000.0) * 0.30 + 582000.0;
        double surcharge = (income - 120000000.0) * 0.10;
        return baseTax + surcharge;
    }
}

int main() {
    int residenceStatus;
    std::string incomeInput;

    std::cout << "(0-Resident, 1-Non-resident)\n";
    std::cout << "Enter the residence status: ";
    std::cin >> residenceStatus;

    std::cout << "Enter the taxable income: ";
    std::cin >> incomeInput;

    double taxableIncome = std::stod(stripCommas(incomeInput));

    double tax;
    if (residenceStatus == 0) {
        tax = computeResidentTax(taxableIncome);
    } else {
        tax = computeNonResidentTax(taxableIncome);
    }

    // Print without unnecessary decimal places (whole shillings)
    std::cout << "Tax is " << static_cast<long long>(std::round(tax)) << "." << std::endl;

    return 0;
}
