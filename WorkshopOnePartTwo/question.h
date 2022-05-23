//************************************************//
//Name: Hashmeet Singh Saini
//Student Number : 153070214
//Section : NFF
//Seneca Email : hsaini28@myseneca.ca
//************************************************//
#ifndef QUIZZER_QUESTION_H
#define QUIZZER_QUESTION_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
namespace quizzer {
	const int MAX_QUESTION_LENGTH = 1024;
	const int MAX_ANSWER_LENGTH =128;
	const int MAX_ANSWERS = 10;
	const int MAX_QUESTIONS = 60;
	const int MAX_QUIZZES = 5;

	struct answers {
		bool correct;
		char answer[MAX_ANSWER_LENGTH + 1];
	};
	struct question {
		char type;
		char ques[MAX_QUESTION_LENGTH + 1];
		int quizAns;
		struct answers ans[MAX_ANSWERS];
	};
	struct quiz {
		struct question ques[MAX_QUESTIONS];
		int quesNum = 0;
		int QuesNo = 0;
		int correctAnswers = 0;
		int started = 0;
	};

	extern question ques[MAX_QUESTIONS];
	extern quiz quiztemp;
	char loadQues(char tmp[MAX_QUESTION_LENGTH+1], quiz* quiztemp, int *quesNum, int *ansNum, int *newLine);
}


#endif // !QUIZZER_QUESTION_H
