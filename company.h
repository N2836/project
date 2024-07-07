#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include "job.h" // فرض بر اینکه کلاس Job قبلا تعریف شده است
#include "person.h" // فرض بر اینکه کلاس Person قبلا تعریف شده است

class Company {
public:
    std::string company_name;
    std::vector<Job> company_jobs; // آرایه پویا از شغل‌ها
    std::vector<Person> employees; // آرایه پویا از افراد
    std::vector<std::string> followers;

    // سازنده با آرگومان‌ها (Parameterized Constructor)
    Company(const std::string& company_name, const std::vector<Job>& company_jobs,
            const std::vector<Person>& employees, const std::vector<std::string>& followers)
        : company_name(company_name), company_jobs(company_jobs), employees(employees), followers(followers) {}

    // متد Create_Job (فرض بر اینکه شغلی را ایجاد می‌کند)
    Job Create_Job(const std::string& salary, const std::string& job_name, const std::string& company_name,
                   const std::vector<std::string>& skills_required, const std::string& workplace_type,
                   const std::string& location, const std::string& type) {
        Job new_job(salary, job_name, company_name, skills_required, workplace_type, location, type);
        company_jobs.push_back(new_job);
        return new_job;
    }
};

#endif // COMPANY_H
