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


#endif // TASK_H