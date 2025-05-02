#include <iostream>
#include <string>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}


	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		GuessResult results = { true, 3, 0 };

		results.strikes = CheckStrike(guessNumber);
		if (results.strikes < 3) results.solved = false;
		return results;
	}

	int CheckStrike(const string& guessNumber) {
		int returnValue = 0;
		for (auto i = 0; i < guessNumber.size(); i++) {
			if (guessNumber[i] == question[i]) returnValue++;
		}

		return returnValue;
	}

	int CheckBall(const string& guessNumber) {
		for (char ch : guessNumber) {
			size_t pos = question.find(ch);
			if (pos != std::string::npos) {

			}
		}
	}


	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}

	bool isDuplicatedNumber(const string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]) {
			return true;
		}

		return false;
	}

private:
	string question;

};