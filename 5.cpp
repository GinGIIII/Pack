// Этап 5
class AlwaysExcellentTeacher : public Teacher {
public:
    AlwaysExcellentTeacher(std::string name) : Teacher(name) {}

    void addGradeRandomly(Student& student) override {
        int adjustedGrade = 5;
        student.addGrade(adjustedGrade);
        gradeCount++;

        std::cout << "Teacher " << getName() << " always gave a grade " << adjustedGrade
                  << " to student " << student.getName() << std::endl;

        if (gradeCount % 5 == 0) {
            changeMoodRandomly();
            std::cout << "Teacher's mood changed: "
                      << (goodMood ? "Good" : "Bad") << std::endl;
        }
    }
};

class AlwaysLowGradeTeacher : public Teacher {
public:
    AlwaysLowGradeTeacher(std::string name) : Teacher(name) {}

    void addGradeRandomly(Student& student) override {
        int adjustedGrade = 2;
        student.addGrade(adjustedGrade);
        gradeCount++;

        std::cout << "Teacher " << getName() << " always gave a grade " << adjustedGrade
                  << " to student " << student.getName() << std::endl;

        if (gradeCount % 5 == 0) {
            changeMoodRandomly();
            std::cout << "Teacher's mood changed: "
                      << (goodMood ? "Good" : "Bad") << std::endl;
        }
    }
};

int main() {
    std::srand(std::time(0));

    return 0;
}
