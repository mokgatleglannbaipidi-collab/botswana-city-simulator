#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Structure to hold city data
struct City {
    string name;
    int population;
    long long budget;
    int water;
    int electricity;
    int housing;
    int environment;
    int traffic;
    int turn;
};

// Function Prototypes
void displayMenu(const City& c);
void viewCityStatistics(const City& c);
void buildInfrastructure(City& c);
void manageWater(City& c);
void manageElectricity(City& c);
void manageHousing(City& c);
void manageTransport(City& c);
void processTurn(City& c);
void triggerRandomEvent(City& c);
void saveGame(const City& c);
void loadGame(City& c);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random events

    City myCity = {
        "Glen City",
        25000,
        5000000,
        82,
        76,
        68,
        84,
        23,
        1
    };

    int choice;

    cout << "\n========================================\n";
    cout << "     WELCOME TO BOTSWANA CITY SIMULATOR\n";
    cout << "========================================\n";
    cout << "Enter your city's name (e.g., Gaborone, Francistown, Glen City): ";
    getline(cin, myCity.name);

    do {
        displayMenu(myCity);
        cout << "Enter your choice (0-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                buildInfrastructure(myCity);
                processTurn(myCity);
                break;
            case 2:
                manageWater(myCity);
                processTurn(myCity);
                break;
            case 3:
                manageElectricity(myCity);
                processTurn(myCity);
                break;
            case 4:
                manageHousing(myCity);
                processTurn(myCity);
                break;
            case 5:
                manageTransport(myCity);
                processTurn(myCity);
                break;
            case 6:
                viewCityStatistics(myCity);
                break;
            case 7:
                triggerRandomEvent(myCity);
                processTurn(myCity);
                break;
            case 8:
                saveGame(myCity);
                break;
            case 9:
                loadGame(myCity);
                break;
            case 0:
                cout << "\nExiting simulator. Thank you for building Botswana!\n";
                break;
            default:
                cout << "\n[!] Invalid choice. Please select between 0 and 9.\n";
        }
    } while (choice != 0);

    return 0;
}

// Display the main dashboard menu
void displayMenu(const City& c) {
    cout << "\n╔══════════════════════════════════════════╗\n";
    cout << "║       🇧🇼 BOTSWANA CITY SIMULATOR        ║\n";
    cout << "╠══════════════════════════════════════════╣\n";
    cout << "║ City: " << c.name << " (Turn " << c.turn << ")               \n";
    cout << "║ Population: " << c.population << "                      \n";
    cout << "║ Budget: P" << c.budget << "                    \n";
    cout << "║ Water: " << c.water << "%                         \n";
    cout << "║ Electricity: " << c.electricity << "%                   \n";
    cout << "║ Housing: " << c.housing << "%                       \n";
    cout << "║ Environment: " << c.environment << "%                   \n";
    cout << "║ Traffic: " << c.traffic << "%                       \n";
    cout << "╠══════════════════════════════════════════╣\n";
    cout << "║ 1. Build Infrastructure                  ║\n";
    cout << "║ 2. Manage Water Supply                   ║\n";
    cout << "║ 3. Manage Electricity                    ║\n";
    cout << "║ 4. Manage Housing                        ║\n";
    cout << "║ 5. Manage Transport                      ║\n";
    cout << "║ 6. View City Statistics & Rating         ║\n";
    cout << "║ 7. Trigger Random Event (Next Turn)      ║\n";
    cout << "║ 8. Save Game                             ║\n";
    cout << "║ 9. Load Game                             ║\n";
    cout << "║ 0. Exit                                  ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
}

// View detailed statistics and overall rating
void viewCityStatistics(const City& c) {
    int overallRating = (c.water + c.electricity + c.housing + c.environment + (100 - c.traffic)) / 5;

    cout << "\n==================================\n";
    cout << "       CITY PERFORMANCE RATINGS    \n";
    cout << "==================================\n";
    cout << "Water Supply   : " << c.water << "%\n";
    cout << "Electricity    : " << c.electricity << "%\n";
    cout << "Housing        : " << c.housing << "%\n";
    cout << "Environment    : " << c.environment << "%\n";
    cout << "Traffic Control: " << (100 - c.traffic) << "% (Congestion: " << c.traffic << "%)\n";
    cout << "----------------------------------\n";
    cout << "OVERALL CITY RATING: " << overallRating << "%\n";
    cout << "==================================\n";
}

// Build infrastructure to boost city stats
void buildInfrastructure(City& c) {
    int choice;
    cout << "\n--- INFRASTRUCTURE MENU ---\n";
    cout << "1. Solar Farm (Cost: P750,000 | +15% Elec, +5% Env)\n";
    cout << "2. Water Treatment Plant (Cost: P900,000 | +20% Water)\n";
    cout << "3. Affordable Houses (Cost: P1,200,000 | +15% Housing, +2,000 Pop)\n";
    cout << "4. Paved Roads (Cost: P500,000 | -10% Traffic)\n";
    cout << "0. Back\n";
    cout << "Choose building option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (c.budget >= 750000) {
                c.budget -= 750000;
                c.electricity = min(100, c.electricity + 15);
                c.environment = min(100, c.environment + 5);
                cout << "\n[+] Solar farm successfully constructed!\n";
            } else {
                cout << "\n[!] Insufficient budget!\n";
            }
            break;
        case 2:
            if (c.budget >= 900000) {
                c.budget -= 900000;
                c.water = min(100, c.water + 20);
                cout << "\n[+] Water treatment plant online!\n";
            } else {
                cout << "\n[!] Insufficient budget!\n";
            }
            break;
        case 3:
            if (c.budget >= 1200000) {
                c.budget -= 1200000;
                c.housing = min(100, c.housing + 15);
                c.population += 2000;
                cout << "\n[+] New housing development completed! Population increased.\n";
            } else {
                cout << "\n[!] Insufficient budget!\n";
            }
            break;
        case 4:
            if (c.budget >= 500000) {
                c.budget -= 500000;
                c.traffic = max(0, c.traffic - 10);
                cout << "\n[+] Roads upgraded. Traffic congestion reduced!\n";
            } else {
                cout << "\n[!] Insufficient budget!\n";
            }
            break;
        default:
            cout << "Returning to main menu.\n";
    }
}

