/*
Group Number 14
Group Leader: Ezra L. Alejandre
Group Member: 
Ric Manuel C. Avilla
Gezelle Franz D. Maranan
Topic: Console Based Asylum Management System
*/

//(Ezra) hi, idea pa lang ilagay dito. kung may gusto kayo idagdag, comments at suggestions lagay lang kayo tas lagay nyo rin pangalan nyo salamattttttttttt 


/* (Ezra) idea 1:
Churvaness Asylum Virtual Registration
kunin muna information ng user, parang log in: e-mail, name, age, contact no., address.
sa umpisa may main menu.
tapos may options, pagpipilian ay diagnosed/undiagnosed.
pag undiagnosed, online consultation muna sya sa idea 2, magfill up ng appointment form para magpaevaluate muna sya sa psychiatrist onsite sa ating asylum.
pag diagnosed, may options, pagpipilian nakalagay mga sinearch na mental disorders hahahaa balew
        nakagroup na yung mga mental disorders base sa matino, medj matino, medj valew, valew na tlga(research tungkol dito)
        tapos base sa kung gaano kalala mental disorder niya, dun sya ilalagay kung saan sya nararapat na group.
*/

/* (Ezra) idea 2:
Churvaness Asylum Virtual Consultation
kunin ule information kung di pa nakukuha.
main menu. pili ule kung diagnosed/undiagnosed.
diagnosed: punta sa registration.
undiagnosed: mag aanswer ang user ng questionnaire(research tungkol sa tinatanong sa mga valew).
        kung ano yung nagmamatch na mental disorder sa kanya base sa mga tanong, yun yung magiging result na mental disorder.
pagkalabas ng result, may option kung gusto niya magregister sa ating asylum/ayaw.
        pag ayaw, tapos na.
        pag magpaparegister, pupunta sa idea 1 virtual registration.
*/






/*
PSEUDOCODE:

*/

/*(Gezelle) ilagay ko na din pala here yung sa canva para sa presentation sa DSA*/
https://www.canva.com/design/DAGDhjO0QWM/I84ZIHIQry-sA33SGsCirw/edit?utm_content=DAGDhjO0QWM&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton

//For DSA activity, yung gagawin sa diagnosed at undiagnosed. May search at sort.
#include <iostream>
#include <string>
using namespace std;

void selectionSort(string arr[], int n);
int linearSearch(string arr[], int n, string key);
void groupDiagnoses(string arr[], int n);

int main() {
    string diagnoses[] = {
        "Neurodevelopmental disorders",
        "Neurocognitive disorders",
        "Sleep-wake disorders",
        "Anxiety Disorders",
        "Depressive disorders",
        "Bipolar and related disorders",
        "Schizophrenia spectrum and other psychotic disorders",
        "Trauma- and stressor-related disorders",
        "Substance-related and addictive disorders",
        "Personality disorders",
        "Obsessive-compulsive and related disorders",
        "Feeding and eating disorders"
    };
    int size = sizeof(diagnoses) / sizeof(diagnoses[0]);

    int choice;
    cout << "What is your mental health assessment status?" << endl;
    cout << "1. Diagnosed" << endl;
    cout << "2. Undiagnosed" << endl;
    cout << "Answer (1/2): ";
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Please choose a valid answer (1/2)." << endl;
        cout << "Answer (1/2): ";
        cin >> choice;
    }

    if (choice == 1) {
        selectionSort(diagnoses, size);
        groupDiagnoses(diagnoses, size);

        int selected;
        cout << "Please choose one from the given diagnoses:" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << diagnoses[i] << endl;
        }
        cout << "Answer (1-" << size << "): ";
        cin >> selected;

        while (selected < 1 || selected > size) {
            cout << "Please choose a valid answer (1-" << size << "): ";
            cin >> selected;
        }

        string selectedDiagnosis = diagnoses[selected - 1];
        cout << selectedDiagnosis << endl;

        int position = linearSearch(diagnoses, size, selectedDiagnosis);
        if (position != -1) {
            if (position <= 4) {
                cout << "Your diagnosis is classified as mild." << endl;
            } else if (position <= 8) {
                cout << "Your diagnosis is classified as moderate." << endl;
            } else if (position <= 11) {
                cout << "Your diagnosis is classified as moderately severe." << endl;
            } else {
                cout << "Your diagnosis is classified as severe." << endl;
            }
        } else {
            cout << "Diagnosis not found." << endl;
        }
    } else if (choice == 2) {
        cout << "Please make a consultation appointment first." << endl;
    }

    return 0;
}

void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int linearSearch(string arr[], int n, string key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i + 1;
        }
    }
    return -1;
}

void groupDiagnoses(string arr[], int n) {
    string mild[] = { arr[3], arr[4], arr[10], arr[11] };
    string moderate[] = { arr[8], arr[1], arr[0], arr[9] };
    string moderatelySevere[] = { arr[5], arr[2], arr[7] };
    string severe[] = { arr[6] };
}



/* (Gezelle & Ric ) Eto yung na code namin kumbaga may kulang pa dito e , diko alam ano ilalagay ko about sa undiagnosed ,tas ano nilagay ko yung list of mental disorders mo 
dun sa part ng diagnose */

