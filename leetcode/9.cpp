class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        deque<int> temp;
        while(x){
            temp.push_front(x % 10);
            x /= 10;
        }

        while(!temp.empty()){
            if(temp.front() != temp.back())
                return false;

            if(temp.size() == 1)
                return true;

            temp.pop_front();
            temp.pop_back();
        }

        return true;
    }
};
