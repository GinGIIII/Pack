// Этап 7
class Parent {
public:
    Parent(std::string name) : name(name) {}

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
            std::cout << "Error: This student is not a child of the parent." << std::endl;
        }
    }

private:
    virtual void tellAboutChild(const Student* student) const {
        std::cout << "Parent " << name << " talks about the child " << student->getName() << ": ";
        // Implement the logic based on mood and student's excellence
        // ...
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
    std::vector<const Student*> children;
};

int main() {
    std::srand(std::time(0));

    return 0;
}
