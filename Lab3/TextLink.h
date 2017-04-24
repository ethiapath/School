//
//  TextLink.h
//  Lab3
//
//  Created by Hargobind Atwal on 4/23/17.
//  Copyright © 2017 Hargobind Atwal. All rights reserved.
//

#ifndef TextLink_h
#define TextLink_h

class TextLink
{
private:
    TextLink * next;
    TextLink * prev;
    char data;
public:
    TextLink(char d = ' ', TextLink * next = nullptr, TextLink * prev = nullptr);
    
    char getData();
    
    TextLink * getNext();
    TextLink * getPrev();
    
    void setNext(TextLink * next);
    void setPrev(TextLink * prev);
    
};

#endif /* TextLink_h */
