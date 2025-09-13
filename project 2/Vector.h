#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;
template<typename Ty>


class Vector {
    Ty* arr;
    int Size;
    int Capacity;
    void expand() {
        Capacity *= 2;
        Ty* temp = new Ty[Capacity]{};
        for (int i = 0; i < Size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
public:
    Vector() :Size(0), Capacity(0), arr(nullptr) {}
    Vector(int size) :Size(size), Capacity(size) {
        arr = new Ty[Capacity]{};
    }
    Vector(const Vector& obj) {
        Capacity = obj.Capacity;
        Size = obj.Size;
        if (obj.arr == nullptr) {
            arr = nullptr;
            return;
        }
        arr = new Ty[Capacity]{};
        for (int i = 0; i < Capacity; i++) {
            arr[i] = obj.arr[i];
        }
    }
    void operator=(const Vector& obj) {
        Capacity = obj.Capacity;
        Size = obj.Size;
        if (obj.arr == nullptr) {
            arr = nullptr;
            return;
        }
        delete[] arr;
        arr = new Ty[Capacity]{};
        for (int i = 0; i < Capacity; i++) {
            arr[i] = obj.arr[i];
        }
    }
    bool full() {
        return Size == Capacity;
    }
    bool empty() {
        return Size == 0;
    }
    int size() {
        return Size;
    }
    int capacity() {
        return Capacity;
    }
    void push_back(Ty value) {
        if (arr == nullptr) {
            Capacity = 1;
            arr = new Ty[Capacity]{};
        }
        if (full()) {
            expand();
        }
        arr[Size] = value;
        Size++;
    }
    Ty& operator[](int index) {
        return arr[index];
    }
    void pop_back() {
        if (empty()) {
            return;
        }
        Size--;
        if (Size < Capacity / 4) {
            shrink_to_fit();
        }
    }
    void shrink_to_fit() {
        Capacity = Size;
        Ty* temp = new Ty[Capacity]{};
        for (int i = 0; i < Size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    void push_front(Ty value) {
        if (empty()) {
            push_back(value);
            return;
        }
        if (full()) {
            expand();
        }
        for (int i = Size; i >= 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        Size++;
    }
    void pop_front() {
        if (empty()) {
            return;
        }
        if (Size == 1) {
            pop_back();
            return;
        }
        for (int i = 0; i <= Size - 2; i++) {
            arr[i] = arr[i + 1];
        }
        pop_back();
    }
    void push_at(int index, Ty value) {
        if (empty() || index < 0 || index >= Size) {
            return;
        }
        if (full()) {
            expand();
        }
        if (index == 0) {
            push_front(value);
            return;
        }
        for (int i = Size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        Size++;
    }
    void pop_at(int index) {
        if (empty() || index < 0 || index >= Size) {
            return;
        }
        if (index == 0) {
            pop_front();
            return;
        }
        if (index == Size - 1) {
            pop_back();
            return;
        }
        for (int i = index; i <= Size - 2; i++) {
            arr[i] = arr[i + 1];
        }
        pop_back();
    }
    void reverse() {
        if (Size <= 1) {
            return;
        }
        int left = 0;
        int right = Size - 1;
        while (left < right) {
            Ty temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    void print() {
        for (int i = 0; i < Size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    
    ~Vector() {
        delete[] arr;
    }
};

