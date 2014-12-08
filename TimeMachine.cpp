#include <iostream>
#include <limits>
#include "TimeSpan.h"

using namespace std;

int main() {
	TimeSpan dur0;
	TimeSpan dur1(37);
	TimeSpan dur2(19, 54);
	TimeSpan dur3(7, 8, 9);
	TimeSpan dur4(1.2f, 2.5, 3);
	TimeSpan dur5(0, 59, 183);
	TimeSpan dur6(-3, 5, -7);
	TimeSpan dur7(67, 67, 67);
	TimeSpan dur8(-3600);
	TimeSpan dur9(-dur8);
	TimeSpan dur10;

	cout << "Duration0(): " << dur0 << endl;
	cout << "Duration1(37): " << dur1 << endl;
	cout << "Duration2(19, 54): " << dur2 << endl;
	cout << "Duration3(7, 8, 9): " << dur3 << endl;
	cout << "Duration4(1.2f, 2.5, 3): " << dur4 << endl;
	cout << "Duration5(0, 59, 183): " << dur5 << endl;
	cout << "Duration6(-3, 5, -7): " << dur6 << endl;
	cout << "Duration7(67, 67, 67): " << dur7 << endl;
	cout << "Duration8(-3600): " << dur8 << endl;
	cout << "Duration9(-dur8): " << dur9 << endl << endl;
	cout << "Enter a time duration for Duration10 (format: Hrs Mins Secs): ";
	cin >> dur10;
	cout << "Duration10: " << dur10 << endl << endl;

	cout << "Duration1 + Duration2 = " <<  (dur1 + dur2) << endl;
	cout << "Duration1 = " << dur1 << endl;
	cout << "Duration2 = " << dur2 << endl << endl;

	cout << "Duration3 - Duration4 = " << (dur3 - dur4) << endl;
	cout << "Duration3 = " << dur3 << endl;
	cout << "Duration4 = " << dur4 << endl << endl;

	cout << "Duration1 += Duration2 = " <<  (dur1 += dur2) << endl;
	cout << "Duration1 = " << dur1 << endl;
	cout << "Duration2 = " << dur2 << endl << endl;

	cout << "Duration3 -= Duration4 = " << (dur3 -= dur4) << endl;
	cout << "Duration3 = " << dur3 << endl;
	cout << "Duration4 = " << dur4 << endl << endl;

	cout << "Duration6 = " << dur6 << endl;
	cout << "-Duration6 = " << -dur6 << endl;
	cout << "Duration6 = " << dur6 << endl << endl;

	cout << "Duration4: " << dur4 << endl;
	cout << "Duration5: " << dur5 << endl;
	
	cout << "Does Duration4 == Duration5?" << endl;
	if(dur4 == dur5) {
		cout << "Yes, those durations match!" << endl << endl;
	} else {
		cout << "No, those durations do not match!" << endl << endl;
	}

	cout << "Duration8: " << dur8 << endl;
	cout << "Duration10: " << dur10 << endl;
	cout << "Does Duration8 == Duration10?" << endl;
	if(dur8 == dur9) {
		cout << "Yes, those durations match!" << endl << endl;
	} else {
		cout << "No, those durations do not match!" << endl << endl;
	}
	
	/*TimeSpan tester(0, 0, -61);

	cout << "Tester: " << tester << endl;*/

	cout << endl << "any key to exit.";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return(0);
}