#pragma once
#include "dependies.h"
template<typename T>
struct Element_array
{
    T data;
    int index;
    Element_array* next;
    Element_array* prev;
    Element_array(T data, int index);
};
template<typename T>
Element_array<T>::Element_array(T data, int index) {
    this->data = data;
    this->index = index;
    this->next = nullptr;
    this->prev = nullptr;

}
template<typename T>
class Array {
    Element_array<T>* element;
    int lenght;
    int grow;
public:
    Array();
    Array(int lenght);
    int Getsize();
    void Set_Size(int size, int grow);
    int Get_Apper_bound();
    bool is_Empty();
    void free_Extra();
    void Remove_all();
    void Add(T data);
    T GetAt(int index);
    void SetAt(T data, int index);
    T& operator[](int index);
    void Append(Array<T>& a);
    Array& operator=(Array<T>& a);
    void Insert_at(T data, int position);
    void Remove_at(int position);
    Element_array<T>* GetData();
};
template<typename T>
Array<T>::Array() {
    this->lenght = 8;
    this->grow = 1;
    Element_array<T>* temp = this->element;
    int index = 0;
    while (index != this->lenght)
    {
        if (temp == nullptr) {
            temp = new Element_array<T>(0, index);
            this->element = temp;
        }
        else
        {
            Element_array<T>* temp = this->element;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Element_array<T>(0, index);
            temp->next->prev = temp;
        }
        index++;
    }
}
template<typename T>
Array<T>::Array(int lenght) {
    this->lenght = lenght;
    this->grow = 1;
    Element_array<T>* temp = this->element;
    int index = 0;
    while (index != this->lenght)
    {
        if (temp == nullptr) {
            temp = new Element_array<T>(0, index);
            this->element = temp;
        }
        else
        {
            Element_array<T>* temp = this->element;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Element_array<T>(0, index);
            temp->next->prev = temp;
        }
        index++;
    }
}
template<typename T>
int Array<T>::Getsize() {
    return this->lenght;
}
template<typename T>
void Array<T>::Set_Size(int size, int grow) {
    this->grow = grow;
    if (this->lenght < size) {
        Element_array<T>* temp = this->element;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp->index != size - 1)
        {
            temp->next = new Element_array<T>(0, temp->index + 1);
            temp->next->prev = temp;
            temp = temp->next;
        }
        this->lenght = size;
    }
    else
    {
        Element_array<T>* temp = this->element;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp = temp->prev;
        while (temp->index >= size - 1)
        {
            delete temp->next;
            temp->next = nullptr;
            if (temp->prev!=nullptr)
            {
                temp = temp->prev;
            }
            else
            {
                break;
            }
            
        }
        this->lenght = size;
    }
    Element_array<T>* temp = this->element;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    if ((temp->index == (this->lenght - 1)) && (temp->data != 0))
    {
        this->lenght += grow;
        while (temp->index != this->lenght - 1)
        {
            temp->next = new Element_array<T>(0, temp->index + 1);
            temp->next->prev = temp;
            temp = temp->next;
        }
    }

}
template<typename T>
int Array<T>::Get_Apper_bound() {
    Element_array<T>* temp = this->element;
    while (temp->next->data != 0)
    {
        temp = temp->next;
    }
    return temp->index;
}
template<typename T>
bool Array<T>::is_Empty() {
    if (this->element == nullptr || this->element->data == 0)
    {
        return true;
    }
    return false;
}
template<typename T>
void  Array<T>::free_Extra() {
    int lastindex = this->Get_Apper_bound();
    Element_array<T>* temp = this->element;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp = temp->prev;
    while (temp->index >= lastindex)
    {
        delete temp->next;
        temp->next = nullptr;
        temp = temp->prev;
    }
    this->lenght = lastindex;
}
template<typename T>
void Array<T>::Remove_all() {
    Element_array<T>* temp = this->element;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp = temp->prev;
    while (temp->next != nullptr)
    {
        delete temp->next;
        temp->next = nullptr;
        if (temp->prev != nullptr) {
            temp = temp->prev;
        }
    }
    if (temp->next == nullptr) {
        delete temp;
        temp = nullptr;
        this->element = temp;
    }
}
template<typename T>
void Array<T>::Add(T data) {
    Element_array<T>* temp = this->element;
    if (temp == nullptr) {
        int index = 0;
        while (index != this->lenght)
        {
            if (temp == nullptr) {
                temp = new Element_array<T>(0, index);
                this->element = temp;
            }
            else
            {
                Element_array<T>* temp = this->element;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = new Element_array<T>(0, index);
                temp->next->prev = temp;
            }
            index++;
        }
        temp = this->element;
        temp->data = data;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->data != 0)
        {
            this->Set_Size(this->lenght, this->grow);
            temp = temp->next;
            temp->data = data;
        }
        else
        {
            if (this->element->data == 0) {
                this->element->data = data;
            }
            else
            {
                while (temp->data == 0)
                {
                    temp = temp->prev;
                }

                temp = temp->next;
                temp->data = data;
            }
        }

    }

}
template<typename T>
T Array<T>::GetAt(int index) {
    Element_array<T>* temp = this->element;
    while (temp->next != nullptr)
    {
        if (temp->index == index) {
            return temp->data;
        }
        temp = temp->next;
    }
    return 0;
}
template<typename T>
void Array<T>::SetAt(T data, int index) {
    Element_array<T>* temp = this->element;
    while (temp->next != nullptr)
    {
        if (temp->index == index) {
            temp->data = data;
        }
        temp = temp->next;
    }
}
template<typename T>
T& Array<T>::operator[](int index) {
    Element_array<T>* temp = this->element;
    while (temp->next != nullptr)
    {
        if (temp->index == index) {
            return temp->data;
        }
        temp = temp->next;
    }
}
template<typename T>
void Array<T>::Append(Array<T>& a) {
    Element_array<T>* temp = a.element;
    while (temp->data != 0) {
        this->Add(temp->data);
        temp = temp->next;
    }
}
template<typename T>
Array<T>& Array<T>::operator=(Array<T>& a) {
    if (this->element != nullptr) {
        this->Remove_all();
        Element_array<T>* temp = a.element;
        while (temp != nullptr)
        {
            this->Add(temp->data);
            temp = temp->next;
        }
        this->lenght = a.lenght;
        this->grow = a.grow;
    }
    else
    {
        Element_array<T>* temp = a.element;
        while (temp != nullptr)
        {
            this->Add(temp->data);
            temp = temp->next;
        }
        this->lenght = a.lenght;
        this->grow = a.grow;
    }
    return *this;
}
template<typename T>
void Array<T>::Remove_at(int position) {
    Element_array<T>* temp = this->element;
    while (temp->index != position)
    {
        temp = temp->next;
    }
    Element_array<T>* temp_2 = temp->prev;
    temp = temp->next;
    delete temp->prev;
    temp_2->next = temp;
    temp->prev = temp_2;
    temp_2 = temp_2->next;
    while (temp_2->next != nullptr)
    {
        temp_2->index--;
        temp_2 = temp_2->next;
    }
    temp_2->index--;
    temp_2->next = new Element_array<T>(0, temp_2->index + 1);
}
template<typename T>
void Array<T>::Insert_at(T data, int position) {
    Element_array<T>* newNode = new Element_array<T>(data, position);
    Element_array<T>* temp = this->element;
    while (temp->next->index != position) {
        temp = temp->next;
    }
    Element_array<T>* temp_2 = temp->next;
    newNode->prev = temp;
    newNode->next = temp_2;
    temp->next = newNode;
    temp_2->prev = newNode;
    this->lenght++;
    while (temp_2 != nullptr) {
        temp_2->index++;
        temp_2 = temp_2->next;
    }
    {

    }

}
template<typename T>
inline Element_array<T>* Array<T>::GetData()
{
    return this->element;
}
