#ifndef TODO_H
#define TODO_H
#include "LinkedList.h"
#include "Task.h"


class todo {
    public:
        todo();
        void addTask(Task task);
        void markDone(std::string title);
        void listIncomplete();
        void listCompleted();
    private:
        LinkedList<Task> completed;
        LinkedList<Task> incomplete;
};

todo::todo() {}

void todo::addTask(Task task) {
    incomplete.addLast(task);
}

void todo::markDone(std::string title) {
    for (int i = 0; i < incomplete.getSize(); i++) {
        if (incomplete.get(i).getTitle() == title) {
            incomplete.del(i);
            completed.addLast(incomplete.get(i));
            break;
        }
    }
}

void todo::listIncomplete() {
    incomplete.print();
}

void todo::listCompleted() {
    completed.print();
}

#endif // TODO_H