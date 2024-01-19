// Этап 1
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Student {
public:
    Student(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    bool isExcellentStudent() const {
        return calculateAverageGrade() >= 4.5;
    }

private:
    double calculateAverageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (int grade : grades) {
            sum += grade;
        }

        return sum / grades.size();
    }

private:
    std::string name;
    std::vector<int> grades;
};

int main() {
//1 этап
    return 0;
}
