#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    public:
    // constructor
    Task(std::string title, bool done, std::string description);

    // getters
    std::string getTitle();
    bool getDone();
    std::string getDescription();

    // setters
    void setTitle(std::string title);
    void setDone(bool done);
    void setDescription(std::string description);

    // methods
    void markDone();

    private:
    std::string title;
    bool done;
    std::string description;
};

// constructor
Task::Task(std::string title, bool done, std::string description) {
    this->title = title;
    this->done = done;
    this->description = description;
}

// getters
std::string Task::getTitle() {
    return this->title;
}
bool Task::getDone() {
    return this->done;
}
std::string Task::getDescription() {
    return this->description;
}

// setters
void Task::setTitle(std::string title) {
    this->title = title;
}
void Task::setDone(bool done) {
    this->done = done;
}
void Task::setDescription(std::string description) {
    this->description = description;
}

// methods
void Task::markDone() {
    this->done = true;
}


#endif // TASK_H