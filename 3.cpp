// Этап 3
class Teacher {
public:
    Teacher(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    bool getMood() const {
        return goodMood;
    }

    void addGradeRandomly(Student& student) {
        int adjustedGrade = calculateAdjustedGrade(student.isExcellentStudent());
        student.addGrade(adjustedGrade);
        gradeCount++;

        std::cout << "Teacher " << name << " gave a grade " << adjustedGrade
                  << " to student " << student.getName() << " with " << (goodMood ? "good" : "bad") << " mood" << std::endl;

        if (gradeCount % 5 == 0) {
            changeMoodRandomly();
            std::cout << "Teacher's mood changed: "
                      << (goodMood ? "Good" : "Bad") << std::endl;
        }
    }

protected:
    int calculateAdjustedGrade(bool isExcellentStudent) const {
        if (goodMood) {
            return (isExcellentStudent) ? 5 : (rand() % 2 + 4);
        }
        else {
            return (isExcellentStudent) ? (rand() % 2 + 4) : (rand() % 2 + 2);
        }
    }

    void changeMoodRandomly() {
        goodMood = (rand() % 2 == 0);
    }

private:
    bool goodMood = (rand() % 2 == 0);
    std::string name;
    int gradeCount;
};

int main() {
    std::srand(std::time(0));

    return 0;
}
