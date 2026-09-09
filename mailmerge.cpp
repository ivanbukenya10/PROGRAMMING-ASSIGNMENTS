#include <iostream>
#include <string>
#include <ctime>

// Returns the correct ordinal suffix for a given day (1st, 2nd, 3rd, 4th, etc.)
std::string ordinalSuffix(int day) {
    if (day % 100 >= 11 && day % 100 <= 13) return "th";
    switch (day % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

int main() {
    std::string firstName, lastName, program, academicYear;

    // --- Collect user input ---
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter study program: ";
    std::getline(std::cin, program);

    std::cout << "Enter academic year (e.g. 2027/2028): ";
    std::getline(std::cin, academicYear);

    // --- Autodate: get current system date ---
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    char monthYear[64];
    std::strftime(monthYear, sizeof(monthYear), "%B %Y", now); // e.g. "September 2026"
    int day = now->tm_mday;

    // --- Output the letter ---
    std::cout << "\n";
    std::cout << "Date: " << day << ordinalSuffix(day) << " " << monthYear << "\n\n";

    std::cout << "To: " << firstName << " " << lastName << ",\n\n";

    std::cout << "Dear " << firstName << ",\n\n";

    std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    std::cout << "Admissions Board has approved your application for admission to the\n";
    std::cout << academicYear << " academic year.\n\n";

    std::cout << "You have been offered a place for the following course:\n";
    std::cout << "PROGRAM: " << program << "\n\n";

    std::cout << "As a student of Makerere University, you will be part of a historic\n";
    std::cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    std::cout << "that you report to the Academic Registrar's office with your original\n";
    std::cout << "academic documents for verification during orientation week.\n\n";

    std::cout << "We look forward to welcoming you to Makerere University.\n\n";

    std::cout << "Yours sincerely,\n\n\n";
    std::cout << "John Doe\n";
    std::cout << "Registrar\n";

    return 0;
}
