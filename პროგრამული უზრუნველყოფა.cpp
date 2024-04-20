//პროგრამული უზრუნველყოფა - ლუკა ბეჟაშვილი

#include <iostream>
#include <fstream>

using namespace std;

namespace Logger {

    void Log(const string& message) {
        if (message.empty()) {
            throw invalid_argument("mesiji aris carieli.");
        }

        for (char c : message) {
            if (!(isalpha(c) || c == ' ')) {
                throw invalid_argument("mesiji sheicavs ucnob simbolos");
            }
        }

        cout << message << endl;
    }

    void LogToFile(const string& message, const string& filename = "filename.txt") {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("faili ver gaixsna.");
        }
        file << message;
    }
}

int main() {
    try {
        Logger::Log("testi");
        Logger::LogToFile("testi");
    }
    catch (const exception& e) {
        cerr << "gamonaklisi: " << e.what() << endl;
    }
}
