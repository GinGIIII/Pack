#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

class Teacher {
public:
    Teacher(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    bool getMood() const {
        return goodMood;
    }

    virtual void addGradeRandomly(Student& student) {
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

    void addGrade(Student& student, int grade) {
        student.addGrade(grade);
        std::cout << "Teacher " << name << " gave a grade " << grade
                  << " to student " << student.getName() << std::endl;
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

    bool goodMood = (rand() % 2 == 0);
    std::string name;
    int gradeCount;
};

class RandomlyTeacher : public Teacher {
public:
    RandomlyTeacher(std::string name) : Teacher(name) {}

    void addGrade(Student& student) {
        int adjustedGrade = rand() % 4 + 2;
        student.addGrade(adjustedGrade);
        gradeCount++;

        std::cout << "Teacher " << this->getName() << " gave a grade " << adjustedGrade
                  << " to student " << student.getName() << std::endl;

        if (gradeCount % randomNumberMood == 0) {
            changeMoodRandomly();
            std::cout << "Teacher's mood changed: "
                      << (goodMood ? "Good" : "Bad") << std::endl;
        }
    }

    void addGradeRandomly(Student& student) override {
        addGrade(student);
    }

private:
    int randomNumberMood = rand() % 3 + 3;
};

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

    bool hasTeacher(const Teacher& teacher) const {
        return std::find(teachers.begin(), teachers.end(), &teacher) != teachers.end();
    }

    const std::vector<Student*>& getStudents() const {
        return students;
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

class Caretaker {
public:
    Caretaker(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void addChild(Student& student) {
        children.push_back(&student);
    }

    bool hasChild(const Student& student) const {
        return std::find(children.begin(), children.end(), &student) != children.end();
    }

    void tellAboutAllChildren() const {
        std::cout << "Story about all children:" << std::endl;
        for (const Student* student : children) {
            tellAboutChild(student);
        }
        std::cout << std::endl;
    }

    void tellAboutOneRandomChild() const {
        if (children.empty()) {
            std::cout << "No children to tell about." << std::endl;
            return;
        }

        int randomIndex = rand() % children.size();
        tellAboutChild(children[randomIndex]);
        std::cout << std::endl;
    }

    void tellAboutAverageChildren() const {
        if (children.empty()) {
            std::cout << "No children to tell about." << std::endl;
            return;
        }

        double averageGrade = calculateAverageGrade();
        std::cout << "Story about the average performance of children: " << (averageGrade >= 4.5 ? "Good" : "Bad") << std::endl;
        std::cout << std::endl;
    }

    void tellAboutSpecificChild(const Student* student) const {
        auto it = std::find(children.begin(), children.end(), student);
        if (it != children.end()) {
            tellAboutChild(*it);
        }
        else {
            std::cout << "Error: This student is not a child of the caretaker." << std::endl;
        }
    }

protected:
    virtual void tellAboutChild(const Student* student) const {
        std::cout << "Caretaker " << name << " talks about the child " << student->getName() << ": ";
        if (goodMood) {
            std::cout << (student->isExcellentStudent() ? "Excellent student" : "Not an excellent student") << std::endl;
        }
        else {
            std::cout << "There's always something wrong with them." << std::endl;
        }
    }

    double calculateAverageGrade() const {
        double sum = 0.0;
        for (const Student* student : children) {
            sum += (student->isExcellentStudent() ? 5.0 : 3.0);
        }

        return sum / children.size();
    }

private:
    std::string name;
    bool goodMood = (rand() % 2 == 0);
    std::vector<const Student*> children;
};

class GrandCaretaker : public Caretaker {
public:
    GrandCaretaker(std::string name) : Caretaker(name) {}

    void tellAboutChild(const Student* student) const override {
        if (hasChild(*student)) {
            std::cout << "Grandma " << getName() << " talks about her grandson " << student->getName() << ": ";
            std::cout << "Always been a good child, smart and diligent." << std::endl;
        }
        else {
            std::cout << "Grandma " << getName() << " talks about someone else's child " << student->getName() << ": ";
            if (goodMood) {
                std::cout << (student->isExcellentStudent() ? "Excellent student" : "Not an excellent student") << std::endl;
            }
            else {
                std::cout << "There's always something wrong with them." << std::endl;
            }
        }
    }

private:
    std::string name;
    bool goodMood = (rand() % 2 == 0);
    std::vector<const Student*> children;
};

class SchoolCouncil {
public:
    SchoolCouncil(const std::string& name) : name(name) {}

    void addParticipant(Teacher& teacher) {
        teachers.push_back(&teacher);
    }

    void addParticipant(Caretaker& caretaker) {
        caretakers.push_back(&caretaker);
    }

    void discussSubjects() {
        std::cout << "Start of the council meeting: " << name << std::endl;

        for (Subject& subject : subjects) {
            std::cout << "Discussion of the subject: " << subject.getName() << std::endl;

            for (Teacher* teacher : teachers) {
                if (subject.hasTeacher(*teacher)) {
                    for (Student* student : subject.getStudents()) {
                        Caretaker* caretaker = findCaretakerOfStudent(*student);
                        if (caretaker) {
                            caretaker->tellAboutSpecificChild(student);
                        }
                        else {
                            childrenWithoutCaretakers.push_back(student);
                        }
                    }
                }
            }
        }

        if (!childrenWithoutCaretakers.empty()) {
            std::cout << "Children without caretakers at the council:" << std::endl;
            for (const Student* student : childrenWithoutCaretakers) {
                std::cout << student->getName() << std::endl;
            }
        }

        std::cout << "End of the council meeting: " << name << std::endl;
    }

    void addSubject(const Subject& subject) {
        subjects.push_back(subject);
    }

private:
    Caretaker* findCaretakerOfStudent(const Student& student) {
        for (Caretaker* caretaker : caretakers) {
            if (caretaker->hasChild(student)) {
                return caretaker;
            }
        }
        return nullptr;
    }

    std::string name;
    std::vector<Teacher*> teachers;
    std::vector<Caretaker*> caretakers;
    std::vector<Subject> subjects;
    std::vector<const Student*> childrenWithoutCaretakers;
};

int main() {
    std::srand(std::time(0));
    setlocale(LC_ALL, "English");

    Teacher teacher1("Sidorov");
    RandomlyTeacher teacher2("Blue");
    GrandCaretaker caretaker1("Anna");
    Caretaker caretaker2("Igor");
    Student student1("Ivanov");
    Student student2("Petrov");
    Student student3("Sidorov");

    caretaker1.addChild(student1);
    caretaker2.addChild(student2);

    Subject subject1("Math");
    subject1.addTeacher(teacher1);
    subject1.addTeacher(teacher2);
    subject1.addStudent(student1);
    subject1.addStudent(student2);
    subject1.conductSubject();

    Subject subject2("Physics");
    subject2.addTeacher(teacher2);
    subject2.addStudent(student3);
    subject2.conductSubject();

    caretaker1.tellAboutAllChildren();
    caretaker2.tellAboutOneRandomChild();

    teacher1.addGrade(student1, 4);
    teacher1.addGrade(student2, 5);
    teacher1.addGrade(student3, 3);

    caretaker1.tellAboutSpecificChild(&student1);
    caretaker2.tellAboutAverageChildren();

    SchoolCouncil council("School Council");
    council.addParticipant(teacher1);
    council.addParticipant(teacher2);
    council.addParticipant(caretaker1);
    council.addParticipant(caretaker2);
    council.addSubject(subject1);
    council.addSubject(subject2);

    council.discussSubjects();

    return 0;
}
