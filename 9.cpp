// Этап 9
class Grandmother : public Parent {
public:
    Grandmother(std::string name) : Parent(name) {}

private:
    void tellAboutChild(const Student* student) const override {
        std::cout << "Grandmother " << getName() << " talks about the child " << student->getName() << ": ";
        std::cout << "Always been a good child, smart and diligent." << std::endl;
    }
};

int main() {
    std::srand(std::time(0));

    return 0;
}
