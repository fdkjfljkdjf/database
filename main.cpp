#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <exception>
#include <sstream>
#include <algorithm>
#include <iomanip>
// финальная задача первого курса

using namespace std;

class Date {
public:
	Date(const int& year,const int& month,const int& day)
	{
		Year = year;
		Month = month;
		Day = day;
	}
  int GetYear() const
  {
	  return Year;
  }
  int GetMonth() const
  {
	  return Month;
  }
  int GetDay() const
  {
	  return Day;
  }
private:
  int Year;
  int Month;
  int Day;
};

bool operator<(const Date& lhs, const Date& rhs){
	if((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth())){
		return lhs.GetDay() < rhs.GetDay();
	}
	else if(lhs.GetYear() == rhs.GetYear()){
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

void EnsureNextSymbolAndSkip(istringstream& stream){
	if (stream.peek() != '-'){
		throw runtime_error("Wrong date format: " + stream.str());
	}
	stream.ignore(1);
}

void ChecksFormat(istringstream& stream, int& Nomber){
	if(!(stream >> Nomber)){
		throw runtime_error("Wrong date format: " + stream.str());
	}
}

Date ParseDate(istringstream& stream){
	string date;
	stream >> date;
	istringstream input(date);
	int Year, Month, Day;

	if(input){
		ChecksFormat(input, Year);
		EnsureNextSymbolAndSkip(input);
		ChecksFormat(input, Month);
		EnsureNextSymbolAndSkip(input);
		ChecksFormat(input, Day);
		char ignor;
		if(input >> ignor){
			throw runtime_error("Wrong date format: " + input.str());
		}
	}

	if(!(Month >= 1 && Month <= 12) && !(Day >= 1 && Day <= 31)){
		throw invalid_argument("Month value is invalid: " + to_string(Month));
	}
	else if(!(Month >= 1 && Month <= 12)){
		throw invalid_argument("Month value is invalid: " + to_string(Month));
	}
	else if(!(Day >= 1 && Day <= 31)){
		throw invalid_argument("Day value is invalid: " + to_string(Day));
	}
	return {Year, Month, Day};
}

class Database {
public:

  void AddEvent(const Date& date, const string& event){
	  if(database.count(date)){
		  int check = 0;
		  for(const auto& i : database[date]){
			  if(i == event){
				  check++;
			  }
		  }
		  if(check == 0){
			  database[date].push_back(event);
			  sort(database[date].begin(), database[date].end());
		  }
	  }
	  else{
		  database[date].push_back(event);
	  }
  }
  vector<string> Find(const Date& date) {
	  return  database[date];
  }
  int  DeleteDate(const Date& date){
	  int Size = database[date].size();
	  database.erase(date);
	  return Size;
  }
  bool DeleteEvent(const Date& date, const string& event){
	  if(database.count(date)){
		  vector<string> buffer;
		  for (auto& i : database[date]){
			  if(i != event){
				  buffer.push_back(i);
			  }
		  }
		  if(buffer.size() == database[date].size()){
			  return false;
		  }
		  else{
			  database[date].clear();
			  for(const auto& i : buffer){
				  database[date].push_back(i);
			  }
			  return true;
		  }
	  }
	  return false;
  }
  void Print() const{
	  for(const auto& DateEvent : database){
		  for(const auto& events : DateEvent.second){
			  cout << setw(4) << setfill('0') << DateEvent.first.GetYear()
					  << '-' << setw(2) << setfill('0') << DateEvent.first.GetMonth()
					  << '-' << setw(2) << setfill('0') << DateEvent.first.GetDay()
					  << ' ' << events << endl;
		  }
	  }
  }
private:
  map<Date, vector<string>> database;
};

int main() {
	try{
		Database db;
		string command;
		while (getline(cin, command)){
			istringstream stream(command);
			string command;
			if(stream >> command){
				if(command == "Add"){
					Date date = ParseDate(stream);
					string event;
					stream >> event;
					db.AddEvent(date, event);
				}
				else if(command == "Find"){
					Date date = ParseDate(stream);
					for (const auto& i : db.Find(date)){
						cout << i << endl;
					}
				}
				else if(command == "Del"){
					Date date = ParseDate(stream);
					string event;
					if(stream >> event){
						if(db.DeleteEvent(date, event)){
							cout << "Deleted successfully" << endl;
						}
						else{
							cout << "Event not found" << endl;
						}
					}
					else{
						cout << "Deleted " << db.DeleteDate(date) <<" events" << endl;
					}
				}
				else if(command == "Print"){
					db.Print();
				}
				else{
					throw runtime_error("Unknown command: " + command);
				}
			}
		}
	}
    catch (exception& ex) {
    	cout << ex.what();
    }
  return 0;
}


