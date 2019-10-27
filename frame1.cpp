//frame sort

#include <bits/stdc++.h>
using namespace std;

#define MAX_MSG_SIZE 127

struct Frame
{
	int sequence;
	char data[10];
};

// compare function for sort by sequence number
bool compare(Frame f1, Frame f2)
{
	return (f1.sequence < f2.sequence);
}

// to print the message in the frame
void print_msg(Frame f[], int n)
{
	cout << endl;
	int i;
	for(i = 0; i < n; i++)
		// cout << f[i].data;
		cout << f[i].sequence << " " << f[i].data << endl;
	cout << endl;
}

int main()
{
	char msg[MAX_MSG_SIZE];
	cout << "Enter your message" << endl;
	scanf("%[^\n]", msg);
	
	int frame_size;
	cout << "Enter single frame size: ";
	cin >> frame_size;

	int no_of_frames = ceil(strlen(msg) / (float)frame_size);

	Frame f[no_of_frames];
	
	int i;
	// creating frames of frame_size bit
	for(i = 0; i < no_of_frames; i++)
	{
		f[i].sequence = (i + 1);
		strncpy(f[i].data, msg+(i*frame_size), frame_size);
		f[i].data[frame_size] = '\0';
	}
	
	// random shuffle
	for(i = 0; i < no_of_frames/2; i++)
	{
		int idx = random() % no_of_frames;
		swap(f[i], f[idx]);
	}
	
	// print shuffled message
	printf("Suffled Message is ");
	print_msg(f, no_of_frames);
	
	// sort the message
	sort(f, f + no_of_frames, compare);
	
	// print sorted message
	printf("Recieved Message is ");
	print_msg(f, no_of_frames);
	
	return 0;
}
