#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<Windows.h>



using namespace std;

class Reservoir {
    string name;
    double width;
    double length;
    double maxDepth;
    string type;

public:
    Reservoir() : name("empty"), width(0), length(0), maxDepth(0), type("empty") {}
    
    Reservoir(const string& name, double width, double length, double maxDepth, const string& type) 
        : name(name), width(width), length(length), maxDepth(maxDepth), type(type) {}

    void display() const {
        cout << "Назва: " << name << "\nШирина: " << width << "\nДовжина: " << length 
             << "\nМаксимальна глибина: " << maxDepth << "\nТип: " << type << endl;
    }

    double approximateVolume() const {
        return width * length * maxDepth;
    }

    double surfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return type == other.type;
    }

    bool compareSurfaceArea(const Reservoir& other) const {
        return isSameType(other) && (surfaceArea() > other.surfaceArea());
    }

    // Getters and Setters
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    double getWidth() const { return width; }
    void setWidth(double width) { this->width = width; }

    double getLength() const { return length; }
    void setLength(double length) { this->length = length; }

    double getMaxDepth() const { return maxDepth; }
    void setMaxDepth(double maxDepth) { this->maxDepth = maxDepth; }

    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }
};

class ReservoirManager {
    vector<Reservoir> reservoirs;

public:
    void addReservoir(const Reservoir& res) {
        reservoirs.push_back(res);
    }

    void removeReservoir(size_t index) {
        if (index < reservoirs.size()) {
            reservoirs.erase(reservoirs.begin() + index);
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& res : reservoirs) {
            file << res.getName() << " " << res.getWidth() << " " << res.getLength() 
                 << " " << res.getMaxDepth() << " " << res.getType() << endl;
        }
    }

    void displayAll() const {
        for (const auto& res : reservoirs) {
            res.display();
            cout << "Приблизний об'єм: " << res.approximateVolume() << endl;
            cout << "Площа поверхні води: " << res.surfaceArea() << endl;
            cout << endl;
        }

        // Порівняння площ поверхні води для однакових типів
        for (size_t i = 0; i < reservoirs.size(); ++i) {
            for (size_t j = i + 1; j < reservoirs.size(); ++j) {
                if (reservoirs[i].isSameType(reservoirs[j])) {
                    cout << "Порівняння " << reservoirs[i].getName() 
                         << " і " << reservoirs[j].getName() << ": " << endl;
                    if (reservoirs[i].compareSurfaceArea(reservoirs[j])) {
                        cout << reservoirs[i].getName() << " має більшу площу поверхні." << endl;
                    } else {
                        cout << reservoirs[j].getName() << " має більшу площу поверхні." << endl;
                    }
                    cout << endl;
                }
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    ReservoirManager manager;
    Reservoir res1("Ocean1", 56, 27, 26, "Sea");
    Reservoir res2("Lake1", 89, 90, 87, "Lake");
    Reservoir res3("Ocean2", 78, 63, 90, "Sea");

    manager.addReservoir(res1);
    manager.addReservoir(res2);
    manager.addReservoir(res3);

    manager.displayAll();
    manager.saveToFile("reservoirs.txt");

    return 0;
}
