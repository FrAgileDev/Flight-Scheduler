#include "requests.h"

requests::requests() {

}

requests::requests(int time) {
	timeinqueue = time;
}


requests::~requests(void)
{
}

int requests::gettime() {
	return timeinqueue;
}

void requests::leaveq(int time) {
	timeoutqueue = time;
}

int requests::getleavetime() {
	return timeoutqueue;
}