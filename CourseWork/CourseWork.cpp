#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <sstream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class clDate {
private:
    Date date;
public:
    clDate() {
        date.day = 1;
        date.month = 1;
        date.year = 2000;
    }
    clDate(int d, int m, int y) {
        date.day = d;
        date.month = m;
        date.year = y;
    }
    clDate(const Date& cDate) {
        date = cDate;
    }
    bool setDate(Date& sDate) {
        if ((sDate.day < 32) && (sDate.day > 0))
            date.day = sDate.day;
        else {
            cout << "Неверное значение дня (от 1 до 31, введено " << sDate.day << " )" << endl;
            return 1;
        }
        if ((sDate.month < 13) && (sDate.month > 0))
            date.month = sDate.month;
        else {
            cout << "Неверное значение месяца (от 1 до 12, введено " << sDate.month << " )" << endl;
            return 1;
        }
        if ((sDate.year <= 2023) && (sDate.year >= 1990))
            date.year = sDate.year;
        else {
            cout << "Неверное значение года (от 1990 до 2023, введено " << sDate.year << " )" << endl;
            return 1;
        }
        return 0;
    }
    Date getDate() {
        return date;
    }
    void printDate() {
        if (date.day < 10) cout << "0" << date.day;
        else cout << date.day;
        cout << ".";
        if (date.month < 10) cout << "0" << date.month;
        else cout << date.month;
        cout << ".";
        cout << date.year;
    }
};

enum class Sex {Man, Woman};
enum class Mark {Absence, Fail, Bad, Satisfactory, Good, Excellent, Pass};

struct ExamsRecords {
    char ExamName[30];
    enum class Mark mark;
    bool isFilled;
};

struct StudentNode {
    char Surname[30];
    char Name[30];
    char MiddleName[30];
    char Institute[10];
    char Department[20];
    char Group[15];
    char StudentCardNumb[15];
    clDate BirthDate;
    enum class Sex sex;
    int StartYear;
    ExamsRecords ExamsData[9][10];
};

class clStudent {
private:
    StudentNode student;
public:
    clStudent() {
    }
    clStudent(StudentNode data) {
        student = data;
    }
    StudentNode getStudentData() {
        return student;
    }

