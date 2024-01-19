// Этап 4
class Subject {
public:
    Subject(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void addTeacher(Teacher& teacher) {
        teachers.push_back(&teacher);
    }

    void addStudent(Student& student) {
        students.push_back(&student);
    }

    void conductSubject() {
        std::cout << "Teachers: ";
        for (Teacher* teacher : teachers) {
            std::cout << teacher->getName() << " ";
        }
        std::cout << "conducted a class for students: ";
        for (Student* student : students) {
            std::cout << student->getName() << " ";
        }
        std::cout << std::endl << "Results of the class " << this->getName() << ":" << std::endl;
        std::cout << "---------------" << std::endl;
        for (Teacher* teacher : teachers) {
            for (Student* student : students) {
                if (rand() % 2 == 0) {
                    if (teacher->getMood()) {
                        int numGrades = rand() % 5 + 1;
                        for (int i = 0; i < numGrades; ++i) {
                            teacher->addGradeRandomly(*student);
                        }
                    }
                    else {
                        int numGrades = rand() % 3 + 1;
                        for (int i = 0; i < numGrades; ++i) {
                            teacher->addGradeRandomly(*student);
                        }
                    }
                }
            }
        }
        std::cout << "---------------" << std::endl;
    }

private:
    std::string name;
    std::vector<Teacher*> teachers;
    std::vector<Student*> students;
};

int main() {
    std::srand(std::time(0));

    return 0;
}
