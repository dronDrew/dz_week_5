#pragma once
#include "dependies.h"
 
template<typename T>
class Array
{
    class Element_array {
    public:
        T data;
        int index;
        Element_array* next;
        Element_array* prev;
        Element_array(T data, int index);//done

    };
public:
    Element_array* element;
    int lenght;
    int grow;
    Array();//done
    Array(int lenght);//done
    int Getsize();//done
    void Set_Size(int size, int grow);//done
    int Get_Apper_bound();//done
    bool is_Empty();//done
    void free_Extra();//done;
    void Remove_all();//done
    void Add(T data);//done
    T GetAt(int index);//done
    void SetAt(T data,int index);//done;
    T& operator[](int index);//done
    void Append(Array<T>& a);//done
    Array& operator=(Array<T>& a);//done
    void Insert_at(T data, int position);//done
    void Remove_at(int position);//done
};
template<typename T>
Array<T>::Element_array::Element_array(T data ,int index) {
    this->data = data;
    this->index = index;
}
template<typename T>
Array<T>::Array() {
    this-> lenght = 8;
    this->grow = 1;
    Element_array* temp = this->element;
    int index = 0;
    while (index!=this->lenght)
    {
        if (temp == nullptr) {
            temp = new Element_array(0, index);
            this->element = temp;
        }
        else
        {
            Element_array* temp = this->element;
                while (temp->next!=nullptr)
                {
                    temp = temp->next;
                }
            temp->next = new Element_array(0, index);
            temp->next->prev = temp;
        }
        index++;
    }
}
template<typename T>
Array<T>:: Array(int lenght) {
    this->lenght = lenght;
    this->grow = 1;
    Element_array* temp = this->element;
    int index = 0;
    while (index != this->lenght)
    {
        if (temp == nullptr) {
            temp = new Element_array(0, index);
            this->element = temp;
        }
        else
        {
            Element_array* temp = this->element;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
            temp->next = new Element_array(0, index);
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
        Element_array* temp = this->element;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp->index!=size-1)
        {
            temp->next = new Element_array(0, temp->index+1);
            temp->next->prev = temp;
            temp = temp->next;
        }
        this->lenght = size;
    }
    else
    {
        Element_array* temp = this->element;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp = temp->prev;
        while (temp->index >= size - 1)
        {
            delete temp->next;
            temp->next=nullptr;
            temp = temp->prev;
        }
        this->lenght = size;
    }
    Element_array* temp = this->element;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    if ((temp->index==(this->lenght-1))&&(temp->data!=0))
    {
        this->lenght += grow;
        while (temp->index != this->lenght - 1)
        {
            temp->next = new Element_array(0, temp->index + 1);
            temp->next->prev = temp;
            temp = temp->next;
        }
    }

}
template<typename T>
int Array<T>::Get_Apper_bound() {
    Element_array* temp = this->element;
    while (temp->next->data!=0)
    {
        temp = temp->next;
    }
    return temp->index;
}
template<typename T>
bool Array<T>::is_Empty() {
    if (this->element==nullptr|| this->element->data == 0)
    {
        return true;
    }
    return false;
}
template<typename T>
void  Array<T>::free_Extra() {
    int lastindex = this->Get_Apper_bound();
    Element_array* temp = this->element;
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
    Element_array* temp = this->element;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp = temp->prev;
    while (temp->next!=nullptr)
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
    Element_array* temp = this->element;
    if (temp == nullptr) {
        int index = 0;
        while (index != this->lenght)
        {
            if (temp == nullptr) {
                temp = new Element_array(0, index);
                this->element = temp;
            }
            else
            {
                Element_array* temp = this->element;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = new Element_array(0, index);
                temp->next->prev = temp;
            }
            index++;
        }
        temp = this->element;
        temp->data = data;
    }
    else
    {
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        if (temp->data!=0)
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
    Element_array* temp = this->element;
    while (temp->next!=nullptr)
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
    Element_array* temp = this->element;
    while (temp->next != nullptr)
    {
        if (temp->index == index) {
            temp->data=data;
        }
        temp = temp->next;
    }
}
template<typename T>
T& Array<T>::operator[](int index) {
    Element_array* temp = this->element;
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
    Element_array* temp = a.element;
    while (temp->data !=0) {
        this->Add(temp->data);
        temp = temp->next;
    }
}
template<typename T>
Array<T>& Array<T>::operator=(Array<T>& a) {
    if (this->element != nullptr) {
        this->Remove_all();
        Element_array* temp = a.element;
        while (temp!=nullptr)
        {
            this->Add(temp->data);
            temp = temp->next;
        }
        this->lenght = a.lenght;
        this->grow = a.grow;
    }
    else
    {
        Element_array* temp = a.element;
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
    Element_array* temp = this->element;
    while (temp->index!=position)
    {
        temp = temp->next;
    }
    Element_array* temp_2 = temp->prev;
    temp = temp->next;
    delete temp->prev;
    temp_2->next = temp;
    temp->prev = temp_2;
    temp_2 = temp_2->next;
    while (temp_2->next!=nullptr)
    {
        temp_2->index--;
        temp_2 = temp_2->next;
    }
    temp_2->index--;
    temp_2->next = new Element_array(0, temp_2->index+1);
}
template<typename T>
void Array<T>::Insert_at(T data, int position) {
    Element_array* newNode = new Element_array(data, position);
    Element_array* temp = this->element;
    while (temp->next->index != position) {
        temp = temp->next;
    }
    Element_array* temp_2= temp->next;
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