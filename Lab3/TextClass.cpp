//
//  TextClass.cpp
//  Lab3
//
//  Created by Hargobind Atwal on 4/23/17.
//  Copyright © 2017 Hargobind Atwal. All rights reserved.
//

#include "TextClass.h"
#include <sstream>

TextClass::TextClass()
{
    head = tail = nullptr;
}

TextClass::~TextClass()
{
    TextLink * ptr = head;
    while (ptr != nullptr)
    {
        TextLink * temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}

void TextClass::insertHead(char val)
{
    // Special case empty list
    if( isEmpty() )
        head = tail = new TextLink(val);
    // insert new head element
    else
    {
        head->setPrev(new TextLink(val, head, nullptr));
        head = head->getPrev();
    }
}

void TextClass::insertTail(char val)
{
    // Special case empty list
    if( isEmpty() )
        head = tail = new TextLink(val);
    // insert new head element
    else
    {
        tail->setNext(new TextLink(val, nullptr, tail));
        tail = tail->getNext();
    }
}

char TextClass::deleteHead()
{
    // check for empty list
    if ( isEmpty() )
        throw std::underflow_error("Empty_List");
    // Save data for deleation
    TextLink * temp = head;
    
    // update list
    head = head->getNext();
    // check if list is now empty
    if( head == nullptr )
        tail = nullptr;
    else
        head->setPrev(nullptr);
    int data = temp->getData();
    delete temp;
    return data;
    
}


char TextClass::deleteTail()
{
    // check for empty list
    if ( isEmpty() )
        throw std::underflow_error("Empty_List");
    // Save data for deleation
    TextLink * temp = tail;
    
    // update list
    tail = tail->getPrev();
    // check if list is now empty
    if( tail == nullptr )
        head = nullptr;
    else
        head->setNext(nullptr);
    int data = temp->getData();
    delete temp;
    return data;
}

bool TextClass::isEmpty()
{
    if( head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}


bool TextClass::findKey(char key)
{
    TextLink * ptr = head;
    while(ptr != nullptr)
    {
        if( key == ptr->getData() )
        {
            iter = ptr;
            return true;
        }
        ptr = ptr->getNext();
    }
    return false;
}

bool TextClass::insertKey(char value)
{
    // check for empty list or if iter is nullptr
    if ( iter == nullptr)
        return false;
    // check if iter is head
    if(iter->getPrev() == nullptr)
    {
        head = new TextLink(value, iter, nullptr);
        iter->setPrev(head);
        return true;

    }
    else
    {
        // sets prev link's next ptr to new link
        iter->getPrev()->setNext(new TextLink(value, iter, iter->getPrev()));
        // sets iter's prev ptr to whats stored in the previous's next ptr
        iter->setPrev(iter->getPrev()->getNext());
        return 1;
    }
}
bool TextClass::deleteIter()
{
    // check for empty list
    if ( iter == nullptr)
        return false;
    // remove refrences to iter
    iter->getPrev()->setNext(iter->getNext());
    iter->getNext()->setPrev(iter->getPrev());
    
    delete iter;
    return true;

}

bool TextClass::deleteKey(char key)
{
    // check for empty list
    if ( isEmpty() )
        throw std::underflow_error("Empty_List");
    TextLink * ptr = head;
    while(ptr != nullptr)
    {
        if( key == ptr->getData() )
        {
            // if not last
            if( ptr->getNext() != nullptr )
                ptr->getNext()->setPrev(ptr->getPrev());
            else
                tail = ptr->getPrev();
            
            // if not first
            if( ptr->getPrev() != nullptr )
                ptr->getPrev()->setNext(ptr->getNext());
            else
                head = ptr->getNext();
            
            delete ptr;
            return true;
        }
        ptr = ptr->getNext();
    }
    return false;
}

std::string TextClass::displayList()
{
    // check for empty list
    if ( isEmpty() )
        return "";
    std::stringstream out;
    TextLink * ptr = head;
    while( ptr != nullptr )
    {
        out << ptr->getData();
        ptr = ptr->getNext();
    }
    return out.str();
}

void TextClass::appendList(TextClass * list2)
{
    TextClass list = *list2;
    this->insertTail(' ');
    while ( !list.isEmpty() ) {
        this->insertTail(list.deleteHead());
    }
}

TextClass& TextClass::operator= (const TextClass& oldList)
{
    TextClass newList;
    TextLink * ptr = oldList.head;
    while (ptr != nullptr) {
        newList.insertHead(ptr->getData());
        ptr = ptr->getNext();
    }
    return newList;
}
