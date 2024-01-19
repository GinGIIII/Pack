// Этап 2
class Teacher {
public:adada
    Teacher(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void addGrade(Student& student, int grade) {
        student.addGrade(grade);
        std::cout << "Teacher " << name << " gave a grade " << grade
                  << " to student " << student.getName() << std::endl;
    }

private:
    std::string name;
};

int main() {
    std::srand(std::time(0));
    
    return 0;
}
