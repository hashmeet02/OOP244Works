//************************************************//
//Name: Hashmeet Singh Saini
//Student Number : 153070214
//Section : NFF
//Seneca Email : hsaini28@myseneca.ca
// LoadQuiz function inspired by the ideas of Sebastian Rubina Schanez(peer)
//************************************************//

#define _CRT_SECURE_NO_WARNINGS
#include "question.h"


namespace quizzer {
	FILE* fp = nullptr;
	int LoadQuiz(const char* filename)
	{
		int flag=-1;
		int newLine = 0;
		int quesNum = 0;
		int ansNum = 0;
		int j = 0, i=0;
		int sucess;
		char result =' ';
		quiztemp.quesNum = 0;
		for (j = 0; j < MAX_QUESTIONS; j++)
		{
			quiztemp.ques[j] = { 0 };
		}
		fp = fopen(filename, "r");
		if (fp) {
			flag = 0;
			char tempques[MAX_QUESTION_LENGTH + 1];
			do {
				sucess = fscanf(fp, "%[^\n]", tempques);
				if (fgetc(fp) == '\n') newLine++;
				if (newLine != 2) {
					result=loadQues(tempques, &quiztemp, &quesNum, &ansNum, &newLine);
				}
				if (result == 'a') ansNum++;

				if (newLine == 2) {
					newLine = 0;
					quesNum++;
					ansNum = 0;
				}
			} while (feof(fp) == 0);
		}
		return flag;
	}


	int IsQuizValid()
	{
		int i, ansFlag=1, flag=1;
		bool quesNumCheck=0, ansNumCheck=0;
		int j, ansNum=0,rightQues=0;
		if (quiztemp.quesNum >= 5) {
			for (i = 0; i < quiztemp.quesNum; i++) {
				
				for (j = 0; j < MAX_ANSWERS; j++)
				{
					if (quiztemp.ques[i].ans[j].correct) ansNum++;
					//cout << ansNum << endl;
				}
				if (quiztemp.ques[i].type== 'C') {
					if (ansNum == 1) {
						cout << "QUESTION " << i + 1 << " -> OK" << endl;
						rightQues++;
					}
					else {
						cout << "QUESTION " << i + 1 << " -> ERROR" << endl;
						ansFlag = 0;
					}
				}
				else {
					if (ansNum >= 1) {
						cout << "QUESTION " << i + 1 << " -> OK" << endl;
						rightQues++;

					}
					else {
						cout << "QUESTION " << i + 1 << " -> ERROR" << endl;
						ansFlag = 0;
					}	
				}
				ansNum = 0;
			}
			
		}
		
		if (ansFlag && (rightQues >= 5)) flag = 1;
		else flag = 0;
		return flag;
		//*******8previos attemp on creating a logic*************8
			/*quesNumCheck = 1;
			for (i = 0; (i < quiztemp.quesNum) && quesNumCheck; i++) {
				ansFlag = 0;
				ansNum = 0;
				if (quiztemp.ques[i].type == "mc") {
					for (j = 0; j < MAX_ANSWERS; j++)
					{
						if (quiztemp.ques[i].ans[j].correct) {
							ansNum++;
						}
					}
					if (ansNum == 1) {
						cout << "QUESTION " << i + 1 << " -> OK" << endl;
						ansFlag = 1;
					}
					else {
						cout << "QUESTION " << i + 1 << " -> ERROR" << endl;
						ansFlag = 0;
					}
				}
				else
				{
					for (j = 0; j < MAX_ANSWERS; j++)
					{
						if (quiztemp.ques[i].ans[j].correct) {
							ansNum++;
						}
					}
					if (ansNum >= 1) {
						cout << "QUESTION " << i + 1 << " -> OK" << endl;
						ansFlag = 1;
					}
					else {
						cout << "QUESTION " << i + 1 << " -> ERROR" << endl;
						ansFlag = 0;
					}
				}
			}*/
	}


	int HasMoreQuestions()
	{
		int flag = 0;
		if (quiztemp.QuesNo < quiztemp.quesNum) flag = 1;
		else flag = 0;

		return flag;
	}


	void ShowNextQuestion()
	{
		int i = 0;
		int cQues= quiztemp.QuesNo;
		quiztemp.started = 1;
		cout << quiztemp.ques[cQues].ques +5<< endl;
		for ( i = 0; i < MAX_ANSWERS; i++)
		{
			if (quiztemp.ques[cQues].ans[i].answer[0] == '[')
			{
				cout << i + 1 << "." << quiztemp.ques[cQues].ans[i].answer + 3 << endl;
			}
		}
		cout << "Your answer? ";
		cin >> quiztemp.ques[cQues].quizAns;
		if (quiztemp.ques[cQues].ans[quiztemp.ques[cQues].quizAns - 1].correct)
		{
			quiztemp.correctAnswers++;
		}
		quiztemp.QuesNo += 1;
	}


	void ShowQuizResults()
	{
		if (quiztemp.started != 0) {
			int i = 0;
			cout << endl << "QUIZ RESULTS : your score is " << quiztemp.correctAnswers << "/" << quiztemp.quesNum << endl;

			for ( i = 0; i < MAX_QUESTIONS; i++)
			{
				quiztemp.ques[i] = { 0 };
				
			}
			quiztemp.started = 0;
			quiztemp.quesNum = 0;
			quiztemp.QuesNo = 0;
			quiztemp.correctAnswers = 0;
		}
	}
}