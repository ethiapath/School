//
//  main.cpp
//  Test Program for Lab3
//
//  Created by Jim Bailey on 4/20/17.
//  Copyright © 2017 jim. All rights reserved.
//


#include <iostream>

// Lab include files
#include "TextClass.h"
//#include "StudentList.h"
//#include "TList.h"

using namespace std;

int main(int args, char * argv[])
{
    
    // defines to select a given test
#define TextClass_test
#define Append_test
//#define StudentList_test
    
    
#ifdef TextClass_test
    
    /*
     *  testing textClass
     */
    cout << endl << "Testing TextClass" << endl << endl;
    
    TextClass * textList1 = new TextClass;
    
    // check for add and delete head
    textList1->insertHead('a');
    textList1->insertHead('b');
    textList1->insertHead('c');
    cout << endl << "Testing insert and delete head, output s/b cba -- is: ";
    cout << textList1->deleteHead() << textList1->deleteHead() << textList1->deleteHead() << endl;
    
    cout << "Testing delete head from an empty list: ";
    try {
        textList1->deleteHead();
    }
    catch ( underflow_error & err ) {
        cout << "Caught error: " << err.what() << endl;
    }
    
    // check for add and delete tail
    textList1->insertTail('x');
    textList1->insertTail('y');
    textList1->insertTail('z');
    cout << endl << "Testing insert and delete tail, output s/b zyx -- is: ";
    cout << textList1->deleteTail() << textList1->deleteTail() << textList1->deleteTail() << endl;
    
    cout << "Testing delete tail from an empty list: ";
    try {
        textList1->deleteTail();
    }
    catch ( underflow_error & err ) {
        cout << "Caught error: " << err.what() << endl;
    }
    
    // check for add tail, delete head
    textList1->insertTail('x');
    textList1->insertTail('y');
    textList1->insertTail('z');
    cout << endl << "Testing insert tail and delete head, output s/b xyz -- is: ";
    cout << textList1->deleteHead() << textList1->deleteHead() << textList1->deleteHead() << endl;
    
    // testing iter methods
    textList1->insertTail('0');
    textList1->insertTail('3');
    textList1->insertTail('5');
    textList1->insertTail('3');
    
    
    // iter find
    cout << endl << "Testing Iter find, should find 3 and not find 4" << endl;
    cout << ((textList1->findKey('3'))?" found 3":" did not find 3") << endl;
    cout << ((textList1->findKey('4'))?" found 4":" did not find 4") << endl;
    
    // iter insert
    cout << endl << "Testing insert, starting string should be 0353, is: " << textList1->displayList() << endl;
    textList1->findKey('3');
    textList1->insertKey('1');
    textList1->findKey('3');
    textList1->insertKey('6');
    textList1->findKey('3');
    textList1->insertKey('2');
    cout << "Ending string should be 0123563, is: " << textList1->displayList() << endl;
    
    //iter delete
    textList1->findKey('5');
    textList1->deleteIter();
    cout << endl << "Testing deleteIter, ending string should be 012363, is: " << textList1->displayList() << endl;
    
    // delete key
    textList1->deleteKey('6');
    cout << endl << "Testing DeleteKey, ending string should be 01233, is: " << textList1->displayList() << endl;
    
    delete textList1;
    
    //changing a string
    TextClass * stringList = new TextClass;
    string stringOne = "That is a test";
    int lengthOne = static_cast<int>(stringOne.length());
    
    for ( int i = 0; i < lengthOne; i++ )
    {
        stringList->insertTail( stringOne[i] );
    }
    cout << endl << "String list starts as: " << stringList->displayList() << endl;
    stringList->findKey('i');
    stringList->insertKey('w');
    stringList->insertKey('a');
    stringList->deleteIter();
    cout << "After changing 'i' to 'wa', list now reads: " << stringList->displayList() << endl;
    
    
    delete stringList;
#endif
    
#ifdef Append_test
    
    /*
     * Testing append
     */
    
    cout << endl << "Testing append " << endl << endl;
    
    TextClass * catList = new TextClass;
    
    string stringCat = "This is a cat";
    int lengthCat = (int)stringCat.length();
    
    for ( int i = 0; i < lengthCat; i++ )
    {
        catList->insertTail( stringCat[i] );
    }
    cout << "Cat list starts as: " << catList->displayList() << endl;
    
    
    TextClass * dogList = new TextClass;
    
    string stringDog = "That is a dog";
    int lengthDog = (int)stringDog.length();
    
    for ( int i = 0; i < lengthDog; i++ )
    {
        dogList->insertTail( stringDog[i] );
    }
    cout << "Dog list starts as: " << dogList->displayList() << endl;
    
    catList->appendList( dogList );
    cout << endl << "After append, cat list is: " << catList->displayList() << endl;
    
    catList->findKey( 'T' );
    catList->findKey( 'T' );
    catList->insertKey( ' ' );
    catList->insertKey( 'a' );
    catList->insertKey( 'n' );
    catList->insertKey( 'd' );
    catList->insertKey( ' ' );
    catList->insertKey( 't' );
    catList->deleteIter();
    
    cout << "After changes, cat list is: " << catList->displayList() << endl;
    cout << endl << "Dog list should be unchanged and is: " << dogList->displayList() << endl;
    
    delete catList;
    delete dogList;
#endif
    
    
#ifdef StudentList_test
    
    /*
     * Testing student list functions
     */
    cout << endl << "Testing StudentList" << endl << endl;
    
    // create a list to play with
    StudentList * sList = new StudentList;
    
    // create some students
    Student * frodo = new Student("Frodo", 50);
    Student * bilbo = new Student("Bilbo", 111);
    Student * gandalf = new Student("Gandalf", 500);
    Student * pippen = new Student("Pippen", 30);
    Student * sam = new Student("Samwise", 40);
    
    // load the list
    sList->insertHead(frodo);
    sList->insertTail(bilbo);
    sList->insertHead(gandalf);
    sList->insertTail(pippen);
    sList->insertHead(sam);
    
    // check empty
    cout << "Checking isEmpty, should not be empty, is: " << (sList->isEmpty()?"empty":"not empty") << endl;
    
    // check find
    cout << "Checking find with Sam, should find: " << (sList->findKey("Samwise")?"found":"not found") << endl;
    cout << "Checking find with Merry, should not find: " << (sList->findKey("Merry")?"found":"not found") << endl;
    
    // check deleteKey
    cout << "Checking deleteKey with Pippen, should find: " << (sList->deleteKey("Pippen")?"found":"not found") << endl;
    cout << "Checking deleteKey with Merry, should not find: " << (sList->deleteKey("Merry")?"found":"not found") << endl;
    
    // check deleteHead
    cout << "Checking delete head, should show in order: Samwise, Gandalf, Frodo, Bilbo" << endl;
    while ( true )
    {
        try {
            Student * temp = sList->deleteHead();
            cout << temp->getName() << " ";
            delete temp;
        }
        catch ( underflow_error & ex ) {
            cout << endl << "Caught error: " << ex.what() << endl;
            break;
        }
    }
    
    // checkikng empty again
    cout << "Checking isEmpty again, should now be empty, is: " << (sList->isEmpty()?"empty":"not empty") << endl;
    
    delete sList;
#endif
    
    
    cout << endl << "All done" << endl << endl;
    
    return 0;
}
