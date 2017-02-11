#pragma once
class requests {
public:
	requests();
	requests(int time);
	~requests(void);
	void leaveq(int time);
	int gettime();
	int getleavetime();
protected:
	int timeinqueue;
	int timeoutqueue;

};