// Manage water allocations
void manageWater(City& c) {
    int choice;
    cout << "\n--- WATER MANAGEMENT ---\n";
    cout << "Current Water Level: " << c.water << "%\n";
    cout << "1. Issue Water Conservation Campaign (Cost: P50,000 | +5% Water)\n";
    cout << "2. Drill Boreholes (Cost: P300,000 | +12% Water)\n";
    cout << "0. Back\n";
    cin >> choice;

    if (choice == 1 && c.budget >= 50000) {
        c.budget -= 50000;
        c.water = min(100, c.water + 5);
        cout << "\n[+] Conservation campaign launched successfully.\n";
    } else if (choice == 2 && c.budget >= 300000) {
        c.budget -= 300000;
        c.water = min(100, c.water + 12);
        cout << "\n[+] New boreholes drilled successfully.\n";
    } else if (choice != 0) {
        cout << "\n[!] Action failed or insufficient funds.\n";
    }
}

// Manage electricity supplies
void manageElectricity(City& c) {
    int choice;
    cout << "\n--- ELECTRICITY MANAGEMENT ---\n";
    cout << "Current Electricity Level: " << c.electricity << "%\n";
    cout << "1. Upgrade Grid Substation (Cost: P400,000 | +10% Electricity)\n";
    cout << "0. Back\n";
    cin >> choice;

    if (choice == 1 && c.budget >= 400000) {
        c.budget -= 400000;
        c.electricity = min(100, c.electricity + 10);
        cout << "\n[+] Grid substation upgraded!\n";
    }
}

// Manage housing
void manageHousing(City& c) {
    cout << "\n--- HOUSING MANAGEMENT ---\n";
    cout << "Current Housing Index: " << c.housing << "%\n";
    cout << "Housing is improved by constructing houses under the Build menu.\n";
}

// Manage transport
void manageTransport(City& c) {
    int choice;
    cout << "\n--- TRANSPORT MANAGEMENT ---\n";
    cout << "Current Traffic Congestion: " << c.traffic << "%\n";
    cout << "1. Introduce Public Bus Shuttle Fleet (Cost: P250,000 | -8% Traffic)\n";
    cout << "0. Back\n";
    cin >> choice;

    if (choice == 1 && c.budget >= 250000) {
        c.budget -= 250000;
        c.traffic = max(0, c.traffic - 8);
        cout << "\n[+] Bus shuttles deployed! Traffic eased.\n";
    }
}

// Random events that occur during gameplay
void triggerRandomEvent(City& c) {
    int eventID = rand() % 5;
    cout << "\n----------------------------------------\n";
    cout << "⚠ RANDOM EVENT OCCURRED:\n";

    switch (eventID) {
        case 0:
            cout << "Severe drought affects the region!\n";
            c.water = max(0, c.water - 15);
            c.environment = max(0, c.environment - 5);
            break;
        case 1:
            cout << "Economic boom! Local businesses thrive.\n";
            c.budget += 800000;
            break;
        case 2:
            cout << "Power grid failure reported across districts.\n";
            c.electricity = max(0, c.electricity - 12);
            break;
        case 3:
            cout << "Heavy seasonal rainfall replenishes water reservoirs!\n";
            c.water = min(100, c.water + 15);
            break;
        case 4:
            cout << "Tourism surge in nearby national parks boosts municipal revenue.\n";
            c.budget += 500000;
            c.environment = min(100, c.environment + 3);
            break;
    }
    cout << "----------------------------------------\n";
}

// Process turn economics (taxes collected vs expenses paid)
void processTurn(City& c) {
    c.turn++;
    long long taxRevenue = c.population * 120; // P120 tax per citizen per turn
    long long maintenance = (c.population / 100) * 15000; // City maintenance cost
    long long netProfit = taxRevenue - maintenance;

    c.budget += netProfit;

    cout << "\n[Turn Summary]\n";
    cout << "Tax Revenue collected: P" << taxRevenue << "\n";
    cout << "Municipal Maintenance: P" << maintenance << "\n";
    cout << "Net Profit/Loss: P" << netProfit << "\n";
}

// Save game state to file using file handling
void saveGame(const City& c) {
    ofstream outFile("savegame.txt");
    if (outFile.is_open()) {
        outFile << c.name << endl;
        outFile << c.population << endl;
        outFile << c.budget << endl;
        outFile << c.water << endl;
        outFile << c.electricity << endl;
        outFile << c.housing << endl;
        outFile << c.environment << endl;
        outFile << c.traffic << endl;
        outFile << c.turn << endl;
        outFile.close();
        cout << "\n[+] Game successfully saved to 'savegame.txt'!\n";
    } else {
        cout << "\n[!] Error opening file for saving.\n";
    }
}

// Load game state from file
void loadGame(City& c) {
    ifstream inFile("savegame.txt");
    if (inFile.is_open()) {
        getline(inFile, c.name);
        inFile >> c.population;
        inFile >> c.budget;
        inFile >> c.water;
        inFile >> c.electricity;
        inFile >> c.housing;
        inFile >> c.environment;
        inFile >> c.traffic;
        inFile >> c.turn;
        inFile.close();
        cout << "\n[+] Game successfully loaded!\n";
    } else {
        cout << "\n[!] No saved game found.\n";
    }
}