#include <iostream>
#include <string>
using namespace std;

const int maxPatients = 1000;

struct Patient {
    int id;
    string name;
    int age;
    char gender;
    string email;
    string address;
    string contactNumber; 
    bool diagnosed;
    string diagnosis;
};

// List of mental disorders
string mentalDisorders[] = {
    "Neurodevelopmental disorders",
    "Neurocognitive disorders",
    "Sleep-wake disorders",
    "Anxiety Disorders",
    "Depressive disorders",
    "Bipolar and related disorders",
    "Schizophrenia spectrum and other psychotic disorders",
    "Trauma- and stressor-related disorders",
    "Substance-related and addictive disorders",
    "Personality disorders",
    "Obsessive-compulsive and related disorders",
    "Feeding and eating disorders"
};
const int numDisorders = sizeof(mentalDisorders) / sizeof(mentalDisorders[0]);

// Function to register a new patient
void registerPatient(Patient patients[], int& patientCount) {
    if (patientCount < maxPatients) {
        cout << "\n======= Patient Registration =======\n";
        cout << "Enter patient name: ";
        cin.ignore(); // Ignore newline character in buffer
        getline(cin, patients[patientCount].name);
        cout << "Enter patient age: ";
        cin >> patients[patientCount].age;
        cout << "Enter patient gender (M/F): ";
        cin >> patients[patientCount].gender;
        cout << "Enter patient email: ";
        cin >> patients[patientCount].email;
        cout << "Enter patient contact number: ";
        cin >> patients[patientCount].contactNumber;
        cout << "Enter patient address: ";
        cin.ignore(); // Ignore newline character in buffer
        getline(cin, patients[patientCount].address);
        patients[patientCount].diagnosed = false;
        patients[patientCount].id = patientCount + 1; // Assigning ID to the patient

        cout << "Patient registered successfully with ID: " << patients[patientCount].id << endl;
        patientCount++;
    }
    else {
        cout << "Maximum patient limit reached.\n";
    }
}

// Function to display all registered patients
void displayPatients(const Patient patients[], int count) {
    cout << "\n=============================================================================================================================\n";
    cout << "| ID\t|  Name\t\t|  Age\t| Gender |     Email\t\t\t| Contact Number\t| Address\t\t| Diagnosed | Diagnosis\n |";
    cout << "=============================================================================================================================\n";
    for (int i = 0; i < count; ++i) {
        cout << "| " << patients[i].id << "\t| " << patients[i].name << "\t\t|  " << patients[i].age << "\t|   " << patients[i].gender << "    | " << patients[i].email << "\t| " << patients[i].contactNumber << "\t| " << patients[i].address << "\t| " << (patients[i].diagnosed ? "Yes" : "No") << "\t   | ";
        if (patients[i].diagnosed) {
            cout << patients[i].diagnosis;
        }
        else {
            cout << "N/A";
        }
        cout << "\n";
    }
    cout << "=============================================================================================================================\n";
}

// Function to diagnose a patient
void diagnosePatient(Patient patients[], int& patientCount) {
    cout << "\n======= Diagnose Patient =======\n";
    cout << "Enter patient ID to diagnose: ";
    int id;
    cin >> id;
    if (id >= 1 && id <= patientCount) {
        cout << "Please select the diagnosis for the patient:\n";
        for (int i = 0; i < numDisorders; ++i) {
            cout << i + 1 << ". " << mentalDisorders[i] << endl;
        }
        cout << "Enter your choice (1-" << numDisorders << "): ";
        int choice;
        cin >> choice;
        if (choice >= 1 && choice <= numDisorders) {
            patients[id - 1].diagnosis = mentalDisorders[choice - 1];
            patients[id - 1].diagnosed = true;
            cout << "Patient diagnosed with " << mentalDisorders[choice - 1] << ".\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    else {
        cout << "Invalid patient ID.\n";
    }
}

// Function to undiagnose a patient
void undiagnosePatient(Patient patients[], int& patientCount) {
    cout << "\n======= Undiagnose Patient =======\n";
    cout << "Enter patient ID to undiagnose: ";
    int id;
    cin >> id;
    if (id >= 1 && id <= patientCount) {
        patients[id - 1].diagnosis = "";
        patients[id - 1].diagnosed = false;
        cout << "Patient undiagnosed. \n";
    }
    else {
        cout << "Invalid patient ID.\n";
    }
}

int main() {
    Patient patients[maxPatients];
    int patientCount = 0;

    cout << "======= Welcome to Churvanes Asylum =======\n";
    cout << "Please register the patient first.\n";
    registerPatient(patients, patientCount);

    while (true) {
        cout << "\n======= Main Menu =======\n";
        cout << "1. Register Patient\n";
        cout << "2. Diagnose Patient\n";
        cout << "3. Undiagnose Patient\n";
        cout << "4. View Patients\n";
        cout << "5. Exit\n";
        cout << "========================\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            registerPatient(patients, patientCount);
            break;
        case 2:
            diagnosePatient(patients, patientCount);
            break;
        case 3:
            undiagnosePatient(patients, patientCount);
            break;
        case 4:
            displayPatients(patients, patientCount);
            break;
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}

