//
//  TextList.cpp
//  Lab3
//
//  Created by Hargobind Atwal on 4/23/17.
//  Copyright © 2017 Hargobind Atwal. All rights reserved.
//

#include "TextLink.h"

TextLink::TextLink(char data/* = ' '*/, TextLink * next/* = nullptr*/, TextLink * prev/* = nullptr*/):data(data), next(next), prev(prev)
{
    
}


char TextLink::getData()
{
    return data;
}

TextLink * TextLink::getNext()
{
    return next;
}
TextLink * TextLink::getPrev()
{
    return prev;
}

void TextLink::setNext(TextLink * next)
{
    this->next = next;
}
void TextLink::setPrev(TextLink * prev)
{
    this->prev = prev;
}
