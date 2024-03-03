/*
 * 
 */
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
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
    
    tlsFirstSort(List);
    printList(List);
    std::cout << "-------" << '\n';

}
