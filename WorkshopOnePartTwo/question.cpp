//************************************************//
//Name: Hashmeet Singh Saini
//Student Number : 153070214
//Section : NFF
//Seneca Email : hsaini28@myseneca.ca
// loadQues function inspired by the ideas of Sebastian Rubina Schanez(peer)
//************************************************//
#define _CRT_SECURE_NO_WARNINGS
#include "question.h"



namespace quizzer{
	question ques[MAX_QUESTIONS] = { 0 };
	quiz quiztemp;
	
	char loadQues(char tmp[MAX_QUESTION_LENGTH + 1], quiz* quiztemp, int* quesNum, int* ansNum, int* newLine)
	{
		char result = ' ';
		if (tmp[0]=='{' && tmp[2]=='c')
		{
			strcpy(quiztemp->ques[*quesNum].ques, tmp);
			quiztemp->ques[*quesNum].type='C';
			strcpy(tmp, " ");
			*ansNum = 0;
			result = 'q';
			quiztemp->quesNum += 1;
			*newLine=0;
		}
		else if (tmp[0] == '{' && tmp[2] == 'a')
		{
			strcpy(quiztemp->ques[*quesNum].ques, tmp);
			quiztemp->ques[*quesNum].type, 'A';
			strcpy(tmp, " ");
			*ansNum = 0;
			result = 'q';
			quiztemp->quesNum += 1;
			*newLine = 0;
		}
		else if (tmp[0] == '[')
		{
			strcpy(quiztemp->ques[*quesNum].ans[*ansNum].answer, tmp);
			if (quiztemp->ques[*quesNum].ans[*ansNum].answer[1] == 'X')
			{
				quiztemp->ques[*quesNum].ans[*ansNum].correct = 1;
			}
			strcpy(tmp, " ");
			result = 'a';
			*newLine = 0;
		}
		else
		{
			result = 'b';
		}
		return result;
	}

}