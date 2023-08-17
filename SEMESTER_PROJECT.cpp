#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//DEFINE QUESTION CLASS TO STORE MCQ AND ESSAY QUESTIONS
class Question {
public:
	string text;
	vector <string> options;
	string studentAnswer;
	string correctOption;
	bool isEssay;

	Question(string _text, vector <string> _options, string _correctOption, bool _isEssay) {
		text = _text;
		options = _options;
		correctOption = _correctOption;
		isEssay = _isEssay;
	}

};


//DEFINE EXAM CLASS TO HANDLE EXAM RELATED FUNCTIONALITLITES
class Exam {
public:
	vector <Question> questions;
	time_t startTime;
	time_t endTime;

	void startExam() {
		startTime = time(nullptr);
	}

	void endExam() {
		endTime = time(nullptr);
	}

	void addQuestion(Question question) {
		questions.push_back(question);
	}

	void displayQuestions() {
		for (size_t i = 0; i < questions.size(); i++) {
			cout << "Question (" << i + 1 << ")" << questions[i].text << endl;
			if (!questions[i].isEssay) {
				for (size_t j = 0; j < questions[i].options.size(); j++) {
					cout << " " << (char)('A+j') << ") " << questions[i].options[j] << endl;
				}
			}

			cout << "Your Answer:  ";
			if (!questions[i].isEssay) {
				cin >> questions[i].studentAnswer;
			}
			else {
				cin.ignore(); // CLEAR NEWLINE CHARACTER
				getline(cin, questions[i].studentAnswer);
			}
		}
	}

	void markExam() {
		int totalQuestions = questions.size();
		int correctCount = 0;

		for (size_t i = 0; i < questions.size(); i++) {
			if (!questions[i].isEssay) {
				if (questions[i].studentAnswer == questions[i].correctOption) {
					correctCount++;
				}
			}
		}

		cout << "EXAM RESULTS:  " << endl;
		cout << "Total Questions:  " << totalQuestions << endl;
		cout << "CORRECT ANSWERS:  " << correctCount << endl;
		cout << "INCORRECT ANSWERS:  " << (totalQuestions - correctCount) << endl;
		cout << "Essay answers are available for the lecturer." << endl;

	}
};


int main()
{
	Exam exam;
	exam.startExam();

	//ADD MCQ QUESTIONS
	exam.addQuestion(Question("What is the capital of France?", { "Paris", "Berlin", "London", "Madrid" }, "A", false));

	exam.addQuestion(Question("Which planet is known as the Red Planet? ", { "Vernus", "Mars", "Jupiter", "Saturn" }, "B", false));
	
	//ADD ESSAY QUESTION
	exam.addQuestion(Question("Explain the concept of artificial intelligence.", {}, "", true));

	//DISPLAY QUESTIONS AND CORRECT ANSWERS
	exam.displayQuestions();


	return 0;
}