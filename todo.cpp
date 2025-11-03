#include <iostream>
using namespace std;

#include "todo.h"
#include "Task.h"
#include "LinkedList.h"

int main() {
    todo todo1;
    Task task1("Buy groceries", "Purchase milk, eggs, and bread from the supermarket", false);
    todo1.addTask(task1);
    todo1.markDone("Buy groceries");



}