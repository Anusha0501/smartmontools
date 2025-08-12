#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex endurance_regex(
        R"(SSD_Life_Left(?:\s*\"?.*)?$|SSD_LifeLeft(?:\(0\.01%\))?(?:\s*\"?.*)?$|Wear_Leveling(?:_Count)?(?:\s*\"?.*)?$|DriveLife_Remaining%|DriveLife_Used%|Drive_Life_Remaining%|Drive_Life_Used%|SSD_Life_Left_Perc|SSD_Remaining_Life_Perc|Percent_Life_Remaining|Percent_Life_Used|PCT_Life_Remaining|Perc_Rated_Life_Used|Percent_Lifetime_Remaining|Percent_Lifetime_Used)",
        std::regex_constants::icase // This enables case-insensitive matching
    );

    std::string attributes[] = {
        "Raw_Read_Error_Rate",
        "Reallocated_Sector_Ct",
        "Wear_Leveling_Count",
        "Power_On_Hours",
        "SSD_Life_Left",
        "Percent_Life_Remaining",
        "Host_Writes_MiB"
    };

    for (auto& attr : attributes) {
        if (std::regex_match(attr, endurance_regex)) {
            std::cout << "MATCH: " << attr << std::endl;
        } else {
            std::cout << "NO MATCH: " << attr << std::endl;
        }
    }
    return 0;
}
