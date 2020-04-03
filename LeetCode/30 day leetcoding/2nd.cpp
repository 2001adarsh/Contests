class Solution {
public:
    
    int sums(int n)
    {
        int sum =0;
        while(n){
            int x =  (n%10);
            sum += x*x ;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        int temp = n;
        bool flag = true;
        set<int> s;
        s.insert(n);
        
        while(flag){
         
            temp = sums(temp);
            //cout<<temp<<endl;
            if(s.find(temp) == s.end()){
                s.insert(temp);
            }    
            else if(s.find(temp) != s.end() && temp != 1)
                return false;
            else return true;
            
        }
        return true;
    }
};