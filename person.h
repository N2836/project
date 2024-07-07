#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
class Person {
public:
    std::string last_name;
    std::string first_name;
    std::string skills;

    // سازنده با آرگومان‌ها (Parameterized Constructor)
    Person(const std::string& last_name, const std::string& first_name, const std::string& skills)
        : last_name(last_name), first_name(first_name), skills(skills) {}

    // متد Take_Job (فرض بر اینکه وظیفه خاصی را انجام می‌دهد)
    void Take_Job(const std::string& job) {
        // پیاده‌سازی متد Take_Job
        std::cout << first_name << " " << last_name << " has taken the job: " << job << std::endl;
    }
};

#endif // PERSON_H
