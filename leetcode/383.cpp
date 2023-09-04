class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> letter_mapping;

        for(int i = 0; i < magazine.size(); i++){
            if(letter_mapping.count(magazine[i]))
                letter_mapping[magazine[i]]++;
            else
                letter_mapping[magazine[i]] = 1;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            if(letter_mapping.count(ransomNote[i])){
                letter_mapping[ransomNote[i]]--;
                if(!letter_mapping[ransomNote[i]])
                    letter_mapping.erase(ransomNote[i]);
                continue;
            }
            return false;
        }
        return true;
    }
};