    bool setStudentSurname(StudentNode* data) {
        for (int i = 0; i < ((string)data->Surname).length(); i++) {
            if (!((data->Surname[i] >= 65 and data->Surname[i] <= 90) or (data->Surname[i] >= 97 and data->Surname[i] <= 122) or (data->Surname[i] >= (-64) and data->Surname[i] <= (-1)))) {
                if (data->Surname[i] >= 48 and data->Surname[i] <= 57) {
                    cout << "В фамилии не могут содержатся цифры (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->Surname[i] >= 33 and data->Surname[i] <= 47) {
                    cout << "В фамилии не могут содержатся специальные символы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->Surname[i] == 32) {
                    cout << "В фамилии не могут быть пробелы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
            }
        }
        strcpy_s(student.Surname, data->Surname);
        return 0;
    }
    
    bool setStudentName(StudentNode* data) {
        for (int i = 0; i < ((string)data->Name).length(); i++) {
            if (!((data->Name[i] >= 65 and data->Name[i] <= 90) or (data->Name[i] >= 97 and data->Name[i] <= 122) or (data->Name[i] >= (-64) and data->Name[i] <= (-1)))) {
                if (data->Name[i] >= 48 and data->Name[i] <= 57) {
                    cout << "В имени не могут содержатся цифры (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->Name[i] >= 33 and data->Name[i] <= 47) {
                    cout << "В имени не могут содержатся специальные символы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->Name[i] == 32) {
                    cout << "В имени не могут быть пробелы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
            }
        }
        strcpy_s(student.Name, data->Name);
        return 0;
    }

    bool setStudentMiddleName(StudentNode* data) {
        for (int i = 0; i < ((string)data->MiddleName).length(); i++) {
            if (!((data->MiddleName[i] >= 65 and data->MiddleName[i] <= 90) or (data->MiddleName[i] >= 97 and data->MiddleName[i] <= 122) or (data->MiddleName[i] >= (-64) and data->MiddleName[i] <= (-1)))) {
                if (data->MiddleName[i] >= 48 and data->MiddleName[i] <= 57) {
                    cout << "В отчестве не могут содержатся цифры (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->MiddleName[i] >= 33 and data->MiddleName[i] <= 47) {
                    cout << "В отчестве не могут содержатся специальные символы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->MiddleName[i] == 32) {
                    cout << "В отчестве не могут быть пробелы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
            }
        }
        strcpy_s(student.MiddleName, data->MiddleName);
        return 0;
    }

    bool setStudentInstitute(StudentNode* data) {
        for (int i = 0; i < ((string)data->Institute).length(); i++) {
            if (!((data->Institute[i] >= 65 and data->Institute[i] <= 90) or (data->Institute[i] >= 97 and data->Institute[i] <= 122) or (data->Institute[i] >= (-64) and data->Institute[i] <= (-1)))) {
                if (data->Institute[i] >= 48 and data->Institute[i] <= 57) {
                    cout << "В названии института не могут содержатся цифры (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->MiddleName[i] >= 33 and data->MiddleName[i] <= 47) {
                    cout << "В названии института не могут содержатся специальные символы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
                if (data->MiddleName[i] == 32) {
                    cout << "В названии института не могут быть пробелы (" << i + 1 << " знак)" << endl;
                    return 1;
                }
            }
        }
        strcpy_s(student.Institute, data->Institute);
        return 0;
    }

    bool setStudentDepartment(StudentNode* data) {
        for (int i = 0; i < ((string)data->Department).length(); i++) {
            if (!((data->Department[i] >= 65 and data->Department[i] <= 90) or (data->Department[i] >= 97 and data->Department[i] <= 122) or (data->Department[i] >= (-64) and data->Department[i] <= (-1)) or (data->Department[i] == 32 or data->Department[i] == 44 or data->Department[i] == 45) or (data->Department[i] >= 48 and data->Department[i] <= 57))) {
                if (data->Department[i] >= 33 and data->Department[i] <= 47) {
                    cout << "В названии кафедры не могут содержатся специальные символы кроме запятой и дефиса (" << i + 1 << " знак)" << endl;
                    return 1;
                }
            }
        }
        strcpy_s(student.Department, data->Department);
        return 0;
    }

    bool setStudentGroup(StudentNode* data) {
        for (int i = 0; i < ((string)data->Group).length(); i++) {
            if (((string)data->Group).length() < 10) {
                cout << "Неверная длина идентификатора группы (нужно еще " << 10 - ((string)data->Group).length() << "символов)" << endl;
                return 1;
            }
            if (i < 4) {
                if (!(data->Group[i] >= (-64) and data->Group[i] <= (-1))) {
                    cout << "Неверно введенная факультетная часть идентификатора группы (символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (i == 4) {
                if (data->Group[i] != 45) {
                    cout << "Неверный формат идентификатора группы (должно быть дефис, символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (i < 7) {
                if (!(data->Group[i] >= 48 and data->Group[i] <= 57)) {
                    cout << "Неверно введен номер группы (символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (i == 7) {
                if (data->Group[i] != 45) {
                    cout << "Неверный формат идентификатора группы (должно быть дефис, символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (i <= 9) {
                if (!(data->Group[i] >= 48 and data->Group[i] <= 57)) {
                    cout << "Неверно введен номер года поступления группы (символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (data->Group[i] != '\0') {
                cout << "Неверная длина идентификатора группы (должно быть 10 символов, введено " << ((string)data->Group).length() << ")" << endl;
                return 1;
            }
        }
        strcpy_s(student.Group, data->Group);
        return 0;
    }

    bool setStudentCardNumb(StudentNode* data) {
        for (int i = 0; i < ((string)data->StudentCardNumb).length(); i++) {
            if (((string)data->StudentCardNumb).length() < 7) {
                cout << "Неверная длина номера зачетной книжки (нужно еще " << 7 - ((string)data->StudentCardNumb).length() << "символов" << endl;
                return 1;
            }
            if (i == 2) {
                if (!(data->StudentCardNumb[i] >= (-64) and data->StudentCardNumb[i] <= (-1))) {
                    cout << "Неверно введенная буквенная часть номера зачетной книжки (символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (i < 2 or (i > 2 and i < 7)) {
                if (!(data->StudentCardNumb[i] >= 48 and data->StudentCardNumb[i] <= 57)) {
                    cout << "Неверно введенная циферная часть номера зачетной книжки (символ " << i + 1 << ")" << endl;
                    return 1;
                }
            }
            else if (data->StudentCardNumb[i] != '\0') {
                cout << "Неверная длина номера зачетной книжки (должно быть 7 символов, введено " << ((string)data->StudentCardNumb).length() << ")" << endl;
                return 1;
            }
        }
        strcpy_s(student.StudentCardNumb, data->StudentCardNumb);
        return 0;
    }

    bool setStudentStartYear(StudentNode* data) {
        if (!(data->StartYear <= 2023 and data->StartYear >= 2010)) {
            cout << "Неверно введен год поступления (от 2010 до 2023, введено " << data->StartYear << endl;
            return 1;
        }
        student.StartYear = data->StartYear;
        return 0;
    }

    bool setStudentBirthDate(Date data) {
        return student.BirthDate.setDate(data);
    }

    void setStudentSex(StudentNode* data) {
        student.sex = data->sex;
    }

    void setStudentExamsData(StudentNode* data) {
        for (int i = 0; i < 9; i++) {
            if (data->ExamsData[i]->isFilled == true) {
                student.ExamsData[i]->isFilled = true;
                for (int j = 0; j < 10; j++) {
                    if (data->ExamsData[i][j].isFilled == true) {
                        student.ExamsData[i][j].isFilled = true;
                        student.ExamsData[i][j] = data->ExamsData[i][j];
                    }
                }

            }
        }
    }
};

struct ListNode {
    clStudent Student;
    ListNode* pNext;
    ListNode(clStudent Data) {
        Student = Data;
        pNext = nullptr;
    }
};

class clList {
private:
    ListNode* Head;
    int Size;
public:
    clList() {
        Size = 0;
        Head = nullptr;
    }
    int getSize() {
        return Size;
    }

    ListNode* getHead() {
        return Head;
    }
    clList getStudentsFromFile() {
        ofstream fileT("database.txt", ios::app);
        fileT.close();
        FILE* file; 
        fopen_s(&file, "database.txt", "r");
        clList List;
        StudentNode data;
        Date date;
        int sex;
        while (fscanf_s(file, "%s%s%s%d%d%d%d%s%s%s%s%d", &data.Surname, 30, &data.Name, 30,  &data.MiddleName, 30, &sex, &date.day, &date.month, &date.year, &data.Institute, 10, &data.Department, 20, &data.Group, 15, &data.StudentCardNumb, 15, &data.StartYear) != EOF) {
            data.sex = static_cast<enum class Sex>(sex);
            int grade;
            for (int i = 0; i < 9; i++) {
                fscanf_s(file, "%d", &data.ExamsData[i]->isFilled);
                if (data.ExamsData[i]->isFilled == 1) {
                    data.ExamsData[i]->isFilled = true;
                    for (int j = 0; j < 10; j++) {
                        fscanf_s(file, "%s%d", &data.ExamsData[i][j].ExamName, 30, &grade);
                        for (int c = 0; c < ((string)data.ExamsData[i][j].ExamName).length(); c++) {
                            if (data.ExamsData[i][j].ExamName[c] == 95) {
                                data.ExamsData[i][j].ExamName[c] = 32;
                            }
                        }
                        data.ExamsData[i][j].mark = static_cast<enum class Mark>(grade);
                        data.ExamsData[i][j].isFilled = true;
                    }
                }
                else break;
            }
            data.BirthDate.setDate(date);
            clStudent Student(data);
            List.push_back(Student);
            data = {};
            date = {};
            sex = 3;
        }
        fclose(file);
        return List;
    }

    void push_back(clStudent Data) {
        if (Size == 0) {
            Head = new ListNode(Data);
            Head->pNext = Head;
        }
        else {
            ListNode* current = this->Head;
            while (current->pNext != Head) {
                current = current->pNext;
            }
            current->pNext = new ListNode(Data);
            current = current->pNext;
            current->pNext = this->Head;
        }
        Size++;
    }

    void pop(int index) {
        if (Size != 1) {
            if (index == 0) {
                ListNode* current = this->Head;
                current = current->pNext;
                while (current->pNext != Head) {
                    current = current->pNext;
                }
                current->pNext = new ListNode(current->Student);
                current = current->pNext;
                current->pNext = Head->pNext;
                this->Head = current;
            }
            else {
                ListNode* current = Head;
                if (index == Size - 1) {
                    while (current->pNext->pNext != Head)
                    {
                        current = current->pNext;
                    }
                    ListNode* temp = current->pNext;
                    current->pNext = Head;
                    delete temp;
                }
                else {
                    int i = 0;
                    while (i < index - 1) {
                        current = current->pNext;
                        i++;
                    }
                    ListNode* temp = current->pNext;
                    current->pNext = temp->pNext;
                    delete temp;

                }
            }
        }
        else {
            delete Head;
        }
        Size--;
    }

    bool edit(int stIndex, int editIndex, StudentNode editData) {
        ListNode* current = this->Head;
        int i = 0;
        while (i != stIndex - 1) {
            current = current->pNext;
            i++;
        }
        if (editIndex == 1) {
            return current->Student.setStudentSurname(&editData);
        }
        else if (editIndex == 2) {
            return current->Student.setStudentName(&editData);
        }
        else if (editIndex == 3) {
            return current->Student.setStudentMiddleName(&editData);
        }
        else if (editIndex == 4) {
            return current->Student.setStudentInstitute(&editData);
        }
        else if (editIndex == 5) {
            return current->Student.setStudentDepartment(&editData);
        }
        else if (editIndex == 6) {
            return current->Student.setStudentGroup(&editData);
        }
        else if (editIndex == 7) {
            current->Student.setStudentSex(&editData);
            return 0;
        }
        else if (editIndex == 8) {
            return current->Student.setStudentStartYear(&editData);
        }
        else if (editIndex == 9) {
            return current->Student.setStudentCardNumb(&editData);
        }
        else if (editIndex == 10) {
            return current->Student.setStudentBirthDate(editData.BirthDate.getDate());
        }
    }

    void addStudentsToFile(clList List) {
        ofstream fileT("database.txt");
        fileT.close();
        ListNode* current = this->Head;
        FILE* file;
        fopen_s(&file, "database.txt", "w");
        for (int i = 0; i < Size; i++) {
            int sex = static_cast<int>(List[i].getStudentData().sex);
            fprintf_s(file, "%s %s %s %d %d %d %d %s %s %s %s %d ", List[i].getStudentData().Surname,  List[i].getStudentData().Name, List[i].getStudentData().MiddleName, sex,
                List[i].getStudentData().BirthDate.getDate().day, List[i].getStudentData().BirthDate.getDate().month, List[i].getStudentData().BirthDate.getDate().year,
                List[i].getStudentData().Institute, List[i].getStudentData().Department, List[i].getStudentData().Group, List[i].getStudentData().StudentCardNumb, List[i].getStudentData().StartYear);
            int j = 0;
            while (List[i].getStudentData().ExamsData[j]->isFilled == true) {
                fprintf_s(file, "%s ", "1");
                for (int n = 0; n < 10; n++) {
                    StudentNode st = List[i].getStudentData();
                    int grade = static_cast<int>(List[i].getStudentData().ExamsData[j][n].mark);
                    for (int c = 0; c < ((string)List[i].getStudentData().ExamsData[j][n].ExamName).length(); c++) {
                        if (List[i].getStudentData().ExamsData[j][n].ExamName[c] == ' ') {
                            st.ExamsData[j][n].ExamName[c] = '_';
                        }
                    }
                    List[i].setStudentExamsData(&st);
                    fprintf_s(file, "%s %d ", List[i].getStudentData().ExamsData[j][n].ExamName, grade);
                }
                j++;
            }
            fprintf_s(file, "%s ", "0");
            current = current->pNext;
        }
        fclose(file);
    }

    void printShortInfo(int index) {
        ListNode* current = this->Head;
        for (int i = 0; i < index; i++) {
            current = current->pNext;
        }
        cout << current->Student.getStudentData().Surname << " " << current->Student.getStudentData().Name << " " << current->Student.getStudentData().MiddleName << " " << current->Student.getStudentData().Group << endl;
    }

    void printFullInfo(int index) {
        ListNode* current = this->Head;
        for (int i = 1; i < index; i++) {
            current = current->pNext;
        }
        cout << "Фамилия: " << current->Student.getStudentData().Surname << " " << "Имя: " << current->Student.getStudentData().Name << " " << "Отчество: " << current->Student.getStudentData().MiddleName << endl
            << "Институт: " << current->Student.getStudentData().Institute << " " << "Кафедра: " << current->Student.getStudentData().Department << " " << "Группа: " << current->Student.getStudentData().Group << endl
            << "Номер зачетной книжки: " << current->Student.getStudentData().StudentCardNumb << " " << "Дата рождения: ";
        current->Student.getStudentData().BirthDate.printDate();
        cout << endl;
        cout << "Пол: ";
        if (current->Student.getStudentData().sex == Sex::Man) {
            cout << "мужской ";
        }
        else cout << "женский ";
        cout << "Год начала обучения: " << current->Student.getStudentData().StartYear << endl;
    }

    void printSessionInfo(int index) {
        ListNode* current = this->Head;
        for (int i = 1; i < index; i++) {
            current = current->pNext;
        }
        if (current->Student.getStudentData().ExamsData[0]->isFilled == true) {
            int i = 0;
            while (current->Student.getStudentData().ExamsData[i]->isFilled == true) {
                cout << i + 1 << ". Семестр" << endl;
                cout << endl;
                for (int j = 0; j < 10; j++) {
                    cout << j + 1 << ". " << current->Student.getStudentData().ExamsData[i][j].ExamName << " - ";
                    if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Absence) {
                        cout << "Отсутствовал по уважительной причине" << endl;
                    }
                    else if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Fail) {
                        cout << "Незачет" << endl;
                    }
                    else if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Pass) {
                        cout << "Зачет" << endl;
                    }
                    else if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Bad) {
                        cout << "Оценка: 2" << endl;
                    }
                    else if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Satisfactory) {
                        cout << "Оценка: 3" << endl;
                    }
                    else if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Good) {
                        cout << "Оценка: 4" << endl;
                    }
                    else if (current->Student.getStudentData().ExamsData[i][j].mark == Mark::Excellent) {
                        cout << "Оценка: 5" << endl;
                    }
                }
                cout << "-------------------------" << endl;
                i++;
            }
        }
        else cout << "Нет информации о результатах сессий студента." << endl;
        cout << "--------------------------------------------------" << endl;
    }
    bool Encrypt(string password)
    {
        string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in database.txt -out database.enc -pass pass:" + password;
        system(command.c_str());
        if (remove("database.txt") != 0) {
            return false;
        }
        return true;
    }

    bool Decrypt(string password)
    {
        string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in database.enc -out database.txt -pass pass:";
        command += password;
        system(command.c_str());
        if (remove("database.enc") != 0) {
            return false;
        }
        return true;
    }

    clStudent& operator[](const int index) {
        ListNode* current = this->Head;
        int count = 0;
        while (current->pNext != Head)
        {
            if (count == index)
            {
                return current->Student;
            }
            current = current->pNext;
            count++;
        }
    }
};

class clMenu {
private:
public:
    void StartMenu(clList List) {
        int choise;
        cout << "--------------------Главное меню--------------------" << endl;
        cout << "1. Отобразить/изменить данные о студентах" << endl;
        cout << "2. Добавить данные о новом студенте / о новой сессии" << endl;
        cout << "3. Выполнить индивидуальное задание" << endl;
        cout << "4. Выйти" << endl;
        cout << "----------------------------------------------------" << endl;
        while (true) {
            cout << "Введите цифру, соответствующую выбору >";
            cin >> choise;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << endl;
            if (choise == 1 or choise == 2 or choise == 3 or choise == 4) {
                break;
            }
            else {
                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
            }
        }
        if (choise == 4) {
            system("cls");
            int saveChoise;
            cout << "Сохранить и выйти?" << endl;
            cout << "1. Да" << endl;
            cout << "2. Нет" << endl;
            while (true) {
                cout << "Введите цифру, соответствующую выбору >";
                cin >> saveChoise;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (saveChoise == 1 or saveChoise == 2) {
                    break;
                }
                else {
                    cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                }
            }
            if (saveChoise == 1) {
                List.addStudentsToFile(List);
                string password;
                cout << "Введите пароль для шифрования данных >";
                cin >> password;
                List.Encrypt(password);
            }
            else if (saveChoise == 2) {
                string password;
                cout << "Введите пароль для шифрования данных >";
                cin >> password;
                List.Encrypt(password);
            }
        }
        else if (choise == 1) {
            system("cls");
            ViewingAndEditingMenu(List);
        }
        else if (choise == 2) {
            system("cls");
            AddMenu(List);
        }
        else if (choise == 3) {
            system("cls");
            Task(List);
        }
    }
    void Task(clList Students) {
        cout << "------------Выполнение индивидуального задания------------" << endl;
        cout << "Вариант 96. Разбить группу на 2 части, с поиском среди лиц" << endl;
        cout << "            с указанием интервала года рождения:" << endl;
        cout << "                - хорошисты и отличники;" << endl;
        cout << "                - троечники." << endl;
        cout << "            Каждую часть отсортировать по номерам зачетных" << endl;
        cout << "            книжек." << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "1. Начать выполнение" << endl;
        cout << "2. Выход в главное меню" << endl;
        cout << "----------------------------------------------------------" << endl;
        int choise;
        while (true) {
            cout << "Введите цифру, соответствующую выбору >";
            cin >> choise;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << endl;
            if (choise == 1 or choise == 2) {
                break;
            }
            else {
                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
            }
        }
        if (choise == 2) {
            system("cls");
            StartMenu(Students);
        }
        else if (choise == 1) {
            system("cls");
            cout << "------------Выполнение индивидуального задания------------" << endl;
            cout << "Вариант 96. Разбить группу на 2 части, с поиском среди лиц" << endl;
            cout << "            с указанием интервала года рождения:" << endl;
            cout << "                - хорошисты и отличники;" << endl;
            cout << "                - троечники." << endl;
            cout << "            Каждую часть отсортировать по номерам зачетных" << endl;
            cout << "            книжек." << endl;
            cout << "----------------------------------------------------------" << endl;
            if (Students.getSize() == 0) {
                cout << "Нет данных о студентах." << endl;
                int escape;
                while (true) {
                    cout << "Введите 1 для выхода в главное меню >";
                    cin >> escape;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (escape == 1) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                    }
                }
                system("cls");
                StartMenu(Students);
            }
            else {
                int startYear;
                while (true) {
                    cout << "Введите левую границу интервала года рождения (от 2000 до 2030) >";
                    cin >> startYear;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (startYear >= 2000 and startYear <= 2030) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод левой границы интервала года рождения, попробуйте еще раз" << endl;
                    }
                }
                cout << "-------------------------------------------" << endl;
                int endYear;
                while (true) {
                    cout << "Введите правую границу интервала года рождения (от левой границы интервала до 2030) >";
                    cin >> endYear;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (endYear >= startYear and endYear <= 2030) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод правой границы интервала года рождения, попробуйте еще раз" << endl;
                    }
                }
                cout << "-------------------------------------------" << endl;
                clList Sort;
                for (int i = 0; i < Students.getSize(); i++) {
                    if (Students[i].getStudentData().BirthDate.getDate().year < endYear and Students[i].getStudentData().BirthDate.getDate().year > startYear) {
                        Sort.push_back(Students[i]);
                    }
                }
                clList Good;
                clList Satis;
                if (Sort.getSize() == 0) {
                    cout << "Студентов в данном годовом диапозоне не найдено" << endl;
                    int escape;
                    while (true) {
                        cout << "Введите 1 для выхода в меню выполнения задания >" << endl;
                        cin >> escape;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (escape == 1) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                        }
                    }
                    system("cls");
                    Task(Students);
                }
                else {
                    for (int c = 0; c < Sort.getSize(); c++) {
                        float performance = 0;
                        int perfCount = 0;
                        int i = 0;
                        while (Sort[c].getStudentData().ExamsData[i]->isFilled == true) {
                            int j = 0;
                            int Score = 0;
                            int ScoreCount = 0;
                            while (Sort[c].getStudentData().ExamsData[i][j].isFilled == true) {
                                if (Sort[c].getStudentData().ExamsData[i][j].mark == Mark::Excellent) {
                                    Score += 5;
                                    ScoreCount++;
                                }
                                else if (Sort[c].getStudentData().ExamsData[i][j].mark == Mark::Good) {
                                    Score += 4;
                                    ScoreCount++;
                                }
                                else if (Sort[c].getStudentData().ExamsData[i][j].mark == Mark::Satisfactory) {
                                    Score += 3;
                                    ScoreCount++;
                                }
                                else if (Sort[c].getStudentData().ExamsData[i][j].mark == Mark::Bad) {
                                    Score += 2;
                                    ScoreCount++;
                                }
                                j++;
                            }
                            if (Score == 0) {
                                performance = 0;
                            }
                            else performance += (float)Score / ScoreCount;
                            i++;
                            perfCount++;
                        }
                        performance = performance / perfCount;
                        if (performance >= 4) {
                            Good.push_back(Sort[c]);
                        }
                        else if (performance >= 3) {
                            Satis.push_back(Sort[c]);
                        }
                    }
                }
                if (Good.getSize() == 0) {
                    cout << "Хорошистов и отличников нет." << endl;
                }
                else if (Good.getSize() == 1) {
                    cout << "Хорошисты и отличники: " << endl;
                    cout << Good[0].getStudentData().Surname << " " << Good[0].getStudentData().Name << " " << Good[0].getStudentData().MiddleName << " " << Good[0].getStudentData().StudentCardNumb << endl;
                }
                else {
                    for (int i = 0; i < Good.getSize() - 1; i++) {
                        for (int j = 0; j < Good.getSize() - i - 1; j++) {
                            if (Good[j].getStudentData().StudentCardNumb[0] > Good[j + 1].getStudentData().StudentCardNumb[0]) {
                                swap(Good[j], Good[j + 1]);
                            }
                            else if (Good[j].getStudentData().StudentCardNumb[0] == Good[j + 1].getStudentData().StudentCardNumb[0]) {
                                if (Good[j].getStudentData().StudentCardNumb[1] > Good[j + 1].getStudentData().StudentCardNumb[1]) {
                                    swap(Good[j], Good[j + 1]);
                                }
                                else if (Good[j].getStudentData().StudentCardNumb[1] == Good[j + 1].getStudentData().StudentCardNumb[1]) {
                                    if (Good[j].getStudentData().StudentCardNumb[2] > Good[j + 1].getStudentData().StudentCardNumb[2]) {
                                        swap(Good[j], Good[j + 1]);
                                    }
                                    else if (Good[j].getStudentData().StudentCardNumb[2] == Good[j + 1].getStudentData().StudentCardNumb[2]) {
                                        if (Good[j].getStudentData().StudentCardNumb[3] > Good[j + 1].getStudentData().StudentCardNumb[3]) {
                                            swap(Good[j], Good[j + 1]);
                                        }
                                        else if (Good[j].getStudentData().StudentCardNumb[3] == Good[j + 1].getStudentData().StudentCardNumb[3]) {
                                            if (Good[j].getStudentData().StudentCardNumb[4] > Good[j + 1].getStudentData().StudentCardNumb[4]) {
                                                swap(Good[j], Good[j + 1]);
                                            }
                                            else if (Good[j].getStudentData().StudentCardNumb[4] == Good[j + 1].getStudentData().StudentCardNumb[4]) {
                                                if (Good[j].getStudentData().StudentCardNumb[5] > Good[j + 1].getStudentData().StudentCardNumb[5]) {
                                                    swap(Good[j], Good[j + 1]);
                                                }
                                                else if (Good[j].getStudentData().StudentCardNumb[5] == Good[j + 1].getStudentData().StudentCardNumb[5]) {
                                                    if (Good[j].getStudentData().StudentCardNumb[6] > Good[j + 1].getStudentData().StudentCardNumb[6]) {
                                                        swap(Good[j], Good[j + 1]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    cout << "Хорошисты и отличники: " << endl;
                    for (int i = 0; i < Good.getSize(); i++) {
                        cout << Good[i].getStudentData().Surname << " " << Good[i].getStudentData().Name << " " << Good[i].getStudentData().MiddleName << " " << Good[i].getStudentData().StudentCardNumb << endl;
                    }
                }
                cout << "-----------------------------------------------------------" << endl;
                if (Satis.getSize() == 0) {
                    cout << "Троечников нет." << endl;
                }
                else if (Satis.getSize() == 1) {
                    cout << "Троечники: " << endl;
                    cout << Satis[0].getStudentData().Surname << " " << Satis[0].getStudentData().Name << " " << Satis[0].getStudentData().MiddleName << " " << Satis[0].getStudentData().StudentCardNumb << endl;
                }
                else {
                    for (int i = 0; i < Satis.getSize() - 1; i++) {
                        for (int j = 0; j < Satis.getSize() - i - 1; j++) {
                            if (Satis[j].getStudentData().StudentCardNumb[0] > Satis[j + 1].getStudentData().StudentCardNumb[0]) {
                                swap(Satis[j], Satis[j + 1]);
                            }
                            else if (Satis[j].getStudentData().StudentCardNumb[0] == Satis[j + 1].getStudentData().StudentCardNumb[0]) {
                                if (Satis[j].getStudentData().StudentCardNumb[1] > Satis[j + 1].getStudentData().StudentCardNumb[1]) {
                                    swap(Satis[j], Satis[j + 1]);
                                }
                                else if (Satis[j].getStudentData().StudentCardNumb[1] == Satis[j + 1].getStudentData().StudentCardNumb[1]) {
                                    if (Satis[j].getStudentData().StudentCardNumb[2] > Satis[j + 1].getStudentData().StudentCardNumb[2]) {
                                        swap(Satis[j], Satis[j + 1]);
                                    }
                                    else if (Satis[j].getStudentData().StudentCardNumb[2] == Satis[j + 1].getStudentData().StudentCardNumb[2]) {
                                        if (Satis[j].getStudentData().StudentCardNumb[3] > Satis[j + 1].getStudentData().StudentCardNumb[3]) {
                                            swap(Satis[j], Satis[j + 1]);
                                        }
                                        else if (Satis[j].getStudentData().StudentCardNumb[3] == Satis[j + 1].getStudentData().StudentCardNumb[3]) {
                                            if (Satis[j].getStudentData().StudentCardNumb[4] > Satis[j + 1].getStudentData().StudentCardNumb[4]) {
                                                swap(Satis[j], Satis[j + 1]);
                                            }
                                            else if (Satis[j].getStudentData().StudentCardNumb[4] == Satis[j + 1].getStudentData().StudentCardNumb[4]) {
                                                if (Satis[j].getStudentData().StudentCardNumb[5] > Satis[j + 1].getStudentData().StudentCardNumb[5]) {
                                                    swap(Satis[j], Satis[j + 1]);
                                                }
                                                else if (Satis[j].getStudentData().StudentCardNumb[5] == Satis[j + 1].getStudentData().StudentCardNumb[5]) {
                                                    if (Satis[j].getStudentData().StudentCardNumb[6] > Satis[j + 1].getStudentData().StudentCardNumb[6]) {
                                                        swap(Satis[j], Satis[j + 1]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    cout << "Троечники: " << endl;
                    for (int i = 0; i < Satis.getSize(); i++) {
                        cout << Satis[i].getStudentData().Surname << " " << Satis[i].getStudentData().Name << " " << Satis[i].getStudentData().MiddleName << " " << Satis[i].getStudentData().StudentCardNumb << endl;
                    }
                    cout << "-------------------------------------------" << endl;
                }
                int escape;
                while (true) {
                    cout << "Введите 1 для выхода в меню выполнения задания >" << endl;
                    cin >> escape;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (escape == 1) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                    }
                }
                system("cls");
                Task(Students);
            }
        }
    }
    void ViewingAndEditingMenu(clList Students) {
        cout << "---Меню просмотра и изменения информации о студентах---" << endl;
        cout << "1. Отобразить список студентов" << endl;
        cout << "2. Изменить информацию о студентах" << endl;
        cout << "3. Выйти в главное меню" << endl;
        cout << "-------------------------------------------------------" << endl;
        int choise;
        while (true) {
            cout << "Введите цифру, соответствующую выбору >";
            cin >> choise;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << endl;
            if (choise == 3 or choise == 1 or choise == 2) {
                break;
            }
            else {
                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
            }
        }
        if (choise == 3) {
            system("cls");
            StartMenu(Students);
        }
        else if (choise == 1) {
            system("cls");
            ViewMenu(Students);
        }
        else if (choise == 2) {
            system("cls");
            EditMenu(Students);
        }
    }
    void ViewMenu(clList Students) {
        cout << "--------------------Меню просмотра информации о студентах---------------------" << endl;
        cout << "Введите порядковый номер студента, чтобы посмотреть полную информацию о нем" << endl;
        cout << "(-1). Выход в меню выбора просмотра или изменения информации" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        if (Students.getSize() == 0) {
            cout << "Нет информации о студентах" << endl;
            int escape;
            while (true) {
                cout << "Введите (-1) для выхода в меню >";
                cin >> escape;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (escape == -1) {
                    break;
                }
                else {
                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                }
            }
            system("cls");
            ViewingAndEditingMenu(Students);
        }
        for (int i = 0; i < Students.getSize(); i++) {
            cout << i + 1 << ". ";
            Students.printShortInfo(i);
        }
        cout << "------------------------------------------------------------------------------" << endl;
        int choise;
        while (true) {
            cout << "Введите цифру, соответствующую выбору >";
            cin >> choise;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << endl;
            if (choise == (-1) or (choise > 0 and choise <= Students.getSize())) {
                break;
            }
            else {
                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
            }
        }
        if (choise == (-1)) {
            system("cls");
            ViewingAndEditingMenu(Students);
        }
        else if (choise > 0 and choise <= Students.getSize()) {
            while (true) {
                system("cls");
                cout << "------------Информация о студенте------------" << endl;
                Students.printFullInfo(choise);
                cout << "---------------------------------------------" << endl;
                cout << "1. Посмотреть информацию о результатах сессий" << endl;
                cout << "2. Выход в меню просмотра информации" << endl;
                cout << "---------------------------------------------" << endl;
                int viewChoise;
                while (true) {
                    cout << "Введите цифру, соответствующую выбору >";
                    cin >> viewChoise;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (viewChoise == 2 or viewChoise == 1) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                    }
                }
                if (viewChoise == 2) {
                    break;
                }
                else if (viewChoise == 1) {
                    system("cls");
                    cout << "---------Информация о сессии---------" << endl;
                    cout << "1. Выход в меню информации о студенте" << endl;
                    cout << "-------------------------------------" << endl;
                    Students.printSessionInfo(choise);
                    int sessChoise;
                    while (true) {
                        cout << "Введите цифру, соответствующую выбору >";
                        cin >> sessChoise;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (sessChoise == 1) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                        }
                    }
                }
            }
            system("cls");
            ViewMenu(Students);
        }
    }
    void EditMenu(clList Students) {
        cout << "------Меню изменения информации о студентах------" << endl;
        cout << "1. Изменить информацию о студенте" << endl;
        cout << "2. Удалить информацию о студенте" << endl;
        cout << "3. Выход в меню просмотра и изменения информации" << endl;
        cout << "-------------------------------------------------" << endl;
        int stChoise;
        while (true) {
            cout << "Введите цифру, соответствующую выбору >";
            cin >> stChoise;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << endl;
            if (stChoise == 1 or stChoise == 2 or stChoise == 3) {
                break;
            }
            else {
                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
            }
        }
        if (stChoise == 3) {
            system("cls");
            ViewingAndEditingMenu(Students);
        }
        else if (stChoise == 1) {
            while (true) {
                system("cls");
                cout << "----------------------Изменение информации о студентах----------------------" << endl;
                cout << "Введите порядковый номер студента, чтобы посмотреть полную информацию о нем" << endl;
                cout << "(-1). Выход в меню выбора изменения информации о студентах" << endl;
                cout << "----------------------------------------------------------------------------" << endl;
                if (Students.getSize() == 0) {
                    cout << "Нет информации о студентах" << endl;
                    int escape;
                    while (true) {
                        cout << "Введите 1 для выхода в меню >";
                        cin >> escape;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (escape == 1) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                        }
                    }
                    break;
                }
                for (int i = 0; i < Students.getSize(); i++) {
                    cout << i + 1 << ". ";
                    Students.printShortInfo(i);
                }
                cout << "----------------------------------------------------------------------------" << endl;
                int choise;
                while (true) {
                    cout << "Введите цифру, соответствующую выбору >";
                    cin >> choise;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (choise == (-1) or (choise > 0 and choise <= Students.getSize())) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                    }
                }
                if (choise == (-1)) {
                    break;
                }
                else if (choise > 0 and choise <= Students.getSize()) {
                    while (true) {
                        system("cls");
                        StudentNode NewStudent;
                        clStudent Student;
                        Date date;
                        cout << "------------Информация о студенте------------" << endl;
                        Students.printFullInfo(choise);
                        cout << "---------------------------------------------" << endl;
                        cout << "1. Изменить фамилию" << endl;
                        cout << "2. Изменить имя" << endl;
                        cout << "3. Изменить отчество" << endl;
                        cout << "4. Изменить институт" << endl;
                        cout << "5. Изменить кафедру" << endl;
                        cout << "6. Изменить группу" << endl;
                        cout << "7. Изменить пол" << endl;
                        cout << "8. Изменить год начала обучения" << endl;
                        cout << "9. Изменить номер зачетной книжки" << endl;
                        cout << "10. Изменить дату рождения" << endl;
                        cout << "11. Изменить успеваемость" << endl;
                        cout << "12. Выход в меню выбора студента" << endl;
                        cout << "---------------------------------------------" << endl;
                        int editChoise;
                        while (true) {
                            cout << "Введите цифру, соответствующую выбору >";
                            cin >> editChoise;
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << endl;
                            if (editChoise > 0 and editChoise < 13) {
                                break;
                            }
                            else {
                                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                            }
                        }
                        if (editChoise == 1) {
                            while (true) {
                                cout << "Введите фамилию >";
                                cin.getline(NewStudent.Surname, 30);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentSurname(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 2) {
                            while (true) {
                                cout << "Введите имя >";
                                cin.getline(NewStudent.Name, 30);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentName(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 3) {
                            while (true) {
                                cout << "Введите отчество >";
                                cin.getline(NewStudent.MiddleName, 30);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentMiddleName(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 4) {
                            while (true) {
                                cout << "Введите институт (аббревиатура) >";
                                cin.getline(NewStudent.Institute, 10);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentInstitute(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 5) {
                            while (true) {
                                cout << "Введите кафедру >";
                                cin.getline(NewStudent.Department, 20);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentDepartment(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 6) {
                            while (true) {
                                cout << "Введите группу >";
                                cin.getline(NewStudent.Group, 15);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentGroup(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 7) {
                            while (true) {
                                cout << "Введите пол (1 - мужской, 2 - женский) >";
                                int sex;
                                cin >> sex;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (sex == 1) {
                                    NewStudent.sex = Sex::Man;
                                    break;
                                }
                                else if (sex == 2) {
                                    NewStudent.sex = Sex::Woman;
                                    break;
                                }
                                else {
                                    cout << "Некоректный ввод пола, попробуйте еще раз" << endl;
                                }
                            }
                            Student.setStudentSex(&NewStudent);
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 8) {
                            while (true) {
                                cout << "Введите год начала обучения >";
                                cin >> NewStudent.StartYear;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentStartYear(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 9) {
                            while (true) {
                                cout << "Введите номер зачетной книжки >";
                                cin.getline(NewStudent.StudentCardNumb, 15);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentCardNumb(&NewStudent) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 10) {
                            while (true) {
                                cout << "Введите день рождения >";
                                cin >> date.day;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << "Введите месяц рождения >";
                                cin >> date.month;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << "Введите год рождения >";
                                cin >> date.year;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (Student.setStudentBirthDate(date) == 0) {
                                    break;
                                }
                            }
                            Students.edit(choise, editChoise, Student.getStudentData());
                            cout << "Данные успешно сохранены!" << endl;
                            Students.printFullInfo(choise);
                            cout << "---------------------------------------------" << endl;
                            int escape;
                            while (true) {
                                cout << "Введите 1 для выхода в меню >";
                                cin >> escape;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (escape == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                }
                            }
                        }
                        else if (editChoise == 11) {
                            while (true) {
                                system("cls");
                                cout << "--------------------Информация о сессии--------------------" << endl;
                                cout << "Введите номер семестра, чтобы перейти к его редактированию" << endl;
                                cout << "Введите (-1) для выхода в меню" << endl;
                                cout << "-----------------------------------------------------------" << endl;
                                Students.printSessionInfo(choise);
                                int sessCount = 0;
                                for (int i = 0; i < 9; i++) {
                                    if (Students[choise - 1].getStudentData().ExamsData[i]->isFilled == true) {
                                        sessCount++;
                                    }
                                }
                                if (sessCount == 0) {
                                    int escape;
                                    while (true) {
                                        cout << "Введите (-1) для выхода в меню >" << endl;
                                        cin >> escape;
                                        cin.clear();
                                        cin.ignore(32767, '\n');
                                        cout << endl;
                                        if (escape == (-1)) {
                                            break;
                                        }
                                        else {
                                            cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    int sessChoise;
                                    while (true) {
                                        cout << "Введите цифру, соответствующую выбору >";
                                        cin >> sessChoise;
                                        cin.clear();
                                        cin.ignore(32767, '\n');
                                        cout << endl;
                                        if (sessChoise == (-1) or (sessChoise > 0 and sessChoise <= sessCount)) {
                                            break;
                                        }
                                        else {
                                            cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                                        }
                                    }
                                    if (sessChoise == (-1)) {
                                        break;
                                    }
                                    else if (sessChoise > 0 and sessChoise <= sessCount) {
                                        while (true) {
                                            system("cls");
                                            cout << "-------------Информация о результатах сессии в семестре-------------" << endl;
                                            cout << "Введите номер предмета, чтобы перейти к его редактированию" << endl;
                                            cout << "Введите (-1) для выхода в меню" << endl;
                                            cout << "--------------------------------------------------------------------" << endl;
                                            cout << sessChoise << ". Семестр" << endl;
                                            for (int i = 0; i < 10; i++) {
                                                cout << i + 1 << ". " << Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].ExamName << " - ";
                                                if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Absence) {
                                                    cout << "Отсутствовал по уважительной причине" << endl;
                                                }
                                                else if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Fail) {
                                                    cout << "Незачет" << endl;
                                                }
                                                else if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Pass) {
                                                    cout << "Зачет" << endl;
                                                }
                                                else if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Bad) {
                                                    cout << "Оценка: 2" << endl;
                                                }
                                                else if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Satisfactory) {
                                                    cout << "Оценка: 3" << endl;
                                                }
                                                else if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Good) {
                                                    cout << "Оценка: 4" << endl;
                                                }
                                                else if (Students[choise - 1].getStudentData().ExamsData[sessChoise - 1][i].mark == Mark::Excellent) {
                                                    cout << "Оценка: 5" << endl;
                                                }
                                            }
                                            cout << "--------------------------------------------------------------------" << endl;
                                            int subjChoise;
                                            while (true) {
                                                cout << "Введите цифру, соответствующую выбору >";
                                                cin >> subjChoise;
                                                cin.clear();
                                                cin.ignore(32767, '\n');
                                                cout << endl;
                                                if (subjChoise == (-1) or (subjChoise > 0 and subjChoise <= 10)) {
                                                    break;
                                                }
                                                else {
                                                    cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                                                }
                                            }
                                            if (subjChoise == (-1)) {
                                                break;
                                            }
                                            else if (subjChoise > 0 and subjChoise <= 10) {
                                                system("cls");
                                                StudentNode NewStudent = Students[choise - 1].getStudentData();
                                                int examType;
                                                while (true) {
                                                    cout << "Выберите тип аттестации (1 - зачет, 2 - экзамен) >";
                                                    cin >> examType;
                                                    cin.clear();
                                                    cin.ignore(32767, '\n');
                                                    cout << endl;
                                                    if (examType == 2 or examType == 1) {
                                                        break;
                                                    }
                                                    else {
                                                        cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                                                    }
                                                }
                                                if (examType == 1) {
                                                    while (true) {
                                                        cout << "Введите предмет >";
                                                        cin.getline(NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName, 30);
                                                        cin.clear();
                                                        cin.ignore(32767, '\n');
                                                        cout << endl;
                                                        int flag = 0;
                                                        for (int c = 0; c < ((string)NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName).length(); c++) {
                                                            if (!((NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 65 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 90) or (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 97 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 122) or (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= (-64) and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= (-1)) or (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] == 32 or NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] == 44))) {
                                                                if (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 48 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 57) {
                                                                    cout << "В названии предмета не могут содержатся цифры (" << c + 1 << " знак)" << endl;
                                                                }
                                                                if (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 33 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 47) {
                                                                    cout << "В названии предмета не могут содержатся специальные символы кроме запятой (" << c + 1 << " знак)" << endl;
                                                                }
                                                                flag = 1;
                                                                break;
                                                            }
                                                        }
                                                        if (flag == 0) {
                                                            break;
                                                        }
                                                        else {
                                                            cout << "Некорректно введено название предмета, попробуйте еще раз" << endl;
                                                        }
                                                    }
                                                    int score;
                                                    while (true) {
                                                        cout << "Введите результат зачета (1 - зачет, 2 - незачет, 3 - неявка) >";
                                                        cin >> score;
                                                        cin.clear();
                                                        cin.ignore(32767, '\n');
                                                        cout << endl;
                                                        if (score == 3 or score == 1 or score == 2) {
                                                            break;
                                                        }
                                                        else {
                                                            cout << "Некорректно введен результат зачета, попробуйте еще раз" << endl;
                                                        }
                                                    }
                                                    if (score == 1) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Pass;
                                                    }
                                                    else if (score == 2) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Fail;
                                                    }
                                                    else if (score == 3) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Absence;
                                                    }
                                                }
                                                else if (examType == 2) {
                                                    while (true) {
                                                        cout << "Введите предмет >";
                                                        cin.getline(NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName, 30);
                                                        cin.clear();
                                                        cin.ignore(32767, '\n');
                                                        cout << endl;
                                                        int flag = 0;
                                                        for (int c = 0; c < ((string)NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName).length(); c++) {
                                                            if (!((NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 65 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 90) or (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 97 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 122) or (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= (-64) and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= (-1)) or (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] == 32 or NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] == 44))) {
                                                                if (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 48 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 57) {
                                                                    cout << "В названии предмета не могут содержатся цифры (" << c + 1 << " знак)" << endl;
                                                                }
                                                                if (NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] >= 33 and NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].ExamName[c] <= 47) {
                                                                    cout << "В названии предмета не могут содержатся специальные символы кроме запятой (" << c + 1 << " знак)" << endl;
                                                                }
                                                                flag = 1;
                                                                break;
                                                            }
                                                        }
                                                        if (flag == 0) {
                                                            break;
                                                        }
                                                        else {
                                                            cout << "Некорректно введено название предмета, попробуйте еще раз" << endl;
                                                        }
                                                    }
                                                    int score;
                                                    while (true) {
                                                        cout << "Введите результат экзамена (от 2 до 5) >";
                                                        cin >> score;
                                                        cin.clear();
                                                        cin.ignore(32767, '\n');
                                                        cout << endl;
                                                        if (score > 1 and score < 6) {
                                                            break;
                                                        }
                                                        else {
                                                            cout << "Некорректно введен результат экзамена, попробуйте еще раз" << endl;
                                                        }
                                                    }
                                                    if (score == 2) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Bad;
                                                    }
                                                    else if (score == 3) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Satisfactory;
                                                    }
                                                    else if (score == 4) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Good;
                                                    }
                                                    else if (score == 5) {
                                                        NewStudent.ExamsData[sessChoise - 1][subjChoise - 1].mark = Mark::Excellent;
                                                    }
                                                }
                                                Students[choise - 1].setStudentExamsData(&NewStudent);
                                                system("cls");
                                                cout << "Данные успешно сохранены!" << endl;
                                                cout << "-------------------------" << endl;
                                                Students.printSessionInfo(choise);
                                                int escape;
                                                while (true) {
                                                    cout << "Введите 1 для выхода в меню >";
                                                    cin >> escape;
                                                    cin.clear();
                                                    cin.ignore(32767, '\n');
                                                    cout << endl;
                                                    if (escape == 1) {
                                                        break;
                                                    }
                                                    else {
                                                        cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if (editChoise == 12) {
                            break;
                        }
                    }
                }
            }
            system("cls");
            EditMenu(Students);
        }
        else if (stChoise == 2) {
            while (true) {
                system("cls");
                cout << "--------------------Меню удаления информации о студентах---------------------" << endl;
                cout << "Введите порядковый номер студента, чтобы посмотреть полную информацию о нем" << endl;
                cout << "(-1). Выход в меню выбора изменения информации о студентах" << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                if (Students.getSize() == 0) {
                    cout << "Нет информации о студентах" << endl;
                    int escape;
                    while (true) {
                        cout << "Введите 1 для выхода в меню >";
                        cin >> escape;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (escape == 1) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                        }
                    }
                    break;
                }
                for (int i = 0; i < Students.getSize(); i++) {
                    cout << i + 1 << ". ";
                    Students.printShortInfo(i);
                }
                cout << "------------------------------------------------------------------------------" << endl;
                int choise;
                while (true) {
                    cout << "Введите цифру, соответствующую выбору >";
                    cin >> choise;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (choise == (-1) or (choise > 0 and choise <= Students.getSize())) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                    }
                }
                if (choise == (-1)) { 
                    break;
                }
                else if (choise > 0 and choise <= Students.getSize()) {
                    while (true) {
                        system("cls");
                        cout << "------------Информация о студенте------------" << endl;
                        Students.printFullInfo(choise);
                        cout << "---------------------------------------------" << endl;
                        cout << "1. Удалить студента" << endl;
                        cout << "2. Выход в меню просмотра информации" << endl;
                        cout << "---------------------------------------------" << endl;
                        int deleteChoise;
                        while (true) {
                            cout << "Введите цифру, соответствующую выбору >";
                            cin >> deleteChoise;
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << endl;
                            if (deleteChoise == 2 or deleteChoise == 1) {
                                break;
                            }
                            else {
                                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                            }
                        }
                        if (deleteChoise == 2) {
                            break;
                        }
                        if (deleteChoise == 1) {
                            cout << "Вы уверены, что хотите его удалить?" << endl;
                            cout << "1. Да" << endl;
                            cout << "2. Нет" << endl;
                            int finalChoise;
                            while (true) {
                                cout << "Введите цифру, соответствующую выбору >";
                                cin >> finalChoise;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (finalChoise == 2 or finalChoise == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                                }
                            }
                            if (finalChoise == 2) {

                            }
                            else if (finalChoise == 1) {
                                system("cls");
                                Students.pop(choise - 1);
                                cout << "Студент успешно удален!" << endl;
                                int escape;
                                while (true) {
                                    cout << "Введите 1 для выхода в меню >";
                                    cin >> escape;
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << endl;
                                    if (escape == 1) {
                                        break;
                                    }
                                    else {
                                        cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                system("cls");
                EditMenu(Students);
            }
        }
    }
    void AddMenu(clList Students) {
        cout << "----Меню добавления данных о новом студенте / о новой сессии----" << endl;
        cout << "1. Добавить нового студента" << endl;
        cout << "2. Добавить данные о новой сессии" << endl;
        cout << "3. Выход в главное меню" << endl;
        cout << "----------------------------------------------------------------" << endl;
        int choise;
        while (true) {
            cout << "Введите цифру, соответствующую выбору >";
            cin >> choise;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << endl;
            if (choise == 1 or choise == 2 or choise == 3) {
                break;
            }
            else {
                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
            }
        }
        if (choise == 3) {
            system("cls");
            StartMenu(Students);
        }
        if (choise == 1) {
            system("cls");
            Date date;
            clStudent Student;
            StudentNode NewStudent;
            cout << "----------Добавление нового студента----------" << endl;
            while (true) {
                cout << "Введите фамилию >";
                cin.getline(NewStudent.Surname, 30);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentSurname(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите имя >";
                cin.getline(NewStudent.Name, 30);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentName(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите отчество >";
                cin.getline(NewStudent.MiddleName, 30);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentMiddleName(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите институт (аббревиатура) >";
                cin.getline(NewStudent.Institute, 10);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentInstitute(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите кафедру >";
                cin.getline(NewStudent.Department, 20);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentDepartment(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите группу >";
                cin.getline(NewStudent.Group, 15);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentGroup(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите номер зачетной книжки >";
                cin.getline(NewStudent.StudentCardNumb, 15);
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentCardNumb(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите день рождения >";
                cin >> date.day;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Введите месяц рождения >";
                cin >> date.month;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Введите год рождения >";
                cin >> date.year;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentBirthDate(date) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите пол (1 - мужской, 2 - женский) >";
                int sex;
                cin >> sex;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (sex == 1) {
                    NewStudent.sex = Sex::Man;
                    break;
                }
                else if (sex == 2) {
                    NewStudent.sex = Sex::Woman;
                    break;
                }
                else {
                    cout << "Некоректный ввод пола, попробуйте еще раз" << endl;
                }
            }
            Student.setStudentSex(&NewStudent);
            cout << "----------------------------------------------" << endl;
            while (true) {
                cout << "Введите год начала обучения >";
                cin >> NewStudent.StartYear;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (Student.setStudentStartYear(&NewStudent) == 0) {
                    break;
                }
            }
            cout << "----------------------------------------------" << endl;
            cout << "Добавить данные по сессии?" << endl;
            cout << "1. Да" << endl;
            cout << "2. Нет" << endl;
            int sessChoise;
            while (true) {
                cout << "Введите цифру, соответствующую выбору >";
                cin >> sessChoise;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (sessChoise == 1 or sessChoise == 2) {
                    break;
                }
                else {
                    cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                }
            }
            if (sessChoise == 1) {
                system("cls");
                int termCount;
                while (true) {
                    cout << "Сколько семестров желаете добавить? (от 1 до 9) >";
                    cin >> termCount;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (termCount > 0 and termCount < 10) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                    }
                }
                cout << "-------------------------" << endl;
                for (int i = 0; i < termCount; i++) {
                    NewStudent.ExamsData[i]->isFilled = true;
                    cout << i + 1 << " Семестр" << endl;
                    for (int j = 0; j < 10; j++) {
                        int examType;
                        NewStudent.ExamsData[i][j].isFilled = true;
                        while (true) {
                            cout << "Выберите тип аттестации (1 - зачет, 2 - экзамен) >";
                            cin >> examType;
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << endl;
                            if (examType == 2 or examType == 1) {
                                break;
                            }
                            else {
                                cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                            }
                        }
                        if (examType == 1) {
                            while (true) {
                                cout << "Введите предмет >";
                                cin.getline(NewStudent.ExamsData[i][j].ExamName, 30);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                int flag = 0;
                                for (int c = 0; c < ((string)NewStudent.ExamsData[i][j].ExamName).length(); c++) {
                                    if (!((NewStudent.ExamsData[i][j].ExamName[c] >= 65 and NewStudent.ExamsData[i][j].ExamName[c] <= 90) or (NewStudent.ExamsData[i][j].ExamName[c] >= 97 and NewStudent.ExamsData[i][j].ExamName[c] <= 122) or (NewStudent.ExamsData[i][j].ExamName[c] >= (-64) and NewStudent.ExamsData[i][j].ExamName[c] <= (-1)) or (NewStudent.ExamsData[i][j].ExamName[c] == 32 or NewStudent.ExamsData[i][j].ExamName[c] == 44))) {
                                        if (NewStudent.ExamsData[i][j].ExamName[c] >= 48 and NewStudent.ExamsData[i][j].ExamName[c] <= 57) {
                                            cout << "В названии предмета не могут содержатся цифры (" << c + 1 << " знак)" << endl;
                                        }
                                        if (NewStudent.ExamsData[i][j].ExamName[c] >= 33 and NewStudent.ExamsData[i][j].ExamName[c] <= 47) {
                                            cout << "В названии предмета не могут содержатся специальные символы кроме запятой (" << c + 1 << " знак)" << endl;
                                        }
                                        flag = 1;
                                        break;
                                    }
                                }
                                if (flag == 0) {
                                    break;
                                }
                                else {
                                    cout << "Некорректно введено название предмета, попробуйте еще раз" << endl;
                                }
                            }
                            int score;
                            while (true) {
                                cout << "Введите результат зачета (1 - зачет, 2 - незачет, 3 - неявка) >";
                                cin >> score;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (score == 3 or score == 1 or score == 2) {
                                    break;
                                }
                                else {
                                    cout << "Некорректно введен результат зачета, попробуйте еще раз" << endl;
                                }
                            }
                            if (score == 1) {
                                NewStudent.ExamsData[i][j].mark = Mark::Pass;
                            }
                            else if (score == 2) {
                                NewStudent.ExamsData[i][j].mark = Mark::Fail;
                            }
                            else if (score == 3) {
                                NewStudent.ExamsData[i][j].mark = Mark::Absence;
                            }
                        }
                        else if (examType == 2) {
                            while (true) {
                                cout << "Введите предмет >";
                                cin.getline(NewStudent.ExamsData[i][j].ExamName, 30);
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                int flag = 0;
                                for (int c = 0; c < ((string)NewStudent.ExamsData[i][j].ExamName).length(); c++) {
                                    if (!((NewStudent.ExamsData[i][j].ExamName[c] >= 65 and NewStudent.ExamsData[i][j].ExamName[c] <= 90) or (NewStudent.ExamsData[i][j].ExamName[c] >= 97 and NewStudent.ExamsData[i][j].ExamName[c] <= 122) or (NewStudent.ExamsData[i][j].ExamName[c] >= (-64) and NewStudent.ExamsData[i][j].ExamName[c] <= (-1)) or (NewStudent.ExamsData[i][j].ExamName[c] == 32 or NewStudent.ExamsData[i][j].ExamName[c] == 44))) {
                                        if (NewStudent.ExamsData[i][j].ExamName[c] >= 48 and NewStudent.ExamsData[i][j].ExamName[c] <= 57) {
                                            cout << "В названии предмета не могут содержатся цифры (" << c + 1 << " знак)" << endl;
                                        }
                                        if (NewStudent.ExamsData[i][j].ExamName[c] >= 33 and NewStudent.ExamsData[i][j].ExamName[c] <= 47) {
                                            cout << "В названии предмета не могут содержатся специальные символы кроме запятой (" << c + 1 << " знак)" << endl;
                                        }
                                        flag = 1;
                                        break;
                                    }
                                }
                                if (flag == 0) {
                                    break;
                                }
                                else {
                                    cout << "Некорректно введено название предмета, попробуйте еще раз" << endl;
                                }
                            }
                            int score;
                            while (true) {
                                cout << "Введите результат экзамена (от 2 до 5) >";
                                cin >> score;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (score >1 and score < 6) {
                                    break;
                                }
                                else {
                                    cout << "Некорректно введен результат экзамена, попробуйте еще раз" << endl;
                                }
                            }
                            if (score == 2) {
                                NewStudent.ExamsData[i][j].mark = Mark::Bad;
                            }
                            else if (score == 3) {
                                NewStudent.ExamsData[i][j].mark = Mark::Satisfactory;
                            }
                            else if (score == 4) {
                                NewStudent.ExamsData[i][j].mark = Mark::Good;
                            }
                            else if (score == 5) {
                                NewStudent.ExamsData[i][j].mark = Mark::Excellent;
                            }
                        };
                    }
                    cout << "-------------------------" << endl;
                }
                Student.setStudentExamsData(&NewStudent);
                system("cls");
                Students.push_back(Student);
                cout << "Данные успешно добавлены!" << endl;
                cout << "Новый студент: " << endl;
                Students.printFullInfo(Students.getSize());
                cout << "-------------------------" << endl;
                Students.printSessionInfo(Students.getSize());
                int escape;
                while (true) {
                    cout << "Введите 1 для выхода в меню >" << endl;
                    cin >> escape;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (escape == 1) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                    }
                }
            }
            if (sessChoise == 2) {
                system("cls");
                Students.push_back(Student);
                cout << "Данные успешно добавлены!" << endl;
                cout << "Новый студент: " << endl;
                Students.printFullInfo(Students.getSize());
                int escape;
                while (true) {
                    cout << "Введите 1 для выхода в меню >" << endl;
                    cin >> escape;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << endl;
                    if (escape == 1) {
                        break;
                    }
                    else {
                        cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                    }
                }
            }
            system("cls");
            AddMenu(Students);
        }
        else if (choise == 2) {
            system("cls");
            cout << "-----------------------Добавление данных о новой сессии-----------------------" << endl;
            cout << "Введите порядковый номер студента, чтобы ввести для него данные о новой сессии" << endl;
            cout << "(-1). Выход в меню выбора добавления данных" << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            if (Students.getSize() == 0) {
                cout << "Нет информации о студентах" << endl;
            }
            for (int i = 0; i < Students.getSize(); i++) {
                cout << i + 1 << ". ";
                Students.printShortInfo(i);
            }
            cout << "------------------------------------------------------------------------------" << endl;
            int addChoise;
            while (true) {
                cout << "Введите цифру, соответствующую выбору >";
                cin >> addChoise;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << endl;
                if (addChoise == (-1) or (addChoise > 0 and addChoise <= Students.getSize())) {
                    break;
                }
                else {
                    cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                }
            }
            if (addChoise == (-1)) {
                system("cls");
                AddMenu(Students);
            }
            else if (addChoise > 0 and addChoise <= Students.getSize()) {
                system("cls");
                cout << "Информация по семестрам: " << endl;
                cout << "-------------------------" << endl;
                Students.printSessionInfo(addChoise);
                int termCount;
                StudentNode Student = Students[addChoise - 1].getStudentData();
                int termCountSt = 0;
                for (int i = 0; i < 9; i++) {
                    if (Student.ExamsData[i]->isFilled == true) {
                        termCountSt++;
                    }
                }
                if (termCountSt == 9) {
                    cout << "Данные о сессиях полностью заполнены!" << endl;
                    int escape;
                    while (true) {
                        cout << "Введите 1 для выхода в меню >";
                        cin >> escape;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (escape == 1) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                        }
                    }
                    system("cls");
                    AddMenu(Students);
                }
                else {
                    while (true) {
                        cout << "Введите количество семестров для добавления информации (от 1 до " << 9 - termCountSt << ") >";
                        cin >> termCount;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (termCount > 0 and termCount < 10 - termCountSt) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                        }
                    }
                    cout << "-------------------------" << endl;
                    for (int i = termCountSt; i < termCountSt + termCount; i++) {
                        Student.ExamsData[i]->isFilled = true;
                        cout << i + 1 << " Семестр" << endl;
                        for (int j = 0; j < 10; j++) {
                            int examType;
                            Student.ExamsData[i][j].isFilled = true;
                            while (true) {
                                cout << "Выберите тип аттестации (1 - зачет, 2 - экзамен) >";
                                cin >> examType;
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << endl;
                                if (examType == 2 or examType == 1) {
                                    break;
                                }
                                else {
                                    cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
                                }
                            }
                            if (examType == 1) {
                                while (true) {
                                    cout << "Введите предмет >";
                                    cin.getline(Student.ExamsData[i][j].ExamName, 30);
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << endl;
                                    int flag = 0;
                                    for (int c = 0; c < ((string)Student.ExamsData[i][j].ExamName).length(); c++) {
                                        if (!((Student.ExamsData[i][j].ExamName[c] >= 65 and Student.ExamsData[i][j].ExamName[c] <= 90) or (Student.ExamsData[i][j].ExamName[c] >= 97 and Student.ExamsData[i][j].ExamName[c] <= 122) or (Student.ExamsData[i][j].ExamName[c] >= (-64) and Student.ExamsData[i][j].ExamName[c] <= (-1)) or (Student.ExamsData[i][j].ExamName[c] == 32 or Student.ExamsData[i][j].ExamName[c] == 44))) {
                                            if (Student.ExamsData[i][j].ExamName[c] >= 48 and Student.ExamsData[i][j].ExamName[c] <= 57) {
                                                cout << "В названии предмета не могут содержатся цифры (" << i + 1 << " знак)" << endl;
                                            }
                                            if (Student.ExamsData[i][j].ExamName[c] >= 33 and Student.ExamsData[i][j].ExamName[c] <= 47) {
                                                cout << "В названии предмета не могут содержатся специальные символы кроме запятой (" << i + 1 << " знак)" << endl;
                                            }
                                            flag = 1;
                                            break;
                                        }
                                    }
                                    if (flag == 0) {
                                        break;
                                    }
                                    else {
                                        cout << "Некорректно введено название предмета, попробуйте еще раз" << endl;
                                    }
                                }
                                int score;
                                while (true) {
                                    cout << "Введите результат зачета (1 - зачет, 2 - незачет, 3 - неявка) >";
                                    cin >> score;
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << endl;
                                    if (score == 3 or score == 1 or score == 2) {
                                        break;
                                    }
                                    else {
                                        cout << "Некорректно введен результат зачета, попробуйте еще раз" << endl;
                                    }
                                }
                                if (score == 1) {
                                    Student.ExamsData[i][j].mark = Mark::Pass;
                                }
                                else if (score == 2) {
                                    Student.ExamsData[i][j].mark = Mark::Fail;
                                }
                                else if (score == 3) {
                                    Student.ExamsData[i][j].mark = Mark::Absence;
                                }
                            }
                            else if (examType == 2) {
                                while (true) {
                                    cout << "Введите предмет >";
                                    cin.getline(Student.ExamsData[i][j].ExamName, 30);
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << endl;
                                    int flag = 0;
                                    for (int c = 0; c < ((string)Student.ExamsData[i][j].ExamName).length(); c++) {
                                        if (!((Student.ExamsData[i][j].ExamName[c] >= 65 and Student.ExamsData[i][j].ExamName[c] <= 90) or (Student.ExamsData[i][j].ExamName[c] >= 97 and Student.ExamsData[i][j].ExamName[c] <= 122) or (Student.ExamsData[i][j].ExamName[c] >= (-64) and Student.ExamsData[i][j].ExamName[c] <= (-1)) or (Student.ExamsData[i][j].ExamName[c] == 32 or Student.ExamsData[i][j].ExamName[c] == 44))) {
                                            if (Student.ExamsData[i][j].ExamName[c] >= 48 and Student.ExamsData[i][j].ExamName[c] <= 57) {
                                                cout << "В названии предмета не могут содержатся цифры (" << i + 1 << " знак)" << endl;
                                            }
                                            if (Student.ExamsData[i][j].ExamName[c] >= 33 and Student.ExamsData[i][j].ExamName[c] <= 47) {
                                                cout << "В названии предмета не могут содержатся специальные символы кроме запятой (" << i + 1 << " знак)" << endl;
                                            }
                                            flag = 1;
                                            break;
                                        }
                                    }
                                    if (flag == 0) {
                                        break;
                                    }
                                    else {
                                        cout << "Некорректно введено название предмета, попробуйте еще раз" << endl;
                                    }
                                }
                                int score;
                                while (true) {
                                    cout << "Введите результат экзамена (от 2 до 5) >";
                                    cin >> score;
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << endl;
                                    if (score > 1 and score < 6) {
                                        break;
                                    }
                                    else {
                                        cout << "Некорректно введен результат экзамена, попробуйте еще раз" << endl;
                                    }
                                }
                                if (score == 2) {
                                    Student.ExamsData[i][j].mark = Mark::Bad;
                                }
                                else if (score == 3) {
                                    Student.ExamsData[i][j].mark = Mark::Satisfactory;
                                }
                                else if (score == 4) {
                                    Student.ExamsData[i][j].mark = Mark::Good;
                                }
                                else if (score == 5) {
                                    Student.ExamsData[i][j].mark = Mark::Excellent;
                                }
                            }
                        }
                        cout << "-------------------------" << endl;
                    }
                    Students[addChoise - 1].setStudentExamsData(&Student);
                    system("cls");
                    cout << "Данные успешно добавлены!" << endl;
                    cout << "Cтудент: " << endl;
                    Students.printFullInfo(addChoise);
                    cout << "-------------------------" << endl;
                    Students.printSessionInfo(addChoise);
                    int escape;
                    while (true) {
                        cout << "Введите 1 для выхода в меню >";
                        cin >> escape;
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << endl;
                        if (escape == 1) {
                            break;
                        }
                        else {
                            cout << "Неверный ввод цифры выхода, попробуйте еще раз" << endl;
                        }
                    }
                    system("cls");
                    AddMenu(Students);
                }
            }
            system("cls");
            AddMenu(Students);
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    clList Database;
    clMenu Menu;
    string password;
    cout << "1. Ввести пароль от существующей базы данных" << endl;
    cout << "2. Создать новую базу данных" << endl;
    cout << "3. Закрыть программу" << endl;
    int choise;
    while (true) {
        cout << "Введите цифру, соответствующую выбору >";
        cin >> choise;
        cin.clear();
        cin.ignore(32767, '\n');
        cout << endl;
        if (choise == 3 or choise == 2 or choise == 1) {
            break;
        }
        else {
            cout << "Неверный ввод цифры выбора, попробуйте еще раз" << endl;
        }
    }
    if (choise == 3) {
        return 0;
    }
    else if (choise == 2) {
        clList NewList;
        system("cls");
        Menu.StartMenu(NewList);
    }
    else if (choise == 1) {
        cout << "Введите пароль для дешифрования >";
        cin >> password;
        Database.Decrypt(password);
        system("cls");
        Menu.StartMenu(Database.getStudentsFromFile());
    }
}