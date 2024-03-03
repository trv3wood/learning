/*
 * 
 */
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
struct StudentNode {
    std::string major;
    std::string _class;
    int ID;
    int tlscore;
    int objscore;
    int sbjscore;
    StudentNode* next;
    StudentNode* prv;

    StudentNode(): major("null"), _class("null"), ID(0), tlscore(0), objscore(0), sbjscore(0), next(nullptr),prv(nullptr) {}
    StudentNode(std::string m, std::string cl, int id, int tls, int obj, int sbj):
    major(m), _class(cl), ID(id), tlscore(tls), objscore(obj), sbjscore(sbj), next(nullptr), prv(nullptr) {}
};

void tlsFirstSort(std::list<StudentNode>& List) {
    List.sort([&](StudentNode prv, StudentNode next) -> bool {
        return prv.tlscore > next.tlscore;
    });
}

void objFirstSort(std::list<StudentNode>& List) {
    List.sort([&](StudentNode prv, StudentNode next) -> bool {
        return prv.objscore > next.objscore;
    });
}

void sbjFirstSort(std::list<StudentNode>& List) {
    List.sort([&](StudentNode prv, StudentNode next) -> bool {
        return prv.sbjscore > next.sbjscore;
    });
}

void printList(const std::list<StudentNode>& List) {
    for (auto curr = List.begin(); curr != List.end(); curr++) {
        printf("%-15s	", curr->major.c_str());
		printf("%10s	", curr->major.c_str());
		printf("%10d	", curr->ID);
		printf("%-8d", curr->tlscore);
		printf("%-8d", curr->objscore);
		printf("%-8d\n", curr->sbjscore);
    }
}

int main() {
    std::ifstream file;
    file.open(".\\Mid-term_exam_score.txt");
    if(!file.is_open() || !file) {
        std::cerr << "cannot open the file";
    }
    char line[33];
    std::list<StudentNode> List;
    while (file.getline(line, 45)) {
        std::stringstream words(line);
        std::string major, cla;
        int id, tls, obj, sbj;
        words >> major >> cla >> id >> tls >> obj >> sbj;
        StudentNode* someone = new StudentNode(major, cla, id, tls, obj, sbj);
        List.push_back(*someone);
    }
    std::cout << "origin list: " << '\n';
    printList(List);
    std::cout << "-------" << '\n';
    printf("Which type of data do you want to sort based on?\n"
        "Please use the serial number to select from the three types below:\n"
        " 1.tlscore; 2.objscore; 3.sbjscore.\n ");
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            tlsFirstSort(List);
            break;
        case 2:
            objFirstSort(List);
            break;
        case 3:
            sbjFirstSort(List);
            break;
        default:
            throw std::invalid_argument("What you entered does not conform to the specification,!Please try again!\n");
    }
    std::cout << "sorted list: " << '\n';
    printList(List);
    return 0;
}
