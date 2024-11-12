#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Reservoir {
    string Nazva;
    double width;
    double length;
    double maxDepth;
    string type;
public:
    Reservoir() : Nazva("empty"), width(0), length(0), maxDepth(0), type("empty") {}
    void display() const {
        cout << "Name: " << Nazva << "\nWidth: " << width << "\nLength: " << length << "\nMax Depth: " << maxDepth << "\nType: " << type << endl;
    }
    explicit Reservoir(const string& name, double width, double length, double maxDepth, const string& tyype) : Nazva(name), width(width), length(length), maxDepth(maxDepth), type(tyype) {}

    Reservoir(const Reservoir& other) : Nazva(other.Nazva), width(other.width), length(other.length), maxDepth(other.maxDepth), type(other.type) {}

    ~Reservoir() {}

    double PriblObsyag() const {
        return width * length * maxDepth;
    }

    double S() const {
        return width * length;
    }
    bool SameType(const Reservoir& other) const {
        if (type == other.type) {
            return (type == other.type);
        }
        return false;
    }
    bool Porivnyannya_S(const Reservoir& other) const {
        if (SameType(other)) {
            return S() > other.S();
        }
        return false;
    }
    void setName(const string& name) {
        this->Nazva = name;
    }

    string getName() const {
        return Nazva;
    }

    void setWidth(double widthh) {
        this->width = widthh;
    }

    double getWidth() const {
        return width;
    }

    void setLength(double lengthh) {
        this->length = lengthh;
    }

    double getLength() const {
        return length;
    }

    void setType(const string& typee) {
        this->type = typee;
    }

    string getType() const {
        return type;
    }

    void setMaxDepth(double maxDepthh) {
        this->maxDepth = maxDepthh;
    }

    double getMaxDepth() const {
        return maxDepth;
    }
    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            Nazva = other.Nazva;
            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;
            type = other.type;
        }
        return *this;
    }
};
class ReservoirInterface {
    vector<Reservoir> vodoymy;
public:
    void addReservoir(const Reservoir& vodoymyy) {
        vodoymy.push_back(vodoymyy);
    }
    void removeReservoir(size_t index) {
        if (index < vodoymy.size()) {
            vodoymy.erase(vodoymy.begin() + index);
        }
    }
    void saveFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& reservoir : vodoymy) {
            file << reservoir.getName() << " " << reservoir.getWidth() << " " << reservoir.getLength() << " " << reservoir.getMaxDepth() << reservoir.getType() << endl;
        }
    }
    void displayAll() const {
        for (const auto& reservoir : vodoymy) {
            reservoir.display();
            reservoir.getMaxDepth();
            cout << "Priblizna plosha: " << reservoir.PriblObsyag() << endl;
            cout << "Same types: " << reservoir.SameType(reservoir) << endl;
            cout << "Plosha water poferhni: " << reservoir.S() << endl;
            cout << endl;
        }
        for (int i = 0; i < vodoymy.size(); ++i) {
            for (int j = i + 1; j < vodoymy.size(); ++j) {
                if (vodoymy[i].SameType(vodoymy[j])) {
                    cout << "Comparing " << vodoymy[i].getName() << " with " << vodoymy[j].getName() << ": " << endl;
                    if (vodoymy[i].Porivnyannya_S(vodoymy[j])) {
                        cout << vodoymy[i].getName() << " has a larger water surface." << endl;
                    }
                    else {
                        cout << vodoymy[j].getName() << " has a larger water surface." << endl;
                    }
                    cout << endl;
                }
            }
        }
    }
};
int main()
{
    ReservoirInterface manager;
    Reservoir res1("Ocean1", 56, 27, 26, "Sea");
    Reservoir res2("Lake", 89, 90, 87, "Lake");
    Reservoir res3("Ocean2", 78, 63, 90, "Sea");

    manager.addReservoir(res1);
    manager.addReservoir(res2);
    manager.addReservoir(res3);

    manager.displayAll();

    manager.saveFile("reservoirs.txt");
}