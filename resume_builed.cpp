#include <bits/stdc++.h>
using namespace std;

class Resume {
private:
    string name, email, phone, education, skills, projects, experience;

public:
    void inputDetails() {
        cout << "Enter Full Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Education: ";
        getline(cin, education);
        cout << "Enter Skills: ";
        getline(cin, skills);
        cout << "Enter Projects: ";
        getline(cin, projects);
        cout << "Enter Experience: ";
        getline(cin, experience);
    }

    void saveToFile() {
        if (name.empty()) {
            cout << " Please create resume first before saving!\n";
            return;
        }

        string filename = name + "_resume.txt";
        for (char &c : filename) {
            if (c == ' ') c = '_';
        }

        ofstream fout(filename);
        fout << "========== Resume ==========\n";
        fout << "Name       : " << name << "\n";
        fout << "Email      : " << email << "\n";
        fout << "Phone      : " << phone << "\n";
        fout << "Education  : " << education << "\n";
        fout << "Skills     : " << skills << "\n";
        fout << "Projects   : " << projects << "\n";
        fout << "Experience : " << experience << "\n";
        fout << "============================\n";
        fout.close();

        cout << "\n Resume saved successfully as " << filename << "\n";
    }

    void displayResume() {
        if (name.empty()) {
            cout << " No resume data found! Please create resume first.\n";
            return;
        }

        cout << "\n========== Resume ==========\n";
        cout << "Name       : " << name << "\n";
        cout << "Email      : " << email << "\n";
        cout << "Phone      : " << phone << "\n";
        cout << "Education  : " << education << "\n";
        cout << "Skills     : " << skills << "\n";
        cout << "Projects   : " << projects << "\n";
        cout << "Experience : " << experience << "\n";
        cout << "============================\n";
    }

    void loadFromFile() {
        cout << "Enter filename to load (example: Rishav_Raj_resume.txt): ";
        string filename;
        getline(cin, filename);

        ifstream fin(filename);
        if (!fin.is_open()) {
            cout << "File not found!\n";
            return;
        }

        cout << "\n📄 Loaded Resume:\n\n";
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
};

int main() {
    Resume r;
    int choice;

    do {
        cout << "\n====== Resume Builder ======\n";
        cout << "1. Create Resume\n2. Display Resume\n3. Save Resume to File\n4. Load Resume from File\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1: r.inputDetails(); break;
            case 2: r.displayResume(); break;
            case 3: r.saveToFile(); break;
            case 4: r.loadFromFile(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
