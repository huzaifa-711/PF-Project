#include "header1.h"

void saveToFile(Tour* tours, int& tourCount, const string filename) {// Function to save tour data to a file
    ofstream fout;
    fout.open(filename);

    if (fout.fail()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i <= tourCount; ++i) {//saves data to file
        fout << tours[i].name << " " << tours[i].location << " " << tours[i].mode << " " << tours[i].days << endl;
    }

    fout.close();
}
// Function to load tour data from a file
void loadFromFile(Tour* tours, int& tourCount, const string filename) {
    ifstream fin;
    fin.open(filename);

    if (fin.fail()) {
        cout << "Error opening file for reading. Starting with an empty data set." << endl;
        return;
    }

    tourCount = 0; // Reset tour count to pick data from the start of the file

    while (tourCount < MAX_TOURS && fin >> tours[tourCount].name >> tours[tourCount].location >> tours[tourCount].mode >> tours[tourCount].days) {
        tourCount++; // Loading data into the struct of tour
    }

    fin.close(); // File closing
}

void add_tour(Tour* tours, int& tourCount, const string filename) {//function to add data
    if (tourCount < MAX_TOURS) {
        // Taking input from the user
        cout << "\nBy which name would you like to book this trip: ";
        cin.ignore();//clear anything in buffer
        getline(cin, tours[tourCount].name);
        cout << "\nWhat is your Destination: ";
        getline(cin, tours[tourCount].location);
        cout << "\nMode of transport (air/road): ";
        getline(cin, tours[tourCount].mode);
        cout << "\nHow many days would you like to spend in the destination (in days): ";
        getline(cin,tours[tourCount].days);

        cout << "Tour added successfully.\n";

        // Now saving data to file we just call the function
        saveToFile(tours, tourCount, filename);
        tourCount++;
    } else {
        cout << "Maximum number of tours reached.\n";
    }
}

void view_tours(Tour* tours, int& tourCount) {//this function views tour data 
    cout << "NAMES\t\tDESTINATION\t\tMODE\t\tDAYS\n" << endl;

    for (int i = 0; i < tourCount; ++i) {
        cout << tours[i].name << "\t\t" << tours[i].location << "\t\t" << tours[i].mode << "\t\t" << tours[i].days << endl;
    }
}

void find_Tour(Tour* tours, int& tourCount) {//this function finds tour data
    cout << "Enter name to find\n";
    string name;
    cin.ignore(); // Ignore any characters in the buffer
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < tourCount; ++i) {
        if (tours[i].name == name) {
            cout << "Match found:\n";
            cout << tours[i].name << "\t" << tours[i].location << "\t" << tours[i].mode << "\t" << tours[i].days << endl;
            found = true;
            break;
        }
    }

    if (!found) {//if match not found
        cout << "Match not found\n";
    }
}

void delete_tour(Tour* tours, int& tourCount, const string filename) {//this function delet tour data
    cout << "Enter Name to Delete:\n";
    string name;
    cin.ignore();
    getline(cin, name);

    int foundIndex = -1;//random value assing to index
    for (int i = 0; i < tourCount; ++i) {
        if (tours[i].name == name) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "Record deleted\n";
        if (foundIndex < tourCount - 1) {//check if the foundindex is not the last index in the array. If it is the last index, there's no need to perform the replacement,just decremnt it
            tours[foundIndex] = tours[tourCount - 1];//assign teh last index data to the foundindex and the decrement the array size.
        }

        tourCount--;//decremantation

        // Save data to file after deleting a tour
        saveToFile(tours, tourCount, filename);
    } else {
        cout << "Match not found\n";
    }
}

void replace_tour(Tour* tours, int& tourCount, const string filename) {//this function repalce tour data
    cout << "Enter Name to Replace:\n";
    string name;
    cin.ignore();
    getline(cin, name);

    int foundIndex = -1;
    for (int i = 0; i < tourCount; ++i) {
        if (tours[i].name == name) {//cheking wether the name exist in file
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
         // Taking new input to replace the old data
        cout << "Enter new Name\n";
        getline(cin, tours[foundIndex].name);
        cout << "Enter location\n";
        getline(cin, tours[foundIndex].location);
        cout << "By Road or Air\n";
        getline(cin, tours[foundIndex].mode);
        cout << "Enter Days\n";
        getline(cin,tours[foundIndex].days);
        cout << "Record replaced successfully\n";

        // Save data to file after replacing a tour
        saveToFile(tours, tourCount, filename);
    } else {
        cout << "Match not found\n";
    }
}

void menu(Tour* tours, int& tourCount, const string filename) {//this function is menu for tour data
    cout << endl
         << endl;
    cout << "\t\tTour Management System\t\t\n";
    cout << " 1. Add Tour Data.\n 2. View Tour Data. \n 3. Find Tour. \n 4. Delete Tour Data.\n 5. Replace Tour Data\n 6. Return back\n";
    int option;
    cin >> option;

    switch (option) {
    case 1:
        add_tour(tours, tourCount,filename);
        break;

    case 2:
        view_tours(tours, tourCount);
        break;

    case 3:
        find_Tour(tours, tourCount);
        break;

    case 4:
        delete_tour(tours, tourCount,filename);
        break;

    case 5:
        replace_tour(tours, tourCount,filename);
        break;

    case 6:
        exit(0);
        break;

    default:
        cout << "Invalid entry\n";
        break;
    }
}
