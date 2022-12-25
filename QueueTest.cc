/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
}

#include <iostream>
#include <fstream>
#include "AnsiPrint.h"
#include "Except.h"
#include "Queue.h"
using namespace std;
const char st1[] = {"Integer Queue:"};
const char st2[] = {"Character Queue:"};
/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[strlen(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str, yellow, red, true, true);
  cout << endl ;
  delete [] str;

}

/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

    assert(progName);
    cout << "Usage: " << progName << " [passes [display [seed]]]" << endl;

}

int
main(int argc, char **argv) {

	istream *is1=&cin, *is2=&cin;

	if (argc>3) {
		PrintUsage(argv[0]);
		exit(-1);
	} else if (argc>2) {
		is2 = new ifstream(argv[2]);
		if (is2==NULL) {
			cerr << "Can't open file " << argv[2] << endl;
			exit(1);
		}
	} 
	if (argc>1) {
		is1 = new ifstream(argv[1]);
		if (is1==NULL) {
			cerr << "Can't open file " << argv[1] << endl;
			exit(2);
		}
	}

	// You need to provide testing exercises here
	try{

		int dataI;
		Queue<int> *myIntQPtr = new Queue<int>;
		while(*is1 >> dataI){
			myIntQPtr->enqueue(dataI);
		}
		Queue<int> myIntQ = *myIntQPtr;
		AnsiPrint(st1, false, false);
		for(int i = 0 ; i < 5 ; i++){
			cout << myIntQ.front() << endl;
			myIntQ.dequeue();
		}
		delete myIntQPtr;

		char dataC;
		Queue<char> myCharQ;
		while(*is2 >> dataC){
			myCharQ.enqueue(dataC);
		}
		AnsiPrint(st2, false, false);
		for(int i = 0 ; i < 5 ; i++){
			cout << myCharQ.front() << endl;
			myCharQ.dequeue();
		}

	}
	catch(Except e){
		AnsiPrint(e, false, false);
	}

	
	PrintMyID("110703022");
	return 0;
    
}
