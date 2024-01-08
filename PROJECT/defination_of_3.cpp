#include "header3.h"

void menu(Tour* tours, int& tourCount, string filename) {//this function is menu for tour data
    cout << endl << endl;
    cout << "\t\tTour Management System\t\t\n";
    cout << " 1. Add Tour Data.\n 2. View Tour Data. \n 3. Find Tour. \n 4. Delete Tour Data.\n 5. Replace Tour Data\n 6. Return back\n";
    int option;
    cin >> option;

    switch (option) {
        case 1:
            add_tour(tours, tourCount, filename);
            break;

        case 2:
            view_tours(tours, tourCount);
            break;

        case 3:
            find_tour(tours, tourCount);
            break;

        case 4:
            delete_tour(tours, tourCount, filename);
            break;

        case 5:
            replace_tour(tours, tourCount, filename);
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Invalid entry\n";
            break;
    }
}



void loadFromFile(Tour* tours, int& tourCount, string filename) {//load data from file to struct
    ifstream fin;
    ifstream nameFile("tour_data.txt"); // File of project 1
    ifstream destinationFile("tours_data2.txt"); // File of project 2

    if (!nameFile.is_open() || !destinationFile.is_open()) {
        cout << "Error opening files\n";
        return; // Error handling
    }
    file_merge(tours,tourCount,nameFile, destinationFile); // Function call

    fin.open(filename);

    if (fin.fail()) {
        cout << "Error opening file for reading. Starting with an empty data set." << endl;
        return; // Error handling
    }

    tourCount = 0; // Reset tour count to pick data from the start of the file

    while (fin >> tours[tourCount].name >> tours[tourCount].destination >> tours[tourCount].day >> tours[tourCount].time) {
        tourCount++; // Loading data into the struct of tour
    }

    fin.close(); // File closing
}





void saveToFile(Tour* tours, int& tourCount, string filename) {// Function to save tour data to a file
    ofstream fout;
    fout.open(filename); // Opening new file

    if (fout.fail()) {
        cout << "Error opening file for writing." << endl; // Error handling
        return;
    }

    for (int i = 0; i <= tourCount; ++i) {
        fout << tours[i].name << " " << tours[i].destination << " " << tours[i].day << " " << tours[i].time << endl; // Writing in file
    }

    fout.close(); // Good practice to close file
}

void file_merge(Tour *tours, int &tourCount, ifstream &nameFile, ifstream &destinationFile)// Function to load tour data from a past 2 project
{
    tourCount = 0; // Reset tour count to pick data from the start of the file

    struct Temp1 {//making temp stuff to hold data 
        string name;
        string location;
        string mode;
        int days;
    };

    struct Temp2 {
        string name;
        string destination;
        string airport;
        string landmark;
    };

    Temp1 temp1[MAX_TOURS]; // Variable declaration
    Temp2 temp2[MAX_TOURS];

    // Reading data from both files 
    while (tourCount < MAX_TOURS &&
           destinationFile >> temp2[tourCount].name >> temp2[tourCount].destination >> temp2[tourCount].airport >> temp2[tourCount].landmark &&
           nameFile >> temp1[tourCount].name >> temp1[tourCount].location >> temp1[tourCount].mode >> temp1[tourCount].days) {
        //taking the data we need
        tours[tourCount].name = temp1[tourCount].name;
        tours[tourCount].destination = temp2[tourCount].destination;
        tourCount++; // Loading data into the struct of tour
    }

    // Close the files after reading
    nameFile.close();
    destinationFile.close();

}
void add_tour(Tour* tours, int& tourCount, string filename) {
    if (tourCount < MAX_TOURS) {
        // Taking input from the user
        cout << "\nFor name: " << tours[tourCount].name << " and Destination: " << tours[tourCount].destination << " enter day of arrival and time\n";
        //the uper line picks name from project 1 file and destination from project 2 file
        cout << "Arrived at what Day\n";
        cin.ignore();
        getline(cin, tours[tourCount].day);
        cout << "Arrived at what time (format hh:mm:ss)\n";
        getline(cin, tours[tourCount].time);
        cout << "Updated successfully.\n";

        saveToFile(tours, tourCount,filename);// Now saving data to file we just call the function
        tourCount++;
    } else {
        cout << "Maximum number of tours reached.\n";
    }
}

void view_tours(Tour* tours, int& tourCount) {//this function views tour data 
    cout << "NAMES\t\tDESTINATION\t\tDAY\t\tTIME\n" << endl;

    for (int i = 0; i < tourCount; ++i) {
        cout << tours[i].name << "\t\t" << tours[i].destination << "\t\t" << tours[i].day << "\t\t" << tours[i].time << endl;
    }
}

void find_tour(Tour* tours, int& tourCount) {//this function finds tour data
    cout << "Enter name to find\n";
    string name;
    cin.ignore();// Ignore any characters in the buffer
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < tourCount; ++i) {
        if (tours[i].name == name) {
            cout << "Match found:\n";
            cout << tours[i].name << "\t" << tours[i].destination << "\t" << tours[i].day << "\t" << tours[i].time << endl;
            found = true;
            break;
        }
    }

    if (!found) {//if match not found
        cout << "Match not found\n";
    }
}



void delete_tour(Tour* tours, int& tourCount, string filename) {//this function delet tour data
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

        saveToFile(tours, tourCount,filename); // Save data to file after deleting a tour
    } else {
        cout << "Match not found\n";
    }
}

void replace_tour(Tour* tours, int& tourCount, string filename) {//this function repalce tour data
    cout << "Enter Name to Replace:\n";
    string name;
    cin.ignore();
    getline(cin, name);

    int foundIndex = -1;
    for (int i = 0; i < tourCount; ++i) {
        if (tours[i].name == name) {//checking whether the name exists in the file
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
         // Taking new input to replace the old data
        cout << "Enter new Name\n";
        getline(cin, tours[foundIndex].name);
        cout << "Enter new Destination\n";
        getline(cin, tours[foundIndex].destination);
        cout << "Arrived at what Day\n";
        getline(cin, tours[foundIndex].day);
        cout << "Arrived at what time (format hh:mm:ss)\n";
        getline(cin, tours[foundIndex].time);
        cout << "Record replaced successfully\n";
        // Save data to file after replacing a tou
        saveToFile(tours, tourCount,filename); // Save data to file after replacing a tour
    } else {
        cout << "Match not found\n";
    }
}
