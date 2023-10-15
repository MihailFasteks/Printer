//
//  main.cpp
//  Pr1
//
//  Created by Michalis on 15.10.2023.
//

#include <iostream>
#include <string>
using namespace std;
class PriorityQueue {
    string* wait;
    int* priority;
    
    int maxQueueLength;
    int queueLength;
public:
    PriorityQueue(int maxSize);
    ~PriorityQueue();
    
    void Add(string, int);
    void Show();

    
    string Extract();
    
    void Clear();
    
    bool IsEmpty();
    bool IsFull();
    
    int GetCount(); 
};
PriorityQueue::PriorityQueue(int maxSize) {
    maxQueueLength = maxSize;
    wait = new string[maxQueueLength];
    priority = new int[maxQueueLength];
    queueLength = 0;
}
PriorityQueue::~PriorityQueue() {
    delete[] wait;
    delete[] priority;
}

void PriorityQueue::Add(string n, int p) {
    if (!IsFull()) {
        wait[queueLength] = n;
        priority[queueLength] = p;
        queueLength++;
    }
}

void PriorityQueue::Show() {
    for (int i = 0; i < queueLength; i++)
        cout << "Имя: " << wait[i] << ", приоритет: " << priority[i] << endl;
}

string PriorityQueue::Extract() {
    if (!IsEmpty()) {
        int indexMaxPriority = 0;

        for (int i = 1; i < queueLength; i++)
            if (priority[indexMaxPriority] < priority[i])
                indexMaxPriority = i;

        string temp1 = wait[indexMaxPriority];
        int temp2 = priority[indexMaxPriority];

        for (int i = indexMaxPriority; i < queueLength - 1; i++) {
            wait[i] = wait[i + 1];
            priority[i] = priority[i + 1];
        }
        queueLength--;
        
        return temp1;
    }
    string err = "Error";
    return err;
}

void PriorityQueue::Clear() { queueLength = 0; }

bool PriorityQueue::IsEmpty() { return queueLength == 0; }
bool PriorityQueue::IsFull() { return queueLength == maxQueueLength; }

int PriorityQueue::GetCount() { return queueLength; }
int main()
    {
    PriorityQueue a(5);
        string tempName;
        int tempPriority;

        for (int i = 0; i < 4; i++) {
            cout << "Введите имя: ";
            cin >> tempName;
            do {
                cout << "Введите приоритет (1-10): ";
                cin >> tempPriority;

                if (tempPriority > 10 || tempPriority < 1)
                    cout << "Вы ввели неверный приоритет!" << endl << endl;
            } while (tempPriority > 10 || tempPriority < 1);
            
            a.Add(tempName, tempPriority);
        }
        cout << endl;

        a.Show();
        cout << endl;

        cout << "Статистика приоритетов: " << endl;
        for (int i = 0; i < 4; i++)
            cout << i + 1 << ". " << a.Extract() << endl;

    return 0;
}
