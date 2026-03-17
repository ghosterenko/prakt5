#include <iostream>

class DoublyLinkedList {

    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void push_front(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void push_back(int value)
    {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void pop_front()
    {
        Node* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    void pop_back() {
        Node* temp = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    void display() {
        if (head == nullptr) {
            std::cout << "Список пуст" << std::endl;
        }
        else {
            Node* node = head;
            while (node != nullptr) {
                std::cout << node->data << " ";
                node = node->next;
            }
            std::cout << std::endl;
        }
    }
    void sort()
    {
        bool s = true;
        Node* nodeG = nullptr;
        Node* cur = nullptr;
        while (s) {
            s = false;
            cur = head;
            while (cur->next != nodeG) {
                if (cur->data > cur->next->data) {
                    int temp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = temp;
                    s = true;
                }
                cur = cur->next;
            }
            nodeG = cur;
        }
    }
    void remove_duplicates()
    {
        Node* cur = head;

        while (cur != nullptr) {
            Node* find = cur->next;

            while (find != nullptr) {
                if (find->data == cur->data) {
                    Node* dup = find;
                    find = find->next;

                    dup->prev->next = dup->next;
                    if (dup->next != nullptr)
                        dup->next->prev = dup->prev;

                    delete dup;
                }
                else {
                    find = find->next;
                }
            }
            cur = cur->next;
        }
    }
};

void menu() {
    std::cout << "1. Добавить элемент в начало" << std::endl;
    std::cout << "2. Добавить элемент в конец" << std::endl;
    std::cout << "3. Удалить элемент с начала" << std::endl;
    std::cout << "4. Удалить элемент с конца" << std::endl;
    std::cout << "5. Отобразить список" << std::endl;
    std::cout << "6. Сортировать список" << std::endl;
    std::cout << "7. Удалить дубликаты" << std::endl;
    std::cout << "8. Выйти" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    DoublyLinkedList list;
    char u;
    while (true) {
        menu();
        std::cin >> u;

        switch (u) {

        case '1':
        {
            system("cls");
            std::cout << "Введите число: ";
            int value;
            std::cin >> value;
            list.push_front(value);
            std::cin.get();
            break;
        }
        case '2':
        {
            system("cls");
            std::cout << "Введите число: ";
            int value;
            std::cin >> value;
            list.push_back(value);
            std::cin.get();
            break;
        }
        case '3':
        {
            system("cls");
            std::cout << "Удалено с начала" << std::endl;
            list.pop_front();
            std::cin.get();
            break;
        }
        case '4':
        {
            system("cls");
            std::cout << "Удалено с начала" << std::endl;
            list.pop_back();
            std::cin.get();
            break;
        }
        case '5':
        {
            system("cls");
            std::cout << "Список: " << std::endl;
            list.display();
            std::cin.get();
            break;
        }
        case '6':
        {
            system("cls");
            std::cout << "Отсортировано " << std::endl;
            list.sort();
            std::cin.get();
            break;
        }
        case '7':
        {
            system("cls");
            std::cout << "Дубликаты удалены" << std::endl;
            list.remove_duplicates();
            std::cin.get();
            break;
        }
        case '8':
        {
            std::cout << "Завершено" << std::endl;
            return 0;
        }
        default:
            std::cout << "Ошибка" << std::endl;
            break;
        }
    }
}
