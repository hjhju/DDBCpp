#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Section10_04 제휴 관계 */

class Doctor; // forward declaration

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;
public:
	Patient(string name_in) :m_name(name_in) {}

	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	// forward declaration 안에서는 doctor의 m_name이 있는지 없는지 알수가 없음
	// body를 분리해서 Doctor아래에 작성해야됨
	void meetDoctors();

	friend class Doctor;
};


class Doctor
{
private:
	string m_name;
	vector <Patient*> m_patients;

public:
	Doctor(string name_in) :m_name(name_in) {}

	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatients()
	{
		for (auto& element : m_patients)
		{
			// patient 클래스를 doctor 클래스의 friend로 설정했기에 변수 접근 가능
			cout << "Meet patient : " << element->m_name << endl;
		}
	}

	friend class Patient;
};


void Patient::meetDoctors()
{
	for (auto& element : m_doctors)
	{
		// patient 클래스를 doctor 클래스의 friend로 설정했기에 변수 접근 가능
		cout << "Meet doctor : " << element->m_name << endl;
	}
}

int main()
{
	Patient *p1 = new Patient("Kim");
	Patient *p2 = new Patient("Park");
	Patient *p3 = new Patient("Lee");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	d1->addPatient(p1);
	p1->addDoctor(d1);

	d2->addPatient(p2);
	p2->addDoctor(d2);

	d1->addPatient(p2);
	p2->addDoctor(d1);

	p1->meetDoctors();

	d1->meetPatients();

	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;

	return 0;
}