// Этап 8
class Meeting {
public:
    Meeting(const std::string& name) : name(name) {}

    void addParticipant(Teacher& teacher) {
        teachers.push_back(&teacher);
    }

    void addParticipant(Parent& parent) {
        parents.push_back(&parent);
    }

    void discussSubjects() {
        std::cout << "Start of the meeting: " << name << std::endl;

        for (Subject& subject : subjects) {
            std::cout << "Discussion of the subject: " << subject.getName() << std::endl;

            for (Teacher* teacher : teachers) {
                if (subject.hasTeacher(*teacher)) {
                    for (Student* student : subject.getStudents()) {
                        Parent* parent = findParentOfStudent(*student);
                        if (parent) {
                            parent->tellAboutSpecificChild(student);
                        }
                        else {
                            childrenWithoutParents.push_back(student);
                        }
                    }
                }
            }
        }

        if (!childrenWithoutParents.empty()) {
            std::cout << "Children without parents at the meeting:" << std::endl;
            for (const Student* student : childrenWithoutParents) {
                std::cout << student->getName() << std::endl;
            }
        }

        std::cout << "End of the meeting: " << name << std::endl;
    }

    void addSubject(const Subject& subject) {
        subjects.push_back(subject);
    }

private:
    Parent* findParentOfStudent(const Student& student) {
        for (Parent* parent : parents) {
            if (parent->hasChild(student)) {
                return parent;
            }
        }
        return nullptr;
    }

private:
    std::string name;
    std::vector<Teacher*> teachers;
    std::vector<Parent*> parents;
    std::vector<Subject> subjects;
    std::vector<const Student*> childrenWithoutParents;
};

int main() {
    std::srand(std::time(0));

    return 0;
}
