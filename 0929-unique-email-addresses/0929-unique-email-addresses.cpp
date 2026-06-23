class Solution {
public:
    int numUniqueEmails(std::vector<std::string>& emails) {
        std::unordered_set<std::string> unique_emails;
        
        // Use a const reference so we don't accidentally copy the whole email string
        for (const std::string& email : emails) {
            std::string clean_email = "";
            bool ignore_local = false; // State tracker for the '+' rule
            
            int i = 0;
            // Phase 1: Parse the local name until we hit the domain
            while (i < email.size() && email[i] != '@') {
                if (email[i] == '+') {
                    ignore_local = true; // Turn on the ignore switch
                }
                
                // Only add the character if we aren't ignoring, AND it's not a dot
                if (!ignore_local && email[i] != '.') {
                    clean_email += email[i];
                }
                i++;
            }
            
            // Phase 2: We hit the '@'. The domain name stays exactly as is.
            // substr(i) grabs everything from the '@' to the very end of the string.
            clean_email += email.substr(i);
            
            // Drop it in the set. If it's a duplicate, the set silently ignores it.
            unique_emails.insert(clean_email);
        }
        
        return unique_emails.size();
    }
};