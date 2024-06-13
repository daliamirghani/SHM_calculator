#include <iostream>
#include <cmath>
using namespace std;

#define gravity 9.8

int main() {
    float amp, k, freq, time, position, periodict, mass, length, omega, phaseconst;
    char choice, system;
    bool valid;

    while (true) {  // Added loop to allow continuous input
        do {
            cout << "**** Welcome to SHM Calculator ****\n";
            cout << "Which system are you working on?\n";
            cout << "Press 1 for mass-spring system\n";
            cout << "Press 2 for simple pendulum system\n";
            cout << "Press 0 to exit\n";
            cin >> system;
            if (system == '0') {
                return 0;  // Exit the program
            }
            valid = true;
            switch (system) {
            case '1':
                cout << "Enter spring constant (k) and mass (m):\n";
                cin >> k >> mass;
                omega = sqrt(k / mass);
                break;
            case '2':
                cout << "Enter length of the pendulum:\n";
                cin >> length;
                omega = sqrt(gravity / length);
                break;
            default:
                cout << "Invalid choice!\n";
                valid = false;
            }
        } while (!valid);

        cout << "What do you want to calculate?\n";
        cout << "Press 1 for position\n";
        cout << "Press 2 for max amplitude\n";
        cout << "Press 3 for angular frequency\n";
        cout << "Press 4 for frequency\n";
        cout << "Press 5 for periodic time\n";
        cout << "Press 6 for time\n";
        cout << "Press 0 to exit\n";
        cin >> choice;

        if (choice == '0') {
            return 0;  // Exit the program
        }

        switch (choice) {
        case '1':
            cout << "please enter the following in order\n";
            cout << "amplitude, time, phase constant ";
            cin >> amp >> time >> phaseconst;
            position = amp * cos(omega * time + phaseconst);
            cout << "position is: " << position << " meters " << endl;
            break;
        case '2':
            cout << "please enter the following in order\n";
            cout << "position, time, phase constant";
            cin >> position >> time >> phaseconst;
            amp = position / cos(omega * time + phaseconst);
            cout << "max amplitude is: +_" << amp << " meters " << endl;
            break;
        case '3':
            cout << "Angular frequency (omega): " << omega << " rad/sec" << endl;
            break;
        case '4':
            cout << "Frequency: " << omega / (2 * 3.14) << " hertz " << endl;
            break;
        case '5':
            cout << "Periodic time: " << 2 * 3.14 / omega << " seconds " << endl;
            break;
        case '6':
            cout << "please enter the following in order\n";
            cout << "position, amplitude, phase constant ";
            cin >> position >> amp >> phaseconst;
            time = (acos(position / amp) - phaseconst) / omega;
            cout << "time at position: " << position << " is: " << time << " seconds" << endl;
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
