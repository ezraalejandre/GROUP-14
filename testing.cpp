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

    if (choice == 1) {
        selectionSort(diagnoses, size);
        groupDiagnoses(diagnoses, size);

        int selected;
        cout << "Please choose from the given diagnoses:" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << diagnoses[i] << endl;
        }
        cout << "Answer (1-" << size << "): ";
        cin >> selected;

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
    } else {
        cout << "Choose a valid answer (1/2)." << endl;
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

// Function to perform linear search
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

