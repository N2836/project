#ifndef JOB_H
#define JOB_H

#include <string>
#include <vector>

class Job {
public:
    std::string salary;
    std::string job_name;
    std::string company_name;
    std::vector<std::string> skills_required; // آرایه پویا از مهارت‌های مورد نیاز
    std::string workplace_type;
    std::string location;
    std::string type;

    // سازنده با آرگومان‌ها (Parameterized Constructor)
    Job(const std::string& salary, const std::string& job_name, const std::string& company_name,
        const std::vector<std::string>& skills_required, const std::string& workplace_type,
        const std::string& location, const std::string& type)
        : salary(salary), job_name(job_name), company_name(company_name), skills_required(skills_required),
          workplace_type(workplace_type), location(location), type(type) {}
};

#endif // JOB_H
