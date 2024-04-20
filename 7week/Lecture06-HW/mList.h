#ifndef MLIST_H
#define MLIST_H

template <typename T>
class mNode {
public:
    T data;
    mNode<T>* next;

    mNode();
    ~mNode();
};

template <typename T>
class mList {
public:
    mNode<T>* head;
    mNode<T>* tail;

    mList();
    ~mList();

    void push_back(T value);
    int get_Size();
    T& operator[](int index); // �迭 ������ �߰�

private:
    int size;
};

template <typename T>
mNode<T>::mNode() : next(nullptr) {}

template <typename T>
mNode<T>::~mNode() {}

template <typename T>
mList<T>::mList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
mList<T>::~mList() {
    while (head != nullptr) {
        mNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void mList<T>::push_back(T value) {
    mNode<T>* newNode = new mNode<T>();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template <typename T>
int mList<T>::get_Size() {
    return size;
}

template <typename T>
T& mList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        // �ε����� ��ȿ���� ���� ���
        // ���⿡���� ���ܸ� ������ ��� �⺻���� ��ȯ�մϴ�.
        // ���⿡���� �⺻������ �ʱ�ȭ�� T Ÿ���� ��ü�� ��ȯ�մϴ�.
        static T defaultObject;
        return defaultObject;
    }

    mNode<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

#endif // MLIST_H
