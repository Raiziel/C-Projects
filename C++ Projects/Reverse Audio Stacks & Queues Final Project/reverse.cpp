/*
	Name: Nicholas Munoz, 2000781568, 1004, #10
	Description: Audio Reverse Queue
	Input: EXPECTED_PROGRAM_INPUT
	Output: EXPECTED_PROGRAM_OUTPUT
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedStack.h"
#include "linkedQueue.h"

using namespace std;

int main(int argc, char* argv[])
{
	// *****************************************************************
	//	Check and process command line arguments.
	//		Usage: ./reverse <inputFile> <outputFile>
	//	 NOTE:	Must exit with "return EXIT_SUCCESS" even if there
	//			is an error.

		// Error message strings provided below

		//	YOUR CODE GOES HERE
		// 

		// no arguments -> usage message

	if (argc == 1)
	{
		cout << "Usage: ./reverse <inputFile> <outputFile>" << endl;
		return EXIT_SUCCESS;
	}
	if (argc != 3)
	{
		// incorrect number of arguments, just error out.
		cout << "Error, must provide input and output file names." << endl;
		return EXIT_SUCCESS;
	}
	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);
	if (inFile.is_open() == false)
	{
		// check argument 1, input file, by attempting to open, read access
		cout << "Error, unable to open input file: " << argv[1] << endl;
		return EXIT_SUCCESS;
	}
	if (outFile.is_open() == false)
	{
		// check argument 2, output file, by attempting to open, write acess
		cout << "Error, unable to open output file: " << argv[2] << endl;
		return EXIT_SUCCESS;
	}

	// *****************************************************************
	//  Headers...

	string	bars(50, '-');
	cout << bars << endl << "CS 202 - Assignment #10" << endl;
	cout << "Audio Reversal Program" << endl << endl;

	// *****************************************************************
	//	Handle audio file header lines
	//		read initial header line
	//			verify format (i.e, "; Sample Rate" is present)
	//			write to output file.
	//		extract sample rate, convert to integer

		// ensure header has correct title
		//	if not, not a audio data file
		// Error message string - place as appropriate


	std::string line = " ";
	std::getline(inFile, line, '\n');
	outFile << line << endl;
	string::size_type pos = 0;
	pos = line.find("; Sample Rate", pos);
	if (pos == string::npos)
	{
		cout << "Invalid audio data file" << endl;
		return EXIT_SUCCESS;
	}
	// Erase Substring here
	line.erase(pos, 13);
	// get sample rate from header
	int sampleRate = stoi(line);
	std::getline(inFile, line, '\n');
	// read second header line and write to output file.
	outFile << line << endl;
	// *****************************************************************
	//	Process and audio data file.

		// declare linked stack and linked queue
		//	use to sampleRate/2 for the node array sizes
	linkedQueue<double> dQueue(sampleRate / 2);
	linkedStack<double> dStack(sampleRate / 2);
	double	sample1 = 0.0, sample2 = 0.0;

	// read input file, store samples
	//	YOUR CODE GOES HERE

	while (!inFile.eof())
	{
		inFile >> sample1 >> sample2;
		if(inFile.eof())
		{
			break;
		}
		dQueue.addItem(sample1);
		dStack.push(sample2);
	}

	// show count of all samples
	cout << "Count = " << dQueue.queueCount() << endl;

	// get samples, write to output file
	//	output format:
	//		outFile << "  " << sample1 << "  " << sample2 << endl;
	while (dQueue.isEmptyQueue() == false)
	{
		outFile << " " << dQueue.front() << " " << dStack.top() << endl;
		dQueue.deleteItem();
		dStack.pop();
	}


// *****************************************************************
//  All done.
//		close file and show final message.

	inFile.close();
	outFile.close();

	cout << bars << endl << "Reversal completed." << endl;

	return	EXIT_SUCCESS;
}