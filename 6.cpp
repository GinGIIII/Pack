// Этап 6
class MoodyTeacher : public Teacher {
public:
    MoodyTeacher(std::string name) : Teacher(name) {}

    void addGradeRandomly(Student& student) override {
        int adjustedGrade = calculateAdjustedGrade(student.isExcellentStudent());
        student.addGrade(adjustedGrade);
        gradeCount++;

        std::cout << "Teacher " << getName() << " gave a grade " << adjustedGrade
                  << " to student " << student.getName() << " with " << (goodMood ? "good" : "bad") << " mood" << std::endl;

        if (gradeCount % 5 == 0) {
            changeMoodRandomly();
            std::cout << "Teacher's mood changed: "
                      << (goodMood ? "Good" : "Bad") << std::endl;
        }
    }

private:
    void changeMoodRandomly() override {
        goodMood = (rand() % 2 == 0);
    }
};

int main() {
    std::srand(std::time(0));

    return 0;
}
