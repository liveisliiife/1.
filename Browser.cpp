#include "Browser.h"

Browser::Browser() {
    windows.append(Window());
}

void Browser::newWindow() {
    windows.prepend(Window());
}

void Browser::closeWindow() {
    if (!windows.isEmpty()) windows.removeNodeAtIndex(0);
}

void Browser::switchToWindow(int index) {
    if (index == 0) return;
    windows.moveToIndex(index, 0);
}

Window &Browser::getWindow(int index) {
    return windows.getNodeAtIndex(index) -> data;
}

void Browser::moveTab(Window &from, Window &to) {
    to.newTab(from.getActiveTab()); from.closeTab();
}

void Browser::mergeWindows(Window &window1, Window &window2) {
    window2.changeActiveTabTo(0);
    while(!window2.isEmpty())
        moveTab(window2, window1);
}

void Browser::mergeAllWindows() {
    int i = 0;
    while (i < windows.getSize()-1){
        mergeWindows(getWindow(0), getWindow(i+1));
        i++;
    }
}

void Browser::closeAllWindows() {
    windows.removeAllNodes();
}

void Browser::closeEmptyWindows() {
    int i = 0; int n = windows.getSize();
    while (i < n){
        if (getWindow(i).isEmpty()) {windows.removeNodeAtIndex(i); n--;}
        else i++;
    }
}

void Browser::print() {
    Node<Window> *head = windows.getFirstNode();
    if(head == NULL) {
        std::cout << "The browser is empty" << std::endl;
    } else {
        (head -> data).print();
        head = head -> next;
        while(head != windows.getFirstNode()) {
            (head -> data).print();
            head = head -> next;
        }
    }
}
