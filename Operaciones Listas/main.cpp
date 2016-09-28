#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
	LinkedList<string> lMiLL;
	LinkedList<string> lMull;
	lMiLL.addFirst("G");
	lMiLL.addFirst("F");
	lMiLL.addFirst("E");
	lMiLL.addFirst("D");
	lMiLL.addFirst("C");
	lMiLL.addFirst("B");
	lMiLL.addFirst("A");
	lMull.addFirst("S");
	lMull.addFirst("S");
	lMull.addFirst("S");
	lMull.addFirst("S");
	lMull.addFirst("S");
	lMull.addFirst("S");
	lMull.addFirst("S");
	node<string> nodillo("A");

    lMiLL+=lMull;
    lMiLL+=nodillo;

    LinkedList<string> nuevo(lMiLL);

    nuevo=lMull;

    nuevo.print();
}
