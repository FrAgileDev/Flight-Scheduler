#include <iostream>
#include <time.h>
#include <queue>
#include "requests.h"
using namespace std;

//0 = false; 1 = true

int main() {

	int rndm;
	int incomingtotal, outgoingtotal;
	incomingtotal = outgoingtotal = 0;
	int lefttime, righttime;
	lefttime = righttime = 121;
	int incount = 0;
	int outcount = 0;
	bool leftopen = true;
	bool rightopen = true;
	srand(time(NULL));
	queue<class requests> incoming;
	queue<class requests> outgoing;

	for(int i = 0; i<=120;i = i++) {
		if(i - righttime == 15) {
				rightopen = true;
			}
			if(i - lefttime == 15) {
				leftopen = true;
			}
		if(i%5==0 && i >= 5) {
			rndm = rand() % 2;
			if (rndm == 0) {
				requests i(i);
				incoming.push(i);
			}
			else if (rndm == 1) {
				requests o(i);
				outgoing.push(o);
			}
		}
		if(!incoming.empty()) {
			if(leftopen) {
				lefttime = i;
				incoming.front().leaveq(i);
				incomingtotal = incomingtotal + (incoming.front().getleavetime() - incoming.front().gettime());
				incoming.pop();
				incount++;
				leftopen = false;
			}
			else if(!leftopen) {
				if(rightopen) {
					righttime = i;
					incoming.front().leaveq(i);
					incomingtotal = incomingtotal + (incoming.front().getleavetime() - incoming.front().gettime());
					incoming.pop();
					incount++;
					rightopen = false;
				}
			}
		}
		if(!outgoing.empty()) {
			if(leftopen) {
				lefttime = i;
				outgoing.front().leaveq(i);
				outgoingtotal = outgoingtotal + (outgoing.front().getleavetime() - outgoing.front().gettime());
				outgoing.pop();
				outcount++;
				leftopen = false;
			}
			else if(!leftopen) {
				if(rightopen) {
					righttime = i;
					outgoing.front().leaveq(i);
					outgoingtotal = outgoingtotal + (outgoing.front().getleavetime() - outgoing.front().gettime());
					outgoing.pop();
					outcount++;
					rightopen = false;

				}
			}
		}
			if(i - righttime == 15) {
				rightopen = true;
			}
			if(i - lefttime == 15) {
				leftopen = true;
			}

	}
	outgoingtotal /= outcount;
	incomingtotal /= incount;

	cout << "Average time in outgoing queue: " << outgoingtotal << endl;
	cout << "Average time in incoming queue: " << incomingtotal << endl;
	cout << incount << " planes landed and " << outcount << " planes took off." << endl;
	cout << outgoing.size() << " planes left in outgoing queue" << endl;
	cout << incoming.size() << " planes left in incoming queue" << endl;

	return 0;
}
	/*
	random incoming or outgoing every five minutes
	if (incoming)
		send to incoming queue
		if(runway open)
			pop off incoming queue
	else if(outgoing)
		send to outgoing queue
		if(incoming queue is empty)
			if(runway open)
				pop off outgoing queue
		else if(incoming queue is occupied)
			if(runway open)
				pop off incoming queue
		if(time%15)
	